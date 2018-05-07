#pragma once

#include <map>
#include <utility>

#include "sparse-matrix.h"


template <class ValueType>
class DOKMatrix : public SparseMatrix<ValueType>
{

public:
  typedef std::pair<int, int> PairType;
  typedef std::map<PairType, ValueType> DictionaryType;


  DictionaryType dictionary;


  DOKMatrix (int rowSize, int columnSize) :
    SparseMatrix<ValueType>(rowSize, columnSize)
  {
  }


  void set(int rowIndex, int columnIndex, ValueType value)
  {
    if (value == 0) return;

    this->increaseNonZeroNumber();
    PairType key = PairType(rowIndex, columnIndex);
    this->dictionary[key] = value;
  }


  ValueType& get(int rowIndex, int columnIndex) {
    PairType key = PairType(rowIndex, columnIndex);
    ValueType& found = this->dictionary[key];

    return found;
  }


  ~DOKMatrix () 
  {
  }

};
