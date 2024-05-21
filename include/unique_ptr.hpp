#ifndef UNIQUE_PTR_HPP
#define UNIQUE_PTR_HPP
#include "unique_ptr.h"
template <typename T>
UniquePtr<T>::UniquePtr() : _p(nullptr) {}

template <typename T>
UniquePtr<T>::UniquePtr(T *ptr) : _p(ptr) {}

template <typename T>
UniquePtr<T>::~UniquePtr() {
  delete _p;
}

template <typename T>
T *UniquePtr<T>::get() const {
  return _p;
}
template <typename T>
T &UniquePtr<T>::operator*() const {
  return *_p;
}
template <typename T>
T *UniquePtr<T>::operator->() const {
  return _p;
}
template <typename T>
void UniquePtr<T>::reset(T *ptr) {
  if (_p != ptr) {
    delete _p;
    _p = ptr;
  }
}
template <typename T>
T *UniquePtr<T>::release() {
  auto rv = _p;
  _p = nullptr;
  return rv;
}
template <typename T>
UniquePtr<T> make_unique(const T &elem) {
  return UniquePtr<T>(new T(elem));
}
template <typename T>
UniquePtr<T>::operator bool() const {
  return _p != nullptr;
}
#include "unique_ptr.hpp"
#endif  // UNIQUE_PTR_HPP
