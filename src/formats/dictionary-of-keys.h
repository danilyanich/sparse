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


  DOKMatrix (int rowsCount, int columnsCount) :
    SparseMatrix<ValueType>(rowsCount, columnsCount)
  {
  }


  void set(int indexInRow, int indexInColumn, ValueType value)
  {
    if (value == 0) return;

    this->increaseNonZeroNumber();
    PairType key = PairType(indexInRow, indexInColumn);
    this->dictionary[key] = value;
  }


  ValueType get(int indexInRow, int indexInColumn) {
    PairType key = PairType(indexInRow, indexInColumn);
    const auto& found = this->dictionary.find(key);

    if (found != this->dictionary.end())
    {
      return found->second;
    }

    return 0;
  }


  void verbose()
  {
    std::cout << "dictionary:" << std::endl;

    for (auto& pair : this->dictionary)
    {
      const PairType& indices = pair.first;
      const ValueType& value = pair.second;

      std::cout
        << " - <" << indices.first
        << "," << indices.second << "> : "
        << value << std::endl;
    }

    const int size = sizeof(DictionaryType) * this->dictionary.size();
    std::cout << "size: " << size / 1000 << "kb" << std::endl;
  }


  ~DOKMatrix ()
  {
  }

};
