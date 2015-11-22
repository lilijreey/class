/**
 * @file     main.cpp
 *           
 *
 * @author   lili  <lilijreey@gmail.com>
 * @date     2015年11月21日 14时50分13秒
 *
 */

#include "string.hpp"
#include <cstdio>


int main(int argc, char *argv[])
{
  String s;
  String s1("hello");
  String s2("");
  String s3(10);
  s2.length();
  s2.empty();
  s2.clear();
  s2 += "fjoef";
  String s5 = s2 ;
  s5.~String();

  String s6 = s3 + s5;
  String s7 = s3 + "oooo";
  s6 == "hellow";
  s6 != "hellow";
  //if (s6) {
  //}

  //s7[3];
  //s4.at(3);
  //s4.sub(3,10);
  //if (s3.length() == 0)
  
  printf("all passed\n");
  return 0;
}
