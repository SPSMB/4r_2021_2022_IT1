#include <stdio.h>
#define DELKA 100

/* 
	funkce generuje odjezdy vlaku a uklada je do pole

	perioda - cas, jak dlouho trva vlaku jeden okruh
	pole - ukazatel na pole, kam budeme generovat odjezdy 
	velPole - velikost pole, kam se ukladaji odjezdy
	dolni_mez - pocatecni odjezd
	horni_mez - nejpozdejsi mozny odjezd
*/
void generujOdjezdy( int perioda, int * pole, int velPole, int dolni_mez, int horni_mez){
	int hodnota = dolni_mez;
	for(int i = 0; hodnota <= horni_mez && i < velPole; i++){
		pole[i] = hodnota;
		hodnota = hodnota + perioda;
	}
}

/* 
	funkce generuje odjezdy vlaku chytre, tak aby navazovali na referencni vlak

	perioda - cas, jak dlouho trva novemu vlaku jeden okruh
	novyVlak - ukazatel na pole, kam budeme generovat odjezdy noveho vlaku
	velPole - velikost pole, kam se ukladaji odjezdy noveho vlaku
	refVlak - pole s odjezdy vlaku, na ktery musi byt zajistene prestupy
	horni_mez - nejpozdejsi mozny odjezd
*/
void generujInteligentniOdjezdy( int perioda, int * novyVlak, 
	int velPole, int * refVlak, int horni_mez){

	int hodnota = refVlak[0]; /* pocatecni hodnota je prvni polozka v poli pro refVlak */
	int i = 0; /* indexy do pole noveho vlaku */

	/* pres odjezdy refVlaku */
	for(int r = 1; r < velPole && hodnota < horni_mez; r++){

		while(1){
			int navaznost = hodnota - (refVlak[r] + 10);
			/* printf("R:%d, I:%d, Navaznost: %d Hodnota: %d\n", r, i, navaznost, hodnota); */
			/* 1 varianta - vygenerovali jsme odjezd, za ktery se vedjde jeste jeden */
			if(hodnota < refVlak[r] && ((refVlak[r] + 10 - hodnota) >= perioda) ){
				// hodnota je platna, ukladam ji do pole
				/* printf("R:%d, I:%d IF1\n", r, i); */
				novyVlak[i] = hodnota;
				i++;
				hodnota = hodnota + perioda; /* generuji dalsi odjezd */
			} else if(hodnota <= refVlak[r]+10 && hodnota >= refVlak[r]){
				/* 2 varianta - odjezd presne navazuje na referencni vlak (je pozdejsi o 0-10 min) */		
				/*printf("R:%d, I:%d IF2\n", r, i);*/
				novyVlak[i] = hodnota;

				i++;
				hodnota = hodnota + perioda; /* generuji dalsi odjezd */
				break; /* posouvam se ve velkem cyklu o kousek dal */
			} else {
				/*návaznost není a další vlak se nevejde */
			 	/*printf("R:%d, I:%d IF3\n", r, i);*/
			 	hodnota = refVlak[r]; /* opravuji aktualni odjezd */
			 	novyVlak[i] = hodnota;

    			i++;
    			hodnota = hodnota + perioda; /* generuji dalsi odjezd */
    			break;
		   }
			
		    
		}



	}
}

void prevodHodin(int hodnota){
	int min = hodnota % 60;
	int hod = hodnota / 60;
	#define USPORNY_KOD
	#ifdef USPORNY_KOD
	printf("%2d : %02d, ", hod, min);
	#else 
	if(hod < 10){
		printf(" %d : ", hod);
	}
	else{
		printf("%d : ", hod);
	}

	if(min < 10){
		printf("0%d, ", min);
	}
	else{
		printf("%d, ", min);	
	}
	#endif
}

void vypisPole(int * pole, int delka){
	for(int i = 0; i < delka; i++){
		if(pole[i] == 0){
			break;
		}else{
			prevodHodin(pole[i]);
			//printf("%d, ", pole[i]);
		}
	}
	printf("\n");
}

int main(void){
	
	/* deklarace promennych */
	int v1_trvani = 90; // Nizbor
	int v2_trvani = 170; // Karlstejn
	int v3_trvani = 40; // Cementarna

	int dolni_mez = 300;  /* 5:00 -> 300 min */
	int horni_mez = 1380; /* 23:00 -> 1380 min */

	int v1_odjezdy[DELKA] = {0}; /* pole pro odjezdy vlaku 1 + nulovani */
	int v2_odjezdy[DELKA] = {0}; /* pole pro odjezdy vlaku 2 + nulovani */
	int v3_odjezdy[DELKA] = {0}; /* pole pro odjezdy vlaku 3 + nulovani */

	// 1 - vygenerujeme odjezdy pro vlak s nejdelsim okruhem
	generujOdjezdy(v2_trvani, v2_odjezdy, DELKA, dolni_mez, horni_mez);
	printf("Vlak 2: Karlstejn:  ");
	vypisPole(v2_odjezdy, DELKA);

	// 2 - vygenerujeme odjezdy pro vlak s 2. nejdelsim okruhem
	generujInteligentniOdjezdy( v1_trvani, v1_odjezdy, 
	DELKA, v2_odjezdy, horni_mez);
   printf("Vlak 1: Nizbor:     ");
   vypisPole(v1_odjezdy, DELKA);

   // 3 - vygenerujeme odjezdy pro vlak s 3. nejdelsim okruhem
   generujInteligentniOdjezdy( v3_trvani, v3_odjezdy, 
	DELKA, v1_odjezdy, horni_mez);
   printf("Vlak 3: Cementarna: ");
   vypisPole(v3_odjezdy, DELKA);
	
	return 0;
}