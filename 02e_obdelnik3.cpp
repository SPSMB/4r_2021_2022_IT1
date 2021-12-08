#include <iostream>
#include <math.h>


using namespace std;

class Bod{
public:
	int x;
	int y;

	// konstruktor bez parametru
	Bod(){
		Bod::x = 0;
		Bod::y = 0;
	}

	// konstruktor se 2 parametry
	Bod(int x, int y){
		Bod::x = x;
		Bod::y = y;
	}

	string vypis(){
		return "[" + to_string(x) + ", " + to_string(y) + "]";
	}
};

// trida obdelnik
class Obdelnik{
  private:
	// data 
	Bod o_A; /* levy dolni roh */
	int o_plocha; int obvod;
	
  public:

	static int o_pocetObdelniku;
	int o_sirka; int o_vyska; 

	// alpha - uhel, o ktery se otaci
	// r - rotovany bod
	void normalizuj(int alpha, Bod r){
		if (alpha == 90 || alpha == -270) {
			o_A.x = r.x - o_vyska;
			// prohozeni sirky a vysky
			int navic = o_vyska;
			o_vyska = o_sirka;
			o_sirka = navic;
		} else if (alpha == -90 || alpha == 270) {
			o_A.y = r.y - o_sirka;
			// prohozeni sirky a vysky
			int navic2 = o_vyska;
			o_vyska = o_sirka;
			o_sirka = navic2;
		} else if (alpha == 180) {
			o_A.x = r.x - o_sirka;
			o_A.y = r.y - o_vyska;
		}
		cout << "Normalizace - vystupy: [x,y,uhel, sirka, vyska]: " 
				 << o_A.vypis() << ", " << alpha << "," << o_sirka 
				 << "," << o_vyska << "]" << endl;
	}

	// funkce spocita z puvodniho bodu a stredu nove transformovane souradnice
	// in: vstupni bod
	// s: stred
	// out: vystupni bod
	void transformuj(Bod in,Bod s,Bod *out, bool zpetnaTransformace){
		if(zpetnaTransformace){
				out->x = in.x + s.x;
				out->y = in.y + s.y;
		}
		else{	
				out->x = in.x - s.x;
				out->y = in.y - s.y;
		}
	}

	// otoceni podle pocatku souradnic
	// in: vstupni bod 
	// out: rotovany bod
	// alpha - uhel;
	void otoc(Bod in, Bod * out, int alpha){
		float alphaRad = alpha * M_PI / 180.0;
		out->x = in.x * (int) cos(alphaRad) - in.y * (int) sin(alphaRad);
		out->y = in.x * (int) sin(alphaRad) + in.y * (int) cos(alphaRad); 
	}

	// otoci obdelnik podle libovolneho stredu
	// s - bod, podle, ktereho otacime
	// uhel - uhel ve stupnich, o kolik tocime (0,90,180,270)
	void otocPodleStredu(Bod s, int uhel){
		// 1. transformace
		// vytvorim pomocny bod, kam budu ukladat mezivysledky 
		Bod tmp;
		Bod tmp2;
		
		transformuj(o_A, s, &tmp, false);
		cout << "Stav po transformaci: [x,y]: " << tmp.vypis() << endl;

		// 2. rotace
		otoc(tmp, &tmp2, uhel);
		cout << "Stav po rotaci: [x,y]: " << tmp2.vypis() << endl;

		//3. zpetna transformace
		transformuj(tmp2, s, &tmp, true);
		cout << "Stav po zpetne transformaci: [x,y]: " << tmp.vypis() << endl;

		o_A.x = tmp.x;
		o_A.y = tmp.y;

		// 4. normalizace
		normalizuj(uhel, tmp);
		cout << "Stav na konci: [x,y]: " << o_A.vypis() << endl;
		cout << "    sirka: " << o_sirka << ", vyska: " << o_vyska << endl;
	}

	// konstruktory
	Obdelnik(int x, int y, int sirka, int vyska){
		cout << "Vola se konstruktor se 4 parametry." << endl;
		o_A.x = x;
		o_A.y = y;
		o_vyska = vyska;
		o_sirka = sirka;
		o_pocetObdelniku++; // zvysim pocitadlo
	}
	Obdelnik(){
		cout << "Vola se konstruktor s 0 parametry." << endl;
		o_A.x = 0;
		o_A.y = 0;
		o_pocetObdelniku++; // zvysim pocitadlo
	}
	// destruktor
	~Obdelnik(){
		o_pocetObdelniku--;
		cout << "Vola se destruktor" << endl;
	}

	// metody
	void vypisInfo();
	void nastavRozmery(int vyska, int sirka);
	void jeCtvrec(){
		if(o_sirka == o_vyska){
			cout << "Obdelnik je ctverec." << endl;
		} else {
			cout << "Obdelnik neni ctverec." << endl;
		}
	}
	bool jeBodUvnitr(int bx, int by){
		/* vytvorte tuto funkci */
		/* kazdy, kdo ukaze, dostane 1 bod */
		if(	(bx >= o_A.x && bx <= o_A.x + o_sirka) && 
				(by >= o_A.y && by <= o_A.y + o_vyska)){
			cout << "Bod [" << bx << "," << by << "] je uvnitr.\n"; 
			return true;
		} else {
			cout << "Bod [" << bx << "," << by << "] neni uvnitr\n";
			return false;
		}
	}

};

void Obdelnik::nastavRozmery(int vyska, int sirka){
	o_sirka = sirka;
	o_vyska = vyska;
}

void Obdelnik::vypisInfo(){
	cout << "Obdelnik: " << endl;
	cout << "-------" << endl;
	cout << "x,y: [" << o_A.x << "," << o_A.y << "]" << endl;
	cout << "vyska, sirka: " << o_vyska << "," << o_sirka << endl;
}

int Obdelnik::o_pocetObdelniku = 0;

int main(int argc, char ** argv){

	Obdelnik * u_bazen = new Obdelnik(8,4,2,1);
	Obdelnik * u_skola = new Obdelnik(-5,-5,10,20);

	cout << "Pocet obdelniku: " << u_bazen->o_pocetObdelniku << endl;

	delete u_bazen;
	
	cout << "Pocet obdelniku: " << u_skola->o_pocetObdelniku << endl;
	delete u_skola;

	cout << "Pocet obdelniku: " << u_skola->o_pocetObdelniku << endl;

	Obdelnik * u_divadlo = new Obdelnik(8,4,2,1);
	cout << "Pocet obdelniku: " << u_skola->o_pocetObdelniku << endl;

	delete u_divadlo;

	return 0;
}