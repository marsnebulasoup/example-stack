/*
 * Your comment header here
 * modify this file as needed to complete the assignment
 */

#include "functions.h"

void rand_int(int *integer)
{
  *integer = rand() * (rand() % 2 ? 1 : -1);
}

void rand_string(string *str)
{
  // create size 0 to MAXSTRSIZE-1
  int rnum = rand() % MAXSTRSIZE;

  // make buffer to hold rand string
  char *buffer = new char[rnum + 1];

  // fill buffer with random characters A to Z
  int i = 0;
  for (; i < rnum; i++)
  {
    buffer[i] = (rand() % ('Z' - 'A' + 1)) + 'A';
  }
  buffer[i] = '\0';

  // transfer buffer to passed in string
  *str = buffer;

  // clean up
  delete buffer;
  return;
}

bool try_parse(char *c, int *i )
{
  int parsed = std::strtol(c, nullptr, 10);
  int parsed_length = std::to_string(parsed).length();
  int orig_length = 0;
  while(c[++orig_length] != '\0');
  if(parsed_length == orig_length) *i = parsed;
  return parsed_length == orig_length;
}
