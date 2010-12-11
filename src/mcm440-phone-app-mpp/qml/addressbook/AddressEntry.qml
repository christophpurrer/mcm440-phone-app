import Qt 4.7

/**
* AddressBookEntry.qml shows a single address entry
**/
Item {
    id: addressEntry
    property string image_front;
    property string image_back;
    property string currentImage: image_front;
    signal clicked
    /*width:320
    height:140

    property string name
    property string photo : "../../img/avatar.png"

    Rectangle {
        color:"green"
        anchors.fill:parent
    }

    Image {
        x:10
        y:10
        width:100
        height:120
        source: addressEntry.photo
    }

    Text {
        x:130
        y:10
        width: 190
        height:120
        text: addressEntry.name
    }*/

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
