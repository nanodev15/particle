
#include <cassert>
#include "Vector4D.h"
#include "Matrix4x4.h"

//====================================================
//Constructeurs d'initialisation
Vector4D::Vector4D(const float x, const float y, const float z, const float w) {
  vect[0] = x;
  vect[1] = y; 
  vect[2] = z;
  vect[3] = w;
}
//====================================================
//Accesseurs constant
float Vector4D::operator[](int i) const {
  assert(i<4);
  return vect[i];
}
//====================================================
//Accesseurs de modification
float& Vector4D::operator[](int i) {
  assert(i<4);
  return vect[i];
}
//====================================================
//operators
Vector4D& Vector4D::operator*=(const float scalaire) {
  for (int i=0;i<4;++i)
    vect[i] *= scalaire;
  return *this;
}
//====================================================
Vector4D& Vector4D::operator+=(const Vector4D &vecto) {
  for (int i=0;i<4;++i)
    vect[i] += vecto[i];
  return *this;
}
//====================================================
Vector4D& Vector4D::operator-=(const Vector4D &vecto) {
  for (int i=0;i<4;++i)
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
  return ((-1.0 * v2) + v1);
}
Vector4D operator*(const Vector4D &v1,const float scalaire) { 
  return Vector4D(v1[0]*scalaire, v1[1]*scalaire, v1[2]*scalaire, v1[3]*scalaire);
}
Vector4D operator*(const float scalaire, const Vector4D &v1) { 
  return (v1*scalaire);
}
Vector4D operator*(const Matrix4x4 &matrix, const Vector4D &v1) {   
  Vector4D vectTmp;
  for (int j=0;j<4;++j)
    vectTmp[j] = 
      v1[0]*matrix[j][0] + 
      v1[1]*matrix[j][1] +
      v1[2]*matrix[j][2] +
      v1[3]*matrix[j][3];
  return vectTmp;
}
