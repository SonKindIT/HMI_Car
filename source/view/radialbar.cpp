#include <QPainter>
#include<QDebug>
#include "radialbar.h"

RadialBar::RadialBar(QQuickItem *parent)
    : QQuickPaintedItem(parent),
    m_diagColor(QColor(80,80,80)),
    m_progressColor(QColor(1, 228, 224)),
    m_minValue(0),
    m_maxValue(100),
    m_curValue(50),
    m_nameRad(QString("Battery Charge")),
    m_dialWidth(15),
    m_startAngle(0),
    m_spanAngle(-300),
    m_fontText(QFont("Arial", 28, QFont::Normal)),
    m_fontRad(QFont("Arial", 12, QFont::Normal))
{
    setWidth(200);
    setHeight(200);
    setSmooth(true);
    setAntialiasing(true);
}




QColor RadialBar::diagColor() const
{
    return m_diagColor;
}

void RadialBar::setDiagColor(const QColor &newDiagColor)
{
    if (m_diagColor == newDiagColor)
        return;
    m_diagColor = newDiagColor;
    emit diagColorChanged();
}

QColor RadialBar::progressColor() const
{
    return m_progressColor;
}

void RadialBar::setProgressColor(const QColor &newProgressColor)
{
    if (m_progressColor == newProgressColor)
        return;
    m_progressColor = newProgressColor;
    emit progressColorChanged();
}

qint16 RadialBar::minValue() const
{
    return m_minValue;
}

void RadialBar::setMinValue(qint16 newMinValue)
{
    if (m_minValue == newMinValue)
        return;
    m_minValue = newMinValue;
    emit minValueChanged();
}

qint16 RadialBar::maxValue() const
{
    return m_maxValue;
}

void RadialBar::setMaxValue(qint16 newMaxValue)
{
    if (m_maxValue == newMaxValue)
        return;
    m_maxValue = newMaxValue;
    emit maxValueChanged();
}

qint16 RadialBar::curValue() const
{
    return m_curValue;
}

void RadialBar::setCurValue(qint16 newCurValue)
{
    if (m_curValue == newCurValue)
        return;
    m_curValue = newCurValue;
    emit curValueChanged();
}

qreal RadialBar::startAngle() const
{
    return m_startAngle;
}

void RadialBar::setStartAngle(qreal newStartAngle)
{
    if (qFuzzyCompare(m_startAngle, newStartAngle))
        return;
    m_startAngle = newStartAngle;
    emit startAngleChanged();
}

QString RadialBar::nameRad() const
{
    return m_nameRad;
}

void RadialBar::setNameRad(const QString &newNameRad)
{
    if (m_nameRad == newNameRad)
        return;
    m_nameRad = newNameRad;
    emit nameRadChanged();
}


qint8 RadialBar::dialWidth() const
{
    return m_dialWidth;
}

void RadialBar::setDialWidth(qint8 newDialWidth)
{
    if (m_dialWidth == newDialWidth)
        return;
    m_dialWidth = newDialWidth;
    emit dialWidthChanged();
}

qreal RadialBar::spanAngle() const
{
    return m_spanAngle;
}

void RadialBar::setSpanAngle(qreal newSpanAngle)
{
    if (qFuzzyCompare(m_spanAngle, newSpanAngle))
        return;
    m_spanAngle = newSpanAngle;
    emit spanAngleChanged();
}

QFont RadialBar::fontText() const
{
    return m_fontText;
}

void RadialBar::setFontText(const QFont &newFontText)
{
    if (m_fontText == newFontText)
        return;
    m_fontText = newFontText;
    emit fontTextChanged();
}


void RadialBar::paint(QPainter *painter)
{
    qreal size = qMin(this->width(), this->height());
    setWidth(size);
    setHeight(size);

    QRectF rect = this->boundingRect();

    painter->setRenderHint((QPainter::Antialiasing));
    painter->save();
    QPen pen = painter->pen();
    pen.setCapStyle(Qt::RoundCap);

    int startAngleValue = m_startAngle * 16;
    int spanAngleValue = m_spanAngle * 16;

    pen.setWidth(m_dialWidth);
    pen.setColor(m_diagColor);

    painter->setPen(pen);

    //Draw radial bar
    qreal offset = m_dialWidth/2;
    painter->drawArc(rect.adjusted(offset, offset, -offset, -offset), startAngleValue, spanAngleValue);

    painter->restore();
    painter->save();
    //Draw progress bar
    double ratio = ((double)(m_curValue - m_minValue))/((double)(m_maxValue - m_minValue));
    spanAngleValue = spanAngleValue * ratio;
    pen.setWidth(m_dialWidth);
    pen.setColor(m_progressColor);

    painter->setPen(pen);

    painter->drawArc(rect.adjusted(offset, offset, -offset, -offset), startAngleValue, spanAngleValue);

    painter->restore();

    // //Draw circle in dial
    // painter->save();
    // pen.setColor(QColor("transparent"));
    // pen.setWidth(1);
    // painter->setBrush(QColor("transparent"));s

    // offset = m_dialWidth;

    // painter->drawEllipse(rect.adjusted(offset, offset, -offset, -offset));

    // painter->restore();

    //Draw Text
    painter->save();
    pen.setColor(Qt::white);
    painter->setPen(pen);

    painter->setFont(m_fontText);

    QString text = QString::number((int)(ratio*100)) + " %";
    qreal marginTop = m_fontText.pointSize()*0.6 ;

    painter->drawText(rect.adjusted(0,-marginTop, 0, -marginTop), Qt::AlignCenter, text);

    painter->restore();

    //Draw Radial Name
    painter->save();
    pen.setColor(Qt::white);
    painter->setPen(pen);

    painter->setFont(m_fontRad);
    painter->drawText(rect.adjusted(0,marginTop, 0, marginTop), Qt::AlignCenter, m_nameRad);

    painter->restore();

}


QFont RadialBar::fontRad() const
{
    return m_fontRad;
}

void RadialBar::setFontRad(const QFont &newFontRad)
{
    if (m_fontRad == newFontRad)
        return;
    m_fontRad = newFontRad;
    emit fontRadChanged();
}

void RadialBar::setBatteryChanged(qint16 curValue)
{
    setCurValue(curValue);
    update();
}
