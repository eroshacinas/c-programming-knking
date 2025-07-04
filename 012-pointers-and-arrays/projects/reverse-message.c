// write a program that reads a message, then prints the reversal of the image

#include <stdio.h>

#define STR_LEN 50

//func prototypes
int read_line(char[], int);
void reverse_str(const char*, int);

int main(){
char message[STR_LEN + 1];


printf("Enter a message: ");
int len = read_line(message, STR_LEN);

printf("%s\n", message);


reverse_str(message, len);
printf("\n");

return 0;
}

void reverse_str(const char *message, // dont modify stored str in *message 
		int n){
	const char *m = message+n-1; // point to char before '\0'; ensure m doesnt modify orig char

	// loop while m's addr is greater than or eq to message's first char addr
	for(;m >= message; m--){
		printf("%c", *m);
	}
	return;
}



int read_line(char str[], int n){
int ch, i = 0;

while ((ch = getchar()) != '\n')
   if (i < n)
      str[i++] = ch;


str[i] = '\0'; // store terminating char


return i; // return num of chars stored
}

