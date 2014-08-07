// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import com.nokia.symbian 1.1
import "../Component"
import QGoogleAuth 1.0

Page {
    id: addProviderPage
    property int providerId
    property string providerNameValue
    property string providerSecretValue

    tools: ToolBarLayout {
        ToolButtonWithTip {
            flat: true
            text: qsTr("Accept")
            onClicked: {
                accept()
                window.pageStack.pop()
            }
        }

        ToolButtonWithTip {
            flat: true
            text: qsTr("Cancel")
            toolTipText: qsTr("Cancel")
            onClicked: {
                window.pageStack.pop()
            }
        }
    }


    ListHeading {
        id: listHeading

        ListItemText {
            id: headingText
            anchors.fill: listHeading.paddingItem
            text: "Add provider"
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
        placeholderText: qsTr("Enter provider name...")
        text: providerNameValue
        width: addProviderPage.width -10
        anchors {
            top: providerLabel.bottom
        }
    }

    Label {
        id: providerSecretLabel
        text: "Secret key"
        anchors {
            top: providerName.bottom
        }
    }
    TextField {
        id: providerSecret
        width: addProviderPage.width -10
        placeholderText: qsTr("Enter secret...")
        text: providerSecretValue
        anchors {
            top: providerSecretLabel.bottom
        }
        onTextChanged: {
            providerPIN.text = qGoogleAuth.generatePin(providerSecret.text)
        }
    }
    Label {
        id: totpLabel
        text: "PIN"
        anchors {
            top: providerSecret.bottom
        }
    }
    TextField {
        id: providerPIN
        width: addProviderPage.width -10
        readOnly: true
        anchors {
            top: totpLabel.bottom
        }
    }
    Timer {
        id: generatorTimer
        interval: 5000
        running: false
        repeat: true
        onTriggered: {
            providerPIN.text = qGoogleAuth.generatePin(providerSecret.text)
        }
    }

    QGoogleAuth {
        id: qGoogleAuth
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


    function accept()
    {
        if (providerId === 0)
            providerModel.insertProvider(providerName.text, providerSecret.text)
        else {
            providerModel.updateProvider(providerName.text, providerSecret.text, providerId)
        }
    }

}
