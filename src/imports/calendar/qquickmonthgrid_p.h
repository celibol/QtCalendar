/****************************************************************************
**
** Copyright (C) 2020 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of Qt Quick Calendar.
**
** $QT_BEGIN_LICENSE:GPL-MARKETPLACE$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the Marketplace license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
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

#ifndef QQUICKMONTHGRID_P_H
#define QQUICKMONTHGRID_P_H

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

#include <QtQuickTemplates2/private/qquickcontrol_p.h>

QT_BEGIN_NAMESPACE

class QQmlComponent;
class QQuickMonthGridPrivate;

class QQuickMonthGrid : public QQuickControl
{
    Q_OBJECT
    Q_PROPERTY(int month READ month WRITE setMonth NOTIFY monthChanged FINAL)
    Q_PROPERTY(int year READ year WRITE setYear NOTIFY yearChanged FINAL)
    Q_PROPERTY(QVariant source READ source WRITE setSource NOTIFY sourceChanged FINAL)
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged FINAL)
    Q_PROPERTY(QQmlComponent *delegate READ delegate WRITE setDelegate NOTIFY delegateChanged FINAL)

public:
    explicit QQuickMonthGrid(QQuickItem *parent = nullptr);

    int month() const;
    void setMonth(int month);

    int year() const;
    void setYear(int year);

    QVariant source() const;
    void setSource(const QVariant &source);

    QString title() const;
    void setTitle(const QString &title);

    QQmlComponent *delegate() const;
    void setDelegate(QQmlComponent *delegate);

Q_SIGNALS:
    void monthChanged();
    void yearChanged();
    void sourceChanged();
    void titleChanged();
    void delegateChanged();

    void pressed(const QDate &date);
    void released(const QDate &date);
    void clicked(const QDate &date);
    void pressAndHold(const QDate &date);

protected:
    void componentComplete() override;
    void geometryChanged(const QRectF &newGeometry, const QRectF &oldGeometry) override;
    void localeChange(const QLocale &newLocale, const QLocale &oldLocale) override;
    void paddingChange(const QMarginsF &newPadding, const QMarginsF &oldPadding) override;
    void updatePolish() override;

    void timerEvent(QTimerEvent *event) override;

private:
    Q_DISABLE_COPY(QQuickMonthGrid)
    Q_DECLARE_PRIVATE(QQuickMonthGrid)
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QQuickMonthGrid)

#endif // QQUICKMONTHGRID_P_H
