#include "segmentbar.h"
#include<QPainter>
#include<QDebug>

SegmentBar::SegmentBar(QQuickItem *parent) :
    QQuickPaintedItem(parent),
    m_activeColor(QColor("#32D74B")),
    m_inactiveColor(QColor("#01E6DC")),
    m_maxValue(140),
    m_curValue(78),
    m_fontText(QFont("Regular",12)),
    m_textDisplay(QString("--mph")),
    m_numSegment(7)
{}

qint8 SegmentBar::numSegment() const
{
    return m_numSegment;
}

void SegmentBar::setNumSegment(qint8 newNumSegment)
{
    if (m_numSegment == newNumSegment)
        return;
    m_numSegment = newNumSegment;
    emit numSegmentChanged();
}

QFont SegmentBar::fontText() const
{
    return m_fontText;
}

void SegmentBar::setFontText(const QFont &newFontText)
{
    if (m_fontText == newFontText)
        return;
    m_fontText = newFontText;
    emit fontTextChanged();
}

qint16 SegmentBar::maxValue() const
{
    return m_maxValue;
}

void SegmentBar::setMaxValue(qint16 newMaxValue)
{
    if (m_maxValue == newMaxValue)
        return;
    m_maxValue = newMaxValue;
    emit maxValueChanged();
}

qint16 SegmentBar::curValue() const
{
    return m_curValue;
}

void SegmentBar::setCurValue(qint16 newCurValue)
{
    if (m_curValue == newCurValue)
        return;
    m_curValue = newCurValue;
    emit curValueChanged();
}

QColor SegmentBar::activeColor() const
{
    return m_activeColor;
}

void SegmentBar::setActiveColor(const QColor &newActiveColor)
{
    if (m_activeColor == newActiveColor)
        return;
    m_activeColor = newActiveColor;
    emit activeColorChanged();
}

QString SegmentBar::textDisplay() const
{
    return m_textDisplay;
}

void SegmentBar::setTextDisplay(const QString &newTextDisplay)
{
    if (m_textDisplay == newTextDisplay)
        return;
    m_textDisplay = newTextDisplay;
    emit textDisplayChanged();
}

QColor SegmentBar::inactiveColor() const
{
    return m_inactiveColor;
}

void SegmentBar::setInactiveColor(const QColor &newInactiveColor)
{
    if (m_inactiveColor == newInactiveColor)
        return;
    m_inactiveColor = newInactiveColor;
    emit inactiveColorChanged();
}

void SegmentBar::paint(QPainter *painter)
{
    painter->save();

    QRectF rect = boundingRect();

    qreal barWidth = rect.width()*0.6/m_numSegment;
    qreal barX = rect.x();
    qreal barY = rect.y();
    qreal barHeight = rect.height();

    //test
    // barHeight = 10;
    // barWidth = 20;
    qreal margin = 2;

    double valuePerSegment = (double)m_maxValue/(double)m_numSegment;
    int numActiveSegment = m_curValue/valuePerSegment;

    for(int i = 0; i < m_numSegment; i++)
    {

        QRectF rectSegment(barX+i*barWidth, barY, barWidth - margin, barHeight);
        if(i < numActiveSegment)
            painter->setBrush(m_activeColor);
        else
            painter->setBrush(m_inactiveColor);

        painter->setPen(Qt::NoPen);

        painter->drawRoundedRect(rectSegment, 2, 2);
    }

    painter->restore();

    painter->save();

    qreal textWidth = rect.width()*0.4;
    qreal textX = rect.x() + rect.width()*0.6;
    qreal textY = rect.y();
    qreal textHeight = rect.height();
    margin = 5;

    QRectF rectText(textX, textY, textWidth, textHeight);

    QPen pen = painter->pen();
    pen.setColor(Qt::white);
    painter->setPen(pen);
    painter->setFont(m_fontText);

    m_textDisplay = QString::number(m_curValue) + "mph";

    painter->drawText(rectText, Qt::AlignRight | Qt::AlignVCenter, m_textDisplay);


    painter->restore();

}

void SegmentBar::setCurrentSpeed(qint16 speed)
{
    setCurValue(speed);
    update();
}
