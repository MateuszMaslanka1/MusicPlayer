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

    PlaySong {
        id: myObject
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
                        text: myObject.secondStart
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
                        to: myObject.totalDurationInSeconds // Ustawienie maksymalnej wartości Slidera na długość utworu w sekundach
                        value: myObject.positionInSeconds // Ustawienie wartości Slidera na aktualną pozycję odtwarzania w sekundach
                        onValueChanged: myObject.setPosition(value) // Ustawienie pozycji odtwarzania na wartość Slidera
                    }
                }

                Rectangle {
                    color: "#282828"
                    width: parent.width * 0.05
                    height: 20
                    Label {
                        text: myObject.second
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
                functionToCall: myObject.playSound;
            }

            ButtonComponent {
                textForButton: 'P'
                widthButton: 35
                heightButton: 35
            }
        }
    }
}
