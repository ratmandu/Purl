#include "patterngrid.h"

// quick function to use QHash with a QPoint as the key... assuming x < 4000
static uint qHash(const QPoint& p)
{
    return p.x() * 4000 + p.y();
}

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

  for (int i = 0; i < rows(); i++) {
    for (int j = 0; j < columns(); j++) {
      cells.insert(QPoint(j, i), new PatternGridObject(j, i));
      cells.value(QPoint(j, i))->setRect(QRect((j * cellWidth()) + leftMargin(), (i * cellWidth()) + topMargin(), cellWidth(), cellHeight()));
    }
  }
}

void PatternGrid::paint(QPainter *painter)
{
  // set the mouse position
  QPoint mousePos(mouseX(), mouseY());

  // We want a black brush
  QBrush brush(Qt::black);

  // and a brush for highlighting current cell
  QBrush highlight(QColor(155, 189, 252, 128));

  // and a brush for highlighting the current row and column
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
    // Rectangle holding the whole row, for row highlighting detection
    QRect rowRect(leftMargin(), (i * cellHeight()) + topMargin(), cellWidth() * columns(), cellHeight());
    for (int j = 0; j < columns(); j++) {
      QRect columnRect((j * cellWidth()) + leftMargin(), topMargin(), cellWidth(), cellHeight() * rows());
      if (cells.value(QPoint(j, i))->getRect().contains(mousePos)) {
        QBrush oldBrush = painter->brush();
        painter->setBrush(highlight);
        painter->drawRect(cells.value(QPoint(j, i))->getRect());
        painter->setBrush(oldBrush);
      } else if (rowRect.contains(mousePos) || columnRect.contains(mousePos)) {
        QBrush oldBrush = painter->brush();
        painter->setBrush(greyBrush);
        painter->drawRect(cells.value(QPoint(j, i))->getRect());
        painter->setBrush(oldBrush);
      } else {
        painter->drawRect(cells.value(QPoint(j, i))->getRect());
      }
    }
  }

  // now we'll draw the row and column numbers
  int r = rows();
  int c = columns();

  // Columns
  for (int i = 0; i < columns(); i++) {
    int x = ((i * cellWidth())) + leftMargin();
    int y = ((rows() * cellHeight())) + topMargin();

    painter->drawText(QRect(x, y, cellWidth(), cellHeight()), Qt::AlignCenter, QString::number(c--));
  }

  // Rows
  for (int i = 0; i < rows(); i++) {
    int x = (columns() * cellWidth()) + leftMargin();
    int y = (i * cellHeight()) + topMargin();

    painter->drawText(QRect(x, y, cellWidth(), cellHeight()), Qt::AlignCenter, QString::number(r--));
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

void PatternGrid::updatePatternGrid()
{
  for (int i = 0; i < rows(); i++) {
    for (int j = 0; j < columns(); j++) {
      if (!cells.contains(QPoint(j, i))) {
        cells.insert(QPoint(j, i), new PatternGridObject(j, i));
        cells.value(QPoint(j, i))->setRect(QRect((j * cellWidth()) + leftMargin(), (i * cellWidth()) + topMargin(), cellWidth(), cellHeight()));
      }
    }
  }
}

void PatternGrid::updatePatternCellSize()
{
  for (int i = 0; i < rows(); i++) {
    for (int j = 0; j < columns(); j++) {
      if (cells.contains(QPoint(j, i))) {
        QRect rect = cells.value(QPoint(j, i))->getRect();
        rect.setSize(QSize(cellWidth(), cellHeight()));
        rect.setTopLeft(QPoint((j * cellWidth()) + leftMargin(), (i * cellHeight()) + topMargin()));
        rect.setBottomRight(rect.topLeft() + QPoint(cellWidth(), cellHeight()));
        cells.value(QPoint(j, i))->setRect(rect);
      }
    }
  }
}
