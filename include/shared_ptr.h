#ifndef SHARED_PTR
#define SHARED_PTR
template <typename T>
class SharedPtr {
 private:
  T *_p;
  unsigned *ref_count;

 public:
  SharedPtr();
  SharedPtr(T *ptr);
  ~SharedPtr();
  SharedPtr(const SharedPtr &other);
  SharedPtr &operator=(const SharedPtr &other);
  unsigned use_count() const;
  T *get() const;
  T &operator*() const;
  T *operator->() const;
  void reset(T *ptr = nullptr);
  operator bool() const;
};
template <typename T>
SharedPtr<T> make_shared(const T &elem);
#include "shared_ptr.hpp"
#endif  // SHARED_PTR
