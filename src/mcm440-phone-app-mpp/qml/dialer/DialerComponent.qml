import Qt 4.7
import "../"

/**
* DialerComponent.qml is the main part of the application / qml file for the phone application and
 * shows the number pad screen / state on default
 *
**/
Rectangle {
    id: dialer
    // properties
    property int col1origin: 0;
    property int col2origin: 107;
    property int col3origin: 214;
    property int row1origin: 72;
    property int row2origin: 142;
    property int row3origin: 212;
    property int row4origin: 282;
    property int row5origin: 352;
    property string phonenumber

    width: 320
    height: 480

    //background image
    Image {
        id: background
        source: "../../img/dialerBG.png"
    }

    // DialerDisplay shows the typed in phone number
    DialerDisplay {
        id: display
        x: col1origin
        y: 5
        text: phonenumber
    }

    // create the number pad buttons (1-9,0, #,*)
    DialerKey {
        id: key1
        x: col1origin
        y: row1origin
        text: "1"
        onClicked: {phonenumber += text;}
    }

    DialerKey {
        id: key2
        x: col2origin
        y: row1origin
        text: "2"
        onClicked: {phonenumber += text;}
    }

    DialerKey {
        id: key3
        x: col3origin
        y: row1origin
        text: "3"
        onClicked: {phonenumber += text;}
    }

    DialerKey {
        id: key4
        x: col1origin
        y: row2origin
        text: "4"
        onClicked: {phonenumber += text;}
    }

    DialerKey {
        id: key5
        x: col2origin
        y: row2origin
        text: "5"
        onClicked: {phonenumber += text;}
    }

    DialerKey {
        id: key6
        x: col3origin
        y: row2origin
        text: "6"
        onClicked: {phonenumber += text;}
    }

    DialerKey {
        id: key7
        x: col1origin
        y: row3origin
        text: "7"
        onClicked: {phonenumber += text;}
    }

    DialerKey {
        id: key8
        x: col2origin
        y: row3origin
        text: "8"
        onClicked: {phonenumber += text;}
    }

    DialerKey {
        id: key9
        x: col3origin
        y: row3origin
        text: "9"
        onClicked: {phonenumber += text;}
    }

    DialerKey {
        id: key_star
        x: col1origin
        y: row4origin
        text: "*"
        onClicked: {phonenumber += text;}
    }

    DialerKey {
        id: key0
        x: col2origin
        y: row4origin
        text: "0"
        onClicked: {phonenumber += text;}
    }

    DialerKey {
        id: key_hash
        x: col3origin
        y: row4origin
        text: "#"
        onClicked: {phonenumber += text;}
    }

    //power toggle button
    DialerKey {
        id: key_power
        x: col1origin
        y: row5origin
        text: "ON"
        fontsize: 30
        Connections {
            target:OfonoContext
            onPowerOn: {
                key_power.text = "OFF";
            }
            onPowerOff: {
                key_power.text = "ON";
            }
        }
        onClicked: {
            if(key_power.text == "OFF") {
                console.log("QML: powerModemOff: ");
                OfonoContext.powerModemOff();
            } else {
                console.log("QML: powerModemOn: ");
                OfonoContext.powerModemOn();
            }
        }
    }

    //call button
    DialerKey {
        id: key_call
        x: col2origin
        y: row5origin
        icon: "../../img/dialerkey_call.png"
        backgroundimage: "../../img/dialerkey_green.png"
        onClicked: {
            if(phonenumber != "") {
                call.call_type = "outgoing";
                call.number = phonenumber;
                phoneAppMain.showComponent = "call";
                OfonoContext.dialNumber(phonenumber);
            }
        }
    }

    //clear button
    DialerKey {
        id: key_clear
        x: col3origin
        y: row5origin
        icon: "../../img/dialerkey_clear.png"
        onClicked: { phonenumber = ""; }
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

    Connections {
        target: OfonoContext
        onOutgoingCall: {
            console.log("QML: OutgoingCall Call: " + id);
            // dialer.isCalling = true;
            //key_call.backgroundimage = "../../img/dialerkey_red.png";
        }
        onEndCall: {
            console.log("QML: EndCall Call: " + id);
            //dialer.isCalling = true;
            phonenumber ="";
            //key_call.backgroundimage = "../../img/dialerkey_green.png";
        }
    }
}
