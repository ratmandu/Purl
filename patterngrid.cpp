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
  setAcceptHoverEvents(true);
  setAcceptedMouseButtons(Qt::AllButtons);
}

void PatternGrid::paint(QPainter *painter)
{
  // set the mouse position
  QPoint mousePos(mouseX(), mouseY());

  // We want a black brush
  QBrush brush(Qt::black);

  // and a brush for highlighting current cell
  QBrush highlight(QColor(155, 189, 252, 128));
  QBrush greyBrush(QColor(0, 0, 0, 16));

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
    QRect rowRect(leftMargin(), (i * cellHeight()) + topMargin(), cellWidth() * columns(), cellHeight());
    for (int j = 0; j < columns(); j++) {
      int x = (j * cellWidth()) + leftMargin();
      int y = (i * cellHeight()) + topMargin();
      QRect columnRect((j * cellWidth()) + leftMargin(), topMargin(), cellWidth(), cellHeight() * rows());
      QRect rect(x, y, cellWidth(), cellHeight());
      if (rect.contains(mousePos)) {
        QBrush oldBrush = painter->brush();
        painter->setBrush(highlight);
        painter->drawRect(rect);
        painter->setBrush(oldBrush);
      } else if (rowRect.contains(mousePos) || columnRect.contains(mousePos)) {
        QBrush oldBrush = painter->brush();
        painter->setBrush(greyBrush);
        painter->drawRect(rect);
        painter->setBrush(oldBrush);
      } else {
        painter->drawRect(rect);
      }
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

void PatternGrid::mouseMoveEvent(QMouseEvent *e)
{
  setMouseX(e->x());
  setMouseY(e->y());
}

void PatternGrid::mousePressEvent(QMouseEvent *e)
{
  qDebug() << e->x() << e->y();
}

void PatternGrid::hoverMoveEvent(QHoverEvent *e)
{
  setMouseX(e->pos().x());
  setMouseY(e->pos().y());
}
