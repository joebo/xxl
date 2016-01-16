BUILDH="yes"
CC="gcc"
NODE="node" # often 'nodejs'
ARCH="-m64"
LIBS="-pthread"

if [ -x /bin/x86_64-w64-mingw32-gcc-4.9.2.exe ]; then
	echo using mingw64
	CC="/bin/x86_64-w64-mingw32-gcc-4.9.2.exe"
fi

if [ -x /bin/x86_64-pc-cygwin-gcc.exe ]; then
	echo using cygwin
	CC="/bin/x86_64-pc-cygwin-gcc.exe"
fi

if [ "x$BUILDH" = "xyes" ]; then
	$NODE accessors.js > accessors.h && \
	$NODE vary.js > vary.h && \
	$NODE cast.js > cast.h && \
	$NODE types.js > types.h && \
	$NODE repr.js > repr.h 
fi

$CC -DTHREAD -g \
	-Wall -Wno-format-extra-args -Wno-unused-value -Wno-unused-variable -Wno-unused-but-set-variable \
	$LIBS $ARCH \
	xxl.c -o ./xxl 2>&1 \
	&& ./xxl


