// MD5:X3xk358L3JmsEzPsWCqOuA==// Verifikator 4.00// Program:2// Opis zadatka:2// Autor:m m 2// Poèetno vrijeme:18.10.2017. 21:37:22// Završno vrijeme:18.10.2017. 22:06:03// IP:fe80::15b0:2a25:3abc:dca9%6 ( 190 )// #:#include <iostream>,#include <cstdlib>,#include <iomanip>,#include "biblioteka_vrijeme.cc",// Uspješnih/neuspješnih prevoðenja:22/1#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "biblioteka_vrijeme.cc"
using namespace std;

struct podaci{
	int sifra;
	char prez_ime[35];
	char naslov[30];
	float vrijeme_unosa;
	podaci *sljedeci;
};

void unos(podaci *lista){
	podaci *novi, *zadnji;
	zadnji=lista;
	while(zadnji->sljedeci)
		zadnji=zadnji->sljedeci;
	novi= new podaci;
	zadnji->sljedeci=novi;
	novi->sljedeci=NULL;
	vrijeme_pocetak();
	cout<<"Unosi sifra:";
	cin>>novi->sifra;
	cout<<"Unesite prezime i ime:";
	cin>>novi->prez_ime;
	cout<<"Unesite naslov:";
	cin>>novi->naslov;
	vrijeme_kraj();
	novi->vrijeme_unosa=vrijeme_proteklo();
}

void ispis(podaci *lista){
	podaci *tekuci=lista->sljedeci;
	while(tekuci){
		cout<<"Prezime i ime:"<<tekuci->prez_ime<<endl;
		cout<<"Naslov:"<<tekuci->naslov<<endl;
		cout<<"Sifra:"<<tekuci->sifra<<endl;
		tekuci=tekuci->sljedeci;
	}
}

void trazenje(podaci *lista){
	podaci *tekuci=lista->sljedeci;
	int sifra;
	cout<<"Unesite sifru:";
	cin>>sifra;
	int nadeno=0;
	while(tekuci){
		if(tekuci->sifra==sifra){
			nadeno=1;
			cout<<"Element je pronaden."<<endl;
			cout<<"Prezime i ime:"<<tekuci->prez_ime<<endl;
			cout<<"Naslov:"<<tekuci->naslov<<endl;
			cout<<"Sifra:"<<tekuci->sifra<<endl;
			cout<<"Vrijeme unosa iznosi:"<<setprecision(1)<<fixed<<tekuci->vrijeme_unosa/1000<<endl;
			cout<<"Adresa na sljedeci element:"<<int((size_t)tekuci->sljedeci)<<endl;
			return;
		}
		tekuci=tekuci->sljedeci;
	}
	if(nadeno==0)
		cout<<"Element s zadanom sifrom autora ne postoji."<<endl;
}

void brisanje(podaci *lista){
	podaci *brisi=lista->sljedeci, *prethodni=lista;
	int sifra;
	cout<<"Unesite sifru:";
	cin>>sifra;
	while(brisi){
		if(brisi->sifra==sifra){
		prethodni->sljedeci=brisi->sljedeci;
		delete brisi;
		cout<<"Element je izbrisan."<<endl;
		return;
		}
		prethodni=brisi;
		brisi=brisi->sljedeci;
	}
	cout<<"Element s unesenom sifrom autora ne postoji."<<endl;
}
int main(){
	int izbor;
	podaci *lista;
	lista= new podaci;
	lista->sljedeci= NULL;
	do{
		cout<<"Unesite 1 za unos."<<endl;
		cout<<"Unesite 2 za ispis."<<endl;
		cout<<"Unesite 3 za trazenje."<<endl;
		cout<<"Unesite 4 za brisanje."<<endl;
		cout<<"Unesite 9 za izlazak iz programa."<<endl;
		cout<<"Vas izbor je:";
		cin>>izbor;
		cout<<endl<<endl;
		switch(izbor){
			case 1: unos(lista);
				break;
			case 2: ispis(lista);
				break;
			case 3: trazenje(lista);
				break;
			case 4: brisanje(lista);
				break;
		}
		cout<<endl<<endl;
	}while(izbor!=9);
	cout<<"Kraj programa."<<endl;
	system("pause");
	return 0;
}
