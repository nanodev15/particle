
#ifndef _VECTOR4D_H
#define _VECTOR4D_H

#include <iostream>

class Matrix4x4;

//====================================================
class Vector4D {
  friend std::ostream& operator<<(std::ostream&,const Vector4D&);
  friend Vector4D operator+(const Vector4D&,const Vector4D&);
  friend Vector4D operator-(const Vector4D&,const Vector4D&);
  friend Vector4D operator*(const double ,const Vector4D&);
  friend Vector4D operator*(const Vector4D&,const double);
 private:
  double vect[4];
 public:
  //Constructeurs
  Vector4D(const Vector4D &vecto);
  Vector4D(const double x = 0, const double y = 0,
		    const double z = 0, const double w = 1);
  //Accesseurs
  double  operator[](unsigned int i) const;
  double& operator[](unsigned int i);
  //fonctions membres
  Vector4D& operator*=(const Matrix4x4 &matrix);
  Vector4D& operator*=(const double scalaire);
  Vector4D& operator+=(const Vector4D &vecto);
  Vector4D& operator-=(const Vector4D &vecto);
};

//Opérateurs externes
std::ostream& operator<<(std::ostream &os,const Vector4D &vect);
Vector4D operator+(const Vector4D &v1,const Vector4D &v2);
Vector4D operator-(const Vector4D &v1,const Vector4D &v2);
Vector4D operator*(const Vector4D &v1,const double scalaire);
Vector4D operator*(const double scalaire, const Vector4D &v1);
Vector4D operator*(const Vector4D &v, const Matrix4x4 &matrix);
#endif
