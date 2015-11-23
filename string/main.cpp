#include "string.hpp"
#include <cstdio>

#define	STR	 "0123456789"		/*  */
#define	STR1 "01234"		/*  */
#define	STR2 "56789"		/*  */

int main(int argc, char *argv[])
{
  String s;
  String s1(STR);
  String s2(s1);

  //check ==
  assert(s == "");
  assert(s1 == STR);
  assert(s1 == s2);
  assert(s1 != "012345678");
  assert(s != "xxx");
  assert(s1 != "xxxx");
  

  //check length empty
  assert(s.length() == 0);
  assert(s.empty());
  assert(s1.length() == s2.length());

  //check clear
  s1.clear();
  assert(s1.length() == 0);
  assert(s1.empty());

  //check operaot=
  s1 = s2;
  assert(s1.length() == s2.length());

  //[]
  assert(s2[0] == '0');
  assert(s2[1] == '1');
  assert(s2[2] == '2');
  assert(s2[3] == '3');
  assert(s2[9] == '9');
  assert(s2[-1] == '9');
  assert(s2[-2] == '8');
  assert(s2[-3] == '7');
  assert(s2[-9] == '1');
  assert(s2[-10] == '0');

  //check +=
  s1.clear();
  s2.clear();
  s3.clear();

  s1 = STR;
  s2 = STR1;
  s3 = STR2;
  s2 += s3;
  assert(s2 == s1);

  //check +
  s2.clear();
  s3.clear();

  s2 = STR1;
  s3 = STR2;
  s1 = s2 + s3;
  assert(s1 == STR);
  assert(s1 != s2);
  assert(s1 != s3);


  //s2 += "fjoef";
  //String s5 = s2 ;
  //s5.~String();

  //String s6 = s3 + s5;
  //String s7 = s3 + "oooo";
  //s6 == "hellow";
  //s6 != "hellow";
  //if (s6) {
  //}

  //s7[3];
  //s4.at(3);
  //s4.sub(3,10);
  //if (s3.length() == 0)
  
  printf("all passed\n");
  return 0;
}
