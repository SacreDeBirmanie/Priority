import QtQuick 1.1

Row {
    anchors.fill: parent
    Rectangle {
        border.width : 1
        border.color : "black"
        Text {
            text: qsTr("filtrer par tag : ")
            anchors.fill: parent

        }
    }
    Rectangle {
        border.width : 1
        border.color : "black"
        TextInput {
            width: 240
            cursorVisible: true
            anchors.fill: parent
        }
    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
            Qt.quit();
        }
    }
}
