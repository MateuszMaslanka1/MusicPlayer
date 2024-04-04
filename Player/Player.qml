import QtQuick 2.15
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

import "./PlayerLeftBar"
import "./PlayerContent"

Item {
    width: player.width
    height: player.height
    Grid {
        anchors.fill: parent
        rows: 1
        columns: 2
        PlayerLeftBar {}
        PlayerContent {}
    }
}
