#include <vector>
#include <stdio.h>
#include <assert.h>
#include <stdexcept>

void show(const std::vector<int> &c) {
  for (std::vector<int>::const_iterator it = c.begin(); it < c.end(); ++it)
  {
    printf("%d\n", *it);
  }
  printf("-----------------\n");
}

int main(int argc, char *argv[])
{
  //constructor
  std::vector<int> v;
  std::vector<int> v1= {10,20,30,40};
  std::vector<int> v2(4);
  std::vector<int> v3(4, 1);
  std::vector<int> v4(v1.begin(), v1.end());
  assert(v2.size() == 4);
  assert(v2[0] == 0);
  v4 = v1;
  //v2[10]= 4;
  try {
    v2.at(10);

  }catch(std::out_of_range e) {
    printf("at: %s\n", e.what());
  }catch(...) {
    printf("noknown except\n");
  }


  //const int& f = v4.front();
  v4.back() = 100;
  printf("front:%d back:%d\n", 
         v4.front(), v4.back());


  v4.clear();
  //insert
  v4.push_back(1);
  v4.push_back(2);
  v4.push_back(3);
  show(v4);


  //1,2,3
  std::vector<int>::const_iterator it = v4.cbegin();
  //0,1,2,3
  v4.insert(v4.begin(), 0);
  show(v4);
  //0,1,2,3,8,8
  v4.insert(v4.end(), 2, 8);
//  v4.insert(v4.end(), {8,8});
  show(v4);
  v4.insert(v4.begin()+3,
            v1.begin()+1, 
            v1.begin()+3);
  show(v4);

  v4.pop_back();
  show(v4);
  v4.erase(v4.begin());
  show(v4);
  v4.erase(v4.begin(), v4.begin()+4);
  show(v4);

  printf("c:%lu s:%lu\n", v4.capacity(),v4.size());
  v4.reserve(1);
  printf("c:%lu s:%lu\n", v4.capacity(),v4.size());
  v4.reserve(100);
  printf("c:%lu s:%lu\n", v4.capacity(), v4.size());
  v4.clear();

  v4 = {0,1,2,3,4,5,6};
  v4.resize(10);
  printf("s:%lu\n", v4.size());
  show(v4);
  v4.resize(13, 111);
  show(v4);

  v4 = {9,9,9};
  std::vector<int>::iterator iit = v4.begin();
  it = v4.insert(iit, 3);
  it = v4.insert(iit, 2);
  it = v4.insert(iit, 1);
  show(v4);
  //1,2,3,9,9,9
  
  //iit =v4.begin();
  //v4.erase(iit);
  //v4.erase(iit);
  //v4.erase(iit);
  //show(v4);
//printf("%d\n", v4.end() - v4.begin());





  
  return 0;
}

