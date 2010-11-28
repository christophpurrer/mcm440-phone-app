DESCRIPTION = "MCM440-phone-app Application"
LICENSE = "GPL"
PR = "r2"

inherit qmake2

SRC_URI = "git://github.com/christophpurrer/mcm440-phone-app.git;protocol=http"

S = "${WORKDIR}/${P}"

## add example from the slides

