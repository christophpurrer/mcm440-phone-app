require ${ANGSTROM_HOME}/sources/openembedded/recipes/images/base-image.bb

IMAGE_INSTALL = "libqtdeclarative4 \
	hello \
	mcm440-phone-app \
	angstrom-version \
	"

export IMAGE_BASENAME = "mcm440-phone-app"



