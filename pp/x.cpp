#include <stdio.h>
#include <iostream>
#include <limits>

#define PI 3.1415f
//const double PI = 3.1415;

//Pass by value
//void swap(int *p, int *q) {
//    int temp = 0;
//    temp = *p;
//    *p = *q;
//    *q =temp;
//}
void swap(const struct Person &p, int &q) {
    int temp = p;
    p = q;
    q = temp;
}
int main() {
  const int a=1, b=99;
  int& ra1=a;
  int& ra=a;

  //rra =3;
  //

  printf("%d\n",a);

  int *pa = &a;
  int **ppa = &pa;

  printf("%p\n%p\n", &a, &ra);
  ra = b;
  printf("%d:%d:%d\n", a, ra, ra1);
  ra = 1;
  printf("%d:%d\n", a, ra);
  printf("%d,%d\n",a,b);
  swap(a, b);
  printf("%d,%d\n",a,b);
}

#if 0
//constexpr int area(int length) {
//  return PI * 3; //1001
//}

////constexpr int fac(int n) { return (n<2)?1:n*fac(n−1); }
//int main() {
//  //int p = NULL; //0
//  int q = nullptr;
//  //const int b=3;
//  constexpr int a = area(3);
//  printf("area=%d", area(a));
//  int arr[area(3)];
//}
  int r = 3;
  printf("area=%g", PI * r * r);
}

int main()
{
  std::cout << "size of long " << sizeof(1L) << '\n';
  std::cout << "size of long long " << sizeof(1LL) << '\n';
  std::cout << "largest float == " 
      << std::numeric_limits< float >::max() << std::endl;

  std::cout << "char is signed == "
      << std::numeric_limits< char >::is_signed ;
}

int main() {
  bool b1 {};
 bool b2 =1;
  bool b3 =100;

//bool to integer: true as 1, false as 0
//integer to bool: 0 as false, other else as true
  //0:1:1
  std::cout << b1 << ":" 
            << b2 << ":"
            << b3 << ":"
            << std::endl;

  int c = false; //0
  int d = true; //1
  std::cout << c << ":" 
            << d << ":"
            << std::endl;



  //bool b1 = true;
  //bool b2 = false;
  //bool b3 = !true;
  //bool b4 = not true;
  //if (not is_valied()) {
  //  fjeosfj
  //}

  //bool t= true;
  //bool f= false;
  //std::cout << t << ":" << f << std::endl;
  //printf("%d :%p\n", a, pa);
  
  return 0;
}
#endif
