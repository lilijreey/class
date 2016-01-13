#include <stdio.h>
#include <map>
#include <string>
#include <utility>

void show(const std::map<int, std::string> &c) {
  std::map<int, std::string>::const_iterator cit = c.cbegin();

  for (; cit != c.cend(); ++cit)
    printf("%d:%s\n", 
           cit->first,
           cit->second.c_str());
  printf("--------------------\n");
}


int main(int argc, char *argv[])
{
  std::map<int, std::string> m;
  std::map<int, std::string> m1{
    {1,"aa"},
    {2,"bb"},
    {3,"cc"}
  };
  show(m1);
  std::map<int, std::string> m2(m1.begin(), m1.end());

  m1[143] = "oof";
  m1[100] = "xxc";


  std::pair<std::map<int,
                     std::string>::iterator, 
            bool> x =
  m1.insert(std::make_pair(100, "yyc"));
  if (x.second) 
    printf("insert ok\n");
  else {
    printf("insert failed\n");

  }
  printf("%d:%s\n", x.first->first, 
                    x.first->second.c_str());


  x = m1.insert(std::make_pair(77, "ookk"));
  m1.insert({88, "oo"});
  show(m1);

  m1.erase(88);
  m1.erase(33);
  
  return 0;
}
