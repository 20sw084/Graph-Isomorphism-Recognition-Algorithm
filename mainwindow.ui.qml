/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/

import QtQuick
import QtQuick.Controls
import Project

Rectangle {
    id: mainContainer
    width: Constants.width
    height: Constants.height
    color: Constants.backgroundColor

    Column {
        id: layout
        width: 1020
        height: 680
        anchors.verticalCenterOffset: -28
        anchors.horizontalCenterOffset: -97
        spacing: 20
        anchors.centerIn: parent

        GroupBox {
            id: graph1
            title: qsTr("Graph 1")
            width: parent.width * 0.8
            height: 300

            Column {
                spacing: 10
                anchors.fill: parent
                anchors.margins: 10

                Row {
                    spacing: 10
                    Label { text: qsTr("Edges:") }
                    SpinBox {
                        id: edges1
                        x: 44
                        from: 0
                        to: 100
                        value: 0
                    }

                    Label { text: qsTr("Vertices:") }

                    SpinBox {
                        id: vertices1
                        from: 0
                        to: 100
                        value: 0
                    }
                }

                Rectangle {
                    id: graphicsView1
                    color: "#dddddd"
                    width: parent.width
                    height: 150
                }

                Row {
                    spacing: 10
                    Button { text: qsTr("Add Edge") }
                    Button { text: qsTr("Generate Graph") }
                    Button { text: qsTr("Save Image") }
                }
            }
        }

        GroupBox {
            id: graph2
            title: qsTr("Graph 2")
            width: parent.width * 0.8
            height: 300

            Column {
                spacing: 10
                anchors.fill: parent
                anchors.margins: 10

                Row {
                    spacing: 10
                    Label { text: qsTr("Edges:") }
                    SpinBox {
                        id: edges2
                        from: 0
                        to: 100
                        value: 0
                    }

                    Label { text: qsTr("Vertices:") }

                    SpinBox {
                        id: vertices2
                        from: 0
                        to: 100
                        value: 0
                    }
                }

                Rectangle {
                    id: graphicsView2
                    color: "#dddddd"
                    width: parent.width
                    height: 150
                }

                Row {
                    spacing: 10
                    Button { text: qsTr("Add Edge") }
                    Button { text: qsTr("Generate Graph") }
                    Button { text: qsTr("Save Image") }
                }
            }
        }

        Button {
            id: checkIsomorphism
            text: qsTr("Check Isomorphism")
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}
