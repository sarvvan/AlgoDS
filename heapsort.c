#include <stdio.h>
#include <stdlib.h>

typedef struct maxheap_s {
    int* arr;
    int num;
}maxheap;

void swap(int* a, int* b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void printarray(int* arr, int size) {
    int i;
    for(i=0;i<size;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void maxheapify(maxheap* max_heap, int index) {
    int left, right, max;
    max = index;
    left = (index*2) + 1;
    right = (index + 1) * 2;
    
    if(((max_heap->num -1) >= left)&&(max_heap->arr[left] > max_heap->arr[max])) {
        max = left;
    }
    
    if(((max_heap->num -1) >= right)&&(max_heap->arr[right] > max_heap->arr[max])) {
        max = right;
    }
    
    if(index != max) {
        swap(&max_heap->arr[max],&max_heap->arr[index]);
        maxheapify(max_heap, max);
    }
}

maxheap* createmaxheap(int* arr, int num) {
    /* Initialize maxheap datastructure */
    int i;
    maxheap* max_heap;
    max_heap = (maxheap*)malloc(sizeof(maxheap));
    max_heap->arr = arr;
    max_heap->num = num;
    
    /* Heapify bottom-up from bottom-right most node with children */
    
    for(i = (num-2)/2; i>=0; i--) {
        maxheapify(max_heap, i);
    }
    printarray(max_heap->arr, num);
    return max_heap;
}

maxheap* heapsort(maxheap* max_heap) {
    int size = max_heap->num;
    while(max_heap->num > 0) {
        swap(&max_heap->arr[0],&max_heap->arr[max_heap->num - 1]);
        max_heap->num--;
        maxheapify(max_heap,0);
    }
    max_heap->num = size;
    printarray(max_heap->arr, size);
    return max_heap;
}

/* Driver program to test heapsort */
int main() {
    int arr[6]= {14,2,44,13,11,7};
    int num;
    maxheap* max_heap;
    num = sizeof(arr)/sizeof(int);
    /* Print unsorted array */
    printarray(arr,num);
    /* Construct max heap using input array */
    max_heap = createmaxheap(arr,num);
    /* Perform heapsort using maxheap constructed in last step */
    max_heap = heapsort(max_heap);
    
    return 0;
}
