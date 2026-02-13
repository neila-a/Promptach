import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

Window {
    width: 800
    height: 573
    visible: true
    title: qsTr("Promptach设置")

    ColumnLayout {
        spacing: 0
        
        Text {
            text: qsTr("预览")
        }
        RowLayout {
            spacing: 0

            TreeView {
            }
            ColumnLayout {
                spacing: 0

                RowLayout {
                    spacing: 0

                    Text {
                        text: qsTr("文本来源")
                    }
                    TextInput {
                    }
                }
                RowLayout {
                    spacing: 0

                    Text {
                        text: qsTr("颜色")
                    }
                    TextInput {
                    }
                }
                RowLayout {
                    Layout.alignment: Qt.AlignBottom
                    spacing: 0

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
                    Layout.alignment: Qt.AlignBottom
                    spacing: 0

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
}