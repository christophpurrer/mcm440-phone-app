import Qt 4.7
import "../home/"

/**
  * CallScreen is shown on outgoing/incoming calls and contains controls for answering/ending a call
  */
Item {
    id: call
    property string call_type: "outgoing"
    property int offsetY1: 100
    property int offsetY2: 135
    property string number: "[insert number]"
    width: 320
    height: 480

    //background image
    Image {
        id: background
        source: "../../img/callBG.png"
    }

    //"calling" text
    Text {
        id: callingtext
        width: 320
        y: offsetY1
        text: "CALLING"
        color: "#ffffff"
        font.pixelSize: 36
        font.bold: true
        horizontalAlignment: Text.AlignHCenter
    }

    //phonenumber text
    Text {
        id: numbertext
        width: 320
        y: offsetY2
        text: number
        font.pixelSize: 36
        font.bold: true
        horizontalAlignment: Text.AlignHCenter
    }

    //outgoing call: hang up
    HomeButton {
        id: call_hangup
        x: 15
        y: 260
        opacity: 1
        backgroundimage: "../../img/call_hangup.png"
        enabled: true
        onClicked: {
            OfonoContext.hangupAll();
            phoneAppMain.showComponent = "home"
        }
    }

    //incoming call: accept
    HomeButton {
        id: call_accept
        x: 15
        y: 260
        opacity: 0
        backgroundimage: "../../img/call_accept.png"
        enabled: true
        onClicked: {
            //accept incoming call
            call_type = "incomingActive"
        }
    }

    //incoming call: deny
    HomeButton {
        id: call_deny
        x: 160
        y: 260
        opacity: 0
        backgroundimage: "../../img/call_deny.png"
        enabled: true
        onClicked: {
            //refuse incoming call
            phoneAppMain.showComponent = "home"
        }
    }

    // states
    states: [
        State {
            name: "outgoingState";
            when: call.call_type == "outgoing";
            PropertyChanges {
                target: call_hangup; opacity: 1
            }
            PropertyChanges {
                target: call_accept; opacity: 0
            }
            PropertyChanges {
                target: call_deny; opacity: 0
            }
            PropertyChanges {
                target: callingtext; y: offsetY1
            }
            PropertyChanges {
                target: numbertext; y: offsetY2
            }
        },
        State {
            name: "incomingState";
            when: call.call_type == "incoming";
            PropertyChanges {
                target: call_hangup; opacity: 0
            }
            PropertyChanges {
                target: call_accept; opacity: 1
            }
            PropertyChanges {
                target: call_deny; opacity: 1
            }
            PropertyChanges {
                target: callingtext; y: offsetY2
            }
            PropertyChanges {
                target: numbertext; y: offsetY1
            }
        },
        State {
            name: "incomingActiveState";
            when: call.call_type == "incomingActive";
            PropertyChanges {
                target: call_hangup; opacity: 1
            }
            PropertyChanges {
                target: call_accept; opacity: 0
            }
            PropertyChanges {
                target: call_deny; opacity: 0
            }
            PropertyChanges {
                target: callingtext; y: offsetY2
            }
            PropertyChanges {
                target: numbertext; y: offsetY1
            }
        }
    ]
}
