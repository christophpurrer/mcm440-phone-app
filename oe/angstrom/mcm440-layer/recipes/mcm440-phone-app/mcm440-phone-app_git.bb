DESCRIPTION = "MCM440-phone-app Application"
LICENSE = "GPL"
# Increase the version counter if this file get changed, after bitbake has built it already once successfully
<<<<<<< HEAD
PR = "r11"
=======
PR = "r5"
>>>>>>> 1356654845a11eb00b463c8ae9a7b32b06af2f3d


SRC_URI = "git://github.com/christophpurrer/mcm440-phone-app.git;protocol=http;tag=master"
# SRC_URI = "git:///home/feistling/workspace/mcm440-phone-app/;protocol=git;tag=master"
# SRC_URI= "file:///home/feistling/workspace/mcm440-phone-app/"

inherit qt4x11

# S >> locate the resources
# S = "${WORKDIR}/${P}"
S = "${WORKDIR}/git/src/mcm440-phone-app-mpp/"

# S = "/home/feistling/workspace/mcm440-phone-app/src/mcm440-phone-app-mpp"

# compile task is always the same so we do not define it here

# add example from the slides
do_install() {
	export INSTALL_ROOT=${D}
	make install
}


