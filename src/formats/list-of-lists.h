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
    rowList(rowSize)
  {
  }


  void set(int indexInRow, int indexInColumn, ValueType value)
  {
    if (value == 0) return;

    this->increaseNonZeroNumber();
    RowType& row = this->rowList[indexInRow];
    row[indexInColumn] = value;
  }


  ValueType& get(int indexInRow, int indexInColumn) {
    RowType row = this->rowList[indexInRow];
    ValueType& found = row[indexInColumn];

    return found;
  }

  void verbose()
  {
    int size = 0;

    size += sizeof(RowType) * this->rowList.size();
    std::cout << "rows:" << std::endl;
    for (auto& map : this->rowList)
    {

      size += sizeof(PairType) * map.size();

      std::cout << " - ";
      for (auto& value : map)
      {
        std::cout << "<" << value.first << "," << value.second << "> ";
      }
      std::cout << std::endl;
    }

    std::cout << "size: " << size << "kb" << std::endl;
  }


  ~LILMatrix ()
  {
  }

};
