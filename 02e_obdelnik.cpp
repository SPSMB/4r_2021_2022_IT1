#include <iostream>
#include <math.h>

using namespace std;



// trida obdelnik
class Obdelnik{
  private:
	// data 
	int o_x; int o_y; /* levy dolni roh */
	int o_plocha; int obvod;
	
  public:
	int o_sirka; int o_vyska; 

	// alpha - uhel, o ktery se otaci
	// x_rot - xova souradnice rotovaneho bodu
	// y_rot - yova souradnice rotovaneho bodu
	void normalizuj(int alpha, int x_rot, int y_rot){
		if (alpha == 90 || alpha == -270) {
			o_x = x_rot - o_vyska;
			// prohozeni sirky a vysky
			int navic = o_vyska;
			o_vyska = o_sirka;
			o_sirka = navic;
		} else if (alpha == -90 || alpha == 270) {
			o_y = y_rot - o_sirka;
			// prohozeni sirky a vysky
			int navic2 = o_vyska;
			o_vyska = o_sirka;
			o_sirka = navic2;
		} else if (alpha == 180) {
			o_x = x_rot - o_sirka;
			o_y = y_rot - o_vyska;
		}
		cout << "Normalizace - vystupy: [x,y,uhel, sirka, vyska]: [" << o_x << ", " 
				 << o_y << ", " << alpha << "," << o_sirka 
				 << "," << o_vyska << "]" << endl;
	}

	// funkce spocita z puvodniho bodu a stredu nove transformovane souradnice
	// in: vstupni bod
	// s: stred
	// out: vystupni bod
	void transformuj(int in_x, int in_y, int s_x, int s_y, int * out_x, int * out_y, bool zpetnaTransformace){
		if(zpetnaTransformace){
				*out_x = in_x + s_x;
				*out_y = in_y + s_y;
		}
		else{	
				*out_x = in_x - s_x;
				*out_y = in_y - s_y;
		}
	}

	// otoceni podle pocatku souradnic
	// in: vstupni bod 
	// out: rotovany bod
	// alpha - uhel;
	void otoc(int in_x, int in_y, int alpha, int * out_x, int * out_y){
		float alphaRad = alpha * M_PI / 180.0;
		*out_x = in_x * (int) cos(alphaRad) - in_y * (int) sin(alphaRad);
		*out_y = in_x * (int) sin(alphaRad) + in_y * (int) cos(alphaRad); 
	}

	// otoci obdelnik podle libovolneho stredu
	// s_x - x souradnice stredu 
	// s_y - y souradnice stredu
	// uhel - uhel ve stupnich, o kolik tocime (0,90,180,270)
	void otocPodleStredu(int s_x, int s_y, int uhel){
		// 1. transformace
		// vytvorim pomocny bod, kam budu ukladat mezivysledky 
		int tmp_x, tmp_y;
		int tmp2_x, tmp2_y;
		transformuj( o_x, o_y, s_x, s_y, & tmp_x, & tmp_y, false);
		cout << "Stav po transformaci: [x,y]: [" << tmp_x << "," << tmp_y << "]" << endl;

		// 2. rotace
		otoc( tmp_x, tmp_y, uhel, & tmp2_x, & tmp2_y);
		cout << "Stav po rotaci: [x,y]: [" << tmp2_x << "," << tmp2_y << "]" << endl;

		//3. zpetna transformace
		transformuj( tmp2_x, tmp2_y, s_x, s_y, & tmp_x, & tmp_y, true);
		cout << "Stav po zpetne transformaci: [x,y]: [" << tmp_x << "," << tmp_y << "]" << endl;

		o_x = tmp_x;
		o_y = tmp_y;

		// 4. normalizace
		normalizuj( uhel, tmp_x, tmp_y);
		cout << "Stav na konci: [x,y]: [" << o_x << "," << o_y << "]" << endl;
		cout << "    sirka: " << o_sirka << ", vyska: " << o_vyska << endl;
	}

	// konstruktory
	Obdelnik(int x, int y, int sirka, int vyska){
		cout << "Vola se konstruktor se 4 parametry." << endl;
		o_x = x;
		o_y = y;
		o_vyska = vyska;
		o_sirka = sirka;
	}
	Obdelnik(){
		cout << "Vola se konstruktor s 0 parametry." << endl;
		o_x = 0;
		o_y = 0;
	}
	// destruktor
	~Obdelnik(){
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
		if(	(bx >= o_x && bx <= o_x + o_sirka) && 
				(by >= o_y && by <= o_y + o_vyska)){
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
	cout << "x,y: [" << o_x << "," << o_y << "]" << endl;
	cout << "vyska, sirka: " << o_vyska << "," << o_sirka << endl;
}

int main(int argc, char ** argv){

	/*
	Obdelnik skolnihriste(35,45,100,100);

	cout << "Skolnihriste sirka:" 
		   << skolnihriste.o_sirka << endl;

	skolnihriste.nastavRozmery(300,400);
	skolnihriste.vypisInfo();
	skolnihriste.jeCtvrec();
	skolnihriste.jeBodUvnitr(35,45);
	*/
	Obdelnik bazen(8,4,2,1);
	bazen.otocPodleStredu(3, 5, 180);

	return 0;
}