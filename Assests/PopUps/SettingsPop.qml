import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Item {
    id:setPop
    anchors{
        top:parent.top
        bottom: parent.bottom
        left: parent.left
        right: parent.right
    }
    Rectangle{
        id: settingsPop
        height: 300
        width: 300
        anchors.centerIn: parent.Center

        color: "black"
        ComboBox {
            id: comboBox
            anchors.centerIn: parent.Center

            width: 200
            model: handler.portList
            onCurrentIndexChanged: {
                    console.log("Selected index:", comboBox.currentIndex);
                        console.log("Selected item:", comboBox.currentText);
                    }

        }

    }
}
