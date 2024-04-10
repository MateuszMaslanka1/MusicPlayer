import QtQuick 2.15
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
Item {
    width: player.width * 0.75
    height: player.height
    Label {

        // text:  musicPlayer.someData;
        font.pixelSize: 36
        color: "#fff"
        font.weight: 500
    }
    Rectangle {

        anchors.fill: parent
        anchors.topMargin: 60;
        color: "#202020"
        ScrollView {
            width: (player.width * 0.75) - 30
            height: player.height - 80
            ScrollBar.vertical.policy: ScrollBar.AlwaysOn
            Grid {
                width: parent.width
                anchors.fill: parent
                columns: 1
                spacing: 5
                Repeater {
                    model: musicPlayer.someData.length
                    Rectangle {
                        width: parent.width
                        height: 50
                        color: "#404040"
                        radius: 5
                        Text {
                            text: musicPlayer.someData[index]
                        }
                    }
                }
            }
        }
    }

}
