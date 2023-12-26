import QtQuick 2.15

Rectangle{
    id: topBarInv
    height: parent.height / 10
    width: parent.width
    anchors{
        top: parent.top
        left: parent.left
        right: parent.right
    }
    color: "transparent"
    MouseArea {
        id:mouseArea
        anchors.fill: parent
        hoverEnabled: true
        property bool hovered: false
        onEntered: hovered = true
        onExited: hovered = false
    }
    Rectangle{
        id:topBar

        height: parent.height
        width: parent.width -400
        radius: 30
        anchors{
            top: parent.top
            horizontalCenter: parent.horizontalCenter
        }
        color: "blue"
        visible: mouseArea.hovered
        Text{
            id: settings
            //property string text1:qsTr("settings")
            anchors{
                verticalCenter: parent.verticalCenter
                left: parent.left
                leftMargin: 100
            }
            text: qsTr("Settings")
            color:  "white"
            MouseArea{
                id: textMouse
                anchors.fill: parent
                //onClicked: parent.text1 = qsTr("clicked")
            }
        }
        Text {
            id: about
            text: qsTr("About")
            color:  "white"
            anchors{
                verticalCenter: parent.verticalCenter
                left: parent.right
                leftMargin: -100
            }
            MouseArea{
                id: textMouseAbout
                anchors.fill: parent
                //onClicked: parent.text1 = qsTr("clicked")
            }
        }


    }
   // visible: mouseArea.containsMouse
}

