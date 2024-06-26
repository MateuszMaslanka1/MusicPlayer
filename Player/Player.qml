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
            Layout.preferredHeight: root.height - 130
            PlayerLeftBar  {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.preferredWidth: parent.width * 0.20
                onSwitchToMusic: {
                    playerContent.switchToView("musicLibraryComponent")
                }
                onSwitchToPlaylist: {
                    playerContent.switchToView("musicPlayListsComponent")
                }
            }

            PlayerContent {
                id: playerContent
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.preferredWidth: parent.width * 0.80
                onHandleStopMusic: {
                    playerController.getSingnalStopMusic = stop;
                }
                onHandlePath: {
                    playerController.getPathName = path;
                }
                onHandlePlaylists: {
                    playerController.getPlaylists = playlists;
                }
                onHandleIsMusicPlayerPath: {
                    playerController.getIsMusicLibrary = flag;
                }
            }
        }

        PlayerController {
            id: playerController
            Layout.topMargin: 0
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.row: 1
            Layout.preferredHeight: 130
        }
    }
}
