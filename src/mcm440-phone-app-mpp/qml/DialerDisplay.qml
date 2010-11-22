import Qt 4.7

/**
* DialerDisplay shows the typed in telephone number
 *
**/
Item {
    id:dialerdisplay
    width: 320
    height: 70
    property string text

    Text {
        id: displaytext
        text: dialerdisplay.text
        font.pixelSize: 40
        font.bold: true
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        anchors.fill: dialerdisplay
    }
}

