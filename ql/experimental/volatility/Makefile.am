
AM_CPPFLAGS = -I${top_srcdir} -I${top_builddir}

this_includedir=${includedir}/${subdir}
this_include_HEADERS = \
    all.hpp \
    abcdatmvolcurve.hpp \
    blackatmvolcurve.hpp \
    blackvolsurface.hpp \
    equityfxvolsurface.hpp \
    extendedblackvariancecurve.hpp \
    extendedblackvariancesurface.hpp \
    interestratevolsurface.hpp \
    noarbsabr.hpp \
    noarbsabrinterpolatedsmilesection.hpp \
    noarbsabrinterpolation.hpp \
    noarbsabrsmilesection.hpp \
    sabrvolsurface.hpp \
    sabrvoltermstructure.hpp \
    sviinterpolatedsmilesection.hpp \
    sviinterpolation.hpp \
    svismilesection.hpp \
    swaptionvolcube1a.hpp \
    volcube.hpp \
    zabr.hpp \
    zabrinterpolatedsmilesection.hpp \
    zabrinterpolation.hpp \
    zabrsmilesection.hpp

cpp_files = \
    abcdatmvolcurve.cpp \
    blackatmvolcurve.cpp \
    blackvolsurface.cpp \
    equityfxvolsurface.cpp \
    extendedblackvariancecurve.cpp \
    extendedblackvariancesurface.cpp \
    interestratevolsurface.cpp \
    noarbsabr.cpp \
    noarbsabrabsprobs.cpp \
    noarbsabrinterpolatedsmilesection.cpp \
    noarbsabrsmilesection.cpp \
    sabrvolsurface.cpp \
    sviinterpolatedsmilesection.cpp \
    svismilesection.cpp \
    volcube.cpp \
    zabr.cpp

if UNITY_BUILD

libVolatility_la_SOURCES = unity.cpp

unity.cpp: Makefile.am
	echo "/* This file is automatically generated; do not edit.     */" > $@
	echo "/* Add the files to be included into Makefile.am instead. */" >> $@
	echo >> $@
	for i in $(cpp_files); do \
		echo "#include \"$$i\"" >> $@; \
	done

EXTRA_DIST = $(cpp_files)

else

libVolatility_la_SOURCES = $(cpp_files)

endif

noinst_LTLIBRARIES = libVolatility.la

all.hpp: Makefile.am
	echo "/* This file is automatically generated; do not edit.     */" > $@
	echo "/* Add the files to be included into Makefile.am instead. */" >> $@
	echo >> $@
	for i in $(filter-out all.hpp, $(this_include_HEADERS)); do \
		echo "#include <${subdir}/$$i>" >> $@; \
	done
	echo >> $@
	subdirs='$(SUBDIRS)'; for i in $$subdirs; do \
		echo "#include <${subdir}/$$i/all.hpp>" >> $@; \
	done

