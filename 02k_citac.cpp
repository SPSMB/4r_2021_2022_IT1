#include <iostream>

using namespace std;

class Citac{
protected:
	int c_hodnota;
	int c_pocHodnota;
public:
	void zvetsit();
	void zmensit(){ 
		c_hodnota --;
	}
	int hodnota(){ 
		return c_hodnota;
	}
	void nastavit(){
		c_hodnota = c_pocHodnota;
	}
	Citac(int ph){
		cout << "Vola se konstruktor tridy Citac.\n";
		c_pocHodnota = ph;
		nastavit();
	}

};

class CitacMod : public Citac{
private:
	int c_modul;
public:
	CitacMod(int ph, int mod) : Citac(ph){
		cout << "Vola se konstruktor tridy CitacMod.\n";
		c_modul = mod;
	}

	void zvetsit(){
		c_hodnota = (c_hodnota+1) % c_modul;
	}

	void zmensit(){
		Citac::zmensit(); // volam funkci z predka
		if(c_hodnota < 0){
			c_hodnota = c_modul - 1;
		}
	}
};

class Citac2 : public Citac{
private:
	int c_modul;
	int c_start;
public:
	Citac2(int ph, int start, int modul) : Citac(ph){
		c_modul = modul;
		c_start = start;
	}
};

int main(void){

	Citac x(0);
	CitacMod x1(0,5);
	Citac2 x2(0,0,5);

	Citac * p = NULL;
	CitacMod * p1 = NULL;
	Citac2 * p2 = NULL;

	x = x1;
	/* x1 = x;  NELZE */
	p = p1;
	/* p1 = p;  NELZE */

	/*x1 = x2;  NELZE */
	x = x2;
	/*p1 = p2;  NELZE */
	p = p2;

	return 0;
}


















	