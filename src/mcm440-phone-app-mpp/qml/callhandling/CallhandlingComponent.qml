import Qt 4.7
import "../dialer"

/**
* CallhandlingComponent.qml shows the address book of the application
**/
Rectangle {
    id:callhandling
    width:320
    height:480

    property string text : "Incoming Call"
    property bool isCallAccepted : false

    Rectangle {
        color:"red"
        anchors.fill:parent

        Text {
            text:callhandling.text
            width: 200
            y: 120
            x: 60
            color:"white"
        }

        //call button
        DialerKey {
            id: key_call
            x: 220
            y: 300
            icon: "../../img/dialerkey_call.png"
            backgroundimage: "../../img/dialerkey_red.png"
            onClicked: {
                OfonoContext.hangupAll();
                callhandling.visible=false;
            }
        }
    }
}
