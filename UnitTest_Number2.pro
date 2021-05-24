QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  \
            tst_unittest.cpp \
            D:/Github/Repos/DoppeltVerketteteListe/DoppeltVerketteteListe/OwnFunctions.cpp

HEADERS += \
            D:/Github/Repos/DoppeltVerketteteListe/DoppeltVerketteteListe/LinkedList.h \
            D:/Github/Repos/DoppeltVerketteteListe/DoppeltVerketteteListe/Auto.h \
            D:/Github/Repos/DoppeltVerketteteListe//DoppeltVerketteteListe/Person.h \
            D:/Github/Repos/DoppeltVerketteteListe/DoppeltVerketteteListe/Node.h \
            D:/Github/Repos/DoppeltVerketteteListe/DoppeltVerketteteListe/OwnFunctions.h

INCLUDEPATH += D:/Github/Repos/DoppeltVerketteteListe/DoppeltVerketteteListe/

