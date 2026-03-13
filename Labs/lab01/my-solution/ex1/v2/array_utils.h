#ifndef ARRAY_UTILS_H // note: this is an include guard, it prevents the contents of the header file from being included multiple times in a single compilation unit, which can lead to errors. 
                      // The first time the header file is included, ARRAY_UTILS_H is not defined, so the code between #ifndef and #endif is included and ARRAY_UTILS_H is defined. If the header file is included again, ARRAY_UTILS_H is already defined, so the code between #ifndef and #endif is skipped.
#define ARRAY_UTILS_H


float* allocate_and_read(int n);
void sort_array(float* vet, int n);
void display_array(const float* vet, int n);

#endif // ARRAY_UTILS_H