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
    anchors.fill: parent
    signal isMusicPlayer(bool isMusicPlayerFlag)
    signal fullPathSong(string path)

    ColumnLayout {
        anchors.fill: parent

        Rectangle {
            Layout.preferredWidth: parent.width
            Layout.preferredHeight: parent.height * 0.10
            Layout.minimumHeight: 50
            Layout.fillHeight: true
            color: "#202020"

            RowLayout {
                anchors.fill: parent
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
                        musicPlayer.getPathToDirectory(folderPath);
                    }
                }

                Button {
                    text: "Otwórz eksplorator katalogów"
                    Layout.alignment: Qt.AlignRight
                    padding: 10

                    Rectangle {
                        width: parent.width
                        height: parent.height
                        color: parent.hovered ? "#808080" : "#363434"
                        radius: 5
                        MouseArea {
                            cursorShape: Qt.PointingHandCursor
                            anchors.fill: parent
                            onClicked: {
                                fileDialog.open()
                            }
                        }
                    }
                }
            }

        }

        Rectangle {
            Layout.preferredWidth: parent.width
            Layout.preferredHeight: parent.height * 0.90
            Layout.fillHeight: true
            color: "#202020"
            ScrollView {
                id: scroller
                anchors.top: parent.top
                anchors.left: parent.left
                width: parent.width
                height: parent.height
                clip : true
                Grid {
                    anchors.fill: parent
                    columns: 1
                    spacing: 5
                    Repeater {
                        model: musicPlayer.someData.length
                        anchors.fill: parent
                        Rectangle {
                            width: parent.width
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
                                            isMusicPlayer(true);
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
                                        text: {
                                            const songLength = musicPlayer.songLenght[index]
                                            const parts = songLength.split(":")
                                            if (parts.length === 2 && parseInt(parts[1]) < 10) {
                                                return parts[0] + ":0" + parts[1]
                                            } else {
                                                return songLength
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
    }
}
