/* File Analyzer.c
     TO DO 1: Write a program which reads a file and counts for each byte value (0-255) how often it occurs.
     TO DO 2: Display the number of occurences as bars (i.e. as a histogram)
     TO DO 3: fgetc(...) is quite inefficient, replace it by reading bigger chunks of the file with fread(...)
     TO DO 4: How do the histogramms of various file types differ, e.g. .txt, .doc, .c, .jpg, .zip
     TO DO 5: Can you make any conclusions regarding the storage efficiency of the format? 
              (optional: Further reading: 'Entropy' in information theory)
     TO DO 6: Develop a metric for calculating a measure of 'information density' in the file. 
              (the less likely you can predict values, the higher is their information content)
     TO DO 7: Try to develop a file format guesser, which guesses the file type based on the character histogram.
*/

#include <stdio.h>
#include <stdlib.h>
#include <Math.h>

int histogramm[256];
int count;

int read_file(char *file_name)
{

   FILE *file;     // File pointer
   int val;
   int cnt;
   unsigned char buffer[1024];

   file=fopen(file_name,"rb");
   if(file==NULL) {
       printf("Error: can't open file.\n");
       return -1;
   }

   count=0;
   while(!feof(file)) {
		cnt=fread(buffer, 1, 1024, file);
		count+=cnt;
		while(--cnt>=0)
			histogramm[buffer[cnt]]++;
   }

  /* while(!feof(file))  {    // End of file not yet reached
       val=fgetc(file);     // Read next character
	   histogramm[val]++;
	   count++;
   }*/

   fclose(file);    // Do not forget this!
   return 0;
}

int main()
{
	char filename[100];
	int i, j;
	float p, h, hsum;

	while(1) {
	printf("Filename?");
	scanf("%s",filename);
	
	for(i=0; i<256; i++)
		histogramm[i]=0;

	if (read_file(filename)) {
		printf("Cannot open file.\n");
		exit(1);
	}

	printf("Read %d bytes.\n",count);

	for(i=0; i<256; i++) {
		printf("%4d",histogramm[i]);
		if(i%16==15) printf("\n");
	}

	hsum=0;
	for(i=0; i<256; i++) {
		printf("\n%3d ",i);
		p=(float)histogramm[i]/count; // Probability
		if(p==0.) h=0.;
		else h=-log(p)*p/log(2.);   // Entropy
		printf("%6.4f ",h);
		hsum+=h;
		j=(int)(256*25*p);
		while(j-->0) printf("%c",219);
	}
	printf("\nEntropy sum=%5g",hsum);
	}
}