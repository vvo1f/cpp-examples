/**
 * System and Device Programming - Exercise 0
 * * PROBLEM DESCRIPTION:
 * The program takes an integer parameter N.
 * It recursively creates processes using fork() and execlp() until N <= 0.
 * It prints '0' at the start of every process.
 * It prints '1' in the parent branch of a fork.
 * It prints '2' in the child branch of a fork.
 * * INPUT:
 * Run the program with a single argument equal to 2.
 * Example command: ./program 2
 * * EXPECTED OUTPUT:
 * The total count of printed characters '0', '1', and '2'.
 * Answer: 5 2 2
 * * EXECUTION TRACE:
 * 1. P(2) starts -> prints "0".
 * - Forks. 
 * - Parent P(2) prints "1", becomes P(1).
 * - Child  P(2) prints "2", becomes P(0).
 * * 2. P(1) starts (from parent of P2) -> prints "0".
 * - Forks.
 * - Parent P(1) prints "1", becomes P(0).
 * - Child  P(1) prints "2", becomes P(-1).
 * * 3. P(0) starts (from child of P2) -> prints "0", exits.
 * 4. P(0) starts (from parent of P1) -> prints "0", exits.
 * 5. P(-1) starts (from child of P1) -> prints "0", exits.
 * * TOTALS:
 * "0": 5 times (P(2), P(1), P(0)x2, P(-1))
 * "1": 2 times (Parent paths of P(2) and P(1))
 * "2": 2 times (Child paths of P(2) and P(1))
 */

#include <stdio.h>   // For printf, sprintf, setbuf
#include <stdlib.h>  // For atoi, exit, system
#include <unistd.h>  // For fork, execlp

int main (int argc, char *argv[]) {
    char str[50];
    int i;

    // Disable output buffering so prints appear immediately on screen
    setbuf (stdout, 0);

    // Every process prints "0" immediately upon starting
    printf ("0");

    // Convert the first command line argument to an integer
    // If running ./program 2, argv[1] is "2"
    if (argc > 1) {
        i = atoi (argv[1]);
    } else {
        // Fallback if no argument is provided
        exit(1);
    }

    // Base case: if i <= 0, the process terminates
    if (i <= 0)
        exit (0);

    // Fork creates a duplicate process
    if (fork () > 0) {
        // --- PARENT PROCESS BLOCK ---
        
        // Prepare string "echo 1"
        sprintf (str, "echo 1");
        // Execute shell command: prints "1" to screen
        system (str);

        // Prepare string for next recursion: current i minus 1
        sprintf (str, "%d", i-1);
        
        // Replace current process image with a new instance of this same program
        // effectively restarting main() with argument (i-1)
        execlp (argv[0], argv[0], str, NULL);
        
    } else {
        // --- CHILD PROCESS BLOCK ---
        
        // Prepare string "echo 2"
        sprintf (str, "echo 2");
        // Execute shell command: prints "2" to screen
        system (str);

        // Prepare string for next recursion: current i minus 2
        sprintf (str, "%d", i-2);

        // Replace current process image with a new instance of this same program
        // effectively restarting main() with argument (i-2)
        execlp (argv[0], argv[0], str, NULL);
    }

    return 0;
}
