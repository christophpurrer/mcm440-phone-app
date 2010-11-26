require ~/angstrom/sources/openembbed/recipes/images/base-image.bb

IMAGE_INSTALL += "libqtdeclarative4 \
	mcm440-phone-app \
	hello \
	angstrom-version \
	"

export IMAGE_BASENAME = "mcm440-phone-app"



