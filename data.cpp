/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt Data Visualization module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:GPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
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

#include "data.h"

#include <QtCore/QRandomGenerator>
#include <QtDataVisualization/QScatterDataProxy>
#include <QtDataVisualization/Q3DScene>
#include <QtDataVisualization/Q3DCamera>
#include <QtDataVisualization/QScatter3DSeries>
#include <QtDataVisualization/Q3DTheme>

using namespace QtDataVisualization;



Data::Data(Q3DScatter *scatter, QScatterDataArray *data,  double _x, double _y, double _size_x, double _size_y, double _min, double _max)
    : m_graph(scatter),
      //! [1]
      m_inputHandler(new AxesInputHandler(scatter)),
      //! [1]
      m_autoAdjust(false)
{
    x = _x;
    y = _y;
    size_x = _size_x;
    size_y = _size_y;
    dataArray = data;
    min = _min;
    max = _max;
    //Vector = data;
    m_graph->activeTheme()->setType(Q3DTheme::ThemeEbony);
    m_graph->activeTheme()->setLabelBorderEnabled(true);
    m_graph->activeTheme()->setLabelBackgroundColor(QColor(QRgb(0x151550)));
    m_graph->activeTheme()->setLabelTextColor(Qt::lightGray);
    m_graph->activeTheme()->setFont(QFont("Arial Black", 30));
    m_graph->setShadowQuality(QAbstract3DGraph::ShadowQualityMedium);
    m_graph->scene()->activeCamera()->setCameraPreset(Q3DCamera::CameraPresetIsometricRight);

    m_graph->axisX()->setRange( x - size_x/2 - 0.0001, x + size_x/2 + 0.0001);
    m_graph->axisZ()->setRange( y - size_y/2 - 0.0001, y + size_y/2 + 0.0001);
    m_graph->axisY()->setRange(min, max);

    m_graph->setAspectRatio(1.0);
    m_graph->setHorizontalAspectRatio(1.0);
    //! [0]
    // Give ownership of the handler to the graph and make it the active handler
    m_graph->setActiveInputHandler(m_inputHandler);
    //! [0]

    //! [2]
    // Give our axes to the input handler
    m_inputHandler->setAxes(m_graph->axisX(), m_graph->axisZ(), m_graph->axisY());
    //! [2]

    addData();
}

Data::~Data()
{
    delete m_graph;
}

void Data::toggleRanges()
{
    if (!m_autoAdjust) {
        m_graph->axisX()->setAutoAdjustRange(true);
        m_graph->axisZ()->setAutoAdjustRange(true);
        m_graph->axisY()->setAutoAdjustRange(true);
        m_inputHandler->setDragSpeedModifier(1.5f);
        m_autoAdjust = true;
    } else {
        m_graph->axisX()->setRange( x - size_x/2 - 0.0001, x + size_x/2 + 0.0001);
        m_graph->axisZ()->setRange( y - size_y/2 - 0.0001, y + size_y/2 + 0.0001);
        m_graph->axisY()->setRange(min, max);
        m_inputHandler->setDragSpeedModifier(15.0f);
        m_autoAdjust = false;
    }
}

void Data::addData()
{
    QScatter3DSeries *series = new QScatter3DSeries;
    series->setMesh(QAbstract3DSeries::MeshCube);
    series->setMeshSmooth(true);
    m_graph->addSeries(series);

    m_graph->seriesList().at(0)->dataProxy()->resetArray(dataArray);
}

