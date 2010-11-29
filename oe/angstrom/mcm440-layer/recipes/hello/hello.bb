DESCRIPTION = "Minimal statically compiled Hello world!"
LICENSE = "GPL"
PR = "r2"
S = "${WORKDIR}/${P}"

do_fetch () {
	mkdir -p ${WORKDIR}/${P}
	cd ${WORKDIR}/${P}
	printf "#include <stdio.h>\n int main(void)\n{\n\t printf(\"Hello world!\\\n\");\twhile(1);\n\t return 0;\n}\n" > helloworld.c
}

do_compile () {
	${CC} ${CFLAGS} -c -o helloworld.o helloworld.c
	${CC} ${LDFLAGS} -o helloworld helloworld.o -static
}

do_install () {
	install -d ${D}${bindir}
	install -m 0755 helloworld ${D}${bindir}/
}

