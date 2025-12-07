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
            id: rareFogId
            source: "qrc:/assets/Rarefoglights.svg"
            width: implicitWidth * screenRatio
            height: implicitHeight * screenRatio
            x : 81 * screenRatio
            y : 346 * screenRatio
        }

        // Progress Bar

        RadialBar{
            id: radBarId
            width: 338 * screenRatio
            height : 338 * screenRatio
            x: 282 * screenRatio
            y: 317 * screenRatio

            Connections{
                target: Controller
                function onCurrentBatChanged(battery){
                    radBarId.setBatteryChanged(battery);
                }
            }
        }

        //Segment Bar

        SegmentBar{
            id: segBarId
            width: 330 * screenRatio
            height: 25 * screenRatio
            x : 353 * screenRatio
            y : 886 * screenRatio

            Connections{
                target: Controller
                function onCurrentSpeedChanged(speed){
                    segBarId.setCurrentSpeed(speed)
                }
            }
        }

        Label{
            id: tempLblId
            width: 125 * screenRatio
            height: 39 * screenRatio
            x : segBarId.x - width - 5
            y: 880 * screenRatio
            text: Controller.currentTemp + " °F"
            color: "white"
            font{
                pixelSize: 20
                weight: Font.Normal
            }
            horizontalAlignment: Text.AlignRight | Text.AlignVCenter
        }


        Label{
            id: speedLblId
            width: 178 * screenRatio
            height: 62 * screenRatio
            x : 871 * screenRatio
            y: 270 * screenRatio
            text: Controller.currentSpeed
            color: "#01E6DE"
            font{
                pixelSize: 134 * screenRatio
                weight: Font.Bold
            }
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter

            Label{
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: parent.bottom
                anchors.topMargin: 20
                text: "MPH"
                color: "#01E6DE"
                font{
                    pixelSize: 46 * screenRatio
                    weight: Font.Medium
                }
            }
        }

        Item{
            id: roadRectId
            width: 367 * screenRatio
            height: 397 * screenRatio
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter

            Image {
                id: roadLeftId
                source: "qrc:/assets/Vector1.svg"
                height: roadRectId.height
                width: implicitWidth*height/implicitHeight
                anchors{
                    left: roadRectId.left
                    bottom: roadRectId.bottom
                }

            }

            Image {
                id: roadRightId
                source: "qrc:/assets/Vector2.svg"
                height: roadRectId.height
                width: implicitWidth*height/implicitHeight
                anchors{
                    right: roadRectId.right
                    bottom: roadRectId.bottom
                }

            }
        }

        Item{
            width: 130 * screenRatio
            height: width
            x : 895 * screenRatio
            y : 795 * screenRatio

            Rectangle{
                width: parent.width
                height: parent.height
                radius: width/2
                border{
                    color: "#FF2626"
                    width: 6
                }
                color: "#D9D9D9"

                Text {
                    id: limitTxtId
                    font{
                        family: "Inter"
                        pixelSize: 52 * screenRatio
                        weight: Font.Bold
                    }
                    anchors.centerIn: parent
                    text: qsTr("70")
                }

            }
        }


        Item{
            width: 318 * screenRatio
            height: 104 * screenRatio
            x : 1277 * screenRatio
            y : 313 * screenRatio

            Image {
                width: implicitWidth * screenRatio
                height: implicitHeight * width / implicitWidth
                id: distanceImgId
                source: "qrc:/assets/Group28.svg"
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
            }

            Item {
                id: rightItemDistId
                anchors.right: parent.right
                anchors.verticalCenter: parent.verticalCenter
                width: 173 * screenRatio
                height: 104 * screenRatio

                Column{
                    Text {
                        id: disTxtId
                        text: qsTr("188 km")
                        color: "white"
                        font{
                            family: "Inter"
                            weight: Font.Medium
                            pixelSize: 50 * screenRatio
                        }
                    }
                    Text {
                        text: qsTr("Distance")
                        color: Qt.rgba(1,1,1,0.3)
                        font{
                            family: "Inter"
                            weight: Font.Medium
                            pixelSize: 36 * screenRatio
                        }
                    }
                }

            }
        }


        Image{
            id: fuelImgId
            source: "qrc:/assets/fuel.svg"
            width: implicitWidth * screenRatio
            height: implicitHeight * width / implicitWidth
            x : 1290 * screenRatio
            y : 479 * screenRatio
        }

        Text {
            id: fuelTxtId
            x : 1422 * screenRatio
            y : 466 * screenRatio

            verticalAlignment: Text.AlignVCenter
            color: "white"
            text: qsTr("34 mpg")
            font{
                weight: Font.Medium
                family: "Inter"
                pixelSize: 50 * screenRatio
            }
        }

        Text {
            x : 1422 * screenRatio
            y : 526 * screenRatio

            color: Qt.rgba(1,1,1,0.3)
            text: qsTr("Avg.Fuel Usage")
            font{
                weight: Font.Medium
                family: "Inter"
                pixelSize: 36 * screenRatio
            }
        }

        Image{
            id: speedImgId
            source: "qrc:/assets/speedometer.svg"
            width: implicitWidth * screenRatio
            height: implicitHeight * width / implicitWidth
            x : 1282 * screenRatio
            y : 631 * screenRatio
        }

        Text {
            id: speedOdoTxtId
            x : 1422 * screenRatio
            y : 619 * screenRatio

            color: "white"
            text: qsTr("78 mph")
            font{
                weight: Font.Medium
                family: "Inter"
                pixelSize: 50 * screenRatio
            }
        }

        Text {
            x : 1422 * screenRatio
            y : 679 * screenRatio

            color: Qt.rgba(1,1,1,0.3)
            text: qsTr("Avg.Speed")
            font{
                weight: Font.Medium
                family: "Inter"
                pixelSize: 36 * screenRatio
            }
        }

        Item{
            Image{
                id: absImgId
                x : 1685 * screenRatio
                y : 93 * screenRatio
                width: implicitWidth * screenRatio
                height: implicitHeight * width / implicitWidth
                source: "qrc:/assets/FourthRightIcon.svg"
            }

            MultiEffect {
                anchors.fill: absImgId
                source: absImgId
                colorization: 1.0
                colorizationColor: "white"
                opacity: 0.4
            }
        }



        Item{
            Image{
                id: parkImgId
                x : 1733 * screenRatio
                y : 173 * screenRatio
                width: implicitWidth * screenRatio
                height: implicitHeight * width / implicitWidth
                source: "qrc:/assets/thirdRightIcon.svg"
            }

            MultiEffect {
                anchors.fill: parkImgId
                source: parkImgId
                colorization: 1.0
                colorizationColor: "white"
                opacity: 0.4
            }
        }

        Item{
            Image{
                id: brakeImgId
                x : 1758 * screenRatio
                y : 253 * screenRatio
                width: implicitWidth * screenRatio
                height: implicitHeight * width / implicitWidth
                source: "qrc:/assets/SecondRightIcon.svg"
            }

            MultiEffect {
                anchors.fill: brakeImgId
                source: brakeImgId
                colorization: 1.0
                colorizationColor: "white"
                opacity: 0.4
            }
        }

        Item{
            Image{
                id: seatBeltImgId
                x : 1792 * screenRatio
                y : 349 * screenRatio
                width: implicitWidth * screenRatio
                height: implicitHeight * width / implicitWidth
                source: "qrc:/assets/FirstRightIcon.svg"
            }

            MultiEffect {
                anchors.fill: seatBeltImgId
                source: seatBeltImgId
                colorization: 1.0
                colorizationColor: "red"
            }
        }

        Text {
            x : 1277 * screenRatio
            y : 870 * screenRatio

            color: "#32D74B"
            text: qsTr("READY")
            font{
                weight: Font.Regular
                family: "Inter"
                pixelSize: 32 * screenRatio
            }
        }

        Item{
            Text {
                x : 1422 * screenRatio
                y : 870 * screenRatio

                color: "#FFFFFF"
                text: qsTr("P")
                font{
                    weight: Font.Regular
                    family: "Inter"
                    pixelSize: 32 * screenRatio
                }
            }

            Text {
                x : 1467 * screenRatio
                y : 870 * screenRatio

                color: "#FFFFFF"
                opacity: 0.3
                text: qsTr("R")
                font{
                    weight: Font.Regular
                    family: "Inter"
                    pixelSize: 32 * screenRatio
                }
            }

            Text {
                x : 1514 * screenRatio
                y : 870 * screenRatio

                color: "#FFFFFF"
                opacity: 0.3
                text: qsTr("N")
                font{
                    weight: Font.Regular
                    family: "Inter"
                    pixelSize: 32 * screenRatio
                }
            }

            Text {
                x : 1561 * screenRatio
                y : 870 * screenRatio

                color: "#FFFFFF"
                opacity: 0.3
                text: qsTr("D")
                font{
                    weight: Font.Regular
                    family: "Inter"
                    pixelSize: 32 * screenRatio
                }
            }
        }

    }

    Component.onCompleted:
    {
        console.log(segBarId.curValue)
    }

}
