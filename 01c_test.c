#include <stdio.h>

int main(void){
	
	/*
	int b;
	b *= 2;
	printf("B= %d\n", b);
	*/

	char retezec[50];

	scanf("%[^\n]%*c", retezec);
	printf(">%s<\n", retezec);
	
	return 0;
}