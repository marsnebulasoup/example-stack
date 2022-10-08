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
  stack = new Data *[this->size];
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
  bool isValid = id > 0 && information.length() > 0;
  bool hasSpace = top < (size - 1);
  if (isValid && hasSpace)
  {
    stack[++top] = new Data{id, information};
  }
  return isValid && hasSpace;
}


bool Stack::pop(Data &to)
{
  bool peekSuccessful = peek(to);
  if (peekSuccessful)
  {
    delete stack[top--];
  }
  return peekSuccessful;
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
  std::cout << "\n-- Stack: (size: " << size << ", top: " << top << ") |" << std::endl;
  for (int i = 0; i < size; i++)
  {
    if (i <= top)
    {
      std::cout << "(" << i << (i == top ? " - top " : "")
                << ") id: " << stack[i]->id
                << " | info: " << stack[i]->information
                << std::endl;
    }
    else
    {
      std::cout << "(" << i << ") empty" << std::endl;
    }
  }
  std::cout << "-- End Stack --" << std::endl;
}