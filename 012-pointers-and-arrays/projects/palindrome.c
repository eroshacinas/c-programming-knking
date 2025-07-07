#include <stdio.h>
#include <stdbool.h>

#define LEN 50

// func prototypes
int read_line(char[], int);
bool is_palindrome(char[], int);

int main (){
	char input[LEN];
	printf("Input string: ");
	int input_len = read_line(input, LEN);
	
	//printf("input: %s\n", input);
	is_palindrome(input, input_len);

	return 0;
}


int read_line(char str[], int n){
int ch, i = 0;

while ((ch = getchar()) != '\n')
   if (i < n)
      str[i++] = ch;


str[i] = '\0'; // store terminating char


return i; // return num of chars stored
}


bool is_palindrome(char input[], int input_len){
	char preprocess_arr[LEN];

	for(char *c = input; *c != '\0'; c++)
		if(*c >= 65 && *c <= 122)
	       		printf("%c", *c);
	
	return true;	

}


