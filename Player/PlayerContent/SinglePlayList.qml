import QtQuick 2.15
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.15
import PlaySong 1.0
import QtQuick.Controls 2.15
import Qt.labs.platform 1.0

Item {
    property string songName
    property string songPath
    property string songTime
    property string playlistsIndex
    signal fullPathSong(string path)
    signal playlistName(string playlistName)
    signal removeSong(string songPath, string playlistName)
    width: parent.width
    height: 50
    Rectangle {
        width: parent.width
        height: 50
        color: "#404040"
        radius: 5
        RowLayout  {
            width: parent.width

            Rectangle {
                width: 50
                height: 50
                color: "#404040"
                radius: 5
                Button {
                    anchors.centerIn: parent
                    width: 35
                    height: 35
                    onClicked: {
                        fullPathSong(songPath)
                        playlistName(playlistsIndex)
                    }
                    contentItem: Image {
                        width: 30
                        height: 30
                        source: "../../icons/play.svg"
                    }
                }
            }

            Rectangle {
                width: parent.width * 0.95 - 100
                height: 50
                color: "#404040"
                Text {
                    anchors.centerIn: parent
                    color: "#ffffff"
                    text: songName
                }
            }

            Rectangle {
                Layout.fillWidth: true
                height: 50
                color: "#404040"
                Text {
                    anchors.centerIn: parent
                    color: "#ffffff"
                    text: songTime
                }
            }

            Rectangle {
                width: 50
                height: 50
                color: "#404040"
                radius: 5
                Button {
                    anchors.centerIn: parent
                    width: 35
                    height: 35
                    onClicked: {
                        removeSong(songPath, playlistsIndex)
                    }
                    contentItem: Image {
                        width: 15
                        height: 15
                        source: "../../icons/trash-fill.svg"
                    }
                }
            }
        }
    }

}

