#pragma once

#include <iostream>


template <class ValueType>
class SparseMatrix
{

public:

  int rowSize;
  int columnSize;
  int numberNonZero = 0;


  SparseMatrix (int rowSize, int columnSize)
  {
    this->rowSize = rowSize;
    this->columnSize = columnSize;
  }


  virtual ValueType& get (int indexInRow, int indexInColumn)
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
    for (int indexInRow = 0; indexInRow < this->rowSize; indexInRow += 1)
    {
      for (int indexInColumn = 0; indexInColumn < this->columnSize; indexInColumn += 1)
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
