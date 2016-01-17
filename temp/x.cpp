#include <limits>
#include <iostream>

//template <typename T>
//T zero() { return T{}; }
//int main() {
  //int i = zero<int>();
  //double d = zero<double>();
  //zero();
//}

template <typename T>
void swap(T &l, T &r) {
  T tmp = l;
  l = r;
  r = tmp;
}

void swap(int &l, int &r) {
  int tmp = l;
  l = r;
  r = tmp;
}

void swap(double &l, double &r) {
  double tmp = l;
  l = r;
  r = tmp;
}

//template <typename T, typename E>
//void swap(T &l, E &r) {
  //T tmp = l;
  //l = r;
  //r = tmp;
//}

struct A{};
struct B{};


int main(int argc, char *argv[])
{
  int i=11, j=99;
  swap<int>(i,j);
  printf("%d %d\n",i,j);
  
  double m=11, n=99;
  swap(n,m);
  return 0;
}
//void swap(int l, int r) { }

#if 0

template <typename T>
T max_limit(T obj) { 
  printf("max_limit template \n");
  return std::numeric_limits<T>::max();
}
double max_limit(double) { 
  printf("max_limit double\n");
  return std::numeric_limits<double>::max();
}














//template <typename T>
//void show(T &v1, T &v2)
//{
  //T tmp = v1;
  //v1 = v2;
  //v2 = tmp;
//}


//int max_limit(int) {
  //return std::numeric_limits<int>::max();}
//unsigned long max_limit(unsigned long) { 
  //return std::numeric_limits<int>::max();}
int main(int argc, char *argv[])
{

  std::cout << max_limit<double>(1.323) << std::endl;
  std::cout << max_limit(1.323) << std::endl;
  std::cout << max_limit(32) << std::endl;
  //std::cout << max_limit<double, int>(3.0f) << std::endl;
  //std::cout << max_limit(false) << std::endl;
  //std::cout << max_limit(32LU) << std::endl;
  //std::cout << max_limit(A) << std::endl;

}
  //std::cout << 
      //std::numeric_limits<int>::max() << std::endl;
  //std::cout 
      //<< std::numeric_limits<double>::max() << std::endl;
  //std::cout 
      //<< std::numeric_limits<unsigned long>::max() << std::endl;
  //std::cout 
      //<< std::numeric_limits<float>::max() << std::endl;
  //std::cout
      //<< std::numeric_limits<bool>::max() << std::endl;
//}
#endif
