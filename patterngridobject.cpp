#include "patterngridobject.h"

PatternGridObject::PatternGridObject(QObject *parent) :
  QObject(parent)
{
}

PatternGridObject::PatternGridObject(int cellColumn, int cellRow, QObject *parent)
{
  setColumn(cellColumn);
  setRow(cellRow);
}

QRect PatternGridObject::getRect() const
{
  return rect;
}

void PatternGridObject::setRect(const QRect &value)
{
  rect = value;
}
int PatternGridObject::getColumn() const
{
  return column;
}

void PatternGridObject::setColumn(int value)
{
  column = value;
}
int PatternGridObject::getRow() const
{
  return row;
}

void PatternGridObject::setRow(int value)
{
  row = value;
}
QColor PatternGridObject::getColor() const
{
  return color;
}

void PatternGridObject::setColor(const QColor &value)
{
  color = value;
}
int PatternGridObject::getSymbolNumber() const
{
  return symbolNumber;
}

void PatternGridObject::setSymbolNumber(int value)
{
  symbolNumber = value;
}





