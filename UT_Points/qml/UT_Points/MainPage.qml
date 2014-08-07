import QtQuick 1.1
import com.nokia.symbian 1.1
import QtMobility.location 1.1
import "delegate"

Page {
    id: mainPage
    property double currentlatitude: 0
    property double currentlongtitude: 0
    property int attemptcount: 0
    property string searchedcity: ""
    property variant mapPage: MapPage {}

    PositionSource {
        id: positionSource
        updateInterval: 1000
        active: false
    }

    Text {
        id: currentPosition
        text: qsTr("Locating...")
        anchors {
            top : header.bottom;
        }
        color: platformStyle.colorNormalLight
        font.pixelSize: 20
        height: mainPage.height / 10
        MouseArea {
            anchors.fill: parent
            onClicked: {
                 startPositioning()
            }
        }
    }

    Header {
        id: header
        text:  qsTr("UT WiFi points")
    }

    TextField {
        id: cityName
        anchors {
            left: mainPage.left;
            top: currentPosition.bottom;
        }
        placeholderText: "Enter city name..."
        width: mainPage.width - 10
        onTextChanged: {
            var l = searchedcity.length;
            if (searchedcity !== cityName.text)
            {
                searchedcity = cityName.text;
                if (searchedcity.length > 2)
                    updateUi();
                else if (l === 3)
                    startPositioning();
            }
        }
    }

    ListView {
        id:  wifiPointsView
        anchors {
            left: mainPage.left; right: mainPage.right
            top: cityName.bottom; bottom: parent.bottom
        }
        delegate: BoxItemDelegate {
            id: itemDelegate
            title: textFormat(model)
            height: mainPage.height / 3.5
            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
            clip: true
            onClicked: {
                var loc = "http://m.ovi.me/?c="+model.latitude+","+model.longtitude
                Qt.openUrlExternally(loc)
            }
        }
        clip: true
    }

    function textFormat(model)
    {
        var result = model.CityName + " (" + model.type + ")<br/>";
        if (model.name !== "")
            result += model.name + " <br/>";
        if (model.address !== "")
            result += model.address + " <br/>";
        if (model.sellplaceworktime !== "")
            result += model.sellplaceworktime + " <br/>";
        if (model.distance > 0)
            result += "Distance: " + model.distance.toFixed(3) + " km";
        return result;
    }

    Component.onCompleted: {
     pointSqlQueryModel.openDB();
     pointSqlQueryModel.initDB();
    }

    Timer {
        id: gpsTimer
        interval: 1000
        running: false
        repeat: true
        onTriggered: {
            attemptcount++
            if ((positionSource.position.latitudeValid && positionSource.position.longitudeValid)|| (searchedcity.length > 2))
            {
                gpsTimer.running = false;
                currentlatitude = positionSource.position.coordinate.latitude;
                currentlongtitude = positionSource.position.coordinate.longitude;
                positionSource.active = false;
                updateUi();
                attemptcount = 0;
            } else {
                currentPosition.text = "Locating (" + attemptcount + ")..."
            }
        }
    }

    function updateUi()
    {
        if (searchedcity.length <= 2)
        {
            currentPosition.text = "Current position: latitude " + currentlatitude.toFixed(2) + "<br/>longtitude " + currentlongtitude.toFixed(2)
            pointSqlQueryModel.refresh(currentlatitude, currentlongtitude, 25)
        }
        else
        {
            pointSqlQueryModel.refreshSearch(searchedcity)
        }

        wifiPointsView.model = pointSqlQueryModel
    }

    function startPositioning()
    {
        positionSource.active = true;
        gpsTimer.running = true;
        gpsTimer.repeat = true
    }

    onStatusChanged: {
        if (status === PageStatus.Activating)
        {
            startPositioning()
        }
        if (status === PageStatus.Deactivating)
        {
            positionSource.active = false;
            gpsTimer.running = false;
        }
    }
}
