import QtQuick 2.15
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.15
import PlaySong 1.0
import QtQuick.Controls 2.15
import Qt.labs.platform 1.0
Item {
    ColumnLayout {
        anchors.fill: parent
        Rectangle {
            Layout.preferredWidth: parent.width
            Layout.preferredHeight: parent.height * 0.10
            Layout.minimumHeight: 50
            Layout.fillHeight: true
            color: "#202020"

            RowLayout {
                anchors.fill: parent
                Label {
                    text: "PlayLists"
                    font.pixelSize: 36
                    color: "#fff"
                    font.weight: 500
                }
            }
        }
    }
}
