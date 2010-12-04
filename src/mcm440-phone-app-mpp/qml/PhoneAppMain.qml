import Qt 4.7
import "callhandling"
import "dialer"
import "home"
import "addressbook"

Rectangle {
    id:phoneAppMain
    width:320
    height:480

    property string showComponent : "home"

    // buttons to control the main application
    HomeComponent {
        id:home
        opacity: 1
    }

    DialerComponent {
        id:dialer
        opacity: 0
    }

    AddressBookComponent {
        id:addressBook
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
        }
    ]

    // transitions
    transitions: [
        Transition {
            to: "homeState"; reversible: true
            NumberAnimation { properties: "opacity"; duration: 500 }
        },

        Transition {
            to: "dialerState"; reversible: true
            NumberAnimation { properties: "opacity"; duration: 500 }
        },

        Transition {
            to: "addressBookState"; reversible: true
            NumberAnimation { properties: "opacity"; duration: 500 }
        }
    ]

    Connections {
        target: OfonoContext
        onIncomingCall: {
            console.log("QML: Incoming Call: " + id);
            phoneAppMain.showAcceptCallDialog(true);
        }
    }


    function showAcceptCallDialog(show) {
        if( show == true ) {
            callingHandling.visible=true;
//            buttonAddressBook.enabled=false;
//            buttonCall.enabled=false;
//            buttonHome.enabled=false;
        }
        else {
            callingHandling.opacity=0;
//            buttonAddressBook.visible=false;
//            buttonCall.enabled=true;
//            buttonHome.enabled=true;
        }
    }

    CallhandlingComponent {
        id:callingHandling
        visible:false
    }
}
