#include "patterngrid.h"

PatternGrid::PatternGrid(QQuickItem *parent) :
  QQuickPaintedItem(parent)
{
  // need to set the ItemHasNoContents flas to false so the Paint() method gets called
//  setFlag(QQuickPaintedItem::ItemHasContents, true);
}

void PatternGrid::paint(QPainter *painter)
{
  QBrush brush(Qt::black);

  // Check to see if we are supposed to draw smoothly, if so, turn on antialiasing
  if (smooth() == true) {
    painter->setRenderHint(QPainter::Antialiasing, true);
  }
  painter->setBrush(brush);

  //
}
