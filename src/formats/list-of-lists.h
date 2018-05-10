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


  RowListType rowsList;


  LILMatrix (int rowsCount, int columnsCount) :
    SparseMatrix<ValueType>(rowsCount, columnsCount),
    rowsList(rowsCount)
  {
  }


  void set(int indexInRow, int indexInColumn, ValueType value)
  {
    if (value == 0) return;

    this->increaseNonZeroNumber();
    RowType& row = this->rowsList[indexInRow];
    row[indexInColumn] = value;
  }


  ValueType get(int indexInRow, int indexInColumn) {
    RowType row = this->rowsList[indexInRow];
    const auto& found = row.find(indexInColumn);

    if (found != row.end())
    {
      return found->second;
    }

    return 0;
  }

  void verbose()
  {
    int size = 0;

    size += sizeof(RowType) * this->rowsList.size();
    std::cout << "rows:" << std::endl;
    for (auto& map : this->rowsList)
    {

      size += sizeof(PairType) * map.size();

      std::cout << " - ";
      for (auto& value : map)
      {
        std::cout << "<" << value.first << "," << value.second << "> ";
      }
      std::cout << std::endl;
    }

    std::cout << "size: " << size / 1000 << "kb" << std::endl;
  }


  ~LILMatrix ()
  {
  }

};
