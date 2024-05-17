import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.12

Item {
    property int widthButton: 150
    property int heightButton: 50
    property string textForButton: ""
    property color colorButton: "#363434"
    property var functionToCall
    width: widthButton
    height: heightButton

    Rectangle {
        anchors.fill: parent
        color: colorButton
        radius: 5
        Text {
            anchors.centerIn: parent
            color: "#fff"
            text: textForButton
            font.weight: 500
        }

    }
}
