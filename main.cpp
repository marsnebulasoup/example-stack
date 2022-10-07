/*********************
Name: Kevin Bryniak
Assignment: Int Stack
A simple implementation of a data stack.
**********************/

#include "main.h"

int main(int argc, char **argv)
{
  srand(time(NULL));

  int size;
  if (argc == 2)
  {
    size = atoi(argv[1]);
    cout << "---TESTS HAVE BEGUN----------------\n"
         << endl;
    cout << "Creating a stack of size " << size << endl;

    Stack stack(size);
    Data *data = new Data;

    cout << endl
         << "Running empty stack tests..." << endl;
    ASSERT_PASSED(stack.isEmpty(), "stack is initially empty.");

    ASSERT_PASSED(!stack.peek(*data), "stack peek failed because stack is empty.");
    ASSERT_DATA_IS_EMPTY(data);

    delete data;
    data = new Data;

    ASSERT_PASSED(!stack.pop(*data), "stack pop failed because stack is empty.");
    ASSERT_DATA_IS_EMPTY(data);
  }
  else
  {
    cout << "Error: You must pass one and only one integer argument when running this program." << endl;
    cout << "   i.e.: \"[program name] [int]\"" << endl;
  }

  return 0;
}
