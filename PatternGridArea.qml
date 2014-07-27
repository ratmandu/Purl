import QtQuick 2.0
import PatternGrid 1.0

Rectangle {
  PatternGridToolbar {
    id: toolBar
  }

  PatternGrid {
    id: patternGrid
    anchors.fill: parent
  }
}
