/*
 * Your comment header here
 * modify this file as needed to complete the assignment
 */

#include "functions.h"

string rand_string(){
    // create size 0 to MAXSTRSIZE-1
    int rnum = rand() % MAXSTRSIZE;
    
    // make buffer to hold rand string
    string str = "";

    // fill buffer with random characters A to Z
    int i = 0;
    for(; i < rnum; i++){
        str += (rand() % ('Z' - 'A' + 1)) + 'A';
    }    

    // transfer buffer to passed in string
    
    return str;
}

