/*********************
Name: Kevin Bryniak
Assignment: Int Stack
A simple implementation of a data stack.
**********************/

#ifndef STACK_H
#define STACK_H

#include "data.h"
#include <string>
#include <iostream> // DEBUG ONLY

using std::string;

#define MIN_SIZE 2
#define DEFAULT_SIZE 10

class Stack
{

public:
  Stack(int);
  ~Stack();

  bool isEmpty();
  bool push(int, string&);
  void pop(Data&);
  void peek(Data&);

  // DEBUG ONLY
  void dumpStack();

private:
  int top;
  int size;
  Data **stack;
  // notice stack is a pointer to a pointer. That means if you do
  // a single array allocation, you will get an array of pointers
};

#endif // STACK_H
