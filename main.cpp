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

    cout << "Running random tests" << endl;
    int top = -1;
    Data currentData;
    Data previousData;
    for (int i = 0; i <= size + 50; i++)
    {
      bool shouldPush = rand() % 2 == 0;
      currentData.id = rand();
      currentData.information = rand_string();

      int prevTop = top; //== -1 ? currentRandomTestId : stack.peek(*data);

      cout << setw(8) << left << i
           << setw(8) << (shouldPush ? "-> PUSH" : "<- POP")
           << setw(15) << right << (shouldPush ? to_string(currentData.id) : "")
           << setw(15) << "top (old): " << top << "" << endl;

      if (shouldPush) // Test push()
      {
        Data currTop;
        if (top < size - 1) // Stack should not be full.
        {
          ASSERT_PASSED(stack.push(currentData.id, currentData.information), "pushing random data into the stack.");                                    // Push random data into stack.
          ASSERT_PASSED(stack.peek(currTop), "peeking the data just pushed.");                                                                             // Get current element at top of stack.
          ASSERT_PASSED(currTop.id == currentData.id && currTop.information == currentData.information, "checking if the data just pushed is correct"); // Assert that the top of the stack is the random data just placed into it.
          ASSERT_PASSED(!stack.isEmpty(), "checking if the stack is not empty");                                                                           // Assert that the stack is not empty.
          top++;
        }
        else // Stack should be full.
        {
          ASSERT_PASSED(!stack.push(currentData.id, currentData.information), "pushing random data into the stack");                              // Push a random int into stack; expect an overflow error.
          ASSERT_PASSED(stack.peek(currTop), "peeking the data just pushed.");                                                                       // Get current element at top of stack; expect no exception.
          ASSERT_PASSED(currTop.id != currentData.id && currTop.information != currentData.information, "checking if the data just pushed is correct"); // Assert that the top of the stack is the same as before.
        }
      }
      previousData.id = currentData.id;
      previousData.information = currentData.information;
    }
  }
  else
  {
    cout << "Error: You must pass one and only one integer argument when running this program." << endl;
    cout << "   i.e.: \"[program name] [int]\"" << endl;
  }

  return 0;
}
