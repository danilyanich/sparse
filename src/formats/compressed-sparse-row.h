#pragma once

#include <vector>
#include <map>
#include <utility>
#include <iostream>


#include "sparse-matrix.h"


template <class ValueType>
class CSRMatrix : public SparseMatrix<ValueType>
{

public:
  typedef std::vector<int> IndicesListType;
  typedef std::vector<ValueType> ValuesListType;


  ValuesListType elements;
  IndicesListType offsetsInColumn;
  IndicesListType indicesInRow;


  CSRMatrix (SparseMatrix<ValueType>& matrix) :
    SparseMatrix<ValueType>(matrix)
  {
    this->offsetsInColumn.push_back(0);

    for (int indexInColumn = 0; indexInColumn < this->rowsCount; indexInColumn += 1)
    {
      for (int indexInRow = 0; indexInRow < this->columnsCount; indexInRow += 1)
      {
        const ValueType& element = matrix.get(indexInRow, indexInColumn);

        if (element != 0)
        {
          this->elements.push_back(element);
          this->indicesInRow.push_back(indexInRow);
        }
      }

      const int offset = this->elements.size();
      this->offsetsInColumn.push_back(offset);
    }
  }


  ValueType get(int indexInRow, int indexInColumn) {
    const int begin = this->offsetsInColumn[indexInColumn];
    const int end = this->offsetsInColumn[indexInColumn + 1];

    for (int index = begin; index < end; index++)
    {
      const int elementIndexInRow = this->indicesInRow[index];

      if (elementIndexInRow == indexInRow)
      {
        return this->elements[index];
      }
    }

    return 0;
  }


  void verbose () {
    std::cout << "AA: ";
    for (auto& value : this->elements)
    {
      std::cout << value << ' ';
    }
    std::cout << std::endl;
    std::cout << "AI: ";
    for (auto& value : this->offsetsInColumn)
    {
      std::cout << value << ' ';
    }
    std::cout << std::endl;
    std::cout << "AJ: ";
    for (auto& value : this->indicesInRow)
    {
      std::cout << value << ' ';
    }
    std::cout << std::endl;

    const int size = this->elements.size() * sizeof(ValueType) +
      (this->offsetsInColumn.size() + this->indicesInRow.size()) * sizeof(int);
    std::cout << "size: " << size / 1000 << "kb" << std::endl;
  }


  ~CSRMatrix ()
  {
  }

};
