#ifndef _MATRIX4x4_H
#define _MATRIX4x4_H
#include <iostream>
#include "Vector4D.h"

//====================================================
class Matrix4x4 {

  Vector4D matrix[4];

public:

  //constructeurs
  Matrix4x4();
  Matrix4x4(const Matrix4x4 &mat);
  //opérateurs
  Vector4D& operator[](const unsigned int i);
  const Vector4D& operator[](const unsigned int i) const;
  void operator*=(const Matrix4x4 &mat);
  //fonctions membres
  void ident();
  void fill(const double d);
  void rotX(const double alpha);
  void rotZ(const double alpha);
  void projection(const double f, const double d);
};

std::ostream& operator<<(std::ostream &os, const Matrix4x4 &mat);
Matrix4x4 operator*(const Matrix4x4 &mat1,const Matrix4x4 &mat2 );

#endif
