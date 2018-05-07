#pragma once

#include <vector>
#include <map>
#include <utility>

#include "sparse-matrix.h"


template <class ValueType>
class LILMatrix : public SparseMatrix<ValueType>
{

public:
  typedef std::pair<int, ValueType> PairType;
  typedef std::map<int, ValueType> RowType;
  typedef std::vector<RowType> RowListType;


  RowListType rowList;


  LILMatrix (int rowSize, int columnSize) :
    SparseMatrix<ValueType>(rowSize, columnSize),
    rowList(columnSize)
  {
  }


  void set(int rowIndex, int columnIndex, ValueType value)
  {
    if (value == 0) return;

    this->increaseNonZeroNumber();
    RowType& row = this->rowList[rowIndex];
    row[columnIndex] = value;
  }


  ValueType& get(int rowIndex, int columnIndex) {
    RowType row = this->rowList[rowIndex];
    ValueType& found = row[columnIndex]; 

    return found;
  }


  ~LILMatrix () 
  {
  }

};
