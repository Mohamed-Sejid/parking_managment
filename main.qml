import QtQuick 2.15
import QtQuick.Window 2.15
import "TopBar"
import "Assests/Led"

Window {
    width: 1024
    height: 784
    visible: true
    title: qsTr("Hello World")
    Image {
        id: background
        source: "qrc:/Assests/black.png"
        fillMode: Image.PreserveAspectFit
    }
    TopBar{
        id: topBar
    }
    Led{
        id: led1
        anchors{
            topMargin: 200
            leftMargin: 100
        }
    }
    Led{
        id: led2
        anchors{
            topMargin: 200
            leftMargin: 325
        }
    }
    Led{
        id: led3
        anchors{
            topMargin: 200
            leftMargin: 530
        }
    }
}
