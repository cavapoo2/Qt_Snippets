import QtQuick 2.9
import assets 1.0
Item {
    anchors {
        top: parent.top
        bottom: parent.bottom
        left: parent.left
    }
    property bool isCollapsed: true
    width: isCollapsed ? Style.widthNavigationBarCollapsed : Style.heightNavigationBarExpanded
    //width: 100
    Rectangle {
        anchors.fill: parent
        color: Style.colourNavigationBarBackground
        /*
        id: navigationBar
        anchors {
            top: parent.top
            bottom: parent.bottom
            left: parent.left
        }
        width: 100
        color: "#000000"
        */
        Column {
            NavigationButton {
                iconCharacter: "\uf0c9"
                description: ""
            }
            NavigationButton {
                iconCharacter: "\uf015"
                description: "Dashboard"
            }
            NavigationButton {
                iconCharacter: "\uf234"
                description: "New Client"

            }
            NavigationButton {
                iconCharacter: "\uf002"
                description: "Find Client"
            }
        }


    }

}
