import Qt 4.7

/**
* AddressBookEntry.qml shows a single address entry
**/
Item {
    id:addressEntry
    width:320
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
    }
}
