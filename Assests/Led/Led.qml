import QtQuick 2.15

Item {
    property color ledColor
    property bool busy: false
    ledColor: busy? "yellow":"green"
    anchors{
        top:parent.top
        bottom: parent.bottom
        left: parent.left
        right: parent.right
    }
    Rectangle{
        id: ledCercle
        width: 75
        height: 75
        radius: 180
        color: ledColor
        anchors.centerIn: parent.Center
    }
    Text {
        id: ledText
        anchors{
            horizontalCenter: ledCercle.horizontalCenter
            top: ledCercle.bottom
            topMargin: 20
        }

        text: busy ? qsTr("Spot is not free") : qsTr("Spot is free")
        color: "white"
    }


}
