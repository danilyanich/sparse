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


  void set(int indexInRow, int indexInColumn, ValueType value)
  {
    if (value == 0) return;

    this->increaseNonZeroNumber();
    PairType key = PairType(indexInRow, indexInColumn);
    this->dictionary[key] = value;
  }


  ValueType& get(int indexInRow, int indexInColumn) {
    PairType key = PairType(indexInRow, indexInColumn);
    ValueType& found = this->dictionary[key];

    return found;
  }


  ~DOKMatrix ()
  {
  }

};
