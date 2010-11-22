import Qt 4.7

/**
  * BackButton used in Dialer/AddressBook to go back to home screen
  */
Item {
    id: backbutton
    signal clicked

    Text {
        id: buttontext
        text: "< BACK"
        font.bold: true
        font.pixelSize: 30
        color: "#ffffff"
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignBottom
    }

    MouseArea {
        id: mouseregion
        anchors.fill: backbutton
        onClicked: {backbutton.clicked();}
    }

    states: [
        State {
            name: "clicked"
            when: mouseregion.pressed == true
            PropertyChanges {
                target:backbutton; opacity:0.8
            }
        }
    ]
}
