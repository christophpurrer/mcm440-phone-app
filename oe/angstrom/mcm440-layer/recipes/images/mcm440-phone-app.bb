require recipes/images/base-image.bb

IMAGE_INSTALL += "libqtdeclarative4 \
	hello \
	mcm440-phone-app \
	"

export IMAGE_BASENAME = "mcm440-phone-app-image"



