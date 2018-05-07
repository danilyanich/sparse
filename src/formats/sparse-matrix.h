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


  virtual ValueType& get(int rowIndex, int columnIndex)
  {
  }


  virtual void set(int rowIndex, int columnIndex, ValueType value)
  {
  }


  void increaseNonZeroNumber() {
    this->numberNonZero += 1;
  }


  void verbose () {
    for (int columnIndex = 0; columnIndex < this->columnSize; columnIndex += 1) 
    {
      for (int rowIndex = 0; rowIndex < this->rowSize; rowIndex += 1) 
      {
        std::cout << this->get(rowIndex, columnIndex) << ' ';
      }
      std::cout << std::endl;
    }
  }


  virtual ~SparseMatrix () 
  {
  }

};
