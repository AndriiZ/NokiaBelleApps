import QtQuick 1.1
import com.nokia.symbian 1.1
import "Component"
import "delegate"
import ProviderModel 1.0

Page {
    id: mainPage
    width: 360
    height: 640
    tools: ToolBarLayout {
        ToolButtonWithTip {
            property Component __exitDialog: null
            iconSource: "Image/close_stop.svg"
            toolTipText: qsTr("Exit")
            onClicked: {
                if (!__exitDialog) __exitDialog = Qt.createComponent("Dialog/ExitDialog.qml")
                __exitDialog.createObject(mainPage)
            }
        }

        ToolButtonWithTip {
            flat: true
            toolTipText: qsTr("Add new provider")
            iconSource: "toolbar-add"
            onClicked: {
                setProviderValues(window.addProviderPage, 0, "", "")
                window.pageStack.push(window.addProviderPage)
            }
        }

        ToolButtonWithTip {
            flat: true
            iconSource: "toolbar-menu"
            toolTipText: qsTr("Change settings")
            onClicked: window.pageStack.depth <= 1 ? Qt.quit() : window.pageStack.pop()
        }
    }

    Header {
        id: header
        text:  qsTr("TOTP providers")
    }

    ListView {
        id:  providerView
        anchors {
            left: mainPage.left; right: mainPage.right
            top: header.bottom; bottom: parent.bottom
        }
        delegate: BoxItemDelegate {
            id: itemDelegate
            title: model.provider
            onClicked: {
                setProviderValues(window.viewProviderPage, model.id, model.provider, model.secret)
                window.pageStack.push(window.viewProviderPage)
            }
        }
        clip: true
    }

    onStatusChanged: {
        if (status === PageStatus.Activating)
        {
            updateUi();
        }
    }

    Component.onCompleted: {
     providerModel.openDB();
     providerModel.initDB();
    }

    function updateUi()
    {
        providerModel.refresh()
        providerView.model = providerModel
    }

    function setProviderValues(page, id, name, secret)
    {
        page.providerId = id
        page.providerNameValue = name
        page.providerSecretValue = secret
    }
}
