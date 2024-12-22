#ifndef MUTANTSTACK_H_
#define MUTANTSTACK_H_

#include <cstddef>
#include <deque>
#include <stack>

template <typename T> class MutantStack {
private:
  std::deque<T> stack;

public:
  MutantStack();
  ~MutantStack();
  MutantStack(const MutantStack &other);
  MutantStack &operator=(const MutantStack &other);
  template <typename ctnr> MutantStack(const ctnr &container) {
    stack.clear();
    stack.insert(stack.begin(), container.begin(), container.end());
  }

  typedef typename std::deque<T>::iterator iterator;
  typedef typename std::deque<T>::const_iterator const_iterator;

  operator std::stack<T>();

  bool empty() const;
  size_t size() const;
  T &top();
  const T &top() const;
  void push(const T &val);
  void pop();

  iterator begin() { return stack.begin(); }
  const_iterator begin() const { return stack.begin(); }
  iterator end() { return stack.end(); }
  const_iterator end() const { return stack.end(); }
  iterator rbegin() { return stack.rbegin(); }
  const_iterator rbegin() const { return stack.rbegin(); }
  iterator rend() { return stack.rend(); }
  const_iterator rend() const { return stack.rend(); }

  // void emplace();
  // void swap();
};

template <typename T> MutantStack<T>::MutantStack() {}

template <typename T> MutantStack<T>::~MutantStack() {}

template <typename T> MutantStack<T>::MutantStack(const MutantStack &other) {
  *this = other;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &other) {
  if (this != &other) {
    stack = other.stack;
  }
  return *this;
}

template <typename T> MutantStack<T>::operator std::stack<T>() {
  std::stack<T> s;
  typename std::deque<T>::iterator itB = stack.begin();
  typename std::deque<T>::iterator itE = stack.end();

  while (itB != itE) {
    s.push(*itB);
    itB++;
  }
  return s;
}

template <typename T> bool MutantStack<T>::empty() const {
  return stack.empty();
}
template <typename T> size_t MutantStack<T>::size() const {
  return stack.size();
}
template <typename T> T &MutantStack<T>::top() { return stack.back(); }
template <typename T> const T &MutantStack<T>::top() const {
  return stack.back();
}
template <typename T> void MutantStack<T>::push(const T &val) {
  stack.push_back(val);
}
template <typename T> void MutantStack<T>::pop() {
  // if (!stack.empty())
  stack.pop_back();
}

// template <typename T> iterator MutantStack<T>::begin() {
//   return stack.begin();
// }
// template <typename T>
// const_iterator MutantStack<T>::begin() const {
//   return stack.begin();
// }
// template <typename T> iterator MutantStack<T>::end() {
//   return stack.end();
// }
// template <typename T>
// const_iterator MutantStack<T>::end() const {
//   return stack.end();
// }
#endif
