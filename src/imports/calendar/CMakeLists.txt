#####################################################################
## qtquickcalendarplugin Plugin:
#####################################################################

set(qml_files
    "DayOfWeekRow.qml"
    "MonthGrid.qml"
    "WeekNumberColumn.qml"
)
set_source_files_properties(DayOfWeekRow.qml PROPERTIES
    QT_QML_SOURCE_VERSIONS "1.0"
)
set_source_files_properties(MonthGrid.qml PROPERTIES
    QT_QML_SOURCE_VERSIONS "1.0"
)
set_source_files_properties(WeekNumberColumn.qml PROPERTIES
    QT_QML_SOURCE_VERSIONS "1.0"
)

qt_internal_add_qml_module(QuickCalendar
    URI "QtQuick.Calendar"
    VERSION "1.0"
    CLASS_NAME QtQuickCalendarPlugin
    PLUGIN_TARGET qtquickcalendarplugin
    DEPENDENCIES
        QtQuick.Templates
    SOURCES
        qquickcalendar.cpp qquickcalendar_p.h
        qquickcalendarmodel.cpp qquickcalendarmodel_p.h
        qquickdayofweekmodel.cpp qquickdayofweekmodel_p.h
        qquickdayofweekrow.cpp qquickdayofweekrow_p.h
        qquickmonthgrid.cpp qquickmonthgrid_p.h
        qquickmonthmodel.cpp qquickmonthmodel_p.h
        qquickweeknumbercolumn.cpp qquickweeknumbercolumn_p.h
        qquickweeknumbermodel.cpp qquickweeknumbermodel_p.h
    QML_FILES
        ${qml_files}
    DEFINES
        QT_NO_CAST_FROM_ASCII
        QT_NO_CAST_TO_ASCII
    LIBRARIES
        Qt::Core
        Qt::CorePrivate
        Qt::Gui
        Qt::GuiPrivate
        Qt::Qml
        Qt::QmlPrivate
        Qt::Quick
        Qt::QuickPrivate
        Qt::QuickTemplates2Private
)

qt_internal_add_docs(QuickCalendar
    doc/qtquickcalendar.qdocconf
)
