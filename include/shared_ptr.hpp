#ifndef SHARED_PTR_HPP
#define SHARED_PTR_HPP
#include "shared_ptr.h"

template <typename T>
SharedPtr<T>::SharedPtr() : _p(nullptr), ref_count(new unsigned(1)) {}
template <typename T>
SharedPtr<T>::SharedPtr(T *ptr) : _p(ptr), ref_count(new unsigned(1)) {}
template <typename T>
SharedPtr<T>::~SharedPtr() {
  if (ref_count) {
    (*ref_count)--;
    if (*ref_count == 0) {
      delete _p;
      delete ref_count;
    }
  }
  _p = nullptr;
  ref_count = nullptr;
}
template <typename T>
SharedPtr<T>::SharedPtr(const SharedPtr &other)
    : _p(other._p), ref_count(other.ref_count) {
  if (ref_count) {
    (*ref_count)++;
  }
}
template <typename T>
SharedPtr<T> &SharedPtr<T>::operator=(const SharedPtr &other) {
  if (this != &other) {
    if (ref_count) {
      (*ref_count)--;
      if (*ref_count == 0) {
        delete _p;
        delete ref_count;
      }
    }
    _p = other._p;
    ref_count = other.ref_count;
    if (ref_count) {
      (*ref_count)++;
    }
  }
  return *this;
}
template <typename T>
unsigned SharedPtr<T>::use_count() const {
  return ref_count ? *ref_count : 0;
}
template <typename T>
T *SharedPtr<T>::get() const {
  return _p;
}
template <typename T>
T &SharedPtr<T>::operator*() const {
  return *_p;
}
template <typename T>
T *SharedPtr<T>::operator->() const {
  return _p;
}
template <typename T>
void SharedPtr<T>::reset(T *ptr) {
  if (ref_count) {
    (*ref_count)--;
    if (*ref_count == 0) {
      delete _p;
      delete ref_count;
    }
    _p = ptr;
    if (_p) {
      ref_count = new unsigned(1);
    } else {
      ref_count = nullptr;
    }
  }
}

template <typename T>
SharedPtr<T> make_shared(const T &elem) {
  return SharedPtr<T>(new T(elem));
}
template <typename T>
SharedPtr<T>::operator bool() const {
  return _p != nullptr;
}
#endif  // SHARED_PTR_HPP
