import QtQuick
import QtQuick.Controls
import QtQuick.Effects
import QtQuick.Layouts
import CustomControls

ApplicationWindow {

    readonly property real screenRatio: 0.6

    width: (1920+58) * screenRatio
    height:(960+58) * screenRatio
    visible: true
    title: qsTr("CAR HMI")


    Image {
        id: backImgId
        source: "qrc:/assets/Dashboard.svg"
        anchors.fill: parent
    }

    Item {
        id: layoutId
        width: 1920 * screenRatio
        height: 960 * screenRatio
        anchors.centerIn: parent

        Image{
            id: headerImgId
            source: "qrc:/assets/Vector70.png"
            width: 1357 * screenRatio
            height: 115
            x : 282 * screenRatio
            y : 0
            sourceSize.width: width
            sourceSize.height: height
            smooth: false
        }


        Image{
            id:headerlowbeamID
            source: "qrc:/assets/Lowbeamheadlights.svg"
            width: 51 * screenRatio
            height: 51 * screenRatio
            x: 480 * screenRatio
            y: 32 * screenRatio
        }

        Label{
            id: timelblId
            text: "19:30"
            font{
                pixelSize: 32
                family: "Inter"
                bold: Font.DemiBold
            }
            color: "#FFFFFF"
            anchors.horizontalCenter: parent.horizontalCenter
            y: 32 * screenRatio
        }

        Label{
            text: "06/12/2025"
            font{
                pixelSize: 20
                family: "Inter"
                bold: Font.DemiBold
            }
            color: "#FFFFFF"
            x: timelblId.x + (timelblId.x - headerlowbeamID.x)
            y: 32 * screenRatio
        }



        //Right Elements
        Image{
            id: parkingrightId
            source: "qrc:/assets/Parkinglights.svg"
            width: implicitWidth * screenRatio
            height: implicitHeight * screenRatio
            x : 164 * screenRatio
            y : 106 * screenRatio
        }

        Image{
            id: lightId
            source: "qrc:/assets/Lights.svg"
            width: implicitWidth * screenRatio
            height: implicitHeight * screenRatio
            x : 115 * screenRatio
            y : 177.9 * screenRatio
        }

        Image{
            id: lowbeamrightId
            source: "qrc:/assets/Lowbeamheadlights.svg"
            width: implicitWidth * screenRatio
            height: implicitHeight * screenRatio
            x : 90 * screenRatio
            y : 266 * screenRatio
        }

        Image{
            id: rareFogid
            source: "qrc:/assets/Rarefoglights.svg"
            width: implicitWidth * screenRatio
            height: implicitHeight * screenRatio
            x : 81 * screenRatio
            y : 346 * screenRatio
        }

        // Progress Bar

        RadialBar{
            id: radBarid
            width: 338 * screenRatio
            height : 338 * screenRatio
            x: 282 * screenRatio
            y: 317 * screenRatio
/*
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

  */
        }

    }

    Component.onCompleted:
    {

    }

}
