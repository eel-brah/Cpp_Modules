#ifndef GITER_H_
#define GITER_H_

#include <algorithm>
template <typename Iter> class Giter {
private:
  Iter it;
  unsigned int size;

  // TODO:
  Giter() {}

public:
  Giter(Iter it, unsigned int size) : it(it), size(size) {}
  ~Giter() {}
  Giter(const Giter &other) { *this = other; }
  Giter &operator=(const Giter &other) {
    if (this != &other) {
      it = other.it;
      size = other.size;
    }
    return *this;
  }

  Iter iter() const { return it; }
  unsigned int iter_size() const { return size; }

  // Giter &operator++() {
  //   it += size;
  //   return *this;
  // }
  // Giter operator++(int) {
  //   Giter tmp = *this;
  //   operator++();
  //   return tmp;
  // }
  Giter &operator+=(unsigned int inc) {
    it += size * inc;
    return *this;
  }
  Giter &operator-=(unsigned int dec) {
    it -= size * dec;
    return *this;
  }
  unsigned int operator-(const Giter &giter) { return (it - giter.iter()) / size; }
  Giter operator-(const unsigned int i) { 
    return it -= i;
  }
  Giter operator+(const unsigned int i) { 
    return it += i;
  }
  bool operator!=(const Giter &giter) const {
    return this->it != giter.iter();
  }

  // unsigned int operator[](unsigned int pos) {
  //   return it[pos * size + size - 1];
  // }
  unsigned int operator[](unsigned int pos) const {
    return it[pos * size + size - 1];
  }
};

template <typename iter> void swap(Giter<iter> it1, Giter<iter> it2) {
  std::swap_ranges(it1.iter(), it1.iter() + it1.iter_size(), it2.iter());
}

template <typename iter>
Giter<iter> make_group_iterator(iter it, unsigned int size) {
  Giter<iter> t(it, size);
  return it;
}
template <typename iter>
Giter<iter> make_group_iterator(Giter<iter> it, unsigned int size) {
  Giter<iter> t(it, size *it.iter_size());
  return t;
}

#endif
