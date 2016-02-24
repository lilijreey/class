#ifndef TABLE_H_
#define TABLE_H_

#include <string>
#include <map>

struct Doc{
  Doc(size_t id, const std::string &doc) : _key(id), _doc(doc)
  {}


  void update(const std::string &doc) {
    _doc = doc;
  }

  const size_t _key;
  std::string _doc;
};

class Table {

 public:
  Table(const std::string &table) ;

  //Table(const Table&) = delete;
  //Table& operator=(const Table&) = delete;
public:

  bool insertDoc(const std::string &doc);
  bool updateDoc(size_t id, const std::string &doc);
  bool deleteDoc(size_t id);

  /** list table rows */
  void show() const;

 private:
  size_t genId();

  std::string _name;
  std::map<size_t, Doc> _rows;
};

class DB {
 public:
  static bool createTable(const std::string &tableName);
  static bool destroyTable(const std::string &tableName);
  static bool isTableExist(const std::string &tableName);
  static bool insertTable(const std::string &tableName, 
                          const std::string &doc);
  static bool deleteTableDoc(const std::string &tableName,
                             size_t id);

  static bool updateTableDoc(const std::string &tableName,
                             size_t id,
                             const std::string &value);

  static void showTable(const std::string &tableName);

  static std::string getTableFileName(const std::string &table);

 private:
  static Table* getTable(const std::string &tableName);


 private:
  static std::map<std::string/*tableName*/, Table> _tables;
};

#endif
