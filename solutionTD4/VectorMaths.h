
#ifndef _VECTORMATHS_H
#define _VECTORMATHS_H
#include <cassert>
#include <iostream>
#include "Vector.h"

template <typename Obj,unsigned int SIZE>
class VectorMaths:public Vector<Obj,SIZE> {
 public:
  VectorMaths<Obj,SIZE>& operator*=(const float scalaire);
  VectorMaths<Obj,SIZE>& operator+=(const Vector<Obj,SIZE> &vecto);
  VectorMaths<Obj,SIZE>& operator-=(const Vector<Obj,SIZE> &vecto);
  void fill(Obj obj);
};

//Opérateurs externes
template <typename Obj,unsigned int SIZE>
std::ostream& operator<<(std::ostream &os, const Vector<Obj,SIZE> &vect);

template <typename Obj,unsigned int SIZE>
Vector<Obj,SIZE> operator+(const Vector<Obj,SIZE>&v1, const Vector<Obj,SIZE>&v2);

template <typename Obj,unsigned int SIZE>
VectorMaths<Obj,SIZE> operator-(const VectorMaths<Obj,SIZE>&v1, const VectorMaths<Obj,SIZE>&v2);

template <typename Obj,unsigned int SIZE>
VectorMaths<Obj,SIZE> operator*(const VectorMaths<Obj,SIZE>&v1, const Obj& scalaire);

template <typename Obj,unsigned int SIZE>
Obj operator*(const VectorMaths<Obj,SIZE>&v1, const VectorMaths<Obj,SIZE>&v2);

template <typename Obj,unsigned int SIZE>
VectorMaths<Obj,SIZE> operator*(const Obj &scalaire, const VectorMaths<Obj,SIZE>&v1);

#include "VectorMaths.cxx"

#endif
