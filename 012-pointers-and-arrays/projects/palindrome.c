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
	// be careful not to modify where an array var's pointed at if youll use it as a pointer
	// ie arrays can be treated as pointers but their address CANT be repointed somewhere else
	// it should always point to address of first value
	char preprocess_arr[LEN], *c=input, *p=preprocess_arr;

	for(; *c; c++)
		if(*c >= 'A' && *c <= 'z'){
			*p=*c; // store alphabet
			p++;
		}

	*p = '\0'; // store terminating char
	printf("%s\n", preprocess_arr);

	
	return true;	

}


