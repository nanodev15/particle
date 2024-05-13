
#ifndef _MATRIX4x4_H
#define _MATRIX4x4_H
#include <iostream>
#include "Vector4D.h"

//====================================================
class Matrix4x4 {

public:

  //opérateurs
  Vector4D& operator[](const unsigned int i);
  const Vector4D& operator[](const unsigned int i) const;
  Matrix4x4& operator*=(const Matrix4x4 &mat);
  //fonctions membres
  void ident();
  void fill(const float d);
  void rotX(const float alpha);
  void rotY(const float alpha);
  void rotZ(const float alpha);
  void projection(const float f, const float d);

 private :
  Vector4D matrix[4];
};

std::ostream& operator<<(std::ostream &os, const Matrix4x4 &mat);
Matrix4x4 operator*(const Matrix4x4 &mat1,const Matrix4x4 &mat2 );

#endif
