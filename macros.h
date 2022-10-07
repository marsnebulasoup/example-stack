/*********************
Name: Kevin Bryniak
Assignment: Int Stack
A simple implementation of a data stack.
**********************/

#ifndef STACKS_MACROS_H
#define STACKS_MACROS_H

#define ASSERT_PASSED(expression, message) \
  if (!expression)                         \
  {                                        \
    cout << "Failed: " << message << endl; \
  }

#define ASSERT_DATA_IS_EMPTY(data) \
  ASSERT_PASSED(data->id == -1 && data->information == "", "returned data is empty.");

#endif // STACKS_MACROS_H