

template <typename Obj,unsigned int SIZE>
VectorMaths<Obj,SIZE>& VectorMaths<Obj,SIZE>::operator*=(const float scalaire) {
  for (unsigned int i=0;i<SIZE;++i)
    (*this)[i]*=scalaire;
  return *this;
}
template <typename Obj,unsigned int SIZE>
VectorMaths<Obj,SIZE>& VectorMaths<Obj,SIZE>::operator+=(const Vector<Obj,SIZE> &vecto) {
  for (unsigned int i=0;i<SIZE;++i)
    (*this)[i]+=vecto[i];
  return *this;
}
template <typename Obj,unsigned int SIZE>
VectorMaths<Obj,SIZE>& VectorMaths<Obj,SIZE>::operator-=(const Vector<Obj,SIZE> &vecto) {
  for (unsigned int i=0;i<SIZE;++i)
    (*this)[i]-=vecto[i];
  return *this;
}

template <typename Obj,unsigned int SIZE>
void VectorMaths<Obj,SIZE>::fill(Obj obj) {
  for (unsigned int i=0;i<SIZE;++i)
     (*this)[i]=obj;
}
//=======================================================================
//=======================================================================

template <typename Obj,unsigned int SIZE>
std::ostream& operator<<(std::ostream &os,const Vector<Obj,SIZE> &vect) {
  os << "[" ;
  if(SIZE>0) {
    os << vect[0];
    for (unsigned int i=1;i<SIZE;++i)
      os << "," <<  vect[i];
  }
  os << "]" << std::endl;
  return os;
}

template <typename Obj,unsigned int SIZE>
Vector<Obj,SIZE> operator+(const Vector<Obj,SIZE>&v1,const Vector<Obj,SIZE>&v2) {
  VectorMaths<Obj,SIZE> tmpV(v1);
  tmpV += v2;
  return tmpV;
}

template <typename Obj,unsigned int SIZE>
VectorMaths<Obj,SIZE> operator-(const VectorMaths<Obj,SIZE>&v1,const VectorMaths<Obj,SIZE>&v2) {
  VectorMaths<Obj,SIZE> tmpV(v1);
  tmpV -= v2;
  return tmpV;
}

template <typename Obj,unsigned int SIZE>
VectorMaths<Obj,SIZE> operator*(const VectorMaths<Obj,SIZE>&v1,const Obj& scalaire) {
  VectorMaths<Obj,SIZE> tmpV(v1);
  tmpV *= scalaire;
  return tmpV;
}

template <typename Obj,unsigned int SIZE>Obj operator*(const VectorMaths<Obj,SIZE>&v1, const VectorMaths<Obj,SIZE>&v2) {
  assert (SIZE>0);
  Obj tmpO;
  tmpO = v1[0] * v2[0];
  for (unsigned int i=1; i<SIZE; ++i)
    tmpO += v1[i] * v2[i];
  return tmpO;
}

template <typename Obj,unsigned int SIZE>
VectorMaths<Obj,SIZE> operator *(const Obj &scalaire,const VectorMaths<Obj,SIZE>&v1) {
  return (v1*scalaire);
}
