import QtQuick 1.1
import com.nokia.symbian 1.1

ListItem {
    id: listItem

    property alias title: boxTitle.text

    ListItemText {
        id : boxTitle
        mode: listItem.mode
        anchors.verticalCenter: parent.verticalCenter
    }


}  
