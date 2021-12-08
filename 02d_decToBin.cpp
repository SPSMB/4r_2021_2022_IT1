#include <iostream>

using namespace std;

/* ukolem je vytvorit funkci, ktera postupnym delenim dvema prevede cislo 
   z dekadicke soustavy na binarni 
*/
/* POSTUP 
 	modulo - zbytek po deleni budeme pripisovat do nejake promenne
 	normalni deleni - ukldame do jine promenne - vysledek deleni 
 		ukladame stale do teto promenne

 	       12
 	      ----
 	zbytek | zustatek
 		0  |    6
 		0  |    3
 		1  |    1
 		1  |    0
 	

 */

void decToBin(int dec){
	int zbytek, zustatek;
	int vystup[50];

	zustatek = dec;
	int i = 0;
	while(zustatek != 0){
		zbytek = zustatek%2;
		zustatek = zustatek/2; /* zustatek /= 2; */
	
		vystup[i] = zbytek;
		i++;
	}
	cout << "Cislo " << dec << " je binarne: ";
	
	/*  tudy ne :-)
		sizeof - vraci velikost promenne v bytech
	    strlen - vraci delku retezce */
	for(int k=i-1; k >= 0 ; k-- ){
		 cout << vystup[k];
		 if(k%4 == 0){
		 	cout << " ";
		 }
	}
	cout << endl;
}

int main(int argc, char ** argv){

	int cislo;
	cout << "Zadejte cislo: ";
	cin >> cislo;
	decToBin(cislo);

	return 0;
}