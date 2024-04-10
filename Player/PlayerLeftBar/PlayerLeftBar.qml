import QtQuick 2.15
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12
import "../SharedComponents"
Item {
    width: player.width * 0.25
    height: player.height
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
                ButtonComponent{
                    textForButton: 'Music'
                    widthButton: navContainer.width
                    heightButton: 50
                }
                ButtonComponent{
                    textForButton: 'Playlist'
                    widthButton: navContainer.width
                    heightButton: 50
                }
            }
        }

    }
}
