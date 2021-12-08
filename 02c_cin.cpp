#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main(void){

/*
	// nacitani vstupu
	char z1, z2, z3;

	// 1. zpusob
	cout << "Zadej 1 znak: ";
	cin >> z1;
	cout << "Zadany znak je '" << z1 << "'" << endl;

	// 2. zpusob - getchar
	cout << "Zadej 1 dalsi znak: ";
	z2 = getchar();
	cout << "Zadany 2. znak je '" << z2 << "'" << endl;

	// 3. zpusob cin.get()
	cout << "Zadej jeste 1 dalsi znak: ";
	z3 = cin.get();
	cout << "Z3: " << z3 << endl;

	cin.ignore(1000, '\n');
	cin.ignore(
		numeric_limits<streamsize>::max(),'\n');
	// nacitam cely radek
	char radek[100];
	cout << "Zadej 1 radek textu: ";
	cin.getline(radek, 100);
	cout << "Radek:>" << radek << "<" << endl;
*/
	int radius; 

	cout << "Zadejte polomer: ";
	cin >> radius;
	while(!cin){
		// sem se dostanu, kdyz nacitani nedopadlo dobre
		cout << "Chyba, prosim zadejte znovu: ";
		cin.clear();
		cin.ignore(1000,'\n');
		cin >> radius;
	}
	cin.ignore(1000,'\n');
	cout << "Hodnota: " << radius << endl;

	return 0;
}