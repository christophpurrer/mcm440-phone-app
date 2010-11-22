import Qt 4.7
import "../"

/**
* AddressBookComponent.qml shows the address book of the application
**/
Rectangle {
    id: addressbook
    width: 320
    height: 480

    /*Rectangle {
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
    }*/

    //background image
    Image {
        id: background
        source: "../../img/addressbookBG.png"
    }

    AddressEntry {
        id: contact_bob
        x: 15
        y: 15
        image_front: "../../img/contact_bob1.png"
        image_back: "../../img/contact_bob2.png"
        onClicked: {currentImage == image_front ? currentImage = image_back : currentImage = image_front}
    }

    AddressEntry {
        id: contact_alice
        x: 160
        y: 15
        image_front: "../../img/contact_alice1.png"
        image_back: "../../img/contact_alice2.png"
        onClicked: {currentImage == image_front ? currentImage = image_back : currentImage = image_front}
    }

    AddressEntry {
        id: contact_johndoe
        x: 15
        y: 160
        image_front: "../../img/contact_johndoe1.png"
        image_back: "../../img/contact_johndoe2.png"
        onClicked: {currentImage == image_front ? currentImage = image_back : currentImage = image_front}
    }

    //back button
    BackButton {
        x: 0
        y: 450
        width: 320
        height: 20
        onClicked: {
            phoneAppMain.showComponent = "home"
        }
    }
}
