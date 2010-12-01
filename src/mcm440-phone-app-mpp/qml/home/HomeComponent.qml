import Qt 4.7

/**
* HomeComponent.qml shows the home screen of the application
**/
Rectangle {
    id:home
    width:320
    height:480

    Image {
        id: background
        source: "../../img/homeBG.png"
    }

    //homebutton to start DialerComponent
    HomeButton {
        x: 5
        y: 10
        id: homebutton_phone
        backgroundimage: "../../img/homebutton_phone.png"
        enabled: true
        onClicked: {
            phoneAppMain.showComponent = "dialer"
        }
    }

    HomeButton {
        x: 5
        y: 160
        id: homebutton_sms
        backgroundimage:  "../../img/homebutton_sms.png"
        enabled: false
    }

    HomeButton {
        x: 150
        y: 160
        id: homebutton_calendar
        backgroundimage: "../../img/homebutton_calendar.png"
        enabled: false
    }

    //homebutton to start AddressBookComponent
    HomeButton {
        x: 5
        y: 305
        id: homebutton_contacts
        backgroundimage:  "../../img/homebutton_contacts.png"
        enabled: true
        onClicked: {
            phoneAppMain.showComponent = "addressBook"
        }
    }
}
