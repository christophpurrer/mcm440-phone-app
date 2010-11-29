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
    qml/PhoneAppMain.qml \
    qml/dialer/DialerKey.qml \
    qml/dialer/DialerDisplay.qml \
    qml/dialer/DialerComponent.qml \
    qml/callhandling/CallhandlingComponent.qml \
    qml/home/HomeComponent.qml \
    qml/addressbook/AddressBookComponent.qml \
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
    qml/addressbook/AddressEntry.qml

RESOURCES += \
    main.qrc
