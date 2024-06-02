import QtQuick 2.15
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.15
import PlaySong 1.0
import QtQuick.Controls 2.15
import Qt.labs.platform 1.0


Item {
    property string songName
    signal fullPathSong(string path)
    signal removeSong(string path)
    width: parent.width
    height: 50
    Component.onCompleted: {
        console.log(playlistsName)
    }

    Rectangle {
        width: parent.width
        height: 50
        color: "#404040"
        radius: 5
        Grid {
            width: parent.width
            rows: 1
            columns: 3
            // spacing: 5
            Rectangle {
                width: 50
                height: 50
                color: "#404040"
                radius: 5
                Button {
                    text: "P"
                    anchors.centerIn: parent;
                    width: 35
                    height: 35
                    onClicked: {
                        fullPathSong(songName);
                    }
                }
            }
            Rectangle {
                width: (parent.width * 0.95) - 100
                height: 50
                color: "#404040"
                Text {
                    anchors.centerIn: parent;
                    color: "#fff";
                    text: songName
                }
            }
            Rectangle {
                width: 50
                height: 50
                color: "#404040"
                radius: 5
                Button {
                    text: "P"
                    anchors.centerIn: parent;
                    width: 35
                    height: 35
                    onClicked: {
                        removeSong(songName);
                    }
                }
            }
        }
    }

}

