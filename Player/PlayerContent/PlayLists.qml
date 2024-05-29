import QtQuick 2.15
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.15
import PlaySong 1.0
import QtQuick.Controls 2.15
import Qt.labs.platform 1.0
import Playlists 1.0
import QtQuick.Dialogs
import QtCore 6.7
Item {
    anchors.fill: parent
    signal fullPathSong(string path)

    Playlists {
        id: playlists
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
                    text: "PlayList"
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
                        color: "#545454"
                        radius: 5

                        Column {
                            anchors.fill: parent
                            anchors.margins: 10
                            spacing: 10

                            Rectangle {
                                width: parent.width
                                color: "#fff"
                                height: 30
                                radius: 5
                                TextInput {
                                    id: playListNameInput
                                    width: parent.width
                                    padding: 5
                                }
                            }

                            Button {
                                text: "Dodaj utwór"
                                width: parent.width
                                onClicked: {
                                    playlists.createPlayLists(playListNameInput.text)
                                    modal.close()
                                }
                            }
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
                        model: playlists.playLists.length
                        anchors.fill: parent
                        Flow {
                            width: parent.width
                            spacing: 5
                            Rectangle {
                                width: parent.width
                                height: 50
                                radius: 5
                                color: "#404040"
                                Grid {
                                    width: parent.width
                                    rows: 1
                                    columns: 3
                                    Rectangle {
                                        width: 250
                                        height: 50
                                        radius: 5
                                        color: "#404040"
                                        property int playListsIndex: index
                                        Button {
                                            anchors.centerIn: parent;
                                            text: "Otwórz eksplorator plikow"
                                            Layout.alignment: Qt.AlignRight
                                            padding: 10
                                            width: parent.width - 17
                                            height: 30
                                            Rectangle {
                                                width: parent.width
                                                height: parent.height
                                                color: parent.hovered ? "#808080" : "#363434"

                                                FileDialog {
                                                    id: fileDialog
                                                    title: "Please choose a file"
                                                    onAccepted: {
                                                        console.log("You chose: " + fileDialog.currentFile)
                                                        playlists.addSongToPlayList(playlists.playLists[index],  fileDialog.currentFile)
                                                    }
                                                    onRejected: {
                                                        console.log("rejected")
                                                    }
                                                }
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
                                            text: playlists.playLists[index]
                                        }
                                    }
                                    Rectangle {
                                        width: (parent.width * 0.05)
                                        height: 50
                                        radius: 5
                                        color: "#404040"
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
                            Repeater {
                                model: playlists.songForPlayLists[index]
                                SinglePlayList {
                                    pathSong: modelData
                                    onFullPathSong: {
                                        handlePath(path)
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    Component.onCompleted: {
        playlists.loadPlayLists()
    }
}
