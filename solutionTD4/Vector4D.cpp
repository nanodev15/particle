/*-*-c++-*-*/
/**
 Author: David Auber
 Email : auber@labri.fr
 Last modification : 01/09/2004
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.
*/
#include "Vector4D.h"
//====================================================================
Vector4D::Vector4D(const float xx, const float yy, const float zz, const float ww) {
  (*this)[0]=xx; (*this)[1]=yy; (*this)[2]=zz, (*this)[3]=ww;
}
//====================================================================
Vector4D& Vector4D::operator *= (const float scalaire) {
  this->VectorMaths<float,4>::operator*=(scalaire);
  return *this;
}
