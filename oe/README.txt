1.) 
Use the following folder structure
/home/<USER_NAME>/angstrom
/home/<USER_NAME>/angstrom/build
/home/<USER_NAME>/angstrom/oe-downloads
/home/<USER_NAME>/angstrom/sources
/home/<USER_NAME>/angstrom/...


2.) Create a soft link in your <USER_DIR>/angstrom directory by invoking:

$ cd
$ cp angstrom
$ ln -s /home/<USER_NAME>/workspace/mcm440-phone-app/oe/angstrom/mcm440-layer/ home/<USER_NAME>/angstrom/mcm440-layer


3.) Copy the local.conf and the bblayers.conf files from /home/<USER_NAME>/workspace/mcm440-phone-app/oe/angstrom/build/config/
	to /home/<USER_NAME>/angstrom/build/config

4.) Change the parameter ANGSTROM_HOME in /home/<USER_NAME>/angstrom/build/config/bblayers.conf to fit to your system



