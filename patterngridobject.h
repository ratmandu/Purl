#ifndef PATTERNGRIDOBJECT_H
#define PATTERNGRIDOBJECT_H

#include <QObject>
#include <QRect>

class PatternGridObject : public QObject
{
  Q_OBJECT
public:
  explicit PatternGridObject(QObject *parent = 0);

  QRect getRect() const;
  void setRect(const QRect &value);

  int getColumn() const;
  void setColumn(int value);

  int getRow() const;
  void setRow(int value);

  QColor getColor() const;
  void setColor(const QColor &value);

  int getSymbolNumber() const;
  void setSymbolNumber(int value);

private:
  QRect rect;
  int column;
  int row;
  QColor color;
  int symbolNumber;

signals:

public slots:

};

#endif // PATTERNGRIDOBJECT_H
