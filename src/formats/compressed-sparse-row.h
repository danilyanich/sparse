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
  IndicesListType columnIndices;


  CSRMatrix (SparseMatrix<ValueType>& matrix) :
    SparseMatrix<ValueType>(matrix)
  {
    this->rowsOffset.push_back(0);

    for (int indexInColumn = 0; indexInColumn < this->columnSize; indexInColumn += 1)
    {
      for (int indexInRow = 0; indexInRow < this->rowSize; indexInRow += 1)
      {
        ValueType& element = matrix.get(indexInRow, indexInColumn);
        
        if (element != 0) 
        {
          this->elements.push_back(element);
          this->columnIndices.push_back(indexInColumn);
        }
      }
      
      if (this->elements.size() <= matrix.numberNonZero)
      {
        int offset = this->elements.size();
        this->rowsOffset.push_back(offset);
      }
      else
      {
        break;
      }
    }
  }


  ValueType& get(int indexInRow, int indexInColumn) {
    int begin = this->rowsOffset[indexInColumn];
    int end = this->rowsOffset[indexInColumn + 1];

    std::cout << std::endl << std::endl
      << "indexInRow: " << indexInRow << std::endl
      << "indexInColumn: " << indexInColumn << std::endl
      << "begin: " << begin << std::endl
      << "end: " << end << std::endl;

    for (int index = begin; index <= end; index++)
    {
      int elementIndexInColumn = this->columnIndices[index];

      std::cout << "elementIndexInColumn: " << elementIndexInColumn << " | " << index << std::endl;
      
      if (elementIndexInColumn == indexInColumn)
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
    for (auto& value : this->columnIndices) 
    {
      std::cout << value << ' ';
    }
    std::cout << std::endl;
    this->SparseMatrix<ValueType>::verbose();
  }


  ~CSRMatrix () 
  {
  }

};
