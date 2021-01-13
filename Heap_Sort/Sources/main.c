#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include "../Headers/heap.h"

/* 1. Build maximum heap with required methods. It should support the behaviors like adding element,
      getting maximum element, extracting maximum element, count number of elements and to check the 
      method to test the heap order property.*/
// Create new Heap and count the number of elements in it
void test_newheap(){
   int32_t data[] = {0, 10, 19, 39, 40, 90, 70, 64, 26, 5, 80};
   Heap h1 = heap_new(data, 10);
   Heap *heap = &h1;
   
   assert(heap_size(heap) == 10);
}

// Insert the new element to the Heap
void test_insert(){
   int32_t data[] = {0, 10, 19, 39, 40, 90, 70, 64, 26, 5, 80};
   Heap h1 = heap_new(data, 10);
   Heap *heap = &h1;
    
   assert(heap_size(heap) == 10);


   heap = heap_insert(heap, 50);
   assert(heap_test(heap) == 1);


   heap = heap_insert(heap, 100);
   assert(heap_test(heap) == 1);

}

// Test the Max Heap property
void test_heap_test(){
   int32_t data[] = {0, 10, 19, 39, 40, 90, 70, 64, 26, 5, 80};
   Heap h1 = heap_new(data, 10);
   Heap *heap = &h1;
    
   assert(heap_size(heap) == 10);
   assert(heap_test(heap) == 1);
}

// Get the max element from the Heap
void test_get_max(){
   int32_t data[] = {0, 10, 19, 39, 40, 90, 70, 64, 26, 5, 80};
   Heap h1 = heap_new(data, 10);
   Heap *heap = &h1;
    
   assert(heap_size(heap) == 10);

   assert(heap_get_max(heap) == 90);

}

// Extract the max element from the Heap
void test_heap_extract_max(){
   int32_t data[] = {0, 10, 19, 39, 40, 90, 70, 64, 26, 5, 80};
   Heap h1 = heap_new(data, 10);
   Heap *heap = &h1;
    
   assert(heap_size(heap) == 10);

   assert(heap_extract_max(heap) == 90);

}

/* 2. Modify Q2 to sort the input in ascending order. */
void test_sort(){
   int32_t data[] = {0, 10, 19, 39, 40, 90, 70, 64, 26, 5, 80};
   Heap h1 = heap_new(data, 10);
   Heap *heap = &h1;
    
   assert(heap_size(heap) == 10);

   heap = heap_sort(heap);
   assert(heap->data[1] == 5);
   assert(heap->data[10] == 90);

}

int main(){
   
   test_newheap();
   test_sort();
   test_insert();
   test_heap_test();
   test_get_max();
   test_heap_extract_max();
   
   return 0;
}
