import QtQuick 2.15
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

import "./PlayerLeftBar"
import "./PlayerContent"
import "./PlayerController"

Item {
    width: player.width
    height: player.height
    Grid {
        anchors.fill: parent
        rows: 2
        columns: 2
        PlayerLeftBar {}
        PlayerContent {}
        PlayerController {

        }
    }
}
