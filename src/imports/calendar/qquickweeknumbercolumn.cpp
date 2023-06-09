/****************************************************************************
**
** Copyright (C) 2020 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of Qt Quick Calendar.
**
** $QT_BEGIN_LICENSE:GPL-MARKETPLACE-QT$
**
** Marketplace License Usage
** Users, who have licensed the Software under the Qt Marketplace license
** agreement, may use this file in accordance with the Qt Marketplace license
** agreement provided with the Software or, alternatively, in accordance with
** the terms contained in a written agreement between the licensee and The Qt
** Company. For licensing terms and conditions see
** https://www.qt.io/terms-conditions/#marketplace and
** https://www.qt.io/terms-conditions. For further information use the contact
** form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 or (at your option) any later version
** approved by the KDE Free Qt Foundation. The licenses are as published by
** the Free Software Foundation and appearing in the file LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qquickweeknumbercolumn_p.h"
#include "qquickweeknumbermodel_p.h"

#include <QtQuickTemplates2/private/qquickcontrol_p_p.h>
#include <QtQml/qqmlinfo.h>

QT_BEGIN_NAMESPACE

/*!
    \qmltype WeekNumberColumn
    \inherits Control
//!     \instantiates QQuickWeekNumberColumn
    \inqmlmodule QtQuick.Calendar
    \brief A column of week numbers.

    WeekNumberColumn presents week numbers in a column. The week numbers
    are calculated for a given \l month and \l year, using the specified
    \l {Control::locale}{locale}.

    \image qtquickcalendar-weeknumbercolumn.png
    \snippet qtquickcalendar-weeknumbercolumn.qml 1

    WeekNumberColumn can be used as a standalone control, but it is most
    often used in conjunction with MonthGrid. Regardless of the use case,
    positioning of the column is left to the user.

    \image qtquickcalendar-weeknumbercolumn-layout.png
    \snippet qtquickcalendar-weeknumbercolumn-layout.qml 1

    The visual appearance of WeekNumberColumn can be changed by
    implementing a \l {delegate}{custom delegate}.

    \compatibility

    \sa MonthGrid, DayOfWeekRow
*/

class QQuickWeekNumberColumnPrivate : public QQuickControlPrivate
{
public:
    QQuickWeekNumberColumnPrivate() : delegate(nullptr), model(nullptr) { }

    void resizeItems();

    QVariant source;
    QQmlComponent *delegate;
    QQuickWeekNumberModel *model;
};

void QQuickWeekNumberColumnPrivate::resizeItems()
{
    if (!contentItem)
        return;

    QSizeF itemSize;
    itemSize.setWidth(contentItem->width());
    itemSize.setHeight((contentItem->height() - 5 * spacing) / 6);

    const auto childItems = contentItem->childItems();
    for (QQuickItem *item : childItems)
        item->setSize(itemSize);
}

QQuickWeekNumberColumn::QQuickWeekNumberColumn(QQuickItem *parent) :
    QQuickControl(*(new QQuickWeekNumberColumnPrivate), parent)
{
    Q_D(QQuickWeekNumberColumn);
    d->model = new QQuickWeekNumberModel(this);
    d->source = QVariant::fromValue(d->model);
    connect(d->model, &QQuickWeekNumberModel::monthChanged, this, &QQuickWeekNumberColumn::monthChanged);
    connect(d->model, &QQuickWeekNumberModel::yearChanged, this, &QQuickWeekNumberColumn::yearChanged);
}

/*!
    \qmlproperty int QtQuick.Calendar::WeekNumberColumn::month

    This property holds the number of the month that the week numbers are
    calculated for. The default value is the current month.

    \include zero-based-months.qdocinc

    \sa Calendar
*/
int QQuickWeekNumberColumn::month() const
{
    Q_D(const QQuickWeekNumberColumn);
    return d->model->month() - 1;
}

void QQuickWeekNumberColumn::setMonth(int month)
{
    Q_D(QQuickWeekNumberColumn);
    if (month < 0 || month > 11) {
        qmlWarning(this) << "month " << month << " is out of range [0...11]";
        return;
    }
    d->model->setMonth(month + 1);
}

/*!
    \qmlproperty int QtQuick.Calendar::WeekNumberColumn::year

    This property holds the number of the year that the week numbers are calculated for.

    The value must be in the range from \c -271820 to \c 275759. The default
    value is the current year.
*/
int QQuickWeekNumberColumn::year() const
{
    Q_D(const QQuickWeekNumberColumn);
    return d->model->year();
}

void QQuickWeekNumberColumn::setYear(int year)
{
    Q_D(QQuickWeekNumberColumn);
    if (year < -271820 || year > 275759) {
        qmlWarning(this) << "year " << year << " is out of range [-271820...275759]";
        return;
    }
    d->model->setYear(year);
}

/*!
    \internal
    \qmlproperty model QtQuick.Calendar::WeekNumberColumn::source

    This property holds the source model that is used as a data model
    for the internal content column.
*/
QVariant QQuickWeekNumberColumn::source() const
{
    Q_D(const QQuickWeekNumberColumn);
    return d->source;
}

void QQuickWeekNumberColumn::setSource(const QVariant &source)
{
    Q_D(QQuickWeekNumberColumn);
    if (d->source != source) {
        d->source = source;
        emit sourceChanged();
    }
}

/*!
    \qmlproperty Component QtQuick.Calendar::WeekNumberColumn::delegate

    This property holds the item delegate that visualizes each week number.

    In addition to the \c index property, a list of model data roles
    are available in the context of each delegate:
    \table
        \row \li \b model.weekNumber : int \li The week number
    \endtable

    The following snippet presents the default implementation of the item
    delegate. It can be used as a starting point for implementing custom
    delegates.

    \snippet WeekNumberColumn.qml delegate
*/
QQmlComponent *QQuickWeekNumberColumn::delegate() const
{
    Q_D(const QQuickWeekNumberColumn);
    return d->delegate;
}

void QQuickWeekNumberColumn::setDelegate(QQmlComponent *delegate)
{
    Q_D(QQuickWeekNumberColumn);
    if (d->delegate != delegate) {
        d->delegate = delegate;
        emit delegateChanged();
    }
}

void QQuickWeekNumberColumn::componentComplete()
{
    Q_D(QQuickWeekNumberColumn);
    QQuickControl::componentComplete();
    d->resizeItems();
}

void QQuickWeekNumberColumn::geometryChanged(const QRectF &newGeometry, const QRectF &oldGeometry)
{
    Q_D(QQuickWeekNumberColumn);
    QQuickControl::geometryChanged(newGeometry, oldGeometry);
    if (isComponentComplete())
        d->resizeItems();
}

void QQuickWeekNumberColumn::localeChange(const QLocale &newLocale, const QLocale &oldLocale)
{
    Q_D(QQuickWeekNumberColumn);
    QQuickControl::localeChange(newLocale, oldLocale);
    d->model->setLocale(newLocale);
}

void QQuickWeekNumberColumn::paddingChange(const QMarginsF &newPadding, const QMarginsF &oldPadding)
{
    Q_D(QQuickWeekNumberColumn);
    QQuickControl::paddingChange(newPadding, oldPadding);
    if (isComponentComplete())
        d->resizeItems();
}

QT_END_NAMESPACE
