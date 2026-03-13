/*
Description:
    Given the following program, draw the process generation tree and
    explain what it displays and why.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
  pid_t pid;
  int i;
  setbuf (stdout,0);
  for (i=1; i<=3; i++){
    switch (i) {
      case 1: fork(); break;
      case 2: pid=fork(); if (pid!=0) system ("echo case 2"); break;
      case 3: execlp ("echo", "myPgrm", "case 3", NULL); break;
    }
  }
  return (0);
} 

/*
OUTPUT:
$ g++ main.cpp -o main
    case 2
    case 2
    case 3
    case 3
    case 3
    case 3
*/

/*
EXECUTION ANALYSIS:
    Iteration i = 1:
        P0 executes switch(1) $\rightarrow$ case 1: fork(); break;
        P0 creates a child process, P1.
        Both P0 and P1 exit the switch statement and loop back for the next iteration.
        Active Processes: P0, P1.
    Iteration i = 2:
        Both P0 and P1 execute switch(2) $\rightarrow$ case 2: pid=fork(); if (pid!=0) system("echo case 2"); break;
        P0 forks and creates P2.
            In P0 (the parent), pid is non-zero (it's P2's ID), so P0 executes system("echo case 2"). It prints "case 2" and waits for the system call to finish.
            In P2 (the child), pid is 0, so it skips the system call.
        P1 forks and creates P3.
            In P1 (the parent), pid is non-zero, so P1 executes system("echo case 2"). It prints "case 2".
            In P3 (the child), pid is 0, so it skips the system call.
        All four processes exit the switch and loop back.
        Active Processes: P0, P1, P2, P3.
    Iteration i = 3:
        All four processes (P0, P1, P2, P3) execute switch(3) $\rightarrow$ case 3: execlp("echo", "myPgrm", "case 3", NULL); break;
        The execlp function completely replaces the current process memory image with a new program (the echo command).
        All four processes become echo processes, print "case 3", and then terminate immediately.
        Because exec replaces the program, the loop is destroyed. The break; and return(0); are never reached.
*/


/*
    note: Three fundamental POSIX process management functions: fork(), exec(), and system().
    note: fork() Duplicates the process. Returns twice (once in parent returning child's PID, once in child returning 0).
    note: exec() family Replaces the process. 
        Returns ZERO times (unless it fails, in which case it returns -1). 
        If you put code after a successful exec, it will never be executed! 
    note: A convenient wrapper. It essentially does fork() + exec(shell) + wait(). It pauses your C program, runs the terminal command, and then gives control back to your C program.
*/