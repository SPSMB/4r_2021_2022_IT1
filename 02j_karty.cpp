#include <iostream>

using namespace std;

class BalicekKaret{
private:
	char b_hodnoty[1000];
	int b_pocet; /* kolik karet je v balicku */
public:
	BalicekKaret(){
		b_pocet = 0;
	}

	void vypisBalicek(){
		if(b_pocet == 0){
			cout << "Balicek je prazdny." << endl;
			return;
		}
		cout << "Hodnoty: ";
		for(int i=0; i < b_pocet; i++){
			cout << b_hodnoty[i] << ", ";
		}
		cout << endl;
	}

	void pridejNaVrchol(){
		cout << "Jakou kartu chcete pridat? ";
		char vstup;
		cin >> vstup;
		if (kontrolaVstupu(vstup) == true){
			b_hodnoty[b_pocet] = vstup;
			b_pocet++; // zvysim pocet karet v balicku o 1
		}
	}

	bool kontrolaVstupu(char vstup){
		if((vstup >= 50 && vstup <= 57)
		 || vstup == 'X' || vstup == 'J' ||
		    vstup == 'Q' || vstup == 'K' || vstup == 'A'){
			cin.ignore(1000,'\n'); // vycisteni vstupu 
			return true;
		}
		else{
			cout << vstup << " je spatny vstup, povolene hodnoty: 2-9, X, J, Q, K, A" << endl;
			cin.ignore(1000,'\n');    // vycisteni vstupu 
			return false;
		}
	}

	void vyjmoutZVrchu(){
		if(b_pocet > 0){
			b_pocet--;
		} else {
			cout << "Balicek uz je prazdny, nelze nic vyjmout." << endl;
		}
	}

	void vyjmoutZespodu(){
		cout << "Karta " << b_hodnoty[0] << " byla odebrana.\n";
		for(int i = 0; i < b_pocet-1; i++){
			b_hodnoty[i] = b_hodnoty[i+1];
		}
		b_pocet--;
	}
};

int main(void){

	BalicekKaret b;
	b.vypisBalicek();
	b.pridejNaVrchol();
	b.vypisBalicek();
	b.pridejNaVrchol();
	b.vypisBalicek();
	
	b.vyjmoutZespodu();
	b.vypisBalicek();


	return 0;
}


















	