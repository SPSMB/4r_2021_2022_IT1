#include <iostream>
#include <string>

using namespace std;

int main(void){



	string s1("Pocatecni retezec");
	string s2(s1);
	string s3(s2, 8, 3);
	string s4("Novy retezec"s);
	string s5("Jiny novy retezec", 12);

	string s6b (10, 'a');
	string s7 (s1.begin(), s1.begin()+7); 
	string s8 (s1, 0, 7);

	cout << "s2: " << s2 << endl;
	cout << "s3: " << s3 << endl;
	cout << "s4: " << s4 << endl;
	cout << "s5: " << s5 << endl;

	cout << "s6b: " << s6b << endl;
	cout << "s7: " << s7 << endl;
	cout << "s8: " << s8 << endl;

	cout << "AT: " << s1.at(2) << endl;
	cout << "APPEND: " << s1.append(" cislo 2") << endl;
	cout << "REPLACE: " << s1.replace(10, 7, "slovo") << endl;

	// operator +
	string a, b;
	cout << "Zadej retezec 1: ";
	cin >> a;
	cout << "Zadej retezec 2: ";
	cin >> b;

	string vystup = a + "," + b;
	cout << "Zadane retezce:" << vystup << endl;





	return 0;
}
























/*
	string poleS[10] = {
		string("deleted C:/Users/Tom/jedna.txt 2021-05-20"),
		string("created C:/Users/Tom/dva.txt 2021-05-11"),
		string("new C:/Users/Tom/tri.txt 2021-06-20"),
		string("created C:/Users/Tom/ctyri.txt 2021-07-03"),
		string("updated C:/Users/Tom/pet.txt 2021-07-03"),
		string("new C:/Users/Tom/sest.txt 2021-05-20"),
		string("deleted C:/Users/Tom/sedm.txt 2021-05-11"),
		string("new C:/Users/Tom/osm.txt 2021-05-20"),
		string("updated C:/Users/Tom/devet.txt 2021-05-11"),
		string("updated C:/Users/Tom/deset.txt 2021-07-03") 
	};
	*/