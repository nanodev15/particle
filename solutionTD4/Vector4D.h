
#ifndef _VECTOR4D_H
#define _VECTOR4D_H
#include <cassert>
#include "VectorMaths.h"

class Vector4D:public VectorMaths<float,4u> {
  public:
  Vector4D(const VectorMaths<float,4u>  &vecto) : VectorMaths<float,4u>(vecto) {}
  Vector4D(const float xx=0, const float yy=0, const float zz=0, const float ww=1);
  Vector4D& operator*=(const float scalaire);
};

#endif



