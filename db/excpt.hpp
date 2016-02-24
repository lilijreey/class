#include <exception>

class DBException : public std::exception{
 public:
  DBException(const std::string &type="") {
    _type = type;
  }

  virtual const char * what() const
      noexcept
      override
  {
    return _what.c_str();

  }

 protected:
  std::string _type;
  std::string _what;
};

class DBTableNotExist : public DBException {
 public:
  DBTableNotExist(const std::string &tableName)
      :DBException("[DBTableNotExist] expception ")
  {
    _what = _type + " " + tableName + "not exist";
  }
};

class DBCreateTableFailed: public DBException {
 public:
  DBCreateTableFailed(const std::string &tableName)
      :DBException("[DBCreateTableFailed] expception ")
  {
    _what = _type + " " + tableName + " create failed";
  }
};


//class DBCmdInvaild : DBException {
// public:
//  DBCmdInvaild(const std::string &msg="") {
//    _what = "[error] cmd invalied " + msg;
//  }
//};

