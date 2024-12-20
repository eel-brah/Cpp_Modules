#ifndef ARRAY_H_
#define ARRAY_H_

#include <iostream>
#include <stdexcept>

template <typename T> class Array {
private:
  T *arr;
  unsigned int _size;

public:
  Array();
  Array(const unsigned int n);
  ~Array();
  Array(const Array &other);
  Array &operator=(const Array &other);

  unsigned int size() const;
  T &operator[](unsigned int index);
  const T &operator[](unsigned int index) const;
};

#include "Array.tpp"
#endif
