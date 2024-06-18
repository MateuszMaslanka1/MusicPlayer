import QtQuick 2.15
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import QtMultimedia 5.15
import QtQuick.Layouts 1.15
import "../SharedComponents"
import PlaySong 1.0

Item {
    width: root.width
    height: root.height
    property string getPathName: ""
    property string getPlaylists: ""
    property bool getIsMusicLibrary: false
    property bool isEnabled: false
    PlaySong {
        id: playSong
    }

    Component.onCompleted: {
        playSong.setFirstSong();
    }

    onGetPathNameChanged: {
        if (getPathName) {
            playSong.playSound(getPathName, false);
        }
        getPathName = "";
    }

    onGetPlaylistsChanged: {
        if (getPlaylists) {
            playSong.getPlaylist(getPlaylists, false);
        }
        getIsMusicLibrary = false;
    }

    onGetIsMusicLibraryChanged: {
        if (getIsMusicLibrary) {
            playSong.getPlaylist(getPlaylists, getIsMusicLibrary);
        }
        getPlaylists = "";
    }

    Rectangle {
        anchors.fill: parent
        color: "#282828"

        Rectangle {
            anchors.fill: parent
            anchors.verticalCenter: parent
            color: "#282828"
            anchors.topMargin: 20

            Label {
                id: songName
                text: playSong.songName
                font.pixelSize: 24
                width: parent.width
                horizontalAlignment: Text.AlignHCenter
            }

            Grid {
                columns: 3
                rows: 1
                anchors.fill: parent
                anchors.topMargin: 30

                Rectangle {
                    color: "#282828"
                    width: parent.width * 0.05
                    height: 20
                    Label {
                        text: playSong.secondStart
                        anchors.centerIn: parent
                        font.pixelSize: 12
                    }
                }

                Rectangle {
                    color: "#282828"
                    width: parent.width * 0.90
                    height: 20
                    Slider {
                        id: timeSlider
                        width: parent.width
                        anchors.centerIn: parent
                        from: 0
                        to: playSong.secondForShowOnLineAll
                        value: !userInteraction ? playSong.secondForShowOnLine : ''
                        property bool userInteraction: false
                        enabled: isEnabled
                        onPressedChanged: {
                            if (!pressed) {
                                playSong.setPosition(value)
                                userInteraction = pressed
                            } else {
                                userInteraction = pressed
                            }
                        }
                        onValueChanged: {
                            timeSlider.enabled = true
                        }
                    }
                }

                Rectangle {
                    color: "#282828"
                    width: parent.width * 0.05
                    height: 20
                    Label {
                        text: playSong.second
                        anchors.centerIn: parent
                        font.pixelSize: 12
                    }
                }
            }
        }

        Row {
            spacing: 10
            anchors {
                horizontalCenter: parent.horizontalCenter
                bottom: parent.bottom
                bottomMargin: 22
            }

            Button {
                width: 35
                height: 35
                onClicked: {
                    playSong.backMusic();
                }

                contentItem: Image {
                    width: 30
                    height: 30
                    source: "../../icons/skip-backward-fill.svg"
                }
            }

            Button {
                width: 35
                height: 35
                onClicked: {
                    playSong.playSound(playSong.firstSong,true);
                }

                contentItem: Image {
                    width: 30
                    height: 30
                    source: playSong.isPauseToView ?  "../../icons/pause.svg" :  "../../icons/play.svg"
                }
            }

            Button {
                width: 35
                height: 35
                onClicked: {
                    playSong.nextMusic();
                }

                contentItem: Image {
                    width: 30
                    height: 30
                    source: "../../icons/skip-forward-fill.svg"
                }
            }
        }
    }
}
