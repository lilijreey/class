#include <limits>
#include <iostream>
#include <stdio.h>
#include <typeinfo>
#include <assert.h>

struct Z {
  Z(int s=0, double o =1) :s(s), o(o){}
  int s;
  double o;
  void show() {
    printf("%d:%g\n",s, o);
  }
};

//void swap(int &a, int &b) {
  //printf("swap int\n");
  //int tmp = a;
  //a = b;
  //b = tmp;
//}
//void swap(double &a, double &b) {
  //printf("swap double\n");
  //double tmp = a;
  //a = b;
  //b = tmp;
//}

#if 0

int main(int argc, char *argv[])
{
  //int a=1,b=22;
  //swap(a,b); //<int,int>
  //assert(a==22);
  //assert(b==1);

  Z a1(11,1.11);
  Z a2(22,2.22);
  swap(a1, a2);
  a1.show();
  a2.show();
  
  return 0;
}


template<typename T> void fnG(T a)
 {
   printf("fnG name:%s\n", typeid(T).name());
 }
template<typename T> void fnR(const T &a)
{
   printf("fnG name:%s\n", typeid(T).name());
}
template<typename T> void fnP(const T *a)
{
   printf("fnG name:%s\n", typeid(T).name());
} 

int main() {
  int a=3;
  fnG<int>(a);

  //a=4;
  //fnR(a);
  //fnP(a);

  //fnG(&a);
  //int *p = &a;
  //fnR(p);
  //fnP(&a);


}

template <typename T>
T max_limit(T a) {
  return std::numeric_limits<T>::max();
}

template <typename T, typename E >
void xx(T t, E e) {
  std::cout << t << " " << e << std::endl;
}

template <typename T, typename E >
void xx(T a) {
  E e;
  e.show();
  std::cout << t << " " << e << std::endl;
}




int max_limit(int) { return std::numeric_limits<int>::max();}
//bool max_limit(bool) { std::numeric_limits<bool>::max();}
//float max_limit(float) { std::numeric_limits<int>::max();}
//double max_limit(double) { std::numeric_limits<int>::max();}
//unsigned long max_limit(unsigned long) { std::numeric_limits<int>::max();}
//int max_limit(int i) { return std::numeric_limits<int>::max(); }

struct A {
};
int main(int argc, char *argv[])
{
  xx(1,3.23);
  //std::cout << max_limit(a) << std::endl;
  //std::cout << max_limit<double>(3.33)<< std::endl;
  //std::cout << max_limit(false)<< std::endl;
  //std::cout << std::numeric_limits<int>::max() << std::endl;
  //std::cout << std::numeric_limits<double>::max() << std::endl;
  //std::cout << std::numeric_limits<unsigned long>::max() << std::endl;
  //std::cout << std::numeric_limits<float>::max() << std::endl;
  //std::cout << std::numeric_limits<bool>::max() << std::endl;

}

#endif
