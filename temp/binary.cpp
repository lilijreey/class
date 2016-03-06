#include <stdio.h>
#include <math.h>
template <unsigned long N>
struct binary {
	static unsigned const value = 
			binary<N/10>::value *2 + N % 10 ;
};
template<>
struct binary<0> {
	static unsigned const value = 0 ;
};

int b2i(int b) {
  int num = 0;
  for (int i=0;b > 0; i++) {
    int e = b % 10;
    b /= 10;
    num += pow(2,i) * e;
  }
  return num;
}

int _b2i(int b, int i) {
  if (b <= 0) return 0;
  int e = b % 10;
  return _b2i(b / 10, i+1) + pow(2, i) * e;
}
int B2i(int b) {
  return _b2i(b,0);
}


int main() {
  //2 +4 
  constexpr int v = binary<110>::value;
  binary<110>::value =
      binary<11>::value + xx =
          binary<1>::value + yy + xx =
              binary<0>::value yy + xx + zz =
                0+ yy + xx + zz
                  

  printf("%d\n", v);
  printf("%d\n", b2i(110));
  printf("%d\n", B2i(110));

  return 0;
}
