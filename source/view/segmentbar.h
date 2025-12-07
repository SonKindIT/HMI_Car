#ifndef SEGMENTBAR_H
#define SEGMENTBAR_H

#include <QObject>
#include <QQuickPaintedItem>

class SegmentBar : public QQuickPaintedItem
{
    Q_OBJECT

    Q_PROPERTY(qint8 numSegment READ numSegment WRITE setNumSegment NOTIFY numSegmentChanged FINAL)
    Q_PROPERTY(qint16 maxValue READ maxValue WRITE setMaxValue NOTIFY maxValueChanged FINAL)
    Q_PROPERTY(qint16 curValue READ curValue WRITE setCurValue NOTIFY curValueChanged FINAL)
    Q_PROPERTY(QColor inactiveColor READ inactiveColor WRITE setInactiveColor NOTIFY inactiveColorChanged FINAL)
    Q_PROPERTY(QColor activeColor READ activeColor WRITE setActiveColor NOTIFY activeColorChanged FINAL)
    Q_PROPERTY(QString textDisplay READ textDisplay WRITE setTextDisplay NOTIFY textDisplayChanged FINAL)
    Q_PROPERTY(QFont fontText READ fontText WRITE setFontText NOTIFY fontTextChanged FINAL)

public:
    SegmentBar(QQuickItem *parent = nullptr);



    qint8 numSegment() const;
    void setNumSegment(qint8 newNumSegment);

    QFont fontText() const;
    void setFontText(const QFont &newFontText);

    qint16 maxValue() const;
    void setMaxValue(qint16 newMaxValue);

    qint16 curValue() const;
    void setCurValue(qint16 newCurValue);

    QColor activeColor() const;
    void setActiveColor(const QColor &newActiveColor);

    QString textDisplay() const;
    void setTextDisplay(const QString &newTextDisplay);

    QColor inactiveColor() const;
    void setInactiveColor(const QColor &newInactiveColor);

signals:
    void numSegmentChanged();
    void fontTextChanged();

    void maxValueChanged();

    void curValueChanged();

    void activeColorChanged();

    void textDisplayChanged();

    void inactiveColorChanged();

private:
    qint8 m_numSegment;
    QFont m_fontText;
    qint16 m_maxValue;
    qint16 m_curValue;
    QColor m_activeColor;
    QString m_textDisplay;
    QColor m_inactiveColor;

    // QQuickPaintedItem interface
public:
    void paint(QPainter *painter);


public slots:
    void setCurrentSpeed(qint16 speed);
};

#endif // SEGMENTBAR_H
