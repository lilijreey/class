#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <map>

FILE *open_file(const char *file)
{
  FILE *f = fopen(file, "r");
  if (f == nullptr) {
    perror("fopen");
    exit(1);
  }
  return f;
}

void read_word(FILE *f, std::map<std::string, int> &m)
{
  int c;
  char word[20];
  int i=0;
  while ((c = fgetc(f)) != EOF) {
    if (isalpha(c)) {
      word[i++] = tolower(c);
      continue;
    } 
    word[i] ='\0';
    //printf("%s\n",word);
    if (i != 0)
      m[std::string(word)]++;
    i=0;
  }
}

void show_stat(const std::map<std::string, int>&m)
{
  for (std::map<std::string, int>::const_iterator it = m.begin();
       it != m.end();
       ++it)
    printf("%10s:%d\n", it->first.c_str(), it->second);
}

int main(int argc, char *argv[])
{
  FILE * f = open_file("word.txt");

  std::map<std::string, int> m;
  read_word(f, m);

  show_stat(m);

  
  return 0;
}

