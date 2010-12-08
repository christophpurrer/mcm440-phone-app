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
        onClicked: {
            if(currentImage == image_front) {
                currentImage = image_back;
            } else {
                currentImage = image_front;
                call.call_type = "outgoing"
                call.number = "06641764140";
                phoneAppMain.showComponent = "call";
                OfonoContext.dialNumber("06641764140");
            }
        }
    }

    AddressEntry {
        id: contact_alice
        x: 160
        y: 15
        image_front: "../../img/contact_alice1.png"
        image_back: "../../img/contact_alice2.png"
        onClicked: {
            if(currentImage == image_front) {
                currentImage = image_back;
            } else {
                currentImage = image_front;
                call.call_type = "outgoing"
                call.number = "06767708182";
                phoneAppMain.showComponent = "call";
                OfonoContext.dialNumber("06767708182");
            }
        }
    }

    AddressEntry {
        id: contact_johndoe
        x: 15
        y: 150
        image_front: "../../img/contact_johndoe1.png"
        image_back: "../../img/contact_johndoe2.png"
        onClicked: {
            if(currentImage == image_front) {
                currentImage = image_back;
            } else {
                currentImage = image_front;
                call.call_type = "outgoing"
                call.number = "06605615859";
                phoneAppMain.showComponent = "call";
                OfonoContext.dialNumber("06605615859");
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
