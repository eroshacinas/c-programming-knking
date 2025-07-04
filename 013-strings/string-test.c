#include <stdio.h>


int main(){
    // the difference between *p and ch
    // is that *p is a pointer to an array of characters terminated by a null character '\0'.
    // ch is a single character represented by an integer
    char *p, ch;
    p = "hello";

    ch = 'a';

    printf("%d\n", ch);

    printf(p);

    return 0;
}