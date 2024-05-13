
#ifndef _MATRIX4x4_H
#define _MATRIX4x4_H

#include <cassert>
#include "MatrixMaths.h"
#include "Vector4D.h"

class Matrix4x4:public MatrixMaths<float,4u>
{
  public:
  //fonctions membres
  Matrix4x4(const Matrix4x4 &v):MatrixMaths<float,4u>(v) {}
  Matrix4x4(const MatrixMaths<float,4> &v) : MatrixMaths<float,4u>(v) {}
  Matrix4x4() {}
  void ident();
  void scale(float sx,float sy,float sz);
  void rotX(const float alpha);
  void rotZ(const float alpha);
  void rotY(const float alpha);
  void projection(const float f, const float d);
};

Vector4D operator*(const Matrix4x4 &matrix, const Vector4D &v);

#endif



