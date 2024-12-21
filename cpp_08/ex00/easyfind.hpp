#ifndef EASYFIND_H_
#define EASYFIND_H_

#include <algorithm>
#include <stdexcept>

template <typename T> typename T::iterator easyfind(T &ctner, int i) {
  typename T::iterator it = std::find(ctner.begin(), ctner.end(), i);

  if (it == ctner.end())
    throw std::runtime_error("Value not found");
  return it;
}

#endif
