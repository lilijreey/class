
//#include <algorithm>
#include <string>
#include <stdio.h>

class Person {
 public:
  Person(int id, const std::string& name)
      : id(id)
        ,name(name)
  {}
  void show() const {
    printf("id:%d\n", id);
  }

  static bool bcmp(const Person& l, const Person& r)
  {
    return l.id < r.id;
  }

  bool operator()(const Person& l, const Person& r) const
  {
    printf("comp\n");
    return l.id < r.id;
  }
 private:
  int id;
  std::string name="aa";
};



template <typename T>
T min(T l, T r) {
  if (l < r)
    return l;
  else
    return r;
}

template <typename T, typename Cmp>
T min(T l, T r, Cmp cmp) {
  if (cmp(l, r))
    return l;
  else
    return r;
}

int main(int argc, char *argv[])
{
  //int i=3;
  //int b=5;
  //printf("min:%d\n", min(i, b));
  Person p1(123, "gg");
  Person p2(33, "ff");
  //min(p1, p2, Person::bcmp).show();

  min(p1, p2).show();
  min(p1, p2, p2).show();
  p1(p1, p2);
  printf("min:%d\n",std::min({1,3,4,32,5,3}));
  std::vector<int> v={3,3,2,45,2,23};
  int m = std::min_element(v.begin(), v.end())
      
  return 0;
}
