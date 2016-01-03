#include <array>
#include <iostream>
int main(int argc, char *argv[])
{
  A<int>::iterator x=4; 
  std::array<int, 3> a= {1,2,3};
  std::array<int, 3>::iterator it = a.begin();
  std::array<int, 3>::const_iterator cit = a.cbegin();
  std::array<int, 3>::reverse_iterator rit = a.rbegin();

  if (a = b)

  std::array<int, 3>::const_reverse_iterator crit
      = a.crbegin();


  for (; rit != a.rend(); ++rit) 
    printf("%d\n", ++(*rit));
  //for (cit=a.cbegin(); it != a.cend(); it++) {
    //(*cit) += 1;
    //printf("%d\n", *cit);
  //}

  //it =a.begin();
  //while (it != a.end())
  //  printf("%d\n", *it++);


  int oa[3] = {1,2,3};
  int ot[] ={1,2,3};
  std::array<int,3> t={1,2,3};
  std::array<bool, 0> b;
  if (b.begin() == b.end())
      printf("begin == end\n");




  for (int i = 0; i < a.size()  ; ++i)
    printf("%d\n",oa[i]);

  printf("%lu:%lu\n", sizeof(oa), sizeof(a));
  std::cout << a[1] << std::endl;
  std::cout << a.at(1) << std::endl;
  std::cout << a.front()<< std::endl;
  std::cout << a.back() << std::endl;
  a[1] = 100;
  std::cout << a[1] << std::endl;
  
  return 0;
}

