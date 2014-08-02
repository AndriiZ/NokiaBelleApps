// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import com.nokia.symbian 1.1
import "../Component"
import QGoogleAuth 1.0

Page {
    id: viewProviderPage
    property int providerId
    property string providerNameValue
    property string providerSecretValue
    property variant addProviderPage: AddProviderPage {}

    QueryDialog {
        id: deleteProviderDialog
        titleText: qsTr("Delete request")
        message: qsTr("Delete provider?")
        acceptButtonText: qsTr("Delete")
        rejectButtonText: qsTr("Cancel")

        onAccepted: {
            providerModel.deleteProvider(providerId)
            window.pageStack.pop()
        }
    }

    tools: ToolBarLayout {
        ToolButtonWithTip {
            flat: true
            iconSource: "toolbar-back"
            toolTipText: qsTr("Back")
            onClicked: {
                window.pageStack.pop()
            }
        }

        ToolButtonWithTip {
            flat: true
            text: qsTr("Edit")
            onClicked: {
                setProviderValues(addProviderPage, providerId, providerNameValue, providerSecretValue)
                window.pageStack.push(addProviderPage)
            }
        }

        ToolButtonWithTip {
            flat: true
            text: qsTr("Delete")
            onClicked: {
                deleteProviderDialog.open()
            }
        }


    }


    ListHeading {
        id: listHeading

        ListItemText {
            id: headingText
            anchors.fill: listHeading.paddingItem
            text: "View provider PIN"
        }
    }
    Label {
        id: providerLabel
        text: "Provider name"
        anchors {
            top: listHeading.bottom
        }
    }

    TextField {
        id: providerName
        text: providerNameValue
        width: viewProviderPage.width -10
        anchors {
            top: providerLabel.bottom
        }
        readOnly: true
    }

    Label {
        id: totpLabel
        text: "PIN"
        anchors {
            top: providerName.bottom
        }
    }
    TextField {
        id: providerPIN
        width: viewProviderPage.width -10
        readOnly: true
        anchors {
            top: totpLabel.bottom
        }
        text: qGoogleAuth.generatePin(providerSecretValue)
    }
    Timer {
        id: generatorTimer
        interval: 5000
        running: false
        repeat: true
        onTriggered: {
            providerPIN.text = qGoogleAuth.generatePin(providerSecretValue)
        }
    }

    onStatusChanged: {
        if (status === PageStatus.Activating)
        {
            generatorTimer.running = true
        }

        if (status === PageStatus.Deactivating)
        {
            generatorTimer.running = false
        }
    }

    QGoogleAuth {
        id: qGoogleAuth
    }

    function setProviderValues(page, id, name, secret)
    {
        page.providerId = id
        page.providerNameValue = name
        page.providerSecretValue = secret
    }

}
