#ifndef PATTERNGRID_H
#define PATTERNGRID_H

#include <QQuickItem>
#include <QGraphicsItem>
#include <QPainter>
#include <QWidget>

class PatternGrid : public QQuickItem
{
  Q_OBJECT
  Q_PROPERTY(int rows READ rows WRITE setRows NOTIFY rowsChanged)
  Q_PROPERTY(int columns READ columns WRITE setColumns NOTIFY columnsChanged)
  Q_PROPERTY(int cellWidth READ cellWidth WRITE setCellWidth NOTIFY cellWidthChanged)
  Q_PROPERTY(int cellHeight READ cellHeight WRITE setCellHeight NOTIFY cellHeightChanged)
  int m_rows;

  int m_columns;

int m_cellWidth;

int m_cellHeight;

public:
  explicit PatternGrid(QQuickItem *parent = 0);
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

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

signals:

void rowsChanged(int arg);

void columnsChanged(int arg);

void cellWidthChanged(int arg);

void cellHeightChanged(int arg);

public slots:

void setRows(int arg)
{
  if (m_rows != arg) {
    m_rows = arg;
    emit rowsChanged(arg);
  }
}
void setColumns(int arg)
{
  if (m_columns != arg) {
    m_columns = arg;
    emit columnsChanged(arg);
  }
}
void setCellWidth(int arg)
{
  if (m_cellWidth != arg) {
    m_cellWidth = arg;
    emit cellWidthChanged(arg);
  }
}
void setCellHeight(int arg)
{
  if (m_cellHeight != arg) {
    m_cellHeight = arg;
    emit cellHeightChanged(arg);
  }
}
};

QML_DECLARE_TYPE(PatternGrid)

#endif // PATTERNGRID_H
