template <class T>
class Unique_ptr {
public:
	Unique_ptr(const Unique_ptr &other) = delete;
  Unique_ptr& operator=(const Unique_ptr &o) = delete;

  Unique_ptr(T *p = nullptr) { _p = p; }
  ~Unique_ptr() {
		if (_p != nullptr) delete _p;
	}

  T& operator*() { return *_p; }
  T* operator->() { return _p; }
private:
	T *_p = nullptr;
};
