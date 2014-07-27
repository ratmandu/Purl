#include "patterngrid.h"

PatternGrid::PatternGrid(QQuickItem *parent) :
  QQuickItem(parent)
{
  // need to set the ItemHasNoContents flas to false so the Paint() method gets called
  setFlag(QGraphicsItem::ItemHasNoContents, false);
}

void PatternGrid::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
  if (smooth() == true) {
    painter->setRenderHint(QPainter::Antialiasing, true);
  }

  painter->drawEllipse(widget->rect()/2, 50, 50);

}
