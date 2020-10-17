#ifndef SPARESMATRIX_H
#define SPARESMATRIX_H
#include <vector>
using namespace std;

class SpareSpatrix;

class TempMark{
  friend class SpareSpatrix;
  private:
    int rowSize;
    int rowStart;
};

class MatrixTerm{
  friend class SpareSpatrix;
  private:
    int row, col, val;
};

class SpareSpatrix{
  private:
    int rows, cols, terms, capacity;
    MatrixTerm* smArray;

  public:
    SpareSpatrix(int rows, int cols, int terms) {
      this->rows = rows;
      this->cols = cols;
      this->terms = terms;
    }
    SpareSpatrix FastTranspose();
};

SpareSpatrix SpareSpatrix::FastTranspose(){
  SpareSpatrix b(cols, rows, terms);
  if(terms > 0) {
    vector<TempMark> MarkRow;
    MarkRow.resize(cols);


    for(int i = 0; i < terms; i++) {
      MarkRow[smArray[i].col].rowSize++;
    }

    MarkRow[0].rowStart = 0;
    for(int i = 1; i < cols; i++) {
      MarkRow[i].rowStart = MarkRow[i-1].rowStart + MarkRow[i-1].rowSize;
    }

    for(int i = 0; i < terms; i++) {
      int j = MarkRow[smArray[i].col].rowStart;
      b.smArray[j].row = smArray[i].col;
      b.smArray[j].col = smArray[i].row;
      b.smArray[j].val = smArray[i].val;
      MarkRow[smArray[i].col].rowStart++;
    }

  }
  return b;
};
#endif
