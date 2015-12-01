#include <stdio.h>
#include <stdlib.h>

/* Merge function */
void merge(int* arr, int l, int m, int r) {
    int n1, n2, i, j, k;
    n1 = m - l + 1;
    n2 = r - m;
    int left[n1], right[n2];
    for (i = 0; i < n1 ; i++) {
        left[i] = arr[l+i];
    }
    for (j = 0 ; j < n2 ; j++) {
        right[j] = arr[j+m+1];
    }
    
    i = 0;
    j = 0;
    k = l;
    
    while((i < n1) && (j < n2)) {
        if(left[i] < right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while(i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }
    while(j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

/* Recursive mergesort */
void mergesort(int* arr,int l,int r) {
    /* Divide and conquer recursively */
    int mid = (r-l)/2 + l;
    if(l < r) {
        mergesort(arr, l, mid);
        mergesort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
}

/* Utility print function */
void printarray(int* arr, int size) {
    int i;
    for(i=0;i<size;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

/* Driver function to test mergesort */
int main() {
    int arr[] = {37,27,9,12,18,23};
    int size, l, r;
    size = sizeof(arr)/sizeof(int);
    /* Print unsorted array */
    printarray(arr,size);
    /* Mergesort the unsorted array */
    mergesort(arr,0,size-1);
    /* Print sorted array */
    printarray(arr,size);
    return 0;
}
