template <typename T> Array<T>::Array() : arr(NULL), _size(0) {}

template <typename T> Array<T>::Array(const unsigned int n) {
  try {
    arr = new T[n]();
    _size = n;
  } catch (const std::bad_alloc &e) {
    std::cout << "Memory allocation failed: " << e.what() << std::endl;
    arr = NULL;
    _size = 0;
  }
}

template <typename T> Array<T>::~Array() { delete[] arr; }

template <typename T> Array<T>::Array(const Array &other) {
  arr = NULL;
  *this = other;
}

template <typename T> Array<T> &Array<T>::operator=(const Array &other) {
  if (this != &other) {
    delete [] arr;
    try {
      if (other._size) {
        arr = new T[other._size];
        _size = other._size;
        for (unsigned int i = 0; i < _size; i++)
        arr[i] = other.arr[i];
      }
      else {
        arr = NULL;
        _size = 0;
      }
    } catch (const std::bad_alloc &e) {
      std::cout << "Memory allocation failed: " << e.what() << std::endl;
      arr = NULL;
      _size = 0;
    }
  }
  return *this;
}

template <typename T> unsigned int Array<T>::size() const { return _size; }

template <typename T> T &Array<T>::operator[](unsigned int index) {
  if (index >= _size || arr == NULL) {
    throw std::out_of_range("Index out of bounds!");
  }
  return arr[index]; // Return a reference to the element
}

template <typename T> const T &Array<T>::operator[](unsigned int index) const {
  if (index >= _size || arr == NULL) {
    throw std::out_of_range("Index out of bounds!");
  }
  return arr[index]; // Return a reference to the element (const version)
}

