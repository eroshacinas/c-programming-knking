#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define N 10

// function prototypes
int extract_digit(int num, int ind);

int main(void){
    int a[N] = {0}; // initialize array to all zeros

    long num, num_copy;

    printf("Enter a number with 10 digits or less: ");
    scanf("%ld", &num);

    num_copy = num; // store copy

    
    // check if number is 10 digits or less
    int dig_count = 1;

    // run until dig_count is zero
    while(num/10 > 0){
        if (dig_count > N) {
            printf("[ERROR] Number exceeds 10 digits.\n");
            return 1; // exit if more than 10 digits
        }

        dig_count++;

        num /= 10; // remove last digit
    }



    // store digits of input num in reverse order in array
    // e.g. store 12345 as 5 4 3 2 1
    // where first dig is a[0], second dig is a[1], etc.

    for(int i = 0; i < dig_count; i++){
        a[i] = extract_digit(num_copy, i+1); // offset by 1. index 0 is 1st digit, etc.
    }

    // print how many digits
    printf("Number has %d digits.\n", dig_count);

    // print in reverse order
    for(int i = dig_count-1; i >= 0; i-- ){
        printf("%d\t", a[i]);
    }

    printf("\n");

    // check if there are repeating numbers
    for(int i = 0, hold_num; i < dig_count; i++){
        hold_num = a[i];

        int repeated = 0; // num of times digit is repeated
        for(int j = i+1; j < dig_count; j++){
            if(hold_num == a[j])
                repeated++;
        }

        printf("digit `%d` is repeated %d times\n", hold_num, repeated);
    }

    return 0;
}



int extract_digit(int num, int ind){
    int denom = pow(10, ind); 

    // (num % (10^index)) / 10^(index-1)
    return (num%denom)/(denom/10);
}
