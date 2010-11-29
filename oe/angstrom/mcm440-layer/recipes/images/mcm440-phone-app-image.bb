#mcm440-phone-app-image
#gives you a an awesome beagleboard image with fancy functionality
<<<<<<< HEAD
PR = "r6"
=======
>>>>>>> 1356654845a11eb00b463c8ae9a7b32b06af2f3d

require recipes/images/base-image.bb

XSERVER = "xserver-kdrive-fbdev"

IMAGE_INSTALL += " \
<<<<<<< HEAD
	libqtdeclarative4 \
	${XSERVER} \
	mcm440-phone-app \
	hello \
	"
# mcm440-phone-app \	
=======
	${XSERVER} \	
	libqtdeclarative4 \
	hello \		
	"

# mcm440-phone-app \
>>>>>>> 1356654845a11eb00b463c8ae9a7b32b06af2f3d

export IMAGE_BASENAME = "mcm440-phone-app-mpp-image"

#inherit image

# change some configuration files in the rootfilesystem
<<<<<<< HEAD
mcm440-phone-app-image_rootfs_postprocess() {
=======
mcm440-phone-app_rootfs_postprocess() {
>>>>>>> 1356654845a11eb00b463c8ae9a7b32b06af2f3d
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

<<<<<<< HEAD
=======
	# change opk package management system feed urls
>>>>>>> 1356654845a11eb00b463c8ae9a7b32b06af2f3d
	rm -rf ./etc/opkg/*-feed.conf
	echo "src/gz all http://192.168.0.200/all" >                 ./etc/opkg/all-feed.conf
	echo "src/gz armv7a http://192.168.0.200/armv7a" >           ./etc/opkg/arm7a-feed.conf
	echo "src/gz beagleboard http://192.168.0.200/beagleboard" > ./etc/opkg/beagleboard-feed.conf

	cd $curdir
}

# register the above command for execution
<<<<<<< HEAD
# ROOTFS_POSTPROCESS_COMMAND += "mcm440-phone-app-image_rootfs_postprocess"
=======
ROOTFS_POSTPROCESS_COMMAND += "mcm440-phone-app_rootfs_postprocess"
>>>>>>> 1356654845a11eb00b463c8ae9a7b32b06af2f3d
