#include<stdio.h>

typedef struct times{
    int s_time;
    int f_time;
} act_times;

/* Compare helper function for qsort */
int compare(const void* a, const void* b) {
    act_times *c = (act_times*)a;
    act_times *d = (act_times*)b;
    return (c->f_time - d->f_time);
}

/* Function to implement greedy algo */
void printMaxActivities(act_times* s, int n) {
    int i,j;
    /* Sort according to finish times */
    qsort(s, n, sizeof(act_times), compare);
    
    /* First activity is always part of solution */
    i = 0;
    printf("%d %d \n ",s[i].s_time,s[i].f_time);
    
    /* Check if start time of other activities is greater than or equal to last 
     * activity chosen as part of solution
     */
     for(j = 1;j < n;j++) {
         if(s[j].s_time >= s[i].s_time) {
             printf("%d %d \n ",s[j].s_time,s[j].f_time);
             i = j;
         }
     }

}

// driver program to test above function
int main()
{
    act_times a[] = {{3,4}, {1,2} ,{0,6}, {8,9}, {5,7}, {5,9}};
	int n = sizeof(a)/sizeof(a[0]);
	printMaxActivities(a, n);
	getchar();
	return 0;
}
