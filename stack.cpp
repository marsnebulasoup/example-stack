/*********************
Name: Kevin Bryniak
Assignment: Int Stack
A simple implementation of a data stack.
**********************/

#include "stack.h"

Stack::Stack(int size)
{
  this->size = (size < MIN_SIZE ? DEFAULT_SIZE : size);
  top = -1;
  stack = new Data *[size];
}

Stack::~Stack()
{
}

bool Stack::isEmpty()
{
  return top == -1;
}

bool Stack::push(int id, string &information)
{
  return false;
}

bool Stack::pop(Data &to)
{
  return false;
}

bool Stack::peek(Data &to)
{
  bool isEmpty = this->isEmpty();

  to.id = isEmpty ? -1 : stack[top]->id;
  to.information = isEmpty ? "" : stack[top]->information;

  return !isEmpty;
}

void Stack::dumpStack() // DEBUG ONLY
{

  std::cout << "\n-- Stack: (size: " << size << ", top: " << top << ") \n| ";
  for (int i = 0; i < size; i++)
  {
    std::cout << "(" << i << (i == top ? " - top " : "") << ") id: " << stack[i]->id << " | info: " << stack[i]->information;
  }
  std::cout << "-- End Stack --" << std::endl;
}