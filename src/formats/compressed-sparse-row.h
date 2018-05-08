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
  IndicesListType rowsOffset;
  IndicesListType indicesInRow;


  CSRMatrix (SparseMatrix<ValueType>& matrix) :
    SparseMatrix<ValueType>(matrix)
  {
    this->rowsOffset.push_back(0);

    for (int indexInColumn = 0; indexInColumn < this->columnSize; indexInColumn += 1)
    {
      for (int indexInRow = 0; indexInRow < this->rowSize; indexInRow += 1)
      {
        const ValueType& element = matrix.get(indexInRow, indexInColumn);

        if (element != 0)
        {
          this->elements.push_back(element);
          this->indicesInRow.push_back(indexInRow);
        }
      }

      if (this->elements.size() <= matrix.numberNonZero)
      {
        const int offset = this->elements.size();
        this->rowsOffset.push_back(offset);
      }
      else
      {
        break;
      }
    }
  }


  ValueType& get(int indexInRow, int indexInColumn) {
    const int begin = this->rowsOffset[indexInColumn];
    const int end = this->rowsOffset[indexInColumn + 1];

    for (int index = begin; index < end; index++)
    {
      const int elementIndexInRow = this->indicesInRow[index];

      if (elementIndexInRow == indexInRow)
      {
        return this->elements[index];
      }
    }

    return *(new ValueType());
  }


  void verbose () {
    std::cout << "AA: ";
    for (auto& value : this->elements)
    {
      std::cout << value << ' ';
    }
    std::cout << std::endl;
    std::cout << "AI: ";
    for (auto& value : this->rowsOffset)
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
      (this->rowsOffset.size() + this->indicesInRow.size()) * sizeof(int);
    std::cout << "size: " << size << "kb" << std::endl;
  }


  ~CSRMatrix ()
  {
  }

};
