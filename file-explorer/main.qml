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
        id: row
        anchors.top: parent.top
        anchors.topMargin: 12
        anchors.horizontalCenter: parent.horizontalCenter
    }

    ItemSelectionModel {
        id: sel
        model: fileSystemModel
    }

    TreeView {
        id: view
        anchors.fill: parent
        anchors.margins: 2 * 12 + row.height
        model: fileSystemModel
        rootIndex: rootPathIndex
        selection: sel

        TableViewColumn {
            title: "Nom"
            role: "fileName"
            resizable: true
        }

        TableViewColumn {
            title: "Taille"
            role: "size"
            resizable: true
            horizontalAlignment : Text.AlignRight
            width: 70
        }

        TableViewColumn {
            title: "Dernière modification"
            role: "lastModified"
            resizable: true
        }

        onActivated : {
            var url = fileSystemModel.data(index, FileSystemModel.UrlStringRole)
            Qt.openUrlExternally(url)
        }
    }
}
