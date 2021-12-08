#include <iostream>
#include <iomanip>

using namespace std;

int main(void){

	//hlavicka:
	cout << "    ";
	for(int i = 1; i <= 10; i++){
		cout << setw(4) << i << " ";
	}
	cout << endl;
	// vypise 1 radek s podtrzitky
	cout << setfill('_') << setw(3+10*5) << "" << endl;

	cout << setfill(' ');
	for(int r = 10; r <= 20; r++){
		// r:
		cout << r << ": "; 
		for(int s = 1; s <= 10; s++){
			cout << setw(4) << r*s  << " ";
		}
		cout << endl; // konec radku
	}

	return 0;
}