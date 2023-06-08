#include <iostream>
#include <iomanip>
#include <cmath>
#include "vrijeme.cc"

using namespace std;

class ctrokut{
	
private: 
	float s;
	cvrijeme vrijeme; 
	
public: 
	static int brojac; 
	char naziv[30];
	float a, b, c;
	float povrsina() {
		s = (a+b+c)/2;
		float p; 
		p = sqrt(s*(s-a)*(s-b)*(s-c));
		if(s*(s-a)*(s-b)*(s-c) <= 0)
			return -1;
		return p;
	}
	void unos() {
		vrijeme.pocetak();
		cout << "Upisite naziv trokuta: " << endl;
		cin.ignore();
		cin.getline(naziv, 30); 
		cout << "Upisite stranicu a: " << endl;
		cin >> a; 
		cout << "Upisite stranicu b: " << endl;
		cin >> b;
		cout << "Upisite stranicu c: " << endl;
		cin >> c; 
		vrijeme.kraj();
		vrijeme.proteklo();
	}
	void ispis(){
		cout << "Naziv trokuta: " << naziv << endl;
		cout << "Duljine stranica trokuta: " << a <<", " << b <<", " << c << endl;
		if(povrsina()==-1)
			cout << "Stranice ne cine trokut." << endl;
		else 
			cout << "Povrsina trokuta: " << povrsina() << endl;
		cout << "Vrijeme unosa: " << int(vrijeme.proteklo()/1000*100)/100.0<< endl;
	}
	bool pravokutni(){
		if( pow(a,2)+pow(b,2) == pow(c,2) )
			return true; 
		else 
			return false; 
	}
	bool nije_trokut() {
		if (povrsina()==-1)
			return true;
		else
			return false;
	}
	
};
int ctrokut::brojac = 0;


int main () {
	
	int izbor, br=0, br2=0;
	float suma; 
	bool pravokutni = false; 
	ctrokut *trokut;
	trokut = new ctrokut[100];
	
	do {
		cout << "1 za unos" << endl;
		cout << "2 za ispis" << endl;
		cout << "3 za statistiku" << endl;
		cout << "4 za prepoznavanje odredenih vrsta trokuta" << endl;
		cout << "9 za izlaz" << endl; 
		cout << "Vas izbor: " << endl;
		cin >> izbor;
		
		switch(izbor) {
			case 1: 
				trokut[ctrokut::brojac].unos(); 
				ctrokut::brojac++;
				break;
			case 2: 
				for(int i=0;i<ctrokut::brojac; i++){
				
				 	if(trokut[i].povrsina() != -1) 
						trokut[i].ispis();
					else	
						trokut[i].ispis();
				}
				break;
			case 3:
				br = 0;
				br2 = 0;
				suma = 0; 
				for(int i=0;i<ctrokut::brojac;i++)
				 	if(trokut[i].nije_trokut())
				 		br++;
				 	else {
				 		suma = suma + trokut[i].povrsina();
				 		br2++; }
				cout << "Ukupan broj korisnikovih zapisa: " << ctrokut::brojac << ", broj unosa koji cine trokut: " << br2 << endl;
				cout << "Ukupan broj korisnikovih zapisa: " << ctrokut::brojac << ", broj unosa koji ne cine trokut: " << br << endl;
				cout << "Ukupan broj korisnikovih zapisa: " << ctrokut::brojac << ", povrsina svih trokuta: " << suma << endl;
				break;
			case 4: 
				for(int i=0;i<ctrokut::brojac;i++) {
					if(trokut[i].pravokutni() )
						trokut[i].ispis();
				}
			break;
			case 9: cout << "Kraj programa!" << endl;
		}
	}
	while(izbor!=9);
	
	delete [] trokut;
	
	system("pause");
	return 0;
}
