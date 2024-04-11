import QtQuick 2.15
Item {
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
