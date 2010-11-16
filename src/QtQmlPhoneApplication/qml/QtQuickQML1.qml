import Qt 4.7
import "../js/Helper.js" as Helper

Rectangle {
    width: 400
    height: 200


    ButtonUI {
        x: 66
        text: "Btn"
        iconSource: "../images/Save.png"
        onClicked: {
            console.log("Button clicked");
            myTextField.text = "new text" + Helper.increaseCounter() + OfonoContext.setPowerOn()
        }
    }

    Text {
        id: myTextField
        x: 66
        y: 93
        text: "Hello World"
    }

    Text {
        x: 166
        y: 93
        text: "Hello Christoph" + backgroundColor
    }

//    AppModules.AppIcon {
//        iconSource: "images/key_100.png"
//        id: btnPowerOn
//        text: "On"
//        width: parent.width / 4
//        anchors.left: btnHome.right
//        height: parent.height - 2
//        onClicked: { OfonoContext.setPowerOn() }
//    }
}
