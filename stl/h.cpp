#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <initializer_list>


class Stack {
  enum {MAX_LEN=10};
  int buf[MAX_LEN];
  int top =0;

 public:
  explicit Stack(const std::initializer_list<int> &i) {
    for (auto e :i) {
      push(e);
    }

  }
  void push(int e) {
    if (top >= MAX_LEN)
      return;
    buf[top++] = e;
  }

  void show() const {
    for (int i =0; i < top; ++i)
      printf("%d", buf[i]);
    printf("---------------\n");
  }
};

int main(int argc, char *argv[])
{
  int i=3;
  int &j=i;
  auto k = j;
  k = 100;
  printf("%d\n", j);
  //std::array<int, 34>
  //std::initializer_list<int> i={1,3,4,5};
  //printf("i.size:%lu sizeof:%lu\n", i.size(),
  //sizeof(i));

  //std::initializer_list<int> i={1,2,3};
  //Stack s{1,2,4};
  //s.push(1);
  //s.push(2);
  //s.push(3);
  //s.show();
  
  return 0;
}

#if 0
//void show(const std::unordered_set<int> & c)
void show(int c)
{
}
int main(int argc, char *argv[])
{
  std::array<int, 5> x{1,3,4,5,64};

  for (const auto& e : x) {
    printf("%d\n",e);
  }

  return 0;
}

int main(int argc, char *argv[])
{
  //std::unordered_map<int, std::string> hm;
  std::unordered_map<int, std::string> hm
  {{1,"aa"}, 
   {2,"bb"}};

 //piar<int, std::string> a{3,"cc"};
  //hm.insert(std::make_pair(3,"cc"));
  hm.insert({2, "cc"});
  std::string& v= hm[100];
  printf("v:%s\n",v.c_str());



  //std::unordered_map<int, std::string>::iterator it = hm.begin();
  auto it = hm.begin();
  printf("key:%d\n", it->first);
  
  auto i = 100;
  printf("i:%d\n", i);
  auto& j = i;
  j = 111;
  printf("i:%d\n", i);




  

  //copy constructor
  //itertor 


  return 0;
}



int main(int argc, char *argv[])
{
  std::unordered_set<int> h;
  std::unordered_set<int> h1={1,2,3,4,5};
  std::unordered_set<int> h2(h1);
  std::unordered_set<int> h3(h1.begin(),
                             h2.end(),10);
  std::unordered_set<int> h4(3);
  show(h1);
  show(h3);
  show(h4);

  //std::pair<std::unordered_set<int>::iterator,
      //xx> = h.insert(1); show(h);
  h.insert({1,2}); show(h);
  h.insert(h1.begin(), h1.end()); show(h);

  h.erase(2);
  show(h);
  h.erase(h.begin());
  show(h);
  h.erase(h.begin(), h.end());
  show(h);

  assert(h.count(3) == 0);
  h.insert(3);
  assert(h.find(3) != h.end());

  printf("all pass\n");

  std::unordered_multiset<int> ms={1,3,4,2,3,4,5,10};
  for (auto x: ms) 
    printf("%d\n", x);

  ms.insert(3);
  
  return 0;
}

#endif
