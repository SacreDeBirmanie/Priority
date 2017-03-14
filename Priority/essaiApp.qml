import QtQuick 2.6
import QtQuick.Window 2.2
import QtQml.Models 2.2
import QtQuick.Controls 1.5

ApplicationWindow {
    visible: true
    visibility: "Maximized"
    width: 640
    height: 480
    title: qsTr("Priority")

    menuBar: MenuBar {
        Menu {
            title: qsTr("Fichier")
            MenuItem {
                text: qsTr("Quitter")
                onTriggered: Qt.quit();
            }
        }
    }

    Row {
        id : row1

        signal creerUnNouveauTag(string msg)
        TextField {
            id : tagtext
            text: ""
        }
        Button {
            text: "ajouter Tag"
            onClicked: row1.creerUnNouveauTag(tagtext.text)
        }
    }
}
