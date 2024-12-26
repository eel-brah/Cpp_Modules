#ifndef MUTANTSTACK_H_
#define MUTANTSTACK_H_

#include <stack>

template <typename T> class MutantStack : public std::stack<T> {
private:
public:
  MutantStack();
  ~MutantStack();
  MutantStack(const MutantStack &other);
  MutantStack &operator=(const MutantStack &other);

  typedef typename std::stack<T>::container_type::iterator iterator;
  typedef
      typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
  typedef typename std::stack<T>::container_type::const_iterator const_iterator;
  typedef typename std::stack<T>::container_type::const_reverse_iterator
      const_reverse_iterator;

  iterator begin();
  const_iterator cbegin() const;
  iterator end();
  const_iterator cend() const;
  reverse_iterator rbegin();
  const_reverse_iterator crbegin() const;
  reverse_iterator rend();
  const_reverse_iterator crend() const;
};

template <typename T> MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T> MutantStack<T>::~MutantStack() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &other) : std::stack<T>(other) {}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &other) {
  if (this != &other) {
    std::stack<T>::operator=(other);
  }
  return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
  return std::stack<T>::c.begin();
}
template <typename T> typename MutantStack<T>::iterator MutantStack<T>::end() {
  return std::stack<T>::c.end();
}
template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin() {
  return std::stack<T>::c.rbegin();
}
template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend() {
  return std::stack<T>::c.rend();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cbegin() const {
  return std::stack<T>::c.cbegin();
}
template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cend() const {
  return std::stack<T>::c.cend();
}
template <typename T>
typename MutantStack<T>::const_reverse_iterator
MutantStack<T>::crbegin() const {
  return std::stack<T>::c.crbegin();
}
template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crend() const {
  return std::stack<T>::c.crend();
}
#endif
