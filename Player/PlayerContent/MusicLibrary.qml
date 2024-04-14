import QtQuick 2.15
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

import "../SharedComponents"
Item {
    // width: player.width * 0.75
    height: player.height * 0.70
    Label {
        text: "Music Library"
        font.pixelSize: 36
        color: "#fff"
        font.weight: 500
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
                                width: 35
                                height: 50
                                radius: 5
                                color: "#404040"
                                ButtonComponent{
                                    anchors.centerIn: parent;
                                    textForButton: 'P'
                                    widthButton: 35
                                    heightButton: 35
                                }
                            }
                            Rectangle {
                                width: (parent.width * 0.95) - 35
                                height: 50
                                color: "#404040"
                                Text {
                                    anchors.centerIn: parent;
                                    color: "#fff";
                                    text: musicPlayer.someData[index]
                                }
                            }
                            Rectangle {
                                width: (parent.width * 0.05) - 35
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
