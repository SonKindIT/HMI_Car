#ifndef RADIALBAR_H
#define RADIALBAR_H

#include <QQuickPaintedItem>

class RadialBar : public QQuickPaintedItem
{
    Q_OBJECT

    Q_PROPERTY(QColor diagColor READ diagColor WRITE setDiagColor NOTIFY diagColorChanged FINAL)
    Q_PROPERTY(QColor progressColor READ progressColor WRITE setProgressColor NOTIFY progressColorChanged FINAL)
    Q_PROPERTY(qint16 minValue READ minValue WRITE setMinValue NOTIFY minValueChanged FINAL)
    Q_PROPERTY(qint16 maxValue READ maxValue WRITE setMaxValue NOTIFY maxValueChanged FINAL)
    Q_PROPERTY(qint16 curValue READ curValue WRITE setCurValue NOTIFY curValueChanged FINAL)
    Q_PROPERTY(qreal startAngle READ startAngle WRITE setStartAngle NOTIFY startAngleChanged FINAL)
    Q_PROPERTY(QString nameRad READ nameRad WRITE setNameRad NOTIFY nameRadChanged FINAL)
    Q_PROPERTY(qint8 dialWidth READ dialWidth WRITE setDialWidth NOTIFY dialWidthChanged FINAL)
    Q_PROPERTY(qreal spanAngle READ spanAngle WRITE setSpanAngle NOTIFY spanAngleChanged FINAL)
    Q_PROPERTY(QFont fontText READ fontText WRITE setFontText NOTIFY fontTextChanged FINAL)
    Q_PROPERTY(QFont fontRad READ fontRad WRITE setFontRad NOTIFY fontRadChanged FINAL)

public:
    RadialBar(QQuickItem *parent = nullptr);


    QColor diagColor() const;
    void setDiagColor(const QColor &newDiagColor);

    QColor progressColor() const;
    void setProgressColor(const QColor &newProgressColor);

    qint16 minValue() const;
    void setMinValue(qint16 newMinValue);

    qint16 maxValue() const;
    void setMaxValue(qint16 newMaxValue);

    qint16 curValue() const;
    void setCurValue(qint16 newCurValue);

    qreal startAngle() const;
    void setStartAngle(qreal newStartAngle);

    QString nameRad() const;
    void setNameRad(const QString &newNameRad);

signals:
    void diagColorChanged();

    void progressColorChanged();

    void minValueChanged();

    void maxValueChanged();

    void curValueChanged();

    void startAngleChanged();

    void nameRadChanged();

    void stopAngleChanged();

    void dialWidthChanged();


    void spanAngleChanged();

    void fontTextChanged();


    void fontRadChanged();

private:
    QColor m_diagColor;
    QColor m_progressColor;
    qint16 m_minValue;
    qint16 m_maxValue;
    qint16 m_curValue;
    qreal   m_startAngle;
    QString m_nameRad;

    // QQuickPaintedItem interface

    qint8 m_dialWidth;



    qreal m_spanAngle;

    QFont m_fontText;


    QFont m_fontRad;

public:
    void paint(QPainter *painter);
    qint8 dialWidth() const;
    void setDialWidth(qint8 newDialWidth);
    qreal spanAngle() const;
    void setSpanAngle(qreal newSpanAngle);
    QFont fontText() const;
    void setFontText(const QFont &newFontText);
    QFont fontRad() const;
    void setFontRad(const QFont &newFontRad);
};

#endif // RADIALBAR_H
