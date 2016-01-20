#include <iostream>
#include <vector>
#include <iterator>
#include <forward_list>
#include <list>
#include <assert.h>
#include <set>

//template <typename Iter>
//void MyAdvance(Iter &it, int n) 
//{
  //for (int i = 0; int i < n; ++int i)
  //{
    //++it;
  //}
//}




int main() {
  std::list<int> v{1,2,3,4,5,6};
  auto it = v.begin();
  auto it2 = std::next(v.begin(), 3);
  std::cout << std::distance(it, it2) << std::endl;
  it2 = std::prev(it2, 3);
  std::cout << std::distance(it2, v.begin()) << std::endl;
  



#if 0
  std::vector<int> v{1,2,3,4,5,6};
  auto it = std::next(v.begin(), 3);
  assert(*it == 4);
  it = std::next(it);
  assert(*it == 5);
  it = std::next(it,-2);
  assert(*it == 3);

  int step = 3;
  assert(step == distance(v.begin(),
                          next(v.begin(), step),


  std::vector<int> v{1,2,3,4,5,6};
  auto it = v.begin();
  //auto it2 = v.begin() + 3;
  //auto it2 = it;
  //std::advance(it2, 3);
  auto it2 = it + 3;
  assert(*it2 == 4);
  std::cout << std::distance(it , it2) << std::endl;
  std::cout << std::distance(it2 , it) << std::endl;

  std::forward_list<int> fl ={1,2,3,4};
  //auto  fit = fl.begin();
  //std::advance(fit, 2);
  //std::cout << std::distance(fit, fl.begin())
  //    << std::endl;


  //int step = 3;
  //auto l = fl.begin();
  //auto r = fl.begin();
  //advance(r, step);
  //assert(step == distance(l, r));




  //std::list<int> l{1,2,3,4,3,5,4};
  //std::cout << l.size() << std::endl;
  //std::forward_list<int> fl = {1,2,3,4,3,5,4};
  ////std::cout << fl.size() << std::endl;

  //std::cout << "size: "
  //    << std::distance(fl.begin(), fl.end()) 
  //    << std::endl;



    //std::vector<int> v{ 3, 1, 4 };
    //std::forward_list<int> v{ 3, 1, 4 };
    //auto vi = v.begin();
    //vi += 2;
    ////std::advance(vi, 2);
    //std::advance(vi, -2);
    ////assert(vi == v.end());
    //std::cout << *vi << '\n';
#endif
}
