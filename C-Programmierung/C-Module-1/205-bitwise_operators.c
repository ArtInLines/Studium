/* bitwise_operators.c binary operations */
/* TODO 1: Something is wrong with the output 
	   Hint: put the output first into an additional variable m, 
	   use bitwise operators and count the digits */
/* TODO 2: A second number should be entered and 
	   both numbers should be combined with the various bitwise
	   operators before providing the output */
/* TODO 3: Use signed integers and see how negative numbers 
           are presented in binary format */

#include <stdio.h>

int twoUnsigned();
int oneUnsigned();
int oneInt();
int printUnsignedBinary(unsigned int n);

int main() {
	int n;
	int toExit = 0;
	while (!toExit) {
		printf("\nPlease enter the number of the task you want to run or 0 to exit: ");
		scanf("%i",&n);
		printf("\n");
		
		switch (n) {
			case 0:
				toExit = 1;
				break;
				
			case 1:
				oneUnsigned();
				break;
			
			case 2:
				twoUnsigned();
				break;
				
			case 3:
				oneInt();
				break;
		}
	}
}

int printUnsignedBinary(unsigned int n) {
	unsigned int m, i = 0;
	
	if (n == 0) {
		printf("0");
		return 0;
	}
	
	// Store n in reversed order in m
	while(n > 0) {
		// printf("\nm: %d - m<<1: %d - n&1: %d\n", m, m<<1, n&1);
		m = (m << 1) | (n&1);
		n = n >> 1;
		// printf("n: %d - m: %d\n", n, m);
		i++;
	}
	
	// Print m in reversed order, to print n, but withou unnecessary 0s in front for small numbers
	while (i > 0) {
		printf("%d",m&1);
		m = m>>1;
		i--;
	}
}

int oneUnsigned() {
	unsigned int n = 0;

	printf("Please enter a positive number or 0 to exit: ");
	scanf("%u",&n);   // Input unsigned fron console

	printf("Binary representation: ");
	printUnsignedBinary(n);
	printf("\n");

}

int twoUnsigned() {
	unsigned int m, n, op = 0;
	
	printf("Please enter the first positive number: ");
	scanf("%u",&m);
	
	printf("Please enter which operation - 1: and, 2: or, 3: xor - you want to execute: ");
	scanf("%u",&op);
	
	printf("Please enter the second positive number: ");
	scanf("%u",&n);
	
	printf("Binary represantation:  ");
	printf("%d: ",m);
	printUnsignedBinary(m);
	printf(", %d: ",n);
	printUnsignedBinary(n);
	
	printf("\nAfter operation ");
	if (op <= 1) {
		printf("'&':\n");
		n = m & n;
		printf("%d: ",n);
		printUnsignedBinary(n);
	}
	else if (op == 2) {
		printf("'|':\n");
		n = m | n;
		printf("%d: ",n);
		printUnsignedBinary(n);
	}
	else {
		printf("'^':\n");
		n = m ^ n;
		printf("%d: ",n);
		printUnsignedBinary(n);
	}
	printf("\n");
}

int oneInt() {
	int n = 0;
	
	// TODO: Fix this!
	
	printf("Please enter a number: ");
	scanf("%i",&n);
	
	while (n != 0) {
		printf("%i - %i\n",n,n&1);
		n = n << 1;
	}
}