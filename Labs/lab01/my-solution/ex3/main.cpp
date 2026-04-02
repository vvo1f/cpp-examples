/**
 * @file main.cpp
 * @author Salar Farahmand
 * @version 0.1
 * 
 * @copyright Copyright (c) 2026
 * 
 */

/*
    Exercise 03
    Code analysis: fork, exec, system
    ---------------------------------

    Given the following program, draw the process generation tree and
    explain what it displays and why.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main () {
int i;
setbuf (stdout,0);
for (i=0; i<2; i++) {
    printf ("i=%d\n", i);
    if (fork())             // Call # 1
    fork ();              // Call # 2
    else
    system ("echo i=i");  // Call # 3
}
return (1);
}



/*
OUTPUT:
i=0
i=1
i=1
i=i
i=1
i=i
i=i
i=i

EXPLANATION:
1. The program starts with a single process (let's call it P0).
2. In the first iteration of the loop (i=0):
   - P0 prints "i=0".
   - P0 calls fork() (Call #1), creating a child process (P1).
   - Both P0 and P1 execute the next fork() (Call #2):
     - P0 creates another child process (P2).
     - P1 creates another child process (P3).
   - P0 and P1 continue to the next iteration of the loop (i=1):
     - P0 prints "i=1".
     - P0 calls fork() (Call #1), creating a child process (P4).
     - P1 calls fork() (Call #1), creating a child process (P5).
   - P2 and P3 do not execute the next fork() (Call #2) because they are in the child process created by the first fork() (Call #1).
   - P4 and P5 do not execute the next fork() (Call #2) because they are in the child process created by the second fork() (Call #2).
3. The processes P2 and P3 execute the system("echo i=i") (Call #3), printing "i=i" to the console.
4. The processes P4 and P5 do not execute the system("echo i=i") (Call #3) because they are in the child process created by the second fork() (Call #2).
5. The final output consists of the printed values of "i=0", "i=1", and "i=i" from the respective processes. 





*/