import Qt 4.7
import "../"
import "../home/"

/**
* AddressBookComponent.qml shows the address book of the application
**/
Rectangle {
    id: addressbook
    width: 320
    height: 480

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
        number: "06641764140"
        onClicked: {
            if(currentImage == image_front) {
                currentImage = image_back;
            } else {
                currentImage = image_front;
                call.call_type = "outgoing"
                call.number = contact_bob.number;
                phoneAppMain.showComponent = "call";
                OfonoContext.dialNumber(contact_bob.number);
            }
        }
    }

    AddressEntry {
        id: contact_alice
        x: 160
        y: 15
        image_front: "../../img/contact_alice1.png"
        image_back: "../../img/contact_alice2.png"
        number:"06767708182"
        onClicked: {
            if(currentImage == image_front) {
                currentImage = image_back;
            } else {
                currentImage = image_front;
                call.call_type = "outgoing"
                call.number = contact_alice.number;
                phoneAppMain.showComponent = "call";
                OfonoContext.dialNumber(contact_alice.number);
            }
        }
    }

    AddressEntry {
        id: contact_johndoe
        x: 15
        y: 150
        image_front: "../../img/contact_johndoe1.png"
        image_back: "../../img/contact_johndoe2.png"
        number:"06605615859"
        onClicked: {
            if(currentImage == image_front) {
                currentImage = image_back;
            } else {
                currentImage = image_front;
                call.call_type = "outgoing"
                call.number = contact_johndoe.number;
                phoneAppMain.showComponent = "call";
                OfonoContext.dialNumber(contact_johndoe.number);
            }
        }
    }

    //new contact
    HomeButton {
        id: contact_new
        x: 155
        y: 148
        backgroundimage: "../../img/contact_new.png"
        enabled: false
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
