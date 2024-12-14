#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
  (void)other;
  return *this;
}

void ScalarConverter::convert(char *s) {

  bool (*checks[5])(char *s) = {is_char, is_int, is_float, is_double,
                                is_special};
  void (*converters[5])(char *s) = {from_char, from_int, from_float,
                                    from_double, from_special};

  for (int i = 0; i < 5; i++) {
    if (checks[i](s)) {
      converters[i](s);
      break;
    }
  }
}

bool is_int(char *s) {
  int i = 0;

  if (!s[0])
    return false;
  if ((s[i] == '-' || s[i] == '+') && std::strlen(s) > 1)
    i++;
  while (s[i]) {
    if (!std::isdigit(s[i]))
      return false;
    i++;
  }
  return true;
}

bool is_double(char *s) {
  int i = 0;
  bool found = false;

  if (!s[0])
    return false;
  if ((s[i] == '-' || s[i] == '+') && std::strlen(s) > 1)
    i++;
  while (s[i]) {
    if (!std::isdigit(s[i])) {
      if (s[i] == '.' && !found) {
        if (i > 0 && std::isdigit(s[i - 1]) && std::isdigit(s[i + 1])) {
          found = true;
          i++;
          continue;
        }
      }
      return false;
    }
    i++;
  }
  return true && found;
}

bool is_special(char *s) {
  std::string str = s;
  if (str == "nan" || str == "nanf" || str == "+inff" || str == "+inf" ||
      str == "-inff" || str == "-inf")
    return 1;
  return 0;
}

bool is_float(char *s) {
  int len;
  bool r;

  if (!s[0])
    return false;
  len = std::strlen(s);
  if (s[len - 1] != 'f')
    return false;
  s[len - 1] = 0;
  r = is_double(s);
  s[len - 1] = 'f';
  return r;
}

bool is_char(char *s) {
  if (std::strlen(s) == 1 && std::isprint(s[0]) && !std::isdigit(s[0]))
    return true;
  return false;
}

void from_char(char *s) {
  char c;
  int i;
  float f;
  double d;

  c = s[0];
  i = static_cast<int>(c);
  f = static_cast<float>(c);
  d = static_cast<double>(c);
  if (std::isprint(c))
    std::cout << "char: '" << c << "'" << std::endl;
  else
    std::cout << "char: " << "Non displayable" << std::endl;
  std::cout << "int: " << i << std::endl;
  std::cout << "float: " << f << ".0f" << std::endl;
  std::cout << "double: " << d << ".0" << std::endl;
}

void from_int(char *s) {
  char c;
  float f;
  double d;
  long n;

  errno = 0;
  n = std::strtol(s, NULL, 10);
  if (((n == LONG_MAX || n == LONG_MIN) && errno == ERANGE) ||
      (n > INT_MAX || n < INT_MIN)) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
    return;
  } else {
    c = static_cast<char>(n);
    if (n > CHAR_MAX || n < CHAR_MIN)
      std::cout << "char: impossible" << std::endl;
    else if (std::isprint(c))
      std::cout << "char: '" << c << "'" << std::endl;
    else
      std::cout << "char: " << "Non displayable" << std::endl;
    std::cout << "int: " << n << std::endl;
  }
  f = static_cast<float>(n);
  std::cout << "float: " << f << ".0f" << std::endl;
  d = static_cast<double>(n);
  std::cout << "double: " << d << ".0" << std::endl;
}

bool check_f(char *s) {
  int len = std::strlen(s);
  for (int i = len - 2; s[i] != '.'; i--) {
    if (s[i] != '0')
      return false;
  }
  return true;
}

void from_float(char *s) {
  char c;
  long n;
  float f;
  double d;

  errno = 0;
  f = std::strtof(s, NULL);
  if (errno == ERANGE) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;

    errno = 0;
    std::strtod(s, NULL);
    if (errno == ERANGE)
      std::cout << "double: impossible" << std::endl;
    else {
      d = static_cast<double>(f);
      if (std::fmod(d, 1.0) != 0.0)
        std::cout << "double: " << d << std::endl;
      else
        std::cout << "double: " << d << ".0" << std::endl;
    }
    return;
  }
  n = static_cast<long>(f);
  if (f > INT_MAX || f < INT_MIN) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
  } else {
    c = static_cast<char>(f);
    if (f > CHAR_MAX || f < CHAR_MIN)
      std::cout << "char: impossible" << std::endl;
    else if (std::isprint(c))
      std::cout << "char: '" << c << "'" << std::endl;
    else
      std::cout << "char: " << "Non displayable" << std::endl;
    std::cout << "int: " << n << std::endl;
  }

  if (std::fmod(f, 1.0f) != 0.0f)
    std::cout << "float: " << f << "f" << std::endl;
  else
    std::cout << "float: " << f << ".0f" << std::endl;

  errno = 0;
  std::strtod(s, NULL);
  if (errno == ERANGE)
    std::cout << "double: impossible" << std::endl;
  else {
    d = static_cast<double>(f);
    if (std::fmod(d, 1.0) != 0.0)
      std::cout << "double: " << d << std::endl;
    else
      std::cout << "double: " << d << ".0" << std::endl;
  }
}

void from_double(char *s) {
  double d;
  char c;
  long n;
  float f;

  errno = 0;
  d = strtod(s, NULL);
  if (errno == ERANGE) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
    return;
  }

  f = static_cast<float>(d);
  if (d < -FLT_MAX || d > FLT_MAX) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;

    if (std::fmod(d, 1.0) != 0.0)
      std::cout << "double: " << d << std::endl;
    else
      std::cout << "double: " << d << ".0" << std::endl;
    return;
  }
  n = static_cast<long>(d);
  if (d > INT_MAX || d < INT_MIN) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
  } else {
    c = static_cast<char>(d);
    if (d > CHAR_MAX || d < CHAR_MIN)
      std::cout << "char: impossible" << std::endl;
    else if (std::isprint(c))
      std::cout << "char: '" << c << "'" << std::endl;
    else
      std::cout << "char: " << "Non displayable" << std::endl;
    std::cout << "int: " << n << std::endl;
  }

  if (std::fmod(f, 1.0f) != 0.0f)
    std::cout << "float: " << f << "f" << std::endl;
  else
    std::cout << "float: " << f << ".0f" << std::endl;

  if (std::fmod(d, 1.0) != 0.0)
    std::cout << "double: " << d << std::endl;
  else
    std::cout << "double: " << d << ".0" << std::endl;
}

void from_special(char *s) {
  std::string str = s;

  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;
  if (str == "nan" || str == "nanf") {
    std::cout << "float: nanf" << std::endl;
    std::cout << "double: nan" << std::endl;
  } else if (str == "+inf" || str == "+inff") {
    std::cout << "float: +inff" << std::endl;
    std::cout << "double: +inf" << std::endl;
  } else if (str == "-inf" || str == "-inff") {
    std::cout << "float: -inff" << std::endl;
    std::cout << "double: -inf" << std::endl;
  }
}
