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
  typedef typename std::stack<T>::container_type::const_iterator const_iterator;

  iterator begin();
  const_iterator begin() const;
  iterator end();
  const_iterator end() const;
  iterator rbegin();
  const_iterator rbegin() const;
  iterator rend();
  const_iterator rend() const;
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
typename MutantStack<T>::iterator MutantStack<T>::rbegin() {
  return std::stack<T>::c.rbegin();
}
template <typename T> typename MutantStack<T>::iterator MutantStack<T>::rend() {
  return std::stack<T>::c.rend();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const {
  return std::stack<T>::c.begin();
}
template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const {
  return std::stack<T>::c.end();
}
template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::rbegin() const {
  return std::stack<T>::c.rbegin();
}
template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::rend() const {
  return std::stack<T>::c.rend();
}
#endif
