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

#ifndef QQUICKMONTHMODEL_P_H
#define QQUICKMONTHMODEL_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtCore/qabstractitemmodel.h>
#include <QtCore/qdatetime.h>
#include <QtCore/qlocale.h>
#include <QtQml/qqml.h>

QT_BEGIN_NAMESPACE

class QQuickMonthModelPrivate;

class QQuickMonthModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int month READ month WRITE setMonth NOTIFY monthChanged FINAL)
    Q_PROPERTY(int year READ year WRITE setYear NOTIFY yearChanged FINAL)
    Q_PROPERTY(QLocale locale READ locale WRITE setLocale NOTIFY localeChanged FINAL)
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged FINAL)
    Q_PROPERTY(int count READ rowCount CONSTANT FINAL)

public:
    explicit QQuickMonthModel(QObject *parent = nullptr);

    int month() const;
    void setMonth(int month);

    int year() const;
    void setYear(int year);

    QLocale locale() const;
    void setLocale(const QLocale &locale);

    QString title() const;
    void setTitle(const QString &title);

    Q_INVOKABLE QDate dateAt(int index) const;
    Q_INVOKABLE int indexOf(const QDate &date) const;

    enum {
        DateRole = Qt::UserRole + 1,
        DayRole,
        TodayRole,
        WeekNumberRole,
        MonthRole,
        YearRole
    };

    QHash<int, QByteArray> roleNames() const override;
    QVariant data(const QModelIndex &index, int role) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

Q_SIGNALS:
    void monthChanged();
    void yearChanged();
    void localeChanged();
    void titleChanged();

private:
    Q_DISABLE_COPY(QQuickMonthModel)
    Q_DECLARE_PRIVATE(QQuickMonthModel)
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QQuickMonthModel)

#endif // QQUICKMONTHMODEL_P_H
