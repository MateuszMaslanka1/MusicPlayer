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
    signal songName(string name)
    signal fullPathSong(string path)

    ColumnLayout {
        anchors.fill: parent
        Rectangle {
            Layout.preferredWidth: parent.width
            Layout.preferredHeight: parent.height * 0.10
            Layout.minimumHeight: 50
            Layout.fillHeight: true
            color: "#202020"
            border.color: "blue"

            RowLayout {
                anchors.fill: parent
                Layout.fillWidth: true
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
                    width: 250
                    height: 50
                    MouseArea {
                        cursorShape: Qt.PointingHandCursor
                        anchors.fill: parent
                        hoverEnabled: true
                        // onEntered: parent.color = "#808080"
                        // onExited: parent.color = colorButton
                        onClicked: {
                            fileDialog.open()
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
                anchors.fill: parent
                clip: true
                // ScerollBar.vertical.policy: ScrollBar.AlwaysOn
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
