#ifndef SCALARCONVERTER_H_
#define SCALARCONVERTER_H_

#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iostream>

bool is_char(char *s);
bool is_int(char *s);
bool is_float(char *s);
bool is_double(char *s);
bool is_special(char *s);

void from_char(char *s);
void from_int(char *s);
void from_float(char *s);
void from_double(char *s);
void from_special(char *s);

class ScalarConverter {
private:
  ScalarConverter();
  ~ScalarConverter();
  ScalarConverter(const ScalarConverter &other);
  ScalarConverter &operator=(const ScalarConverter &other);

public:
  static void convert(char *s);
};

#endif
