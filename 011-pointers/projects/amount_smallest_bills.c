// this is based on chapter 2 proj 7 in page 33

#include <stdio.h>

// func prototypes
void pay_amount(int, int*, int*, int*, int*);


int main(){

int amount = 0, twenties=0, tens=0, fives=0, ones=0;


printf("Enter amount: ");
scanf("%d", &amount);

printf("Amount: %d\n", amount);
printf("------------\n");

pay_amount(amount, &twenties, &tens, &fives, &ones);

printf("$20 bills: %d\n", twenties);
printf("$10 bills: %d\n", tens);
printf("$5 bills: %d\n", fives);
printf("$1 bills: %d\n", ones);


return 0;

}


void pay_amount(int dollars,
		int *twenties,
		int *tens,
		int *fives,
		int *ones){


*twenties = dollars/20;
dollars %= 20; 

*tens = dollars/10;
dollars %= 10;

*fives = dollars/5;
dollars %= 5;

*ones = dollars;

return;
}


