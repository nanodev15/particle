
#ifndef _VECTOR4D_H
#define _VECTOR4D_H

#include <iostream>

class Matrix4x4;

//====================================================
class Vector4D {
  friend std::ostream& operator<<(std::ostream&,const Vector4D&);
  friend Vector4D operator+(const Vector4D&,const Vector4D&);
  friend Vector4D operator-(const Vector4D&,const Vector4D&);
  friend Vector4D operator*(const float ,const Vector4D&);
  friend Vector4D operator*(const Vector4D&,const float);

 public:
  //Constructeurs
  explicit Vector4D(const float x = 0, const float y = 0, 
		    const float z = 0, const float w = 0);
  //Accesseurs
  float  operator[](int i) const;
  float& operator[](int i);
  //fonctions membres
  Vector4D& operator*=(const float scalaire);
  Vector4D& operator+=(const Vector4D &vecto);
  Vector4D& operator-=(const Vector4D &vecto);

 private:
  float vect[4];
};

//Opérateurs externes
std::ostream& operator<<(std::ostream &os,const Vector4D &vect);
Vector4D operator+(const Vector4D &v1,const Vector4D &v2);
Vector4D operator-(const Vector4D &v1,const Vector4D &v2);
Vector4D operator*(const Vector4D &v1,const float scalaire);
Vector4D operator*(const float scalaire, const Vector4D &v1);
Vector4D operator*(const Matrix4x4 &matrix, const Vector4D &v );
#endif
