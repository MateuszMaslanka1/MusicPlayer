import QtQuick 2.15
import QtQuick.Controls 2.15
Item {
    width: player.width * 0.75
    height: player.height
    Label {
        text: qsTr("Music Library")
        font.pixelSize: 36
        color: "#fff"
        font.weight: 500
    }
    Rectangle {
        anchors.fill: parent
        anchors.topMargin: 80;
        color: "#202020"
        ScrollView {
            width: (player.width * 0.75) - 30
            height: player.height - 80
            ScrollBar.vertical.policy: ScrollBar.AlwaysOn
            // ScrollBar.vertical.color: "#808080"
            Grid {
                width: parent.width
                anchors.fill: parent
                columns: 1
                flow: GridLayout.FlowDown
                spacing: 5
                Repeater {
                    model: 30

                    Rectangle {
                        width: parent.width
                        height: 50
                        color: "lightblue"
                    }
                }
            }
        }
    }

}
