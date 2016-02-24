#include <algorithm>
#include "Table.hpp"
#include "excpt.hpp"

//aa.table

std::map<std::string, Table> DB::_tables;

bool DB::updateTableDoc(const std::string &tableName,
                        size_t id,
                        const std::string &value) {

  if (not isTableExist(tableName))
    return false;
  
  auto it= _tables.find(tableName);
  return it->second.updateDoc(id, value);
}

bool DB::deleteTableDoc(const std::string &tableName,
                             size_t id) {

  if (not isTableExist(tableName))
    return false;

  auto it= _tables.find(tableName);
  it->second.deleteDoc(id);


  printf("TODO deleteTableDoc\n");
  return true;
}

bool DB::isTableExist(const std::string &tableName) {
  return _tables.count(tableName) == 1;
}


bool DB::createTable(const std::string &tableName) {
  if (isTableExist(tableName)) {
    throw DBTableNotExist(tableName);
    return false;
  }



  FILE *f = fopen(getTableFileName(tableName).c_str(), "a+");
  if (f == nullptr)  {
    //_tables.erase(tableName);
    throw DBCreateTableFailed(tableName);
  }
  fclose(f);

  Table t(tableName);
  _tables.insert(std::make_pair(tableName, t));
  return true;
}


bool DB::destroyTable(const std::string &tableName) {
  if (_tables.erase(tableName) == 1) {
    remove(getTableFileName(tableName).c_str());
    return true;
  }
  return  false;
}

Table* DB::getTable(const std::string &tableName) {
  auto it= _tables.find(tableName);
  if (it == _tables.end()) 
    return nullptr;

  return &(it->second);
}

bool DB::insertTable(const std::string &tableName, const std::string &doc) {
  Table* t = getTable(tableName);
  if (t == nullptr)
    return false;

  return t->insertDoc(doc);
}

void DB::showTable(const std::string &tableName) {
  Table* t = getTable(tableName);
  if (t == nullptr)
    return;

  return t->show();
}

Table::Table(const std::string &tableName) 
  : _name(tableName)
{}

//生成的id保证不和当前所有id重复
size_t Table::genId() {
  if (_rows.empty())
    return 1;
  return _rows.rbegin()->first + 1;
}

bool Table::insertDoc(const std::string &doc) {
  size_t id = genId();

  _rows.insert({id, Doc(id, doc)});
  return true;
}

bool Table::deleteDoc(size_t id) {
  _rows.erase(id);

  return true;
}

bool Table::updateDoc(size_t id, const std::string &doc) {
  //check id exist
  auto it = _rows.find(id);
  if (it == _rows.end()) 
    return false;

  it->second._doc = doc;
  return true;
}

std::string DB::getTableFileName(const std::string &tableName)
{
  return tableName + ".td";
}

void Table::show() const {
  printf("+---id---+-----doc-----+\n");
  std::for_each(_rows.cbegin(),
                _rows.cend(),
                [](const std::pair<size_t, Doc>&p) {
                  printf("|%5lu | %s |\n", p.first, p.second._doc.c_str());}
                );
  printf("+--------+-------------+\n");
}

