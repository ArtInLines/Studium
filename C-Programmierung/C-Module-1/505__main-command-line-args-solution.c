// command line args 
// TO DO: Use the command line arguments to modify previous programs from the lecture, e.g. 
//        devowelizer: provide a string to be "devowelized"
//        ascii-art: provide x and y 
// TO DO: parse the command line arguments: If there is a string "-h" or "-help" 
//        print a small help text


#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	int n, m;

	for(n=0; n < argc; n++) {
		printf("Command line argument %d is %s\n", n+1, argv[n]);
	}
	if( n>1 ) {
		sscanf(argv[1],"%d", &m);
		printf("Wert des ersten Parameters: %d",m);
	}
	return EXIT_SUCCESS; 
}