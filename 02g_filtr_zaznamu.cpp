#include <iostream>
#include <string>

using namespace std;

int main(void){

	string poleS[10] = {
		string("deleted C:/Users/Tom/jedna.txt 2021-05-20"),
		string("created C:/Users/Tom/dva.txt 2021-05-11"),
		string("new C:/Users/Tom/tri.txt 2021-06-20"),
		string("created C:/Users/Tom/ctyri.txt 2021-07-03"),
		string("updated C:/Users/Tom/pet.txt 2021-07-03     aifhasihf"),
		string("new C:/Users/Tom/sest.txt 2021-05-20"),
		string("deleted C:/Users/Tom/sedm.txt 2021-05-11"),
		string("new C:/Users/Tom/osm.txt 2021-05-20"),
		string("updated C:/Users/Tom/devet.txt 2021-05-11"),
		string("updated C:/Users/Tom/deset.txt 2021-07-03") 
	};

	int rok, mesic, den;
	string filtr;
	cout << "Zadejte rok: ";
	cin >> rok;
	cout << "Zadejte mesic: ";
	cin >> mesic;
	cout << "Zadejte den: ";
	cin >> den;

	if(den < 10 && mesic < 10){
		filtr = to_string(rok) + "-0" + to_string(mesic) + "-0" + to_string(den);
	} else if(mesic < 10){
		filtr = to_string(rok) + "-0" + to_string(mesic) + '-' + to_string(den);
	} else if(den < 10){
		filtr = to_string(rok) + '-' + to_string(mesic) + "-0" + to_string(den);
	} else {
		filtr = to_string(rok) + '-' + to_string(mesic) + '-' + to_string(den);
	}
	cout << "Filtr: " << filtr << endl;

	for(int i = 0; i < 10; i++ ){
		if (poleS[i].find(filtr) != string::npos){
			cout << "Nalezeno: " << poleS[i] << endl;
		}
	}





	return 0;
}


















	