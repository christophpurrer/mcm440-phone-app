QT += dbus declarative

SOURCES += \
    srcgen/OfonoModem.cpp\
    srcgen/OfonoSimManager.cpp\
    srcgen/OfonoVoiceCallManager.cpp\
    src/gsm.cpp \
    main.cpp


HEADERS += \
    srcgen/OfonoModem.h\
    srcgen/OfonoSimManager.h\
    srcgen/OfonoVoiceCallManager.h\
    src/gsm.h

OTHER_FILES += \
    ## QML
    qml/addressbook/AddressBookComponent.qml \
    qml/addressbook/AddressEntry.qml \
    qml/callhandling/CallhandlingComponent.qml \
    qml/dialer/DialerKey.qml \
    qml/dialer/DialerDisplay.qml \
    qml/dialer/DialerComponent.qml \
    qml/home/HomeComponent.qml \
    qml/home/HomeButton.qml \
    qml/PhoneAppMain.qml \
    ## IMG
    img/dialerBG.png \
    img/dialerkey_call.png \
    img/dialerkey_clear.png \
    img/dialerkey_down.png \
    img/dialerkey_green.png \
    img/dialerkey_red.png \
    ## JS
    js/dummy.js \
    ## TXT
    txt/README.txt \
    txt/Questions.txt \
    txt/TODOS.txt \
    txt/TODOS_DONE.txt \
    img/homebutton_sms.png \
    img/homebutton_phone.png \
    img/homebutton_contacts.png \
    img/homebutton_calendar.png \
    img/homeBG.png \
    img/contact_johndoe2.png \
    img/contact_johndoe1.png \
    img/contact_bob2.png \
    img/contact_bob1.png \
    img/contact_alice2.png \
    img/contact_alice1.png \
    img/avatar.png \
    img/addressbookBG.png


RESOURCES += \
    main.qrc
