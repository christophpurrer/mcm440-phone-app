import Qt 4.7

/**
* DialerDisplay shows the typed in telephone number
 *
**/
Item {
    id:dialerdisplay
    property string text

    Image {
        id: buttonimage
        source: "../img/dialer_display.png"
    }

    Text {
        id: displaytext
        text: dialerdisplay.text
        font.pixelSize: 40
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        anchors.fill: buttonimage
    }
}

