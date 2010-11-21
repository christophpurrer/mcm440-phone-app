import Qt 4.7

/**
* DialarButtons represents an action button with an attached
 * as background
**/
Item {
    id: dialerbutton
    signal clicked

    Image {
        id: buttonimage
        source: "../img/dialer_call.png"
    }

    Text {
        id: buttontext
        text: "CALL"
        font.pixelSize: 40
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        anchors.fill: buttonimage
    }

    MouseArea {
        id: mouseregion
        anchors.fill: buttonimage
        onClicked: {dialerbutton.clicked();}
    }

    states: [
        State {
            name: "clicked"
            when: mouseregion.pressed == true
            PropertyChanges {
                target:dialerbutton; opacity: 0.6
            }
        }
    ]
}
