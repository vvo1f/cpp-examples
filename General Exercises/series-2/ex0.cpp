/**
 * System and Device Programming - topic: Process Creation and Management
 * * LOGIC TRACE:
 * 1. Initial Process:
 * - Parent Process created
 * * 2. First fork():
 * - Two Processes: Parent and Child
 * * 3. Loop Iteration 1 (i=0):
 * - Parent Process:
 *  - fork() creates Child1
 * - Executes system("echo S") -> Outputs "S"
 * - Child Process:
 * - Executes execlp("echo", "myPgrm", "E")
 * -> Outputs "E"
 * * 4. Loop Iteration 2 (i=1):
 * - Parent Process:
 * - fork() creates Child2
 * - Executes system("echo S") -> Outputs "S"
 * - Child Process:
 * - Executes execlp("echo", "myPgrm", "E")
 * -> Outputs "E"
 * * 5. Final Output:
 * - The combined output from all processes could be:
 * "S E S E" in various orders depending on scheduling.
 * * OUTPUT: The output consists of multiple "S" and "E" characters,
 * 
 * 
**/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main () {
    char str[100];
    int i;
    setbuf (stdout, 0);
    fork();
    for (i=0; i<2; i++){
        if (fork()!=0) {
            sprintf (str, "echo S");
            system (str);
        } else {
            sprintf (str, "E");
            execlp ("echo", "myPgrm", str, NULL);
        }
    }
    return (0);
}