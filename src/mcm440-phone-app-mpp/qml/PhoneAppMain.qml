import Qt 4.7
import "dialer"
import "home"
import "addressbook"

Rectangle {
    id:phoneAppMain
    width:320
    height:520

    property string showComponent : "home"

    // define all the UI components
    HomeComponent {
        id:home
        x:0
    }

    DialerComponent {
        id:dialer
        x:320
    }

    AddressBookComponent {
        id:addressBook
        x:640
    }

    // buttons to control the main application
    Text {
        x: 20
        y: 490
        color: "blue"
        text: "Home"

        MouseArea {
            anchors.fill: parent
            onClicked: {
                phoneAppMain.showComponent = "home"
            }
        }
    }

    Text {
        x: 80
        y: 490
        color: "red"
        text: "Call"

        MouseArea {
            anchors.fill: parent
            onClicked: {
                phoneAppMain.showComponent = "dialer"
            }
        }        
    }

    Text {
        x: 140
        y: 490
        color: "green"
        text: "AddressBook"

        MouseArea {
            anchors.fill: parent
            onClicked: {
                phoneAppMain.showComponent = "addressBook"
            }
        }
    }

    // states
    states: [
        State {
            name: "homeState";
            when: phoneAppMain.showComponent == "home";
            PropertyChanges {
                target: home; x : 0
            }
            PropertyChanges {
                target: dialer; x : 320
            }
            PropertyChanges {
                target: addressBook; x : 640
            }
        },
        State {
            name: "dialerState";
            when: phoneAppMain.showComponent == "dialer";
            PropertyChanges {
                target: home; x : -320
            }
            PropertyChanges {
                target: dialer; x : 0
            }
            PropertyChanges {
                target: addressBook; x : 320
            }
        },
        State {
            name: "addressBookState";
            when: phoneAppMain.showComponent == "addressBook";
            PropertyChanges {
                target: home; x : -640
            }
            PropertyChanges {
                target: dialer; x : -320
            }
            PropertyChanges {
                target: addressBook; x : 0
            }
        }
    ]

    // transitions
    transitions: [
        Transition {
            to: "homeState"; reversible: true
            NumberAnimation { properties: "x"; duration: 500 }
        },

        Transition {
            to: "dialerState"; reversible: true
            NumberAnimation { properties: "x"; duration: 500 }
        },

        Transition {
            to: "addressBookState"; reversible: true
            NumberAnimation { properties: "x"; duration: 500 }
        }
    ]
}
