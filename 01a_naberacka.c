#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>

/* funkce nacte vstup 
   vraci nactene cislo
 */
float nactiVstup(void){
	float vstup;
	int x;
	do { 
		x = scanf("%f", &vstup);
		if (x != 1) {
			while(getchar() != '\n')
			printf("Zadal jsi spatny vstup!\n");
			printf("Zadej nove cislo: ");
		}
   } while (x != 1);
	return vstup;
}

/* vrati objem naberacky podle zadaneho polomeru */
float objemNaberacky(float polomer){
	/* POZOR - konstanty musi byt float */
	/* musime delit 2, potoze pocitame polovicni kouli */
	return ((4.0/3.0) * M_PI * (polomer * polomer * polomer))/2;
}

int main(void){
	
	/* deklarace promennych */
	float polomer;
	float vysledek;
	
	printf("Zadejte prosim polomer: ");
	polomer = nactiVstup();
	vysledek = objemNaberacky(polomer);
	printf("Objem naberacky o polomeru %g je %16.10f.", polomer, vysledek);
	
	return 0;
}