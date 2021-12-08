#include <stdio.h>
#include <stdlib.h>

typedef struct pivo{
	double cena;
	char nazev[30];
	double alkohol;
	double objem;
} Pivo;

double nactiDouble(){
	int x;
	double vystup;
	do { 
		x = scanf("%lf", &vystup);
		if (x != 1) {
			while(getchar() != '\n');
			printf("Zadal jsi spatny vstup.\n");
			printf("Zkus znovu: ");
		} else {
			while(getchar() != '\n');
		}
	}while (x != 1);
	return vystup;
}

int nactiInt(){
	int pocetPiv, x;
	do { 
		x = scanf("%d", &pocetPiv);
		if (x != 1) {
			while(getchar() != '\n');
			printf("Zadal jsi spatny vstup.\n");
			printf("Zadej znovu pocet piv: ");
		} else {
			while(getchar() != '\n');
		}
	}while (x != 1);
	return pocetPiv;
}

void zadaniPiv(int pocetPiv, Pivo * basaPiv){
	for (int i = 0; i < pocetPiv; ++i)
	{
		printf("Zadej nazev piva %d: ", i);
		scanf("%[^\n]%*c", basaPiv[i].nazev);
		printf("Zadej obsah alkoholu, cenu a objem lahve: ");
		scanf("%lg %lg %lg", &(basaPiv[i].alkohol), &(basaPiv[i].cena), &(basaPiv[i].objem));
		while(getchar() != '\n');
		/*
		basaPiv[i].alkohol = nactiDouble();
		basaPiv[i].cena = nactiDouble();
		basaPiv[i].objem = nactiDouble();
		*/
	}
}

void vypisBasu(int pocetPiv, Pivo * basaPiv){
	for(int i = 0; i < pocetPiv; ++i){
		printf("%d: %-20s: Cena: %5.2f Objem: %2.1f Alkohol: %4.1f\n",
			i, basaPiv[i].nazev, basaPiv[i].cena, 
			basaPiv[i].objem, basaPiv[i].alkohol);
	}
}

void vypisNealko(int pocetPiv, Pivo * basaPiv){
	int pocetNealko = 0;
	double soucetCenNealko;
	for(int i = 0; i < pocetPiv; i++){
		if(basaPiv[i].alkohol <= 0.5){
			printf("%d: %-20s: Cena: %5.2f Objem: %2.1f Alkohol: %4.1f\n",
			i, basaPiv[i].nazev, basaPiv[i].cena, 
			basaPiv[i].objem, basaPiv[i].alkohol);	
			pocetNealko++;
			soucetCenNealko += basaPiv[i].cena / basaPiv[i].objem ;	
		}
	}
	printf("pocetNealko: %d\n", pocetNealko);
	printf("soucetCenNealko: %f\n", soucetCenNealko);
	if(pocetNealko != 0){
		printf("Prumerna cena za 1 litr piva v nasi base je %f\n", soucetCenNealko / pocetNealko);
	}
}

int main(void){
	
	int pocetPiv;

	/* 1a Zjistim pocet piv od uzivatele */
	printf("Zadejte pocet piv: ");
	pocetPiv = nactiInt();

	/* 1b dynamicka alokace pameti + kontrola */
	Pivo * basaPiv = (Pivo *) malloc(pocetPiv * sizeof(Pivo));
	if(basaPiv == NULL){
		printf("Alokovani se nezdarilo.");
		return 1;
	}

	zadaniPiv(pocetPiv, basaPiv);
	vypisBasu(pocetPiv, basaPiv);
	printf("-----------------------------\n");
	vypisNealko(pocetPiv, basaPiv);
	/* 2 - zadavani piv */


	free(basaPiv); /* uvolneni alokovane pameti */
	return 0;
}



	/*
	Pivo p1;
	strcpy(p1.nazev, "Klaster");
	p1.cena	= 15;
	p1.alkohol = 3.5;
	p1.objem = 0.5;

	printf("Cena: %p\n", &(p1.cena));
	printf("Nazev: %p\n", &(p1.nazev));
	printf("Alkohol: %p\n", &(p1.alkohol));
	printf("Objem: %p\n", &(p1.objem));
	*/