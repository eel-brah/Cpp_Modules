#ifndef ITER_H_
#define ITER_H_

template <typename T, typename func> void iter(T *array, int length, func f) {
  for (int i = 0; i < length; i++)
    f(array[i]);
}

#endif
