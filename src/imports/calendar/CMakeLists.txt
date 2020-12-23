# Generated from calendar.pro.

#####################################################################
## qtquickcalendarplugin Plugin:
#####################################################################

qt_add_qml_module(qtquickcalendarplugin
    URI "QtQuick.Calendar"
    VERSION "1.0"
    CLASSNAME QtQuickCalendarPlugin
    SOURCES
        qquickcalendar.cpp qquickcalendar_p.h
        qquickcalendarmodel.cpp qquickcalendarmodel_p.h
        qquickdayofweekmodel.cpp qquickdayofweekmodel_p.h
        qquickdayofweekrow.cpp qquickdayofweekrow_p.h
        qquickmonthgrid.cpp qquickmonthgrid_p.h
        qquickmonthmodel.cpp qquickmonthmodel_p.h
        qquickweeknumbercolumn.cpp qquickweeknumbercolumn_p.h
        qquickweeknumbermodel.cpp qquickweeknumbermodel_p.h
        qtquickcalendarplugin.cpp
    DEFINES
        QT_NO_CAST_FROM_ASCII
        QT_NO_CAST_TO_ASCII
    LIBRARIES
        Qt::CorePrivate
        Qt::GuiPrivate
        Qt::QmlPrivate
        Qt::QuickPrivate
        Qt::QuickTemplates2Private
    PUBLIC_LIBRARIES
        Qt::Core
        Qt::Gui
        Qt::Qml
        Qt::Quick
)

#### Keys ignored in scope 1:.:.:calendar.pro:<TRUE>:
# IMPORT_VERSION = "1.0"
# OTHER_FILES = "qmldir"
# TARGETPATH = "QtQuick/Calendar"

## Scopes:
#####################################################################

set(qml_files
    "DayOfWeekRow.qml"
    "MonthGrid.qml"
    "WeekNumberColumn.qml"
)
set_source_files_properties(DayOfWeekRow.qml PROPERTIES
    QT_QML_SOURCE_VERSION "1.0"
)
set_source_files_properties(MonthGrid.qml PROPERTIES
    QT_QML_SOURCE_VERSION "1.0"
)
set_source_files_properties(WeekNumberColumn.qml PROPERTIES
    QT_QML_SOURCE_VERSION "1.0"
)

qt6_target_qml_files(qtquickcalendarplugin
    FILES
        ${qml_files}
)
qt_add_docs(qtquickcalendarplugin
    doc/qtquickcalendar.qdocconf
)

