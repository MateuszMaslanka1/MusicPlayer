import QtQuick 2.15
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.15
import "../PlayerController"
import "../SharedComponents"
import PlaySong 1.0
import QtQuick.Controls 2.15
import Qt.labs.platform 1.0
Item {
    id: musicPlayerComponent
    height: player.height * 0.70
    signal songName(string name)
    signal fullPathSong(string path)

    Rectangle {
        Label {
            text: "Music Library"
            font.pixelSize: 36
            color: "#fff"
            font.weight: 500
        }


        FolderDialog {
            id: fileDialog
            title: "Wybierz katalog"
            folder: StandardPaths.standardLocations(StandardPaths.PicturesLocation)[0]

            onAccepted: {
                const folderPath = fileDialog.currentFolder;
                // console.log("Wybrany katalog:", folderPath);
                musicPlayer.getPathToDirectory(folderPath);
            }
        }

        Button {
            text: "Otwórz eksplorator katalogów"
            anchors.centerIn: parent
            onClicked: fileDialog.open()
        }

        Rectangle {
            anchors.fill: parent
            anchors.topMargin: 60;
            color: "#202020"


            ScrollView {
                // width: (player.width * 0.75) - 30
                height: player.height - 80
                // ScerollBar.vertical.policy: ScrollBar.AlwaysOn
                Grid {
                    width: parent.width
                    anchors.fill: parent
                    columns: 1
                    spacing: 5
                    Repeater {
                        model: musicPlayer.someData.length
                        Rectangle {
                            width: (player.width * 0.75) - 30
                            height: 50
                            color: "#404040"
                            radius: 5
                            Grid {
                                width: parent.width
                                rows: 1
                                columns: 3
                                spacing: 5
                                Rectangle {
                                    width: 50
                                    height: 50
                                    radius: 5
                                    color: "#404040"
                                    Button {
                                        text: "P"
                                        anchors.centerIn: parent;
                                        width: 35
                                        height: 35
                                        onClicked: {
                                            songName(musicPlayer.someData[index]);
                                            fullPathSong(musicPlayer.path[index]);
                                        }
                                    }
                                }
                                Rectangle {
                                    width: (parent.width * 0.95) - 65
                                    height: 50
                                    color: "#404040"
                                    Text {
                                        anchors.centerIn: parent;
                                        color: "#fff";
                                        text: musicPlayer.someData[index]
                                    }
                                }
                                Rectangle {
                                    width: (parent.width * 0.05)
                                    height: 50
                                    color: "#404040"
                                    radius: 5
                                    Text {
                                        anchors.centerIn: parent;
                                        color: "#fff";
                                        text: "2:23"
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
