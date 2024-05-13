#ifndef _MATRIX_H
#define _MATRIX_H
#include "Vector.h"

template<typename Obj,int SIZE>
class Matrix:public Vector<Vector<Obj,SIZE>,SIZE> {
};
#endif
