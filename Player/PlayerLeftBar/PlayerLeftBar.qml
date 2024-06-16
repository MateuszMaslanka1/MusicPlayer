import QtQuick 2.15
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12
import "../SharedComponents"
Item {
    signal switchToMusic()
    signal switchToPlaylist()
    Rectangle {
        anchors.fill: parent
        color: "#1d1d1d"
        Rectangle {
            id: navContainer
            anchors.fill: parent
            color: parent.color
            anchors.margins: 5
            Grid {
                anchors.fill: navContainer
                columns: 1
                spacing: 5
                ButtonComponent {
                    id: musicPlayerButton
                    textForButton: 'Music'
                    widthButton: navContainer.width
                    colorButton: "#363434"
                    heightButton: 50
                    MouseArea {
                        cursorShape: Qt.PointingHandCursor
                        anchors.fill: parent
                        hoverEnabled: true
                        onEntered: musicPlayerButton.colorButton = "#808080"
                        onExited: musicPlayerButton.colorButton = "#363434"
                        onClicked: {
                            switchToMusic()
                        }
                    }
                }
                ButtonComponent {
                    id: playlistButton
                    textForButton: 'Playlist'
                    widthButton: navContainer.width
                    colorButton: "#363434"
                    heightButton: 50
                    MouseArea {
                        cursorShape: Qt.PointingHandCursor
                        anchors.fill: parent
                        hoverEnabled: true
                        onEntered: playlistButton.colorButton = "#808080"
                        onExited: playlistButton.colorButton = "#363434"
                        onClicked: {
                            playlistButton.colorButton = "#808080"
                            switchToPlaylist()
                        }
                    }
                }
            }
        }
    }
}
