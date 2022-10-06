/*********************
Name: Kevin Bryniak
Assignment: Int Stack
A simple implementation of a data stack.
**********************/

#include "stack.h"

Stack::Stack(int size)
{
}

Stack::~Stack()
{
}

bool Stack::isEmpty()
{
  return false;
}

bool Stack::push(int id, string &information)
{
  return false;
}

void Stack::pop(Data &to)
{
}

void Stack::peek(Data &to)
{
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