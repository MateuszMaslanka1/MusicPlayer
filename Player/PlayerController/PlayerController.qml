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
    property string getSongName: ""
    property string getPathName: ""

    PlaySong {
        id: playSong
    }

    onGetSongNameChanged: {

        playSong.playSound();
    }

    onGetPathNameChanged: {
      console.log("test:", getPathName);
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
                text: getSongName
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
                        onPressedChanged: {
                            if (!pressed) {
                                playSong.setPosition(value)
                                userInteraction = pressed
                            } else {
                                userInteraction = pressed
                            }
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

            ButtonComponent {
                textForButton: 'P'
                widthButton: 35
                heightButton: 35
            }

            ButtonComponent {

                textForButton: 'P'
                widthButton: 35
                heightButton: 35
                functionToCall: playSong.playSound;
            }

            ButtonComponent {
                textForButton: 'P'
                widthButton: 35
                heightButton: 35
            }
        }
    }
}
