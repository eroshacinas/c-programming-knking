#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define LEN 50

// func prototypes
int read_line(char[], int);
bool is_palindrome(char[], int);

int main (){
	char input[LEN];
	printf("Input string: ");
	int input_len = read_line(input, LEN);
	
	//printf("input: %s\n", input);
	is_palindrome(input, input_len) ? printf("is a palindrome\n") : printf("not a palindrome\n");

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
	int preprocess_str_count = 0;

	for(; *c; c++)
		if(*c >= 'A' && *c <= 'z'){
			*p=tolower(*c); // store alphabet; ensure it's lowercase
			p++;
			preprocess_str_count++;
		}

	// at this point, preprocess_str_count doesnt count null char
	*p = '\0'; // store terminating char
	printf("%s\n", preprocess_arr);

	int mid_index = (preprocess_str_count%2==0) ? preprocess_str_count/2 : (preprocess_str_count/2)+1; 

	for(int i = 0; i < mid_index; i++){
		// printf("%c  %c\n", preprocess_arr[i], preprocess_arr[preprocess_str_count - 1 - i]);
		if(preprocess_arr[i] != preprocess_arr[preprocess_str_count - 1 - i])
				return false;

	} 
	
	return true;	

}


