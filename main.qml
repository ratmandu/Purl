import QtQuick 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Controls 1.1

ApplicationWindow {
    visible: true
    width: 1280
    height: 1024
    title: qsTr("Purl")

    menuBar: PurlMenuBar {}
    toolBar: PurlToolbar {}

    FileDialog {
      id: fileDialog
    }

    Action {
      id: openAction
      text: "&Open"
      shortcut: StandardKey.Open
      iconName: "edit-open"
      onTriggered: fileDialog.open()
      tooltip: "Open an image"
    }

}
