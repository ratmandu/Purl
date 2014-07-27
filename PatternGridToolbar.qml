import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1

ToolBar {

  property alias numberOfColumns: columnsInput.text
  property alias numberOfRows:    rowsInput.text

  RowLayout {
    Text {
      id: columnsLabel
      text: qsTr("Columns: ")
    }

    TextField {
      id: columnsInput
      text: "10"
    }

    Item { width: 15 }

    Text {
      id: rowsLabel
      text: qsTr("Rows: ")
    }

    TextField {
      id: rowsInput
      text: "5"
    }
  }
}
