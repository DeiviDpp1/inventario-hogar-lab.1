QT += core gui sql printsupport
CONFIG += c++17 release
TEMPLATE = app
TARGET = InventoryManager

SOURCES += \
    src/main.cpp \
    src/models/Component.cpp \
    src/core/InventoryManager.cpp \
    src/core/DatabaseManager.cpp \
    src/core/ReportGenerator.cpp \
    src/ui/MainWindow.cpp \
    src/ui/AddEditDialog.cpp

HEADERS += \
    src/models/Component.h \
    src/core/InventoryManager.h \
    src/core/DatabaseManager.h \
    src/core/ReportGenerator.h \
    src/ui/MainWindow.h \
    src/ui/AddEditDialog.h

RESOURCES +=

QMAKE_CXXFLAGS_RELEASE += -Os -s
QMAKE_LFLAGS_RELEASE += -Wl,--gc-sections
