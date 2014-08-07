// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import com.nokia.symbian 1.1
import QtMobility.location 1.2

Page {
  id: mapPage
  property real mapLatitude : 50
  property real mapLongtitude : 30
  property string mapTitle : ""

  Map {
        id: map
        anchors {
            fill: parent
        }
        plugin: Plugin {name:"nokia"}
        zoomLevel: 17
        center: Coordinate { latitude: mapLatitude; longitude: mapLongtitude }


        MapMouseArea  {
             anchors.fill:parent
             property int lastX : -1
             property int lastY : -1
             onPressed :  { lastX = mouse.x; lastY = mouse.y; }
             onReleased : { lastX = -1; lastY = -1; }
             onPositionChanged: {
                 if (lastX>=0) {
                     map.pan(lastX- mouse.x, lastY - mouse.y)
                     lastX = mouse.x
                     lastY = mouse.y
                 }
             }
         }
    }
}
