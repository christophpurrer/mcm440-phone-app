import Qt 4.7

/**
* Dialer.qml is the main application / qml file for the phone application and
 * shows the number pad screen / state on default
 *
**/
Rectangle {
    // properties
    property int col1origin: 5;
    property int col2origin: 110;
    property int col3origin: 215;
    property int row1origin: 82;
    property int row2origin: 162;
    property int row3origin: 242;
    property int row4origin: 322;
    property int row5origin: 482;

    width: 320
    height: 580

    // DialerDisplay shows the typed in phone number
    DialerDisplay {
        id: display
        x: col1origin
        y: 5
    }

    // create the number pad buttons (1-9,0, #,*)
    DialerKey {
        id: key1
        x: col1origin
        y: row1origin
        text: "1"
        onClicked: {display.text += text;}
    }

    DialerKey {
        id: key2
        x: col2origin
        y: row1origin
        text: "2"
        onClicked: {display.text += text;}
    }

    DialerKey {
        id: key3
        x: col3origin
        y: row1origin
        text: "3"
        onClicked: {display.text += text;}
    }

    DialerKey {
        id: key4
        x: col1origin
        y: row2origin
        text: "4"
        onClicked: {display.text += text;}
    }

    DialerKey {
        id: key5
        x: col2origin
        y: row2origin
        text: "5"
        onClicked: {display.text += text;}
    }

    DialerKey {
        id: key6
        x: col3origin
        y: row2origin
        text: "6"
        onClicked: {display.text += text;}
    }

    DialerKey {
        id: key7
        x: col1origin
        y: row3origin
        text: "7"
        onClicked: {display.text += text;}
    }

    DialerKey {
        id: key8
        x: col2origin
        y: row3origin
        text: "8"
        onClicked: {display.text += text;}
    }

    DialerKey {
        id: key9
        x: col3origin
        y: row3origin
        text: "9"
        onClicked: {display.text += text;}
    }

    DialerKey {
        id: key_star
        x: col1origin
        y: row4origin
        text: "*"
        onClicked: {display.text += text;}
    }

    DialerKey {
        id: key0
        x: col2origin
        y: row4origin
        text: "0"
        onClicked: {display.text += text;}
    }

    DialerKey {
        id: key_hash
        x: col3origin
        y: row4origin
        text: "#"
        onClicked: { display.text += text;}
    }

    // buttons
    DialerButton {
        id: callbutton
        x: col1origin
        y: 402
        onClicked: {
            // OfonoContext.test();
            OfonoContext.callNumber(display.text);
        }
    }

    // on
    DialerKey {
        id: powerOnButton
        x: col1origin
        y: row5origin
        text: "On"
        onClicked: {
            OfonoContext.powerModemOn();
            modemStatus.text = OfonoContext.getModemStatus();
        }
    }

    //
    DialerKey {
        id: modemStatus
        x: col2origin
        y: row5origin
        text: "..."
        onClicked: {
            modemStatus.text = OfonoContext.getModemStatus();
        }
    }


    // off
    DialerKey {
        id: powerOffButton
        x: col3origin
        y: row5origin
        text: "Off"
        onClicked: {
            OfonoContext.powerModemOff();
            modemStatus.text = OfonoContext.getModemStatus();
        }
    }
}
