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
      id: patternGrid
      anchors.fill: parent
    }
  }
}
