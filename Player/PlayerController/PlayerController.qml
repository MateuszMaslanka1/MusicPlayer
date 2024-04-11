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


    Rectangle {
        anchors.fill: parent
        color: "#282828"

        Label {
            text: "song name"
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
                    text: "0:58"
                    anchors.centerIn: parent
                    font.pixelSize: 12
                }
            }

            Rectangle {
                color: "#282828"
                width: parent.width * 0.90
                height: 20
                Slider {
                    id: volumeSlider
                    width: parent.width
                    anchors.centerIn: parent
                    from: 0
                    to: 1
                    value: mediaPlayer.volume
                    onValueChanged: mediaPlayer.volume = value
                }
            }

            Rectangle {
                color: "#282828"
                width: parent.width * 0.05
                height: 20
                Label {
                    text: "1:50"
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
            bottomMargin: 10
        }

        ButtonComponent {
            textForButton: 'P'
            widthButton: 35
            heightButton: 35
        }

        ButtonComponent {
            PlaySong {
                id: myObject
            }
            textForButton: 'P'
            widthButton: 35
            heightButton: 35
            functionToCall: myObject.playSound;
        }

        ButtonComponent {
            textForButton: 'P'
            widthButton: 35
            heightButton: 35
        }
    }
}
