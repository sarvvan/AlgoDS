#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void swap(char* a, char* b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void strrev(char* input) {
    int i;
    int length = strlen(input);
    for(i = 0;i < (length/2);i++) {
        swap(&input[i],&input[length-1-i]);
    }
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int num_cases, length, i, j;
    char input[100];
    scanf("%d",&num_cases);
    while(num_cases) {
        num_cases--;
        scanf("%s",input);
        length = strlen(input);
        
        /* Find largest i, such that input[i] < input[i+1] */
        for(i = length-1;i >= 0;i--) {
            if(input[i] < input[i+1]) {
                break;
            }
        }
        
        /* Last permutation - so no output */
        if(i == -1) {
            printf("no answer \n");
            continue;
        }
        
        /* Find largest k, such that input[k] > input[i] */
        for(j = length-1;j > i;j--) {
            if(input[i] < input[j]) {
                break;
            }
        }
        /* Swap input[i] and input[j] */
        swap(&input[i],&input[j]);
        
        /* Reverse everything after the index i */
        strrev(&input[i+1]);
        
        printf("%s \n",input);
        
    }
    return 0;
}
