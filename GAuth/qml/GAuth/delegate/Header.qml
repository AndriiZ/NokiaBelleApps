import QtQuick 1.1
import com.nokia.symbian 1.1

ListHeading {
    id: listHeading

    property alias text: item.text

    anchors { left: parent.left; right: parent.right; top: parent.top }

    ListItemText {
        id: item
        anchors.fill: parent.paddingItem
        role: "Heading"
    }
} 