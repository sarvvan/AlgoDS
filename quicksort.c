#include <stdio.h>

/* Swap helper function */
void swap(int* a, int* b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

/* Partition function based on Lomuto partition scheme
 * Pivot chosen - last element
 * Algorithm puts pivot in right position
 * Index i is maintained to put the pivot in right position, 
 * if element compared is less than pivot, index is incremented and element is 
 * placed before pivot
 */
int partition(int* arr,int l,int r) {
    int i=l;
    int j;
    int x = arr[r];
    for(j=l;j<r;j++){
        if(arr[j] <= x) {
            swap(&arr[i],&arr[j]);
            i++;
        }
    }
    swap(&arr[i],&arr[r]);
    return i;
    
}

/* Quicksort recursive implementation */
void quicksort(int* arr,int l,int r) {
    int p;
    if(l < r) {
        p = partition(arr,l,r);
        quicksort(arr,l,p-1);
        quicksort(arr,p+1,r);
    }
}

void printarray(int* arr, int num) {
    int i;
    for(i=0;i<num;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

/* Driver program for quicksort */
int main() {
    int arr[]={9,7,3,5,6};
    int l=0;
    int r=sizeof(arr)/sizeof(int);
    printarray(arr,r);
    quicksort(arr,l,r-1);
    printarray(arr,r);
    return 0;
}
