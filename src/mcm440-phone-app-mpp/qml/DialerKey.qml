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
    property string backgroundimage;
    signal clicked

    Image {
        id: buttonimage
        source: backgroundimage
    }

    Image {
        id: buttonoverlay
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
        anchors.fill: buttonoverlay
    }

    Image {
        id: buttonicon
        source: icon
    }

    MouseArea {
        id: mouseregion
        anchors.fill: buttonoverlay
        onClicked: {dialerkey.clicked();}
    }

    states: [
        State {
            name: "clicked"
            when: mouseregion.pressed == true
            PropertyChanges {
                target:buttonoverlay; opacity:100
            }
        }
    ]
}

