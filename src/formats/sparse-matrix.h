#pragma once

#include <iostream>


template <class ValueType>
class SparseMatrix
{

public:

  int rowsCount;
  int columnsCount;
  int numberNonZero = 0;


  SparseMatrix (int rowsCount, int columnCount)
  {
    this->rowsCount = rowsCount;
    this->columnsCount = columnCount;
  }


  virtual ValueType get (int indexInRow, int indexInColumn)
  {
  }


  virtual void set (int indexInRow, int indexInColumn, ValueType value)
  {
  }


  void increaseNonZeroNumber () {
    this->numberNonZero += 1;
  }


  virtual void verbose ()
  {
  }

  void matrix () {
    for (int indexInColumn = 0; indexInColumn < this->rowsCount; indexInColumn += 1)
    {
      for (int indexInRow = 0; indexInRow < this->columnsCount; indexInRow += 1)
      {
        std::cout << this->get(indexInRow, indexInColumn) << ' ';
      }
      std::cout << std::endl;
    }
  }


  virtual ~SparseMatrix ()
  {
  }

};
