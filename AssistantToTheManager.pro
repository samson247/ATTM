QT       += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addressbook.cpp \
    bigint.cpp \
    database.cpp \
    homepage.cpp \
    login.cpp \
    main.cpp \
    minigmp.cpp \
    note.cpp \
    notelabel.cpp \
    notelist.cpp \
    notewidget.cpp \
    passwordentry.cpp \
    passwordwidget.cpp \
    qrsaencryption.cpp

HEADERS += \
    addressbook.h \
    bigint.h \
    database.h \
    homepage.h \
    login.h \
    minigmp.h \
    note.h \
    notelabel.h \
    notelist.h \
    notewidget.h \
    passwordentry.h \
    passwordwidget.h \
    qrsaencryption.h

FORMS += \
    addressbook.ui \
    homepage.ui \
    login.ui \
    notelabel.ui \
    notelist.ui \
    notewidget.ui \
    passwordentry.ui \
    passwordwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
