
#include <cstring>
#include <cassert>
#include "string.hpp"

String::String(const char* str) {
  if (str == nullptr)
    return;
   _strLen = strlen(str);
   _len = _strLen * 2;
   _buf = (char*)malloc(_len);
}

String::String(size_t size)
{
   _len = size;
   _buf = (char*)malloc(_len);
}

String::String(const String &o)
{
   _strLen = o._strLen;
   _len = o._len;
   _buf = (char*)malloc(_len);
   strcpy(_buf, o._buf);
}

String::~String() {
  free(_buf); //0
  _buf = nullptr;
  _strLen = 0;
  _len = 0;
}

void String::clear()
{
  _strLen = 0;
}

const char* String::c_str() const
{
  if (_buf == nullptr)
    return "";
  return _buf;
}

String& String::operator+=(const String &o)
{
  const char *str = o.c_str();
  size_t newStrLen = _strLen + strlen(str);
  if (_len < newStrLen) {
    _len = newStrLen * 2;
    _buf = (char *)realloc(_buf, _len);
  }

  strcpy(&_buf[_strLen], str);
  _strLen = newStrLen;

  return *this;
}
//String& String::operator+=(const char *str)
//{
  //size_t newStrLen = _strLen + strlen(str);
  //if (_len < newStrLen) {
    //_len = newStrLen * 2;
    //_buf = (char *)realloc(_buf, _len);
  //}

  //strcpy(&_buf[_strLen], str);
  //_strLen = newStrLen;

  //return *this;
//}



String String::operator+(const String &o)
{
  String tmp(*this);
  tmp += o;
  return tmp;
}

char String::operator[](int i) const
{
  if (i < 0) 
    i += (int)_strLen;

  if (i >= (int)_strLen || i < 0)
    assert(false && "index overflow");

  return _buf[i];
}

bool String::operator==(const String &o) const
{
  if (_buf == nullptr && o._buf == nullptr)
    return true;

  if (_buf == nullptr || o._buf == nullptr)
    return false;

  return strcmp(_buf, o._buf) == 0;
}

bool String::operator!=(const String &str) const
{
  return ! (*this == str);
}

operator String::bool() const
{
  return not empty();
}
