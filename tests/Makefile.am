## Process this file with automake to produce Makefile.in

TESTS = check_roman_numeral
check_PROGRAMS = check_roman_numeral
check_roman_numeral_SOURCES = check_roman_numeral.c $(top_builddir)/src/roman_numeral.h
check_roman_numeral_CFLAGS = @CHECK_CFLAGS@
check_roman_numeral_LDADD = $(top_builddir)/src/libroman_numeral.la @CHECK_LIBS@
