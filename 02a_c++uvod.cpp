#include <iostream>
#include <iomanip>

using namespace std;

int main(void){

	int teplota = 25;
	int * adr_teplota = &teplota;

	cout << "Adresa: " << adr_teplota << endl;
	
	teplota = 15;

	cout << "Hodnota pres adresu: " 
	     << *adr_teplota << endl;
	
	// reference na teplotu
	int & ref_teplota = teplota; 

	teplota = 10;

	cout << "Teplota pres referenci: " 
		<< ref_teplota << endl;

	// adresa reference
	cout << "Adresa reference: " 
		 << &ref_teplota << endl;

	// cisla 

	double a = 25.01;
	double b = .015;

	cout << "a: " << a << endl;
	cout << "b: " << b << endl;

	int x = 5;
	int y = 2;
	x -= y + 1;
	cout << x << endl;

	// manipulátory

	cout << "-------------------" << endl;

	int x1 = 100;
	int x2 = 200;
	double x3 = 2.51;
	// vypis hexa na 10 znaku
	cout << left << setbase(16) << setw(10) << "Vypis1: "
		 << setw(10) << setfill('_') << x1 << "," 
		 << setbase(10) << setfill(' ') << setw(10) << x2 << endl;

	cout << fixed << setprecision(5) << x3 << "<" << endl;


	return 0;
}