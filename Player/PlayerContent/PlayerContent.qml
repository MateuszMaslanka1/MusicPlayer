import QtQuick 2.15
Item {
    signal handlePath(string path)
    Rectangle {
        anchors.fill: parent
        color: "#202020"
        MusicLibrary{
            anchors.rightMargin: 10
            anchors.leftMargin: 10
            id: childComponent
            onFullPathSong: {
                handlePath(path)
            }
        }
    }
}
