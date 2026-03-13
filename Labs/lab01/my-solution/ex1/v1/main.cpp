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
* DEBUGGING:
note: to compile the code, used g++ at vscode.
note: to execute the code:
$ ./main 5
   Enter 5 real numbers
   3.2 1.5 4.8 2.1 0.9
   sorted array: 0.9 1.5 2.1 3.2 4.8

*/

#include <iostream>
#include <cstdlib> // for malloc, free, atoi, and exit



// 1. a function to allocate and read the array
float* allocate_and_read(int n) {
   // note: as suggested used malloc to allocate the array
   float* vet = (float *) malloc (n * sizeof (float)); // note: here we are allocating an array of floats of size n on the heap at memory address vet
                                                      // note: float* means that vet is a pointer to a float (malloc returns a void pointer that we need to cast to the appropriate type (float* in this case)).
   if (vet == nullptr) {
      std::cerr << "Error: Memory allocation failed!" << std::endl;
      exit(EXIT_FAILURE); // note: here we are existing the program at failure.
   }

   std::cout << "Enter " << n << " real numbers" << std::endl;
   for (int i = 0; i < n; i++) {
      std::cin >> vet[i];
   }

   return vet;
}

// 2. a function to sort the array (Insertion Sort)
// note: insertion sort algorithm in 3 steps:
// - Iterate from the second element to the end of the array
// - For each element, store it as the key and compare it with the elements before it
// - Shift elements that are greater than the key to one position ahead of their current position
void sort_array(float* vet, int n) { // note: n refers to size of the array.
   for (int i = 1; i < n; ++i) {
      float key = vet[i];
      int j = i - 1; // previous index

      // note: we need to move the elems greater than ey one position ahead.
      while(j >= 0 && vet[j] > key) { 
         vet[j + 1] = vet[j]; 
         j = j - 1;
      }
      vet[j + 1] = key; // note: 
   }
}

// 3. The third function displays the sorted array on standard output.
void display_array(const float* vet, int n) {
   std::cout << "sorted array: ";
   for (int i = 0; i < n; ++i) { // note: i++ means increment i by 1 in each iteration of the loop, 
                                 // but ++i means increment i by 1 before using it in the loop body. 
                                 // In this case, since we are using i to access the array elements, we can use either i++ or ++i without affecting the functionality of the code.
      std::cout << vet[i] << " ";

   }
   std::cout << std::endl;
}


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