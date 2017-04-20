######################################################################
# Automatically generated by qmake (2.01a) ?? ?? 24 11:04:10 2015
######################################################################

TEMPLATE = lib
TARGET = lua-52
CONFIG(x64){
TARGET = $$TARGET"64"
}
DEPENDPATH += . src
INCLUDEPATH += .

CONFIG += staticlib

dir = ../..
include($$dir/common.pri)

DEFINES += _CRT_SECURE_NO_WARNINGS

# Input
HEADERS += src/lapi.h \
           src/lauxlib.h \
           src/lcode.h \
           src/lctype.h \
           src/ldebug.h \
           src/ldo.h \
           src/lfunc.h \
           src/lgc.h \
           src/llex.h \
           src/llimits.h \
           src/lmem.h \
           src/lobject.h \
           src/lopcodes.h \
           src/lparser.h \
           src/lstate.h \
           src/lstring.h \
           src/ltable.h \
           src/ltm.h \
           src/lua.h \
           src/lua.hpp \
           src/luaconf.h \
           src/lualib.h \
           src/lundump.h \
           src/lvm.h \
           src/lzio.h
SOURCES += src/lapi.c \
           src/lauxlib.c \
           src/lbaselib.c \
           src/lbitlib.c \
           src/lcode.c \
           src/lcorolib.c \
           src/lctype.c \
           src/ldblib.c \
           src/ldebug.c \
           src/ldo.c \
           src/ldump.c \
           src/lfunc.c \
           src/lgc.c \
           src/linit.c \
           src/liolib.c \
           src/llex.c \
           src/lmathlib.c \
           src/lmem.c \
           src/loadlib.c \
           src/lobject.c \
           src/lopcodes.c \
           src/loslib.c \
           src/lparser.c \
           src/lstate.c \
           src/lstring.c \
           src/lstrlib.c \
           src/ltable.c \
           src/ltablib.c \
           src/ltm.c \
           src/lundump.c \
           src/lvm.c \
           src/lzio.c
