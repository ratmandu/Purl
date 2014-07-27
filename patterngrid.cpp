#include "patterngrid.h"

PatternGrid::PatternGrid(QQuickItem *parent) :
  QQuickPaintedItem(parent),
  m_cellWidth(50),
  m_rows(5),
  m_cellHeight(50),
  m_columns(10),
  m_topMargin(25),
  m_leftMargin(25)
{
  // need to set the ItemHasNoContents flas to false so the Paint() method gets called
//  setFlag(QQuickPaintedItem::ItemHasContents, true);
}

void PatternGrid::paint(QPainter *painter)
{
  // We want a black brush
  QBrush brush(Qt::black);

  // 1 pixel wide black pen
  QPen pen(brush, 1);

  // set the pen as current
  painter->setPen(pen);

  // Check to see if we are supposed to draw smoothly, if so, turn on antialiasing
  if (smooth() == true) {
    painter->setRenderHint(QPainter::Antialiasing, true);
  }

  // Lets draw the grid
  for (int i = 0; i < rows(); i++) {
    for (int j = 0; j < columns(); j++) {
      painter->drawRect((j * cellWidth()) + leftMargin(), (i * cellHeight()) + topMargin(), cellWidth(), cellHeight());
    }
  }

  // now we'll draw the row and column numbers
  int r = rows();
  int c = columns();

  for (int i = 0; i < columns(); i++) {
    int x = ((i * cellWidth())) + leftMargin();
    int y = ((rows() * cellHeight())) + topMargin();

    painter->drawText(QRect(x, y, cellWidth(), cellHeight()), Qt::AlignCenter, QString::number(c--));

//    painter->drawText(((i * cellWidth()) + cellWidth()/2) + leftMargin() - 5, ((rows() * cellHeight()) + 20) + topMargin(), QString::number(c--));
  }

  for (int i = 0; i < rows(); i++) {
    int x = (columns() * cellWidth()) + leftMargin();
    int y = (i * cellHeight()) + topMargin();

    painter->drawText(QRect(x, y, cellWidth(), cellHeight()), Qt::AlignCenter, QString::number(r--));
//    painter->drawText(((columns() * cellWidth()) + cellWidth()/2) + leftMargin(), ((i * cellHeight()) + cellHeight()/2) + topMargin() + 5, QString::number(r--));
  }
}
