import Qt 4.7

/**
* DialerKey represents a single number pad button
*
**/
Item {
    id: dialerkey
    width: 106
    height: 66
    property string text;
    property int fontsize: 40;
    property string icon;
    signal clicked

    Image {
        id: buttonimage
        source: "../img/dialerkey_down.png"
        opacity: 0
    }

    Text {
        id: buttontext
        text: dialerkey.text
        font.bold: true
        font.pixelSize: fontsize
        color: "#ffffff"
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        anchors.fill: buttonimage
    }

    Image {
        id: buttonicon
        source: icon
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
                target:buttonimage; opacity:100
            }
        }
    ]
}

