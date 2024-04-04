import QtQuick
import QtQuick.Controls 2.15
import "./Player"
Window {
    id: root
    width: 1280
    height: 720
    visible: true
    title: qsTr("Music Player")
    Player {
        id: player
        anchors.fill: parent
    }
}
