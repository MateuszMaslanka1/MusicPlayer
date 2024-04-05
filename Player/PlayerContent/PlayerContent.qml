import QtQuick 2.15
// import "MusicLibrary"
Item {
    width: player.width * 0.75
    height: player.height
    Rectangle {
        anchors.fill: parent
        color: "#202020"
        Rectangle {
            anchors.fill: parent
            color: "#202020"
            anchors.leftMargin: 30;
            MusicLibrary{}
        }
    }
}
