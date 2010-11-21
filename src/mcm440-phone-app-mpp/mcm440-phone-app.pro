QT += declarative

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
    img/dialerkey_up.png \
    img/dialerkey_down.png \
    img/dialer_display.png \
    img/dialer_call.png \
    README.txt
