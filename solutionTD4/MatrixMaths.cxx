template<typename Obj,unsigned int SIZE>
void MatrixMaths<Obj,SIZE>::fill(Obj obj) {
  for (unsigned int i=0;i<SIZE;++i)
    (*this)[i].fill(obj);
}

template<typename Obj,unsigned int SIZE>
MatrixMaths<Obj,SIZE> & MatrixMaths<Obj,SIZE>::operator*=(const MatrixMaths<Obj,SIZE> &mat) {
  MatrixMaths<Obj,SIZE> tmpMat(*this);
  fill(0);
  for (unsigned int i=0; i<SIZE; ++i)
    for (unsigned int j=0; j<SIZE; ++j)
      for (unsigned int k=0; k<SIZE; ++k)
	(*this)[i][j] += tmpMat[k][i]*mat[j][k];
  return *this;
}

template<typename Obj,unsigned int SIZE>
MatrixMaths<Obj,SIZE> operator*(const MatrixMaths<Obj,SIZE> &mat1, const MatrixMaths<Obj,SIZE> &mat2) {
  MatrixMaths<Obj,SIZE>tmpMat(mat1);
  tmpMat *= mat2;
  return tmpMat;
}
