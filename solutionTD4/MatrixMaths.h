
#ifndef _MATRIXMATHS_H
#define _MATRIXMATHS_H
#include <cassert>
#include "VectorMaths.h"

template<typename Obj,unsigned int SIZE>
class MatrixMaths:public VectorMaths<VectorMaths<Obj,SIZE>,SIZE>{
  public:
  void fill(Obj obj);
  MatrixMaths<Obj,SIZE> & operator*=(const MatrixMaths<Obj,SIZE> &mat);
};

template<typename Obj,unsigned int SIZE>
MatrixMaths<Obj,SIZE> operator*(const MatrixMaths<Obj,SIZE> &mat1,const MatrixMaths<Obj,SIZE> &mat2);

#include "MatrixMaths.cxx"
#endif

