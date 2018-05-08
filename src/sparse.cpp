#include <iostream>
#include <cmath>

#include "formats/sparse-matrix.h"
#include "formats/dictionary-of-keys.h"
#include "formats/list-of-lists.h"
#include "formats/compressed-sparse-row.h"

int main (int argc, char *argv[])
{
  int columnSize = 0;
  int rowSize = 0;

  std::cin >> rowSize >> columnSize;

  LILMatrix<int>* matrix = new LILMatrix<int>(rowSize, columnSize);

  for (int rowIndex = 0; rowIndex < rowSize; rowIndex += 1)
  {
    for (int columnIndex = 0; columnIndex < columnSize; columnIndex += 1)
    {
      int value = 0;
      std::cin >> value;
      matrix->set(rowIndex, columnIndex, value);
    }
  }


  CSRMatrix<int>* crsmatrix = new CSRMatrix<int>(*matrix);

  matrix->verbose();
  crsmatrix->verbose();

  crsmatrix->matrix();
}
