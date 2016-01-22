
#include <assert.h>
#include <array>
#include <stdio.h>
#include <forward_list>



template <typename T>
//void for_arr(const std::array<T, L> &arr)
void for_arr(const T &arr)
{
  //typename T::iterator it;
  typename T::const_iterator it;
  for (it = arr.begin(); it != arr.end(); it++) {
    //*it = 3;
    printf("%d\n", *it);
  }
  printf("-------------------\n");

  //for (size_t i = 0; i < arr.size(); ++i)
  //{
  //  printf("%d\n", arr[i]);
  //}
}


int main(int argc, char *argv[])
{
  std::forward_list<int> x;
  std::forward_list<int> y(x);
  std::forward_list<int> c{1,2,3,4,4};
  for_arr(c);
  std::forward_list<int> d(c.begin(), ++c.begin());
  for_arr(d);
  //std::forward_list<int>::iterator it = c.begin();
  //std::forward_list<int>::const_iterator cit = c.cbegin();


  //std::array<int, 6> arr = {1,2,3,4,5};
  //const std::array<int, 6>::iterator it = arr.begin();
  //for_arr(arr);


  //arr.cbegin();
  //arr.cend();
  //printf("%d\n",*it);
  //it = arr.end();
  //printf("%d\n",*it);



  //CC::iterator
  //try {
  //  printf("arr[3]:%d\n", arr.at(5));
  //}catch(std::out_of_range &e) {
  //  printf("at:%s\n", e.what());
  //}
  //assert(arr.front() == arr[0]);
  //assert(arr.back() == arr[arr.size()-1]);
  //arr.front() = 3;
  //assert(arr[0] == 3);
  //for_arr(arr);

  




  
  return 0;
}
