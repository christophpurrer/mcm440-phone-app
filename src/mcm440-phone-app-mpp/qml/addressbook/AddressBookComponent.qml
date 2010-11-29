import Qt 4.7

/**
* AddressBookComponent.qml shows the address book of the application
**/
Rectangle {
    id:home
    width:320
    height:480

    Rectangle {
        color:"red"
        anchors.fill:parent

        Column {
            spacing:6
            Row {
                 AddressEntry{
                     name:"Max Mustermann"
                 }

                 AddressEntry{
                     name:"Maxi Musterfrau"
                 }

                 AddressEntry{
                     name:"Herbert Prohaska"
                 }
            }
        }
    }
}
