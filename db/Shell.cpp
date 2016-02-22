#include <regex>
#include <algorithm>
#include <iterator>
#include <string>
#include <iostream>
#include <stdio.h>
#include <map>
#include "Shell.hpp"
#include "Table.hpp"

//?????? ????? ??????? ????????
//CREATE TABLE test
//CREATE TABLE 
//INSERT table id "fjeosf"
//DELTE TABLE test 3


static bool s_isCmdEnd = false;
void Shell::showHelp() {
  const std::string msg=
"Usage: command;[comands]\n"
"comand:\n"
"  CREATE TABLE  <table> -- create a db table\n"
"  DESTROY TABLE <table> -- delete a table\n"
"  SHOW TABLE  <table> -- list all of table rows\n"
"  INSERT        <table> <data> -- insert data to table\n"
//"  UPDATE        <table> <id> -- update data from table\n"
"  DELETE        <table> <id> -- delete data from table\n"
"  SEARCH        <table> <pattern> -- serach data\n"
"  IMPORT        <table> [file] -- import file to table\n"
"  EXPORT        <file> [table] -- export table to fale\n";

  std::cout << msg << std::endl;
}

static void badCmd(const std::string &msg="") {
  std::cout << "Bad command " << msg << std::endl;
  //printf("Bad command\n");
  fflush(stdin);
}


void Shell::loop() {
  while (1) {
    //printf("--debug-- parseCmd\n");
    s_isCmdEnd = false;
    parseCmd();
  }
}

inline static bool isSplitChar(int c) {
  return isblank(c) or c == ';' or c == '\r' or c == '\n';
}

static std::string getToken() {
  std::string token;
  int c;
  while (EOF != (c = getchar())) {
    if (isSplitChar(c)) {
      if (c == ';') {
        s_isCmdEnd = true;
        if (token.empty())
          token += c;
        return token;
      } else {
        if (not token.empty())
          return token;
      }
      continue;
    }
    token += c;
    //printf("--debug %d:%s\n", c, token.c_str());
  }
  return token;
}

bool Shell::isEnd() {
  return s_isCmdEnd || ";" == getToken();
}

void Shell::parseCreateTableParams() {
  std::string token = getToken();
  //printf("parseCreate Table cmd table:%s\n", token.c_str());
  //TODO check is keyword
  //TODO check table is exist
  if (isEnd()) {
    if (DB::createTable(token)) {
      printf("create table %s successed\n", token.c_str());
    } else {
      printf("create table %s failed\n", token.c_str());
    }
    return ;
  }

  badCmd();
}

void Shell::parseInsertTableParams() {
  std::string doc = getToken();
  if (isEnd()) {
    if (DB::insertTable(_tableName, doc)) {
      printf("successed\n");
    } else {
      printf("failed\n");
    }
    return ;
  }
  badCmd();
}


void Shell::parseShowTableParams() {
  std::string token = getToken();
  
  if (!isEnd())
    badCmd();

  DB::showTable(token);
}

void Shell::parseShowTable() {
  std::string token = getToken();
  if (token != "TABLE") {
    badCmd();
    return;
  }
  parseShowTableParams();
}

void Shell::parseInsertTable() {
  _tableName = getToken();

  parseInsertTableParams();
}

void Shell::parseCreateTable() {
  std::string token = getToken();
  if (token != "TABLE") {
    badCmd();
    return;
  }

  parseCreateTableParams();
}

void Shell::parseDestroyTableParams() {
  std::string token = getToken();
  
  if (!isEnd())
    badCmd();

  if (DB::destroyTable(token)) 
    printf("successed\n");
  else
    printf("failed\n");
}


//DELETE test id
void Shell::parseDeleteTable() {
  std::string tableName = getToken();

  ////check table is exist
  //if (not DB::isTableExist(tableName)) {
  //  badCmd("table not exist");
  //  return ;
  //}

  //handler for DELETE test; 3
  if (s_isCmdEnd) {
    badCmd();
    return ;
  }

  std::string idStr= getToken();

  if (!isEnd())
    badCmd();


  //3ab32
  int id = atoi(idStr.c_str());
  //TODO check id is vailed

  if (DB::deleteTableDoc(tableName, id))
    printf("successed\n");
  else
    printf("failed\n");

}

void Shell::parseDestroyTable() {
  std::string token = getToken();
  //printf("--debug getToken:%s\n", token.c_str());
  if (token != "TABLE") {
    badCmd();
    return;
  }
  parseDestroyTableParams();
}


void Shell::parseCmd() {
  printf(">>");
  std::string token = getToken();
  if (token == ";")
    return;

  //printf("parseCmd\n");
  std::map<std::string, void (Shell::*)() > table{
    {"CREATE",  &Shell::parseCreateTable},
    {"DESTROY", &Shell::parseDestroyTable},
    {"SHOW"   , &Shell::parseShowTable},
    {"INSERT",  &Shell::parseInsertTable},

    {"DELETE",  &Shell::parseDeleteTable},
    {"SEARCH",  &Shell::parseCreateTable},
    {"IMPORT",  &Shell::parseCreateTable},
    {"EXPORT",  &Shell::parseCreateTable}
  };

  auto it = table.find(token);
  if (it == table.end()) {
    badCmd();
    return;
  }

  auto fn = it->second;
  (this->*fn)();
}


