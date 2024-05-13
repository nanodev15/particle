template <typename Obj,unsigned int SIZE>
const Obj& Vector<Obj,SIZE>::operator[](const unsigned int i) const {
  assert(i<SIZE);
  return _tab[i];
}

template <typename Obj,unsigned int SIZE>
Obj& Vector<Obj,SIZE>::operator[](const unsigned int i) {
  assert(i<SIZE);
  return _tab[i];
}
