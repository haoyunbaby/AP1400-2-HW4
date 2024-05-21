#ifndef UNIQUE_PTR
#define UNIQUE_PTR
template <typename T>
class UniquePtr {
 private:
  T *_p;

 public:
  UniquePtr();
  UniquePtr(T *ptr);
  ~UniquePtr();
  UniquePtr(const UniquePtr &) = delete;
  UniquePtr &operator=(const UniquePtr &) = delete;
  T *get() const;
  T &operator*() const;
  T *operator->() const;
  void reset(T *ptr = nullptr);
  T *release();
  operator bool() const;
};
template <typename T>
UniquePtr<T> make_unique(const T &elem);
#include "unique_ptr.hpp"
#endif  // UNIQUE_PTR
