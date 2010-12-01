#mcm440-phone-app-image
#gives you a an awesome beagleboard image with fancy functionality
PR = "r9"

require recipes/images/base-image.bb

XSERVER = "xserver-kdrive-fbdev"

IMAGE_INSTALL += " \
	libqtdeclarative4 \
	${XSERVER} \
	mcm440-phone-app \
	hello \
	"
# mcm440-phone-app \	

export IMAGE_BASENAME = "mcm440-phone-app-image"

#inherit image

# change some configuration files in the rootfilesystem
mcm440-phone-app-image_rootfs_postprocess() {
	curdir=$PWD
	cd ${IMAGE_ROOTFS}

	# create/overwrite network configuration
	echo "auto usb0" > ./etc/network/interfaces
	echo "iface usb0 inet static" >> ./etc/network/interfaces
	echo "address 192.168.0.202" >>  ./etc/network/interfaces
	echo "netmask 255.255.255.0" >>  ./etc/network/interfaces
	echo "network 192.168.0.0" >>    ./etc/network/interfaces
	echo "gateway 192.168.0.200" >>  ./etc/network/interfaces

	# activate the SSH dropbear daemon
	echo "DROPBEAR_KEYTYPES=\"rsa\"" >> ./etc/default/dropbear

	# change opk package management system feed urls
	rm -rf ./etc/opkg/*-feed.conf
	echo "src/gz all http://192.168.0.200/all" >                 ./etc/opkg/all-feed.conf
	echo "src/gz armv7a http://192.168.0.200/armv7a" >           ./etc/opkg/arm7a-feed.conf
	echo "src/gz beagleboard http://192.168.0.200/beagleboard" > ./etc/opkg/beagleboard-feed.conf

	cd $curdir
}

# register the above command for execution
# ROOTFS_POSTPROCESS_COMMAND += "mcm440-phone-app-image_rootfs_postprocess"
