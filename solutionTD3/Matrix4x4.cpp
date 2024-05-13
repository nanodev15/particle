
#include "Matrix4x4.h"
#include <cmath>

Vector4D& Matrix4x4::operator[](const unsigned int i) {
  return matrix[i];
}
const Vector4D& Matrix4x4::operator[](const unsigned int i) const {
  return matrix[i];
}
//===================================================
Matrix4x4& Matrix4x4::operator*=(const Matrix4x4 &mat) {
  Matrix4x4 tmpMat(*this);
  fill(0);
  for (int i=0; i<4; ++i)
    for (int j=0; j<4; ++j)
      for (int k=0; k<4; ++k)
	matrix[i][j] += tmpMat[k][i]*mat[j][k];
return *this;

}
//===================================================
//fonctions membres
void Matrix4x4::ident() {
  for (int i=0; i<4; ++i)
    for (int j=0; j<4; ++j)
      matrix[i][j] = (i==j ? 1 : 0);
}
void Matrix4x4::fill(const float d) {
  for (int i=0; i<4; ++i)
    for (int j=0; j<4; ++j)
      matrix[i][j] = d;
}
void Matrix4x4::rotY(const float alpha) {
  ident();
  float cosAlpha = cos(alpha);
  float sinAlpha = sin(alpha);
  matrix[0][0] =  cosAlpha;
  matrix[2][2] =  cosAlpha;
  matrix[0][2] =  sinAlpha;
  matrix[2][0] = -sinAlpha;
}
void Matrix4x4::rotX(const float alpha) {
  ident();
  float cosAlpha = cos(alpha);
  float sinAlpha = sin(alpha);
  matrix[1][1] =  cosAlpha;
  matrix[2][2] =  cosAlpha;
  matrix[1][2] =  sinAlpha;
  matrix[2][1] = -sinAlpha;
}
void Matrix4x4::rotZ(const float alpha) {
  ident();
  float cosAlpha = cos(alpha);
  float sinAlpha = sin(alpha);
  matrix[0][0] =  cosAlpha;
  matrix[1][1] =  cosAlpha;
  matrix[0][1] =  sinAlpha;
  matrix[1][0] = -sinAlpha;
}
void Matrix4x4::projection(const float f, float d) {
  ident();
  matrix[0][0] = f;
  matrix[1][1] = f;
  matrix[2][2] = 1;
  matrix[2][3] = 1;
  matrix[3][3] = d;
}
std::ostream& operator<<(std::ostream &os, const Matrix4x4 &mat) {
  for (int i=0;i<4;++i) {
    os << "|" ;
    for (int j=0;j<4;++j)
      os << mat[i][j] << "\t";
    os << "|" << std::endl;
  }
  return os;
}
Matrix4x4 operator*(const Matrix4x4 &mat1,const Matrix4x4 &mat2 ) {
  Matrix4x4 tmpMat(mat1);
  tmpMat *= mat2;
  return tmpMat;
}
