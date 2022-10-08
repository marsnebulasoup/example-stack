/*********************
Name: Kevin Bryniak
Assignment: Int Stack
A simple implementation of a data stack.
**********************/

#ifndef STACKS_MACROS_H
#define STACKS_MACROS_H

#define ASSERT_PASSED(expression, message) \
  if (!(expression))                       \
  {                                        \
    cout << "Failed: " << message << " (top: " << top << ")" << endl; \
  }

#define ASSERT_DATA_IS_EMPTY(data) \
  ASSERT_PASSED(data->id == -1 && data->information == "", "returned data should be empty.");

#define ASSERT_EQUAL_DATA(data1, data2, message) \
  ASSERT_PASSED(data1.id == data2.id && data1.information == data2.information, message);

#define ASSERT_UNEQUAL_DATA(data1, data2, message) \
  ASSERT_PASSED(data1.id != data2.id || data1.information != data2.information, message);

#endif // STACKS_MACROS_H