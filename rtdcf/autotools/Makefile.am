AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = ${ACLOCAL_FLAGS}

AM_CPPFLAGS=-I"../../include" ${INTER_DINTER_INCLUDES}

prefix=${abs_builddir}

lib_LTLIBRARIES = libinter.la
libinter_la_SOURCES = ${INTER_SOURCES}
libinter_la_LIBADD = -L"../../lib" -lffead-modules -lffead-framework ${INTER_DINTER_LIBRARIES}
libinter_la_LDFLAGS = -avoid-version -shared -no-undefined -module -export-dynamic

#if BUILT_WITH_CONFGURE
lib_LTLIBRARIES += libdinter.la
libdinter_la_SOURCES = ${DINTER_SOURCES}
libdinter_la_LIBADD = -L"../../lib" -lffead-modules -lffead-framework ${INTER_DINTER_LIBRARIES}
libdinter_la_LDFLAGS = -avoid-version -shared -no-undefined -module -export-dynamic
#endif

dist_noinst_SCRIPTS = autogen.sh