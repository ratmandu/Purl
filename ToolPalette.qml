import QtQuick 2.0
import QtQuick.XmlListModel 2.0
import QtQuick.Layouts 1.1

Rectangle {
  anchors.fill: parent

  XmlListModel {
    id: toolPaletteModel
    source: "qrc:///resources/ToolPalette.xml"
    query: "/Purl/Categories/Category"

    XmlRole {
      name: "name"
      query: "Name/string()"
    }

    XmlRole {
      name: "file"
      query: "File/string()"
    }
  }

  Component {
    id: categoryDelegate

    Column {
      spacing: 10
      width: parent.width
//      height: 200


      Rectangle {
        width: parent.width - 20
        height: 100

        color: "#f8f8f8"
        border.color: "#aaaaaa"
        border.width: 1
        anchors.horizontalCenter: parent.horizontalCenter
        radius: 5

        Rectangle {
          border.color: "#aaaaaa"
          border.width: 1
          anchors.horizontalCenter: parent.horizontalCenter
          radius: 5
          height: 20
          width: parent.width

          gradient: Gradient {
            GradientStop { color: "#f8f8f8"; position: 0.0 }
            GradientStop { color: "#cccccc"; position: 1.0 }
          }

          Text {
            text: name
            anchors.centerIn: parent
          }
        }

        XmlListModel {
          id: delegateModel
          source: file
          query: "/Purl/Symbols/Symbol"

          XmlRole { name: "symbolName"; query: "Name/string()" }
          XmlRole { name: "resource"; query: "svgResource/string()" }
        }

        GridView {
          id: symbolView
          anchors.fill: parent
          anchors.topMargin: 25
          anchors.leftMargin: 10
          anchors.rightMargin: 10
          currentIndex: -1

          cellWidth: 50
          cellHeight: 50

          model: delegateModel
          delegate: Column {
            width: parent.cellWidth
            height: parent.cellHeight

            Rectangle {
              id: imgRect
              width: 40
              height: 40
              color: "transparent"
//              color: "white"

              Image {
                anchors.fill: parent
                id: "symbol"
                source: resource
              }

              MouseArea {
                anchors.fill: parent
                onClicked: symbolView.currentIndex = index
              }
            }
            Text {
              horizontalAlignment: Text.AlignHCenter
              anchors.left: imgRect.left
              anchors.top: imgRect.bottom
              width: imgRect.width

              text: symbolName
            }

          }
          highlight: Rectangle { color: "lightgrey"; radius: 5 }
          focus: true
        }
      }
    }
  }

  ListView {
    id: toolPaletteView
    anchors.fill: parent
    model: toolPaletteModel
    spacing: 10

    delegate: categoryDelegate
  }

}
