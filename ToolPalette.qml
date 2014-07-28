import QtQuick 2.0
import QtQuick.XmlListModel 2.0

Item {
  anchors.fill: parent

  XmlListModel {
    id: toolPaletteModel
    source: "qrc:///ToolPalette.xml"
    query: "/Purl/Symbols/Symbol"

    XmlRole {
      name: "name"
      query: "Name/string()"
    }

    XmlRole {
      name: "description"
      query: "Text/string()"
    }
  }

  ListView {
    id: toolPaletteView
    anchors.fill: parent
    model: toolPaletteModel

    delegate: Text { text: name }
  }

}
