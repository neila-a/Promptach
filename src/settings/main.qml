import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import Qt.labs.qmlmodels

Window {
    width: 800
    height: 573
    visible: true
    title: qsTr("Promptach设置")

    Text {
        id: previewText
        text: qsTr("预览")
    }
    RowLayout {
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        anchors.top: previewText.bottom
        spacing: 8

        TreeView {
            Layout.fillHeight: true
            Layout.fillWidth: true
            model: TreeModel {
                TableModelColumn {
                    display: "name"
                }
                rows: (() => {
                        let lines = [];
                        for (let lineIndex = 0; lineIndex < settings.getTextsList().size(); lineIndex++) {
                            let thisLine = textsList.at(lineIndex);
                            lines.push({
                                name: qsTr("第%1行").arg(lineIndex + 1),
                                rows: (() => {
                                        let sides = [];
                                        for (let sideIndex = 0; sideIndex < thisLine.size(); sideIndex++) {
                                            let thisSide = thisLine.at(sideIndex);
                                            sides.push({
                                                name: qsTr("第%1边").arg(sideIndex + 1),
                                                rows: (() => {
                                                        let texts = [];
                                                        for (let textIndex = 0; textIndex < thisSide.size(); textIndex++) {
                                                            let thisText = thisSide.at(textIndex);
                                                            texts.push(thisText);
                                                        }
                                                        return texts;
                                                    })()
                                            });
                                        }
                                        return sides;
                                    })()
                            });
                        }
                        return lines;
                    })()
            }
        }
        ColumnLayout {
            Layout.fillHeight: true
            Layout.alignment: Qt.AlignRight
            spacing: 8

            RowLayout {
                spacing: 0

                Text {
                    text: qsTr("文本来源")
                }
                TextInput {}
            }
            RowLayout {
                spacing: 8

                Text {
                    text: qsTr("颜色")
                }
                TextInput {}
            }
            Rectangle {
                Layout.fillHeight: true
            }
            RowLayout {
                spacing: 8

                Button {
                    text: qsTr("添加行")
                    icon.name: "bqm-add"
                }
                Button {
                    text: qsTr("添加边")
                    icon.name: "bqm-add"
                }
                Button {
                    text: qsTr("添加文本")
                    icon.name: "bqm-add"
                }
            }
            RowLayout {
                spacing: 8

                Button {
                    text: qsTr("移除行")
                    icon.name: "bqm-rmqueue"
                }
                Button {
                    text: qsTr("移除边")
                    icon.name: "bqm-rmqueue"
                }
                Button {
                    text: qsTr("移除文本")
                    icon.name: "bqm-rmqueue"
                }
            }
        }
    }
}
