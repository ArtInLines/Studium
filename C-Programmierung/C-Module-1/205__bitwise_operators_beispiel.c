/* bitwise_operators.c binary operations */

#include <stdio.h>

int main() {
	unsigned int n, n2, m;

	printf("Please enter an integer number:");
	scanf("%u",&n);

	printf("Please enter a second integer number:");
	scanf("%u",&n2);
	
	printf("\n Binary representation of %d AND %d: ", n, n2);

	n = n & n2;

	m=0; n2=n; 

	// Shift n in reverse order into m	
	while(n>0) {
		m=m<<1;
		m=m | (n&1);    
		n=n>>1;   
	}

	// output. n2 (= old n) is used to assure that trailing zeros are not omitted.
	do {
		printf("%d", m&1 );
		m=m>>1;
		n2=n2>>1;
	} while(n2>0);
	printf("\n");
	getchar();	getchar();
}
