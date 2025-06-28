#include <stdio.h>

#define N 10 // number of elements in array

// prototypes
void max_min(int a[], int n, int *max, int *min);

int main(void){
    int b[N], i, big, small;

    printf("Enter %d integers:\n", N);
    for (i=0; i<N; i++){
        scanf("%d", &b[i]);
    }

    max_min(b, N, &big, &small); // call function to find max and min
    printf("Max number: %d\n", big);
    printf("Min number: %d\n", small);

    return 0;


}


void max_min(int a[], int n, int *max, int *min){
    int i;

    *max = *min = a[0]; // initialize max and min to the first element

    for (i=1; i<n; i++){
        if (a[i] > *max) {
            *max = a[i]; // update max if current element is greater
        }
        if (a[i] < *min) {
            *min = a[i]; // update min if current element is smaller
        }
    }
}