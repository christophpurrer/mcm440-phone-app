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
    qml/DialerKey.qml \
    qml/DialerDisplay.qml \
    qml/DialerButton.qml \
    qml/Dialer.qml \
    img/dialerkey_down.png \
    README.txt \
    js/dummy.js \
    img/dialerBG.png \
    img/dialerkey_clear.png \
    img/dialerkey_call.png \
    img/dialerkey_red.png \
    img/dialerkey_green.png \
    Questions.txt
