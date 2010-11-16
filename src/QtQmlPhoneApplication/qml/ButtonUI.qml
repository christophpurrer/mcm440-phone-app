import Qt 4.7
Item {
    id: container
    property string text: ""
    property string iconSource: ""
    signal clicked

    BorderImage {
        id: buttonImage
        opacity: 1
        source: iconSource
    }

    Text {
        anchors.centerIn: buttonImage
        text: container.text
        color: "red"
    }

    MouseArea {
        id: mouseRegion
        anchors.fill: buttonImage
        onClicked: { container.clicked(); }
    }

    states: State {
        name: "Pressed"
        when: mouseRegion.pressed == true
        PropertyChanges { target: container; opacity:
                          0.6 }
    }
}
