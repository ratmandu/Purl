#ifndef PATTERNGRID_H
#define PATTERNGRID_H

#include <QQuickItem>
#include <QQuickPaintedItem>
#include <QGraphicsItem>
#include <QPainter>
#include <QWidget>

class PatternGrid : public QQuickPaintedItem
{
  Q_OBJECT
  Q_PROPERTY(int rows READ rows WRITE setRows NOTIFY rowsChanged)
  Q_PROPERTY(int columns READ columns WRITE setColumns NOTIFY columnsChanged)
  Q_PROPERTY(int cellWidth READ cellWidth WRITE setCellWidth NOTIFY cellWidthChanged)
  Q_PROPERTY(int cellHeight READ cellHeight WRITE setCellHeight NOTIFY cellHeightChanged)
  Q_PROPERTY(int leftMargin READ leftMargin WRITE setLeftMargin NOTIFY leftMarginChanged)
  Q_PROPERTY(int topMargin READ topMargin WRITE setTopMargin NOTIFY topMarginChanged)

  int m_rows;
  int m_columns;
  int m_cellWidth;
  int m_cellHeight;
  int m_topMargin;
  int m_leftMargin;

public:
  explicit PatternGrid(QQuickItem *parent = 0);
  void paint(QPainter *painter);

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

signals:
  void rowsChanged(int arg);
  void columnsChanged(int arg);
  void cellWidthChanged(int arg);
  void cellHeightChanged(int arg);
  void topMarginChanged(int arg);
  void leftMarginChanged(int arg);

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
};

QML_DECLARE_TYPE(PatternGrid)

#endif // PATTERNGRID_H
