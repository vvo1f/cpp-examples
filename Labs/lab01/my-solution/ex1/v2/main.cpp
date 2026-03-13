/**
 * @file main.cpp
 * @author Salar Farahmand
 * @version 0.1
 * 
 * @copyright Copyright (c) 2026
 * 
 */

/*
Description:
The main program receives an integer n on the command line.
Then, it calls three functions:
1. The first one dynamically allocates an array of size "n" of real values
   and reads the array from standard input.
2. The second sorts the array in increasing order.
3. The third function displays the sorted array on standard output.

Write, compile, and debug two versions of this project:
1. The first one includes all functions in a single C++ file.
2. The second one inserts the main and the three functions in three
   separate ".cpp" files. Use a private ".h" file for global
   declarations and definitions.

Suggestions
-----------

1. Define the array using C-like dynamic memory allocation:
   float *vet;
   ...
   vet = (float *) malloc (n * sizeof (float));
   if (vet==nullptr) { ... error ... }

2. Uses one of the main sorting algorithms at your choice (i.e.,
   insertion sort, selection sort, quick-sort, etc.)

*/

/*
* DEBUGGING (multi-files) in Vscode:

> STEP#1: compile the files into one executable file:
way#1: Terminal (Recommended)
$ g++ main.cpp io.cpp sort.cpp -o main
OR
$ g++ *.cpp -o sorter_multi

way#2: using tasks.json in vscode:
- open main.css
- Go to Terminal > configure Default Build Task
- select C/C++:g++ build active file
- open .vscode (hidden) > tasks.json file
- look for "args" array then find the line with "${file}" then:
- change "${file}" to "${workspaceFolder}/*.cpp" to compile all the cpp files in the workspace folder.
   "args": [
      "-fdiagnostics-color=always",
      "-g",
      "${workspaceFolder}/*.cpp", // <--- THIS IS THE MAGIC LINE
      "-o",
      "${fileDirname}/${fileBasenameNoExtension}"
   ],


> STEP#2: Execute the code:
$ ./sorter_multi 5
   Enter 5 real numbers
   3.2 1.5 4.8 2.1 0.9
   sorted array: 0.9 1.5 2.1 3.2 4.8

*/

#include <iostream>
#include <cstdlib> // for malloc, free, atoi, and exit
#include "array_utils.h" // note: include with <> means that the file is a system header file, while include with "" means that the file is a user-defined header file. 


int main(int argc, char *argv[]) {
   // check command line args
   if (argc != 2) {
      std::cerr << "Usage: " << argv[0] << " <number_of_elements>>" << std::endl;
      return EXIT_FAILURE; // note: EXIT_FAILURE is a macro defined in <cstdlib> that indicates unsuccessful program termination. It is typically used to indicate that an error occurred during the execution of the program. 
   } 

   int n = std::stoi(argv[1]); // note: stoi stands for String TO Integer as part of standard <string> libray of C++.
   // validation
   if (n <= 0) {
      std::cerr << "ERROR: number of elements must be greater than 0, man!" << std::endl;

      return EXIT_FAILURE;
   }

   // using functions
   float* myArray = allocate_and_read(n);
   sort_array(myArray, n);
   display_array(myArray, n);

   // free the dynamically allocated memory
   free(myArray);
   
   return 0;
}