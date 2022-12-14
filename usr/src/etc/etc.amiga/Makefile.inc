#	$NetBSD: Makefile.inc,v 1.28.2.1 2020/03/23 10:03:28 martin Exp $
#
#	etc.amiga/Makefile.inc -- amiga-specific etc Makefile targets
#

# If you change the list of distributed kernels, don't forget
# to update the release documentation in distrib/notes/common/contents

KERNEL_SETS=		GENERIC

EXTRA_KERNELS=		INSTALL WSCONS

INSTALLATION_DIRS+=	installation/miniroot	\
			installation/misc

snap_md_post:
	${MAKESUMS} -t ${RELEASEDIR}/${RELEASEMACHINEDIR}/installation/misc '*'
	rm -f		${RELEASEDIR}/${RELEASEMACHINEDIR}/installation/miniroot/miniroot.fs
	${TOOL_GZIP} -cd ${RELEASEDIR}/${RELEASEMACHINEDIR}/installation/miniroot/miniroot.fs.gz > \
			${RELEASEDIR}/${RELEASEMACHINEDIR}/installation/miniroot/miniroot.fs
	${MAKESUMS} -t ${RELEASEDIR}/${RELEASEMACHINEDIR}/installation/miniroot '*.fs*'
