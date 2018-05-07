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
    int length = 0;

    for (int columnIndex = 0; columnIndex < this->columnSize; columnIndex += 1)
    {
      for (int rowIndex = 0; rowIndex < this->rowSize; rowIndex += 1)
      {
        ValueType& element = matrix.get(rowIndex, columnIndex);
        
        if (element != 0) 
        {
          this->elements.push_back(element);
          this->columnIndices.push_back(columnIndex);
        }
      }
      
      int offset = this->elements.size();
      if (offset != length)
      {
        this->rowsOffset.push_back(offset);
      }
      length = this->elements.size();
    }
  }


  ValueType& get(int rowIndex, int columnIndex) {
    // TODO: implement get method
    return this->elements[0];
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
