
#include <cassert>
#include "Vector4D.h"
#include "Matrix4x4.h"
//====================================================
//Constructeurs de copie
Vector4D::Vector4D(const Vector4D &vecto) {
  for (unsigned int i=0;i<4;++i)
    vect[i] = vecto[i];
}
//====================================================
//Constructeurs d'initialisation
Vector4D::Vector4D(const double x, const double y, const double z, const double w) {
  vect[0] = x;
  vect[1] = y;
  vect[2] = z;
  vect[3] = w;
}
//====================================================
//Accesseurs constant
double Vector4D::operator[](unsigned int i) const {
  assert(i<4);
  return vect[i];
}
//====================================================
//Accesseurs de modification
double& Vector4D::operator[](unsigned int i) {
  assert(i<4);
  return vect[i];
}
//====================================================
//operators
Vector4D& Vector4D::operator*=(const Matrix4x4 &matrix) {
  Vector4D vectTmp;
  for (unsigned int j=0;j<4;++j)
    vectTmp[j] = vect[0]*matrix[0][j] +
      vect[1]*matrix[1][j] +
      vect[2]*matrix[2][j] +
      vect[3]*matrix[3][j];
  for (unsigned int j=0;j<4;++j)
    vect[j] = vectTmp[j];
  return *this;
}
//====================================================
Vector4D& Vector4D::operator*=(const double scalaire) {
  for (unsigned int i=0;i<4;++i)
    vect[i] *= scalaire;
  return *this;
}
//====================================================
Vector4D& Vector4D::operator+=(const Vector4D &vecto) {
  for (unsigned int i=0;i<4;++i)
    vect[i] += vecto[i];
  return *this;
}
//====================================================
Vector4D& Vector4D::operator-=(const Vector4D &vecto) {
  for (unsigned int i=0;i<4;++i)
    vect[i] -= vecto[i];
  return *this;
}

//Opérateurs externes
std::ostream& operator<<(std::ostream &os,const Vector4D &vect) {
  os << "[" << vect[0] << "," <<  vect[1] <<  "," <<  vect[2] <<  "," <<  vect[3] << "]";
  return os;
}
Vector4D operator+(const Vector4D &v1,const Vector4D &v2) {
  return Vector4D(v1[0]+v2[0], v1[1]+v2[1], v1[2]+v2[2], v1[3]+v2[3]);
}
Vector4D operator-(const Vector4D &v1,const Vector4D &v2) {
  return ((-1 * v2) + v1);
}
Vector4D operator*(const Vector4D &v1,const double scalaire) {
  return Vector4D(v1[0]*scalaire, v1[1]*scalaire, v1[2]*scalaire, v1[3]*scalaire);
}
Vector4D operator*(const double scalaire, const Vector4D &v1) {
  return (v1*scalaire);
}
Vector4D operator*(const Vector4D &v1, const Matrix4x4 &matrix) {
  return Vector4D(v1) *= matrix;
}
