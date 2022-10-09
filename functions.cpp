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

bool try_parse(char *c, int *i)
{
  int idx = 0;
  bool is_valid = true;
  do
  {
    if (!((idx == 0 && c[idx] == '-' && c[idx + 1] != '0' && c[idx + 1] != '\0') ||
          (c[idx] >= '0' && c[idx] <= '9')))
    {
      is_valid = false;
    }
  } while (is_valid && c[++idx] != '\0');

  if (is_valid)
  {
    *i = std::strtol(c, nullptr, 10);
  }
  return is_valid;
}
