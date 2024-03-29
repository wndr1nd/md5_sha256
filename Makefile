#############################################################################
# Makefile for building: hash2
# Generated by qmake (3.1) (Qt 5.15.2)
# Project:  ../hash2v2/hash2.pro
# Template: app
# Command: /usr/lib/qt5/bin/qmake -o Makefile ../hash2v2/hash2.pro -spec linux-g++
#############################################################################

MAKEFILE      = Makefile


####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB
CFLAGS        = -pipe -O2 -Wall -Wextra -D_REENTRANT -fPIC $(DEFINES)
CXXFLAGS      = -pipe -O2 -std=gnu++1z -Wall -Wextra -D_REENTRANT -fPIC $(DEFINES)
INCPATH       = -I../sha256_md5-newVersion -I. -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I. -I. -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++
QMAKE         = /usr/lib/qt5/bin/qmake
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = $(SUBLIBS) /usr/lib/x86_64-linux-gnu/libQt5Widgets.so /usr/lib/x86_64-linux-gnu/libQt5Gui.so /usr/lib/x86_64-linux-gnu/libQt5Core.so -lGL -lpthread   


####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = ../sha256_md5-newVersion/crc32.cpp \
		../sha256_md5-newVersion/main.cpp \
		../sha256_md5-newVersion/mainwindow.cpp \
		../sha256_md5-newVersion/md5.cpp \
		../sha256_md5-newVersion/sha1.cpp \
		../sha256_md5-newVersion/sha256.cpp moc_mainwindow.cpp
OBJECTS       = crc32.o \
		main.o \
		mainwindow.o \
		md5.o \
		sha1.o \
		sha256.o \
		moc_mainwindow.o

QMAKE_TARGET  = hash2

TARGET        = hash2


first: all
	./hash2
####### Build rules

hash2: ui_mainwindow.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)


all: Makefile hash2



clean: compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

mocclean: compiler_moc_header_clean compiler_moc_objc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_objc_header_make_all compiler_moc_source_make_all

compiler_moc_predefs_make_all: moc_predefs.h
compiler_moc_predefs_clean:
	-$(DEL_FILE) moc_predefs.h
moc_predefs.h: /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/data/dummy.cpp
	g++ -pipe -O2 -std=gnu++1z -Wall -Wextra -dM -E -o moc_predefs.h /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/data/dummy.cpp

compiler_moc_header_make_all: moc_mainwindow.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainwindow.cpp
moc_mainwindow.cpp: ../sha256_md5-newVersion/mainwindow.h \
		../sha256_md5-newVersion/md5.h \
		../sha256_md5-newVersion/ihash.h \
		../sha256_md5-newVersion/sha256.h \
		../sha256_md5-newVersion/sha1.h \
		../sha256_md5-newVersion/crc32.h \
		moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include ../qt2/build-hash2-Desktop-Release/moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I../qt2/sha256_md5-newVersion -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I. -I/usr/include/c++/10 -I/usr/include/x86_64-linux-gnu/c++/10 -I/usr/include/c++/10/backward -I/usr/lib/gcc/x86_64-linux-gnu/10/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include ../sha256_md5-newVersion/mainwindow.h -o moc_mainwindow.cpp


compiler_uic_make_all: ui_mainwindow.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindow.h
ui_mainwindow.h: ../sha256_md5-newVersion/mainwindow.ui \
		/usr/lib/qt5/bin/uic
	/usr/lib/qt5/bin/uic ../sha256_md5-newVersion/mainwindow.ui -o ui_mainwindow.h


compiler_clean: compiler_moc_predefs_clean compiler_moc_header_clean compiler_uic_clean 

####### Compile

crc32.o: ../sha256_md5-newVersion/crc32.cpp ../sha256_md5-newVersion/crc32.h \
		../sha256_md5-newVersion/ihash.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o crc32.o ../sha256_md5-newVersion/crc32.cpp

main.o: ../sha256_md5-newVersion/main.cpp ../sha256_md5-newVersion/mainwindow.h \
		../sha256_md5-newVersion/md5.h \
		../sha256_md5-newVersion/ihash.h \
		../sha256_md5-newVersion/sha256.h \
		../sha256_md5-newVersion/sha1.h \
		../sha256_md5-newVersion/crc32.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o ../sha256_md5-newVersion/main.cpp

mainwindow.o: ../sha256_md5-newVersion/mainwindow.cpp ../sha256_md5-newVersion/mainwindow.h \
		../sha256_md5-newVersion/md5.h \
		../sha256_md5-newVersion/ihash.h \
		../sha256_md5-newVersion/sha256.h \
		../sha256_md5-newVersion/sha1.h \
		../sha256_md5-newVersion/crc32.h \
		ui_mainwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o ../sha256_md5-newVersion/mainwindow.cpp

md5.o: ../sha256_md5-newVersion/md5.cpp ../sha256_md5-newVersion/md5.h \
		../sha256_md5-newVersion/ihash.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o md5.o ../sha256_md5-newVersion/md5.cpp

sha1.o: ../sha256_md5-newVersion/sha1.cpp ../sha256_md5-newVersion/sha1.h \
		../sha256_md5-newVersion/ihash.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sha1.o ../sha256_md5-newVersion/sha1.cpp

sha256.o: ../sha256_md5-newVersion/sha256.cpp ../sha256_md5-newVersion/sha256.h \
		../sha256_md5-newVersion/ihash.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sha256.o ../sha256_md5-newVersion/sha256.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp


