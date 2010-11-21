import Qt 4.7

/**
* DialerKey represents a single number pad button
*
**/
Item {
    id: dialerkey
    property string text
    signal clicked

    Image {
        id: buttonimage
        source: "../img/dialerkey_up.png"
    }

    Text {
        id: buttontext
        text: dialerkey.text
        font.pixelSize: 40
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        anchors.fill: buttonimage
    }

    MouseArea {
        id: mouseregion
        anchors.fill: buttonimage
        onClicked: {dialerkey.clicked();}
    }

    states: [
        State {
            name: "clicked"
            when: mouseregion.pressed == true
            PropertyChanges {
                target:buttonimage; source: "../img/dialerkey_down.png"
            }
        }
    ]
}

