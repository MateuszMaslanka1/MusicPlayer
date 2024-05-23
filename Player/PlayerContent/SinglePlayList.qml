import QtQuick 2.15
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.15
import PlaySong 1.0
import QtQuick.Controls 2.15
import Qt.labs.platform 1.0

Grid {
    property string pathSong: ''
    width: parent.width
    rows: 1
    columns: 3
    spacing: 5
    Rectangle {
        width: 50
        height: 50
        radius: 5
        color: "#404040"
        Button {
            text: "P"
            anchors.centerIn: parent;
            width: 35
            height: 35
            // onClicked: {
            //     songName(musicPlayer.someData[index]);
            //     fullPathSong(musicPlayer.path[index]);
            // }
        }
    }
    Rectangle {
        width: (parent.width * 0.95) - 65
        height: 50
        color: "#404040"
        Text {
            anchors.centerIn: parent;
            color: "#fff";
            text: pathSong
        }
    }
    Rectangle {
        width: (parent.width * 0.05)
        height: 50
        color: "#404040"
        radius: 5
        Text {
            anchors.centerIn: parent;
            color: "#fff";
        //     text: {
        //         const songLength = musicPlayer.songLenght[index]
        //         const parts = songLength.split(":")
        //         if (parts.length === 2 && parseInt(parts[1]) < 10) {
        //             return parts[0] + ":0" + parts[1]
        //         } else {
        //             return songLength
        //         }
        //     }
        }
    }
}

