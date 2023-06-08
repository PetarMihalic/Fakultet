#include<iostream>
using namespace std;

struct tstudent{
	int broj;
	int sifra;
	char prezime[15];
	int godina;
	tstudent *sljedeci;
	tstudent *prethodni;
	tstudent *lijevo;
	tstudent *desno;
};

void dodaj_na_kraj(tstudent *lista){
	tstudent *novi, *zadnji;
	zadnji = lista;
	while(zadnji->sljedeci) zadnji = zadnji->sljedeci;
	novi = new tstudent;
	novi->prethodni = zadnji;
	novi->sljedeci = NULL;
	zadnji->sljedeci = novi;
	cout << "Maticni broj: ";
	cin >> novi->sifra;
	cout << "Prezime i ime: ";
	cin >> novi->prezime;
	cout << "Godina upisa: ";
	cin >> novi->godina;
	cout << endl;
}

void ispis_od_pocetka(tstudent *lista){
	tstudent *tekuci = lista->sljedeci;
	while(tekuci){
		cout << "Maticni broj: " << tekuci->sifra << endl;
		cout << "Prezime i ime: " << tekuci->prezime << endl;
		cout << "Godina upisa: " << tekuci->godina << endl;
		tekuci = tekuci->sljedeci;
		cout << endl;
	}
}

void dodaj_na_pocetak(tstudent *lista){
	if(!lista->sljedeci){
		dodaj_na_kraj(lista);
		return;
	}
	tstudent *novi, *sljedeci;
	sljedeci = lista->sljedeci;
	novi = new tstudent;
	lista->sljedeci = novi;
	novi->sljedeci = sljedeci;
	sljedeci->prethodni = novi;
	novi->prethodni = lista;
	cout << "Maticni broj: ";
	cin >> novi->sifra;
	cout << "Prezime i ime: ";
	cin >> novi->prezime;
	cout << "Godina upisa: ";
	cin >> novi->godina;
	cout << endl;
}

void ispis_od_kraja(tstudent *lista){
	tstudent *tekuci = lista->sljedeci;
	while(tekuci->sljedeci){
		tekuci = tekuci->sljedeci;
	}
	while(tekuci!=lista){
		cout << "Maticni broj: " << tekuci->sifra << endl;
		cout << "Prezime i ime: " << tekuci->prezime << endl;
		cout << "Godina upisa: " << tekuci->godina << endl;
		tekuci = tekuci->prethodni;
		cout << endl;
	}
}

void brisanje(tstudent *lista){
	tstudent *brisi = lista->sljedeci, *prethodni = lista;
	tstudent *sljedeci = brisi->sljedeci;
	int sifra;
	cout << "Sifra: ";
	cin >> sifra;
	while(brisi->sljedeci){
		if(brisi->sifra == sifra){
			prethodni->sljedeci = sljedeci;
			sljedeci->prethodni = prethodni;
			delete brisi;
			cout << "Element je izbrisan" << endl << endl;
			return;
		}
		prethodni = brisi;
		brisi = sljedeci;
		sljedeci = sljedeci->sljedeci;
	}
	if (sifra == brisi->sifra){
		prethodni->sljedeci = brisi->sljedeci;
		delete brisi;
		cout << "Element je izbrisan" << endl << endl;
		return;
	}
	cout << "Element ne postoji" << endl << endl;
}

void cvorovi(tstudent *stablo){
	tstudent *novi, *zadnji;
	zadnji = stablo;
	int broj;
	cout << "Broj: ";
	cin >> broj;
	int dalje =1;
	do{
		if(broj>zadnji->broj){
			if (zadnji->desno!= NULL) zadnji = zadnji->desno;
			else{
				novi = new tstudent;
				zadnji->desno = novi;
				novi->broj = broj;
				novi->lijevo = NULL;
				novi->desno = NULL;
				dalje = 0;
			}
		}
		else{
			if (zadnji->lijevo!= NULL) zadnji = zadnji->lijevo;
			else{
				novi = new tstudent;
				zadnji->lijevo = novi;
				novi->broj = broj;
				novi->lijevo = NULL;
				novi->desno = NULL;
				dalje = 0;
			}
		}	
	}while(dalje == 1);
}

void sort_uzlazno(tstudent *stablo){
	static tstudent *korijen = stablo;
	if(stablo==NULL) return;
	sort_uzlazno(stablo->lijevo);
	if(stablo!=korijen)
		cout << stablo->broj << "  " ;
	sort_uzlazno(stablo->desno);
}


int main(){
	tstudent *lista = new tstudent;
	lista->sljedeci = NULL;
	lista->prethodni = NULL;
	
	tstudent *stablo =new tstudent;
	stablo->lijevo = NULL;
	stablo->desno = NULL;
	
	int izbor;
	do{
		cout << "-------------IZBORNIK------------" << endl;
		cout << "1. Upis na kraj, ispis od pocetka" << endl;
		cout << "2. Upis na pocetak, ispis od kraja" << endl;
		cout << "3. Brisanje cvorova" << endl;
		cout << "4. Dodavanje novog cvora" << endl;
		cout << "9. Kraj" << endl;
		cout << "IZBOR: ";
		cin >> izbor;
		cout << endl;
		
		switch(izbor){
			case 1: dodaj_na_kraj(lista);
					ispis_od_pocetka(lista);break;
			case 2:dodaj_na_pocetak(lista);
					ispis_od_pocetka(lista);break;
			case 3:brisanje(lista);break;
		}
	}while(izbor != 9);
	return 0;
}
