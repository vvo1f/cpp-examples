// Class Exercise
/*
Write a C++ class including
     A constructor and a destructor
         To dynamically allocate and deallocate an array on
            integers (using the C-like construct calloc and free)
     A method
         To generate the values withing the array randomly
         To sort the array using a user version of quicksort
         To sort the array using the library version of quicksort
         To display the array on standard output
     A main program
         To call the previous methods of the class to allocate,
            generate, sort and display the array
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

class MyArray {
    private:
        int* vet;
        int size;

    public:
        // Constructor with size parameter
        MyArray(int size) : size(size) {
            vet = (int*)calloc(size, sizeof(int));
            if (vet == nullptr) {
                std::cerr << "Memory error!" << std::endl;
                exit(1);
            }
        }

        // Constructor with fixed size (100)
        MyArray(): size(100) {
            vet = (int*)calloc(size, sizeof(int));
            if (vet == nullptr) {
                std::cerr << "Memory error!" << std::endl;
                exit(1);
            }
        }

        // Destructor
        ~MyArray() {
            free(vet); // free() is the C version of delete
        }

        // Generate random values
        void generate() {
            srand(static_cast<unsigned int>(time(nullptr))); // seed the rnadom number generator
            for (int i = 0; i < size; ++i) {
                vet[i] = rand() % 1000;
            }
        }

        // Personal quicksort implementation
        void mysort(int low, int high) {
            if (low < high) {
                int pi = partition(low, high);
                mysort(low, pi - 1);
                mysort(pi + 1, high);
            }
        }
        int partition(int low, int high) {
            int pivot = vet[high];
            int i = (low - 1);
            for (int j = low; j <= high - 1; j++) {
                if (vet[j] < pivot) {
                    i++;
                    std::swap(vet[i], vet[j]);
                }
            }
            std::swap(vet[i + 1], vet[high]);
            return (i + 1);
        }

        void mysort() {
            mysort(0, size - 1);
        }

        // Library quicksort
        void libsort() {
            std::sort(vet, vet + size);
        }

        // Display the array
        void display() {
            for (int i = 0; i < size; ++i) {
                std::cout << vet[i] << " ";
            }
            std::cout << std::endl;
        }
};

int main() {
    // Using constructor with size parameter
    MyArray arr1(50);
    arr1.generate();
    std::cout << "Array 1 (initial):" << std::endl;
    arr1.display();
    arr1.mysort();
    std::cout << "Array 1 (final):" << std::endl;
    arr1.display();

    // Using constructor with fixed size
    MyArray arr2;
    arr2.generate();
    std::cout << "\nArray 2 (initial):" << std::endl;
    arr2.display();
    arr2.libsort();
    std::cout << "Array 2 (final):" << std::endl;
    arr2.display();

    return 0;
}