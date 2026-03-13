

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