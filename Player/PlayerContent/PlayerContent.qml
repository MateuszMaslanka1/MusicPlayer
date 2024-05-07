import QtQuick 2.15
Item {
    signal handleSongName(string name)
    signal handlePath(string path)
    Rectangle {
        anchors.fill: parent
        color: "#202020"
        // Rectangle {
        //     anchors.fill: parent
        //     color: "#202020"
            // anchors.topMargin: 10;
            // anchors.leftMargin: 20;
            MusicLibrary{
                id: childComponent
                onSongName: {
                    handleSongName(name)
                }
                onFullPathSong: {
                    handlePath(path)
                }
            }
        // }
    }
}
