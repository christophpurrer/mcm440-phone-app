import Qt 4.7

/**
* AddressBookEntry.qml shows a single address entry
**/
Item {
    id: addressEntry
    property string image_front;
    property string image_back;
    property string currentImage: image_front;
    property string number;
    signal clicked    

    Image {
        id: frontimage
        source: image_front
    }

    Image {
        id: backimage
        source: image_back
    }

    MouseArea {
        id: mouseregion
        anchors.fill: frontimage
        onClicked: {addressEntry.clicked();}
    }

    //states
    states: [
        State {
            name: "front"
            when: currentImage == image_front
            PropertyChanges {
                target: frontimage; opacity: 1
            }
            PropertyChanges {
                target: backimage; opacity: 0
            }
        },
        State {
            name: "back"
            when: currentImage == image_back
            PropertyChanges {
                target: frontimage; opacity: 0
            }
            PropertyChanges {
                target: backimage; opacity: 1
            }
        }
    ]

    //transitions
    transitions: [
        Transition {
            NumberAnimation { properties: "opacity"; duration: 350 }
        }
    ]
}
