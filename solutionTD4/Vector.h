#ifndef _VECTOR_H
#define _VECTOR_H
#include <cassert>

template <typename Obj,unsigned int SIZE>
class Vector {
 public:
  const Obj& operator[](const unsigned int i) const;
  Obj& operator[](const unsigned int i);
 private:
  Obj _tab[SIZE];
};
#include "Vector.cxx"
#endif
