#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([roman_numeral], [1.0], [bug-roman_numeral@x-ctr-l.com])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_CONFIG_SRCDIR([tests/check_roman_numeral.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
PKG_CHECK_MODULES([CHECK], [check >= 0.9.6])

# Checks for libraries.
LT_INIT()
AC_CONFIG_MACRO_DIR([m4])

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile
                 src/Makefile
                 tests/Makefile])
AC_OUTPUT
