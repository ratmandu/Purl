import QtQuick 2.0
import PatternGrid 1.0

Rectangle {
  PatternGridToolbar {
    id: toolBar
  }

  Rectangle {
    anchors.top: toolBar.bottom
    anchors.left: parent.left
    anchors.right: parent.right
    anchors.bottom: parent.bottom

    PatternGrid {
      focus: true
      id: patternGrid
      anchors.fill: parent

      columns: toolBar.numberOfColumns
      rows: toolBar.numberOfRows
      cellHeight: toolBar.cellHeight
      cellWidth: toolBar.cellWidth

//      onMouseXChanged: console.log(mouseX)
    }
  }
}
