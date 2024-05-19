import QtQuick 2.15
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.15
import PlaySong 1.0
import QtQuick.Controls 2.15
import Qt.labs.platform 1.0
import Playlists 1.0
Item {
    anchors.fill: parent
    signal songName(string name)
    signal fullPathSong(string path)

    Playlists {
        id: playlists
        onPlayListsLoaded: {
            console.log("Playlists loaded:", playLists)
            // listView.model = playLists
        }
    }

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
                    text: "PlayLists"
                    font.pixelSize: 36
                    color: "#fff"
                    font.weight: 500
                }

                Popup {
                    id: modal
                    x: (root.width - modal.width) / 2
                    y: (root.height - modal.height) / 2
                    width: 300
                    height: 100
                    visible: false

                    Rectangle {
                        anchors.fill: parent
                        color: "lightgrey"

                        TextInput {
                            id: playListNameInput
                            anchors.centerIn: parent
                            width: parent.width - 40
                            // placeholderText: "Wpisz coś..."
                        }

                        Button {
                            text: "Zamknij modal"
                            anchors {
                                horizontalCenter: parent.horizontalCenter
                                bottom: parent.bottom
                                bottomMargin: 20
                            }
                            onClicked: playlists.createPlayLists(playListNameInput.text);
                        }
                    }
                }

                Button {
                    text: "Utwórz liste odtwarzania"
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
                                modal.open()
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
                id: scrollerPlayLists
                anchors.top: parent.top
                anchors.left: parent.left
                width: parent.width
                height: parent.height
                clip : true
                Grid {
                    anchors.fill: parent
                    columns: 1
                    spacing: 10
                    Repeater {
                        model: 2
                        anchors.fill: parent
                        Flow {
                            width: parent.width
                            spacing: 5
                            Grid {
                                width: parent.width
                                rows: 1
                                columns: 3
                                Rectangle {
                                    width: 250
                                    height: 50
                                    radius: 5
                                    color: "#404040"
                                    Button {
                                        anchors.centerIn: parent;
                                        text: "Otwórz eksplorator plikow"
                                        Layout.alignment: Qt.AlignRight
                                        padding: 10
                                        width: parent.width
                                        height: 30
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
                                Rectangle {
                                    width: (parent.width * 0.95) - 250
                                    height: 50
                                    color: "#404040"
                                    Text {
                                        anchors.centerIn: parent;
                                        color: "#fff";
                                        text: "musicPlayer.someData[index]"
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
                            SinglePlayList {}
                        }
                    }
                }
            }
        }
    }
}
