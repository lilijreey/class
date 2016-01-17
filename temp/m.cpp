#include <stdio.h>



template <typename T, typename R=T>
R add(T l, T r) {
  return l +r;
}

int main(int argc, char *argv[])
{
  double a=3.32, b=100.323;
  add(a,b);
  add<int, double>(a,b);
  
  return 0;
}

#if 0

template <int LEN, typename T>
//template <typename T, int LEN>
constexpr int getLength(T (&ra)[LEN]) {
  return LEN;
}

//template <typename T>
//void getLength(T arr[]) {
//  printf("getLength\n");
//  //printf("length:d\n",
//         //sizeof(arr) /sizeof(arr[0]));
//}

int main(int argc, char *argv[])
{
  int a;
  int arr[323] ={0};
  double brr[getLength(arr)];

  //getLength(arr);
  //getLength(brr);

  
  return 0;
}

template< typename T, int MAXSIZE=10> 
class Stack{  
private:  
  T elems[MAXSIZE];  
  int numElems;  
public:  
  Stack();  
  void push(T const&);  
  void pop();  
  T top() const;  
  bool isEmpty() const{  return numElems == 0; }  
};
void main() {
  Stack<int> s;
  Stack<int> s1;
}

#endif
