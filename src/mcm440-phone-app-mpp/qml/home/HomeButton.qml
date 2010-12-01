import Qt 4.7

/**
  * HomeButton represents a clickable button item on the home screen
  */
Item {
    id:homebutton
    property string backgroundimage;
    property bool enabled: false;
    signal clicked;

    Image {
        id: buttonimage
        source: backgroundimage
    }

    MouseArea {
        id: mouseregion
        anchors.fill: buttonimage
        onClicked: {homebutton.clicked();}
    }

    states: [
        State {
            name: "clicked"
            when: mouseregion.pressed == true && enabled == true
            PropertyChanges {
                target: buttonimage; opacity: 0.8
            }
        }
    ]
}
