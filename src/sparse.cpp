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

  SparseMatrix<int>* matrix = new LILMatrix<int>(rowSize, columnSize);

  for (int columnIndex = 0; columnIndex < columnSize; columnIndex += 1) 
  {
    for (int rowIndex = 0; rowIndex < rowSize; rowIndex += 1) 
    {
      int value = 0;
      std::cin >> value;
      matrix->set(rowIndex, columnIndex, value);
    }
  }

  CSRMatrix<int>* crsmatrix = new CSRMatrix<int>(*matrix);
  std::cout << "nnz: " << crsmatrix->numberNonZero << std::endl;

  crsmatrix->verbose();
}
