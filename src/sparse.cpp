#include <iostream>
#include <cmath>

#include "formats/sparse-matrix.h"
#include "formats/dictionary-of-keys.h"
#include "formats/list-of-lists.h"
#include "formats/compressed-sparse-row.h"

int main (int argc, char *argv[])
{
  int columnCount = 0;
  int rowsCount = 0;
  int numberNonZero = 0;

  std::cin >> rowsCount >> columnCount >> numberNonZero;

  std::cout
    << "rows: " << rowsCount << " "
    << "columns: " << columnCount << " "
    << "nnz: " << numberNonZero << std::endl;

  auto matrix = new LILMatrix<double>(rowsCount, columnCount);

  for (int index = 0; index < numberNonZero; index += 1)
  {
    double real = 0;
    double imaginary = 0;

    int indexInRow = 0;
    int indexInColumn = 0;

    std::cin
      >> indexInRow >> indexInColumn
      >> real >> imaginary;

    matrix->set(indexInRow - 1, indexInColumn - 1, real);
  }

  std::cout << "Parsing complete. Converting to CSR." << std::endl;

  auto crsmatrix = new CSRMatrix<double>(*matrix);

  std::cout << "Conversion complete. Output verbose info:" << std::endl;

  matrix->verbose();
  crsmatrix->verbose();

  delete matrix;
  delete crsmatrix;
}
