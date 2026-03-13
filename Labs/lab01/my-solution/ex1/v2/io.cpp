#include <iostream>
#include <cstdlib> // cstdlib stands for C Standard General Utilities Library, which includes functions for memory allocation, process control, conversions, and others.
#include "array_utils.h" // header file

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