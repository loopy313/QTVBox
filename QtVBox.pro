TEMPLATE = subdirs
CONFIG += ordered
SUBDIRS += \
    lib \
    testapp \

testapp.depens=lib
   #unittest


