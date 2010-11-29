DESCRIPTION = "MCM440-phone-app Application"
LICENSE = "GPL"
# Increase the version counter if this file get changed, after bitbake has built it already once successfully
PR = "r4"

# inherit qmake2

SRC_URI = "git://github.com/christophpurrer/mcm440-phone-app.git;protocol=git;tag=master"
# SRC_URI = "git:///home/feistling/workspace/mcm440-phone-app/;protocol=git;tag=master"
# SRC_URI= "file:///home/feistling/workspace/mcm440-phone-app/"

inherit qt4x11

 
# S >> locate the resources
# S = "${WORKDIR}/${P}"
S = "${WORKDIR}/git/src/mcm440-phone-app-mpp"


# compile task is always the same

# add example from the slides
do_install() {
	export INSTALL_ROOT=${D}
	make install
}
