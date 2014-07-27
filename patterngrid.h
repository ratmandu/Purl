#ifndef PATTERNGRID_H
#define PATTERNGRID_H

#include <QQuickPaintedItem>
#include <QGraphicsItem>
#include <QMouseEvent>
#include <QHoverEvent>
#include <QQuickItem>
#include <QPainter>
#include <QWidget>
#include <QDebug>

class PatternGrid : public QQuickPaintedItem
{
  Q_OBJECT
  Q_PROPERTY(int rows READ rows WRITE setRows NOTIFY rowsChanged)
  Q_PROPERTY(int columns READ columns WRITE setColumns NOTIFY columnsChanged)
  Q_PROPERTY(int cellWidth READ cellWidth WRITE setCellWidth NOTIFY cellWidthChanged)
  Q_PROPERTY(int cellHeight READ cellHeight WRITE setCellHeight NOTIFY cellHeightChanged)
  Q_PROPERTY(int leftMargin READ leftMargin WRITE setLeftMargin NOTIFY leftMarginChanged)
  Q_PROPERTY(int topMargin READ topMargin WRITE setTopMargin NOTIFY topMarginChanged)
  Q_PROPERTY(int mouseX READ mouseX WRITE setMouseX NOTIFY mouseXChanged)
  Q_PROPERTY(int mouseY READ mouseY WRITE setMouseY NOTIFY mouseYChanged)

  int m_rows;
  int m_columns;
  int m_cellWidth;
  int m_cellHeight;
  int m_topMargin;
  int m_leftMargin;
  int m_mouseX;
  int m_mouseY;

public:
  explicit PatternGrid(QQuickItem *parent = 0);
  void paint(QPainter *painter);
  void mouseMoveEvent(QMouseEvent *e);
  void mousePressEvent(QMouseEvent *e);
  void hoverMoveEvent(QHoverEvent *e);

  int rows() const
  {
    return m_rows;
  }

  int columns() const
  {
    return m_columns;
  }

  int cellWidth() const
  {
    return m_cellWidth;
  }

  int cellHeight() const
  {
    return m_cellHeight;
  }

  int topMargin() const
  {
    return m_topMargin;
  }

  int leftMargin() const
  {
    return m_leftMargin;
  }

  int mouseX() const
  {
    return m_mouseX;
  }

  int mouseY() const
  {
    return m_mouseY;
  }

signals:
  void rowsChanged(int arg);
  void columnsChanged(int arg);
  void cellWidthChanged(int arg);
  void cellHeightChanged(int arg);
  void topMarginChanged(int arg);
  void leftMarginChanged(int arg);

  void mouseXChanged(int arg);

  void mouseYChanged(int arg);

public slots:

  void setRows(int arg)
  {
    if (m_rows != arg) {
      m_rows = arg;
      emit rowsChanged(arg);
      update();
    }
  }
  void setColumns(int arg)
  {
    if (m_columns != arg) {
      m_columns = arg;
      emit columnsChanged(arg);
      update();
    }
  }
  void setCellWidth(int arg)
  {
    if (m_cellWidth != arg) {
      m_cellWidth = arg;
      emit cellWidthChanged(arg);
      update();
    }
  }
  void setCellHeight(int arg)
  {
    if (m_cellHeight != arg) {
      m_cellHeight = arg;
      emit cellHeightChanged(arg);
      update();
    }
  }
  void setTopMargin(int arg)
  {
    if (m_topMargin != arg) {
      m_topMargin = arg;
      emit topMarginChanged(arg);
      update();
    }
  }
  void setLeftMargin(int arg)
  {
    if (m_leftMargin != arg) {
      m_leftMargin = arg;
      emit leftMarginChanged(arg);
      update();
    }
  }
  void setMouseX(int arg)
  {
    if (m_mouseX != arg) {
      m_mouseX = arg;
      emit mouseXChanged(arg);
      update();
    }
  }
  void setMouseY(int arg)
  {
    if (m_mouseY != arg) {
      m_mouseY = arg;
      emit mouseYChanged(arg);
      update();
    }
  }
};

QML_DECLARE_TYPE(PatternGrid)

#endif // PATTERNGRID_H
