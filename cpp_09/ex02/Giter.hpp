#ifndef GITER_H_
#define GITER_H_

#include <algorithm>

template <typename Iter> class Giter {
private:
  Iter it;
  unsigned int size;

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

  typedef
      typename std::iterator_traits<Iter>::iterator_category iterator_category;
  typedef typename std::iterator_traits<Iter>::value_type value_type;
  typedef typename std::iterator_traits<Iter>::difference_type difference_type;
  typedef typename std::iterator_traits<Iter>::pointer pointer;
  typedef typename std::iterator_traits<Iter>::reference reference;

  reference operator*() { return it[size - 1]; }
  pointer operator->() { return &(operator*()); }

  Iter iter() const { return it; }
  unsigned int iter_size() const { return size; }

  Giter &operator+=(unsigned int inc) {
    it += size * inc;
    return *this;
  }
  Giter &operator-=(unsigned int dec) {
    it -= size * dec;
    return *this;
  }
  unsigned int operator-(const Giter &giter) {
    return (it - giter.iter()) / size;
  }
  // Giter operator-(const unsigned int i) { return it -= i; }
  // Giter operator+(const unsigned int i) { return it += i; }
  bool operator!=(const Giter &giter) const { return this->it != giter.iter(); }

  unsigned int operator[](unsigned int pos) const {
    return it[pos * size + size - 1];
  }
};
template <typename Iter> Giter<Iter> operator+(Giter<Iter> it, unsigned int i) {
  return it += i;
}

template <typename Iter> Giter<Iter> operator-(Giter<Iter> it, unsigned int i) {
  return it -= i;
}

template <typename iter> void gswap(Giter<iter> it1, Giter<iter> it2) {
  std::swap_ranges(it1.iter(), it1.iter() + it1.iter_size(), it2.iter());
}

template <typename iter>
Giter<iter> make_pair_iterator(Giter<iter> it, unsigned int size) {
  Giter<iter> t(it.iter(), size * it.iter_size());
  return t;
}

#endif
