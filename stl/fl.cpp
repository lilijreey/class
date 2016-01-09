#include <forward_list>
#include <list>
#include <assert.h>

//template <
          //typename T, 
          //template <typename X, typename Alloc>
          //class CO  >

void show(const std::list<int> &l)
{
  for (auto e : l)
    printf("%d\n", e);
  printf("-------------------\n");
}

int main(int argc, char *argv[])
{
  std::list<int> l;
  //1,2,3
  l.push_back(1);
  l.push_back(2);
  l.push_back(3);
  show(l);
std::list<int>::iterator it =  l.insert(l.begin(), 3);

  assert(*it == 3);
  l.insert(l.begin(), {2,6,6});

  show(l);
  //6,6,6, 1,2,3
  
  l.insert(l.end(), {8,8});
  //6,6,6,1,2,3,8,8

  std::list<int> l2{1,2,3,4,5};
  show(l2);
  it = l2.erase(++l2.begin());
  l2.erase(it);
  show(l2);



  //9 //6,6,6,1,2,3,8,8 //9

  return 0;
}


#if 0
void show(const std::forward_list<int> & l)
{
  std::forward_list<int>::const_iterator cit = 
      l.cbegin();


  for (; cit != l.cend(); ++cit)
  {
    printf("%d\n", *cit);
  }
  printf("---------------------\n");

}

int main(int argc, char *argv[])
{
  std::forward_list<int> l;
  //1,2,3,
  l.push_front(3);
  l.push_front(2);
  l.push_front(1);
  show(l);

  std::forward_list<int>::iterator it = l.begin();
  std::forward_list<int>::iterator nt;
  nt = l.insert_after(it, 100);
  //1,100,2,3
  show(l);

  //1,100,2,200,3
  //it++;
  //it++;
  //l.insert_after(it, 200);

  l.insert_after(++nt, 200);
  show(l);

  //nt = l.insert_after(it, 0, 8);
  nt = l.insert_after(it, 3, 8);
  l.insert_after(nt, 666);
  //1.8,8,8,
  show(l);

  // 1,8,8,8,666,100,2,200,3,
  std::forward_list<int> l1;
  assert(l1.begin() == l1.end());
  it = l.begin(); //1
  it++;//8
  it++;//8
  it++;//8
  it++;//666
  it++;//

  l1.insert_after(l1.before_begin(), l.begin(), it);
  show(l1);

  std::forward_list<int> l2 {1};

  //it = l2.begin();
  //it++;//3
  //it++;//5
  //it++;//7
  //it++;//9
  //l2.erase_after(l2.begin(), l2.end());
  //l2.clear();

  it = l2.erase_after(l2.before_begin());
  assert(l2.end() == it);

  //assert(*it == 5);
  show(l2);



  //1,2,3,3,4,5,6,7,8,9,10

  //show(l2);
  //for (it = l2.begin(); ; ++it) {
    //it = l2.insert_after(it, *it +1);
    //if (*it == 10)
      //break;
  //}
  //show(l2);


  return 0;
}

#endif
