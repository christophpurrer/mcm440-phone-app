1.) 
Use the following folder structure
/home/USER_NAME/angstrom
/home/USER_NAME/angstrom/build
/home/USER_NAME/angstrom/oe-downloads
/home/USER_NAME/angstrom/sources
/home/USER_NAME/angstrom/...


2.) Create a soft link to your USER_DIR/angstrom directory by invoking:

$ cd
$ cp angstrom
$ ln -s /home/USER_NAME/workspace/mcm440-phone-app/oe/angstrom/mcm440-layer/ mcm440-layer


3.) Copy /home/USER_NAME/workspace/mcm440-phone-app/oe/angstrom/build/config/bblayers.conf
	to /home/USER_NAME/angstrom/build/config



