/**
 * @file     string.hpp
 * @desc  defined string class 
 */

#include <cstdlib>
class String 
{
 private:
   char *_buf = nullptr;
   size_t _len = 0;
   size_t _strLen=0;

 public:
  String(const char*str=nullptr);
  String(size_t size);
  String(const String &o);
  ~String();

  ///Retrun string length.
  inline size_t length() const {
    return _strLen;
  }

  ///Check instance is empty string.
  inline bool empty() const {
    return length() == 0;
  }

  ///Remove string
  void clear();

  String& operator+=(const String &);
  //String& operator+=(const char *str);
  String operator+(const String &str);
  bool operator==(const String &str) const;
  bool operator!=(const String &str) const;
  operator bool() const;


  char operator[](int i) const;

  const char *c_str() const;

  /////concatenate string
  //String operator+(const String &) const;

  /////append string
  //String operator+=(const String &) const;

  //char operator[](int index) const;

};


