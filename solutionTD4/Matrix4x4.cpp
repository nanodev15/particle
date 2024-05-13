
#include <cmath>
#include "Matrix4x4.h"

void Matrix4x4::ident() {
  for (unsigned int i=0; i<4; ++i)
    for (unsigned int j=0; j<4; ++j)
      (*this)[i][j]=(i==j ? 1 : 0);
}

void Matrix4x4::scale(float sx,float sy,float sz) {
  ident();
  (*this)[0][0] = sx;
  (*this)[1][1] = sy;
  (*this)[2][2] = sz;
}

void Matrix4x4::rotX(const float alpha) {
  ident();
  float cosAlpha = cos(alpha);
  float sinAlpha = sin(alpha);
  (*this)[1][1] =  cosAlpha;
  (*this)[2][2] =  cosAlpha;
  (*this)[1][2] =  sinAlpha;
  (*this)[2][1] = -sinAlpha;
}

void Matrix4x4::rotZ(const float alpha) {
  ident();
  float cosAlpha =  cos(alpha);
  float sinAlpha =  sin(alpha);
  (*this)[0][0]  =  cosAlpha;
  (*this)[1][1]  =  cosAlpha;
  (*this)[0][1]  =  sinAlpha;
  (*this)[1][0]  = -sinAlpha;
}

void Matrix4x4::rotY(const float alpha) {
  ident();
  float cosAlpha = cos(alpha);
  float sinAlpha = sin(alpha);
  (*this)[0][0]=cosAlpha;
  (*this)[2][2]=cosAlpha;
  (*this)[0][2]=sinAlpha;
  (*this)[2][0]=-sinAlpha;
}

void Matrix4x4::projection(const float f, const float d) {
  ident();
  (*this)[0][0] = f;
  (*this)[1][1] = f;
  (*this)[2][2] = 1;
  (*this)[2][3] = 1;
  (*this)[3][3] = d;
}

//====================================================================
Vector4D operator*(const Matrix4x4 &matrix, const Vector4D &v1) {
  Vector4D vectTmp;
  for (unsigned int j=0; j<4; ++j)
    vectTmp[j] =
      v1[0]*matrix[j][0] +
      v1[1]*matrix[j][1] +
      v1[2]*matrix[j][2] +
      v1[3]*matrix[j][3];
  return vectTmp;
}
