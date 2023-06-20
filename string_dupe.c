#include <stdio.h>
#include <string.h>

// TL;DR
//   Fill in string_copy to complete the challenge. The output should
//   print "Hello, world!" twice.
// 
// CHALLENGE
//   Complete the string_copy() function. You may assume the strings
//   are *guaranteed* to be null terminated and can use this assumption
//   to complete the challenge. You must follow the following rules
// 
// RULES
//   - You *may not* index the strings like an array, you must use pointers
//     to navigate through the data (refer to hints on how to do this)
//   - You *may not* use any standard library string functionality for this
//     challenge (such as strlen())
// 
// HINTS
//   - Both pointers and arrays describe locations of data. Since pointers
//     "point" to locations in memory, we can tell a pointer to point to
//     an array
//     
//     int arr[3];
//     int* p = arr; // Pointer now points to front of array *p == arr[0]
// 
//   - Since pointers are represented by integers, we can perform math
//     operations on them
//     p++;          // If we add to the pointer, we go to the next address
//                   // (next element in the array) *(p) == arr[1]
//     p++;          // And again *p == arr[2]
//
//   - We have to make sure we don't try to access an address to memory that
//     doesn't belong to us
// 
//     p++; // Arr is only 3 chars in size! This will go out of bounds and could
//          // segfault or allow access to memory we don't want the user to have!
// 
//   - And of course, we know how to dereference a pointer, but here is some
//     review
// 
//     int arr[2] = {1, 2};
//     int* p = arr;        // *p == arr[0] == 1
//     p++;                 // *p == arr[1] == 2
//     
//     int x = *p           // x == 2

void string_copy(char original[256], char copy[256])
{
    char* p = original;
    char* q = copy;
    while (*p != '\0')
    {
        *q = *p;
        p++;
        q++;

    }
}


int main(void)
{
    
    char original[256] = "Hello, world!";
    char copy[256] = {'\0'};
    
    string_copy(original, copy);
    
    printf("The below code should print the same string twice.\n");
    printf("%s\n", original);
    printf("%s\n", copy);

    return 0;
}