#include <iostream>
#include <string>

using namespace std;

void mocnina(){
	static int lokalni = 2;
	lokalni *= 2;
	cout << "Lokalni: " << lokalni << endl;
}

int main(void){

	for(int i = 0; i<5; i++){
		mocnina();
	}

	return 0;
}


















	