import QtQuick 2.15
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import "./PlayerContent" as PlayerContent
import "./PlayerLeftBar" as PlayerLeftBar
Item {
    width: root.width
    height: root.height
    Grid {
        anchors.fill: parent
        rows: 1
        columns: 2

        Rectangle {
            width: player.width * 0.25
            height: player.height
            color: "#1d1d1d"
        }

        Rectangle {
            width: player.width * 0.75
            height: player.height
            color: "#202020"
        }
    }
}
