import QtQuick 2.15
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.15

import "./PlayerLeftBar"
import "./PlayerContent"
import "./PlayerController"

Item {
    id: player
    width: root.width
    height: root.height

    GridLayout {
        anchors.fill: parent
        columns: 1
        rows: 2
        rowSpacing: 0

        RowLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.row: 0
            spacing: 0
            Layout.preferredHeight: parent.height * 0.90
            PlayerLeftBar  {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.preferredWidth: parent.width * 0.20
            }

            PlayerContent  {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.preferredWidth: parent.width * 0.80
            }
        }

        PlayerController  {
            Layout.topMargin: 0
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.row: 1
            Layout.preferredHeight: parent.width * 0.10
        }
    }
}
