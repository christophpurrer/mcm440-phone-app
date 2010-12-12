import Qt 4.7
import "dialer"
import "home"
import "addressbook"
import "callhandling"

Rectangle {
    id: phoneAppMain
    width: 320
    height: 480

    property string showComponent : "home"

    // buttons to control the main application
    HomeComponent {
        id:home
        opacity: 0
    }

    DialerComponent {
        id:dialer
        opacity: 0
    }

    AddressBookComponent {
        id:addressBook
        opacity: 0
    }

    CallHandlingComponent {
        id: call
        opacity: 0
    }

    // states
    states: [
        State {
            name: "homeState";
            when: phoneAppMain.showComponent == "home";
            PropertyChanges {
                target: home; opacity : 1
            }
            PropertyChanges {
                target: dialer; opacity : 0
            }
            PropertyChanges {
                target: addressBook; opacity : 0
            }
            PropertyChanges {
                target: call; opacity: 0
            }
        },
        State {
            name: "dialerState";
            when: phoneAppMain.showComponent == "dialer";
            PropertyChanges {
                target: home; opacity : 0
            }
            PropertyChanges {
                target: dialer; opacity : 1
            }
            PropertyChanges {
                target: addressBook; opacity : 0
            }
            PropertyChanges {
                target: call; opacity: 0
            }
        },
        State {
            name: "addressBookState";
            when: phoneAppMain.showComponent == "addressBook";
            PropertyChanges {
                target: home; opacity : 0
            }
            PropertyChanges {
                target: dialer; opacity : 0
            }
            PropertyChanges {
                target: addressBook; opacity : 1
            }
            PropertyChanges {
                target: call; opacity: 0
            }
        },
        State {
            name: "callState";
            when: phoneAppMain.showComponent == "call";
            PropertyChanges {
                target: home; opacity: 0
            }
            PropertyChanges {
                target: dialer; opacity: 0
            }
            PropertyChanges {
                target: addressBook; opacity: 0
            }
            PropertyChanges {
                target: call; opacity: 1
            }
        }
    ]

    // transitions
    transitions: [
        Transition {
            to: "homeState"; reversible: true
            NumberAnimation { properties: "opacity"; duration: 400 }
        },
        Transition {
            to: "dialerState"; reversible: true
            NumberAnimation { properties: "opacity"; duration: 400 }
        },
        Transition {
            to: "addressBookState"; reversible: true
            NumberAnimation { properties: "opacity"; duration: 400 }
        },
        Transition {
            to: "callState"; reversible: true
            NumberAnimation { properties: "opacity"; duration: 400 }
        }
    ]


    Connections {
        target: OfonoContext
        onInComingCallChanged: {
            console.log("QML: onIncomingCallChanged Call: " + number);

            // setUp the CallComponent and switch the state
            call.call_type = "incoming";
            call.number = number;
            phoneAppMain.showComponent = "call";

        }
    }
}
