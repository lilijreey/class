#include <forward_list>
#include <array>
#include <cassert>
//ADT
//create
//add element
//push_front
//pop_front
//
//insert_after
//erase_after
//clear
//sort
//merge
//unique
//
//front
//*it
//
//find/count/...
//empty
//
//
//
//destory

template <typename T>
void for_e(const std::forward_list<T> &c)
{
  std::forward_list<int>::const_iterator it;
  for (it = c.cbegin(); it != c.cend(); ++it)
  {
    printf("%d\n", *it);
  }
  printf("----------------------\n");
}

int main(int argc, char *argv[])
{
  std::forward_list<int> a(2,1);
  //std::forward_list<int> b(a.begin(), a.end());
  for_e(a);

  //insert push_front
  a.push_front(5);
  a.push_front(6); //6,5,1,1
  for_e(a);

  //insert_after
  std::forward_list<int>::iterator it = 
  a.insert_after(a.begin(), 7);
  assert(7 ==  *it);

  for_e(a);
  a.insert_after(a.begin(), 0, 8);
  for_e(a);

  std::array<int, 5> arr{11,22,33,44,55};
  it = a.insert_after(a.begin(),
                 arr.begin()+1,
                 arr.begin()+4);
  assert(*it == 44);
  for_e(a);

  std::forward_list<int> f{1,3,5,7,9, 11, 13};
  //1,2,3,4,5,6,7,8,9,10
  //1,2,3,5,7,9
  for (it = f.begin(); it != f.end() ;++it) 
    it = f.insert_after(it, *it+1);

  it = f.before_begin();
  f.insert_after(it, 100);
  for_e(f);

  f.erase_after(f.begin());

  it =  ++++++f.begin();
  std::forward_list<int>::iterator it2;
  it2 = f.erase_after(f.begin(), it);
  assert(it == it2);
  for_e(f);

  if (f.empty())
    printf("f is empty\n");
  
  f.sort();
  f.unique();
  f.front() = 4;


  std::forward_list<int> c = {12, 55,77,33,99, 21};
  c.sort();
  //list
  f.merge(c);
  //zip
  for_e(f);


  //f.clear();
  //for_e(f);


  





  return 0;
}
