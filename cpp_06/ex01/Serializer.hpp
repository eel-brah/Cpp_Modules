#ifndef SERIALIZER_H_
#define SERIALIZER_H_

#include "Data.hpp"

#define uintptr_t unsigned long

class Serializer {
private:
  Serializer();
  ~Serializer();
  Serializer(const Serializer &other);
  Serializer &operator=(const Serializer &other);

public:
  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);
};

#endif
