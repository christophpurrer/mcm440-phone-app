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


# compile task is always the same so we do not define it here

# add example from the slides
do_install() {
	export INSTALL_ROOT=${D}
	make install
}

# change some configuration files in the rootfilesystem
mcm440_rootfs_postprocess() {
	curdir=$PWD
	cd ${IMAGE_ROOTFS}

	# create/overwrite network configuration
	echo "auto usb0" > ./etc/network/interfaces
	echo "iface usb0 inet static" >> ./etc/network/interfaces
	echo "address 192.168.0.202" >> ./etc/network/interfaces
	echo "netmask 255.255.255.0" >> ./etc/network/interfaces
	echo "network 192.168.0.0" >> ./etc/network/interfaces
	echo "gateway 192.168.0.200" >> ./etc/network/interfaces

	# activate the SSH dropbear daemon
	echo "DROPBEAR_KEYTYPES=\"rsa\"" >> ./etc/default/dropbear

	# change opk package management system feed urls
	rm -rf ./etc/opkg/*-feed.conf
	echo "src/gz all http://192.168.0.200/all" > ./etc/opkg/all-feed.conf
	echo "src/gz armv7a http://192.168.0.200/armv7a" > ./etc/opkg/arm7a-feed.conf
	echo "src/gz beagleboard http://192.168.0.200/beagleboard" > ./etc/opkg/beagleboard-feed.conf

	cd $curdir
}

# register the above command for execution
ROOTFS_POSTPROCESS_COMMAND += "mcm440_rootfs_postprocess"


