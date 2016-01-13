#include <set>
#include <stdio.h>

#include <utility>
void show(const std::set<int> &c) {
  for (std::set<int>::const_iterator it = c.begin(); it != c.end(); ++it)
  {
    printf("%d\n", *it);
  }
  printf("-----------------\n");
}

int main(int argc, char *argv[])
{
  std::set<int> s;
  std::set<int> s1{32, 11, 21,6, 3};

  show(s1);

  std::set<int, std::greater<int>> s2{32, 11, 21,6, 3};
  for (auto e : s2) 
    printf("%d\n", e);

  std::set<int> s3(s1.begin(), s1.end());
  
  std::set<int> s4{1,1,1,1,2};
  show(s4);

  //s4.insert(2);
  //s4.insert({56,7,8});
  std::pair<std::set<int>::iterator ,bool> 
      p = s4.insert(3);
  printf("inset successed? %d :%d\n",
         p.second, 
         *(p.first));

  //std::pair<int, double> t();
  //std::pair<int, double> t1{1, 0.11};
  //std::pair<int, double> t2(1,0.11);
  //std::pair<int, double> t3 = std::make_pair(1,0.11);


  //std::tuple
  return 0;
}

