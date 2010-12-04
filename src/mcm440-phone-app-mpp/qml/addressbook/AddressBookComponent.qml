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
        onClicked: {
            if(currentImage == image_front) {
                currentImage = image_back;
            } else {
                currentImage = image_front;
                phoneAppMain.showComponent = "dialer";
                dialer.phonenumber = "06641764140";
                OfonoContext.dialNumber(dialer.phonenumber);
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
                phoneAppMain.showComponent = "dialer";
                dialer.phonenumber = "06767708182";
                OfonoContext.dialNumber(dialer.phonenumber);
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
                phoneAppMain.showComponent = "dialer";
                dialer.phonenumber = "06605615859";
                OfonoContext.dialNumber(dialer.phonenumber);
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
