/*********************
Name: Kevin Bryniak
Assignment: Int Stack
A simple implementation of a data stack.
**********************/

#ifndef STACKS_FUNCTIONS_H
#define STACKS_FUNCTIONS_H

#define MAXSTRSIZE 8

#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */
#include <time.h>   /* time */
#include <string>   /* string */

using std::string;

void rand_int(int *);
void rand_string(string *);

bool try_parse(char *, int *);

#endif /* STACKS_FUNCTIONS_H */