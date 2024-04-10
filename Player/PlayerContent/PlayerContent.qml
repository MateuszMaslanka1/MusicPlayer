import QtQuick 2.15
Item {
    width: player.width * 0.75
    height: player.height
    Rectangle {
        anchors.fill: parent
        color: "#202020"
        Rectangle {
            anchors.fill: parent
            color: "#202020"
            anchors.topMargin: 10;
            anchors.leftMargin: 20;
            MusicLibrary{}
        }
    }
}
