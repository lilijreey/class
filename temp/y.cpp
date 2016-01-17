#include <iostream>
#include <vector>
template <typename T>
class X{
 public:
  T  value;
  void show() const;
  X<T>& operator++();
  void xx() {
    double f = NULL + 1;
  }
};
//template <typename T>
//void X<T>::show() const {
//  std:: cout << value << std::endl;
//}
//template <typename T>
//X<T>& X<T>::operator++() {
//  value++;
//  return *this;
//}

struct O {
  int _v;
  O(int i=0) : _v(i) {}
};

int main(int argc, char *argv[])
{
  //X<int> a;
  //X<double> b;
  //a.value=1;
  //++a;
  //a.show();
  //b.show();


  //a.value =12;
  //a.show();

  //std::vector<int> v = {1,2,3,4,5,6};
  //for (auto &e : v) printf("%d", e);

  //printf("\n");
  //std::vector<O> o = {1,2,3,4,5,6};
  //for (auto &e : o) printf("%d", e._v);


  
  return 0;
}
