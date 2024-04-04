import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    property int widthButton: 150
    property int heightButton: 50
    property string textForButton: ""
    width: widthButton
    height: heightButton

    Button {
        anchors.fill: parent
        Text {
            anchors.centerIn: parent
            color: "#fff"
            text: textForButton
        }

        background: Rectangle {
            color: "#363434"
            radius: 5
        }

    }
}
