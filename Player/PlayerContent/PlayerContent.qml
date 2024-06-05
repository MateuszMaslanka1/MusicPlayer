import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    function switchToView(viewName) {
        if (viewName === "musicLibraryComponent") {
            contentLoader.sourceComponent = musicLibraryComponent
        } else if (viewName === "musicPlayListsComponent") {
            contentLoader.sourceComponent = musicPlayListsComponent
        }
    }

    signal handlePath(string path)
    signal handlePlaylists(string playlists)
    signal handleIsMusicPlayerPath(bool flag)
    Rectangle {
        anchors.fill: parent
        color: "#202020"
        Loader {
            id: contentLoader
            anchors.fill: parent
            asynchronous: true
            sourceComponent: musicLibraryComponent
        }
    }

    Component {
        id: musicLibraryComponent
        MusicLibrary {
            anchors.rightMargin: 10
            anchors.leftMargin: 10
            onFullPathSong: {
                handlePath(path)
            }
            onIsMusicPlayer: {
                handleIsMusicPlayerPath(isMusicPlayerFlag)

            }
        }
    }

    Component {
        id: musicPlayListsComponent
        PlayLists {
            anchors.rightMargin: 10
            anchors.leftMargin: 10
            onFullPathSong: {
                handlePath(path)
            }
            onPlaylistsName: {
               handlePlaylists(playlists)
            }
        }
    }

    Component.onCompleted: {
        contentLoader.sourceComponent = musicLibraryComponent
    }
}
