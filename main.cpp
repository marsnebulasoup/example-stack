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
    int top = -1;
    int failureCount = 0;

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

    cout << "Running random tests..." << endl;
    Data *currentData = new Data;
    Data *previousData = new Data;
    Data *tempData = new Data;
    for (int i = 0; i <= size * TEST_SIZE_MULTIPLIER; i++)
    {
      bool shouldPush = rand() % 2 == 0;
      currentData = new Data;
      rand_int(&currentData->id);
      rand_string(&currentData->information);

      cout << setw(8) << left << i
           << setw(8) << (shouldPush ? "-> PUSH" : "<- POP")
           << setw(15) << right << (shouldPush ? to_string(currentData->id) : "")
           << setw(15) << "top (old): " << top << "" << endl;

      tempData = new Data;

      if (shouldPush) // Test push()
      {
        if (top < size - 1) // Stack should not be full.
        {
          if (currentData->id <= 0 || currentData->information.length() <= 0) // Invalid data, attempt to push it
          {
            ASSERT_PASSED(!stack.push(currentData->id, currentData->information), "pushing random invalid data into the non-full stack succeeded.");
            if (top != -1) // If stack isn't empty, check if the data wasn't added
            {
              ASSERT_PASSED(stack.peek(*tempData), "peeking the invalid data just pushed into the full stack.");
              ASSERT_UNEQUAL_DATA(tempData, currentData, "checking if the invalid data just pushed is not there");
            }
          }
          else // Valid data, push it
          {
            ASSERT_PASSED(stack.push(currentData->id, currentData->information), "pushing random data into the non-full stack.");
            ASSERT_PASSED(stack.peek(*tempData), "peeking the data just pushed into the non-full stack.");
            ASSERT_EQUAL_DATA(tempData, currentData, "checking if the data just pushed is correct");
            ASSERT_PASSED(!stack.isEmpty(), "checking if the stack is not empty");
            top++;
          }
        }
        else // Stack should be full or the data is invalid.
        {
          ASSERT_PASSED(!stack.isEmpty(), "checking if the stack is not empty");
          ASSERT_PASSED(!stack.push(currentData->id, currentData->information), "pushing random data into the full stack succeeded.");
          ASSERT_PASSED(stack.peek(*tempData), "peeking the data just pushed into the full stack.");
          ASSERT_UNEQUAL_DATA(tempData, currentData, "checking if the data just pushed is not there");
        }
      }
      else // Test pop()
      {
        if (top == -1)
        {
          // pop() should fail; top of stack should be empty
          ASSERT_PASSED(!stack.pop(*tempData), "popping item off the stack should fail");
          ASSERT_DATA_IS_EMPTY(tempData);

          delete tempData;
          tempData = new Data;

          // peek() should fail for the same reason.
          ASSERT_PASSED(!stack.peek(*tempData), "peeking item on the top of the stack");
          ASSERT_DATA_IS_EMPTY(tempData);
        }
        else
        {
          // pop should succeed
          ASSERT_PASSED(stack.pop(*tempData), "popping item off the stack should succeed");
          ASSERT_EQUAL_DATA(tempData, previousData, "checking if the popped data is equal to the previous data");
          top--;
        }
      }

      delete tempData;
      stack.peek(*previousData);
    }

    cout << "Dumping final stack:" << endl;
    stack.dumpStack();

    cout << "---TESTS HAVE ENDED----------------\n"
         << endl;
    cout << "Tests completed with " << failureCount << " failure(s)." << endl;
  }
  else
  {
    cout << "Error: You must pass one and only one integer argument when running this program." << endl;
    cout << "   i.e.: \"[program name] [int]\"" << endl;
  }

  return 0;
}
