#include <iostream>
#include <fstream>
#include "biblioteka_vrijeme.cc"
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

struct telement{
	int sifra;
	char prez_ime[35], naslov[40];
	float vrijeme_unosa;
};

struct podaci{
	int sifra;
	char prez_ime[35], naslov[40];
	float vrijeme_unosa;
	podaci *sljedeci;
};
fstream dat;
telement slog;
int brojac;

void dealokacija_liste(podaci *lista){
	podaci *tekuci, *sljedeci;
	tekuci=lista->sljedeci;
	sljedeci=tekuci->sljedeci;
	while(sljedeci){
		delete tekuci;
		tekuci=sljedeci;
		sljedeci=sljedeci->sljedeci;
	}
	lista->sljedeci= NULL;
}
void unos(){
	dat.open("datoteka.dat",ios::in|ios::binary);
	if(!dat){
		brojac=0;
		dat.open("datoteka.dat",ios::out|ios::binary);
	}
	else{
		dat.seekg(0,ios::end);
		brojac=dat.tellg()/sizeof(telement);
		dat.close();
		dat.clear();
		dat.open("datoteka.dat",ios::out|ios::app|ios::binary);
	}
	brojac++;
	cout<<"Redni broj zapisa: "<<brojac<<endl<<endl;
	do{
		vrijeme_pocetak();
		cout<<"Sifra:         "; cin>>slog.sifra;
		cout<<"Prezime i ime: ";	unos(slog.prez_ime);
		cout<<"Naslov:        "; unos(slog.naslov);
		vrijeme_kraj();
		slog.vrijeme_unosa=float(int((vrijeme_proteklo()/1000)*10))/10;
		if(slog.vrijeme_unosa<5) cout<<"Unos se ponistava."<<endl;
	}while(slog.vrijeme_unosa<5);
	dat.write((char*)&slog,sizeof(telement));
	dat.close();
	dat.clear();
}

void datoteka_u_listu(podaci *lista){
	podaci *novi, *zadnji=lista;
	if(lista->sljedeci) dealokacija_liste(lista);
	dat.open("datoteka.dat",ios::in|ios::binary);
	while(1){
		dat.read((char*)&slog,sizeof(telement));
		if(dat.eof())	break;
		novi=new podaci;
		zadnji->sljedeci=novi;
		novi->sljedeci=NULL;
		novi->sifra=slog.sifra;
		novi->vrijeme_unosa=slog.vrijeme_unosa;
		strcpy(novi->prez_ime,slog.prez_ime);
		strcpy(novi->naslov,slog.naslov);
		cout<<"Vrijednost primarnog kljuca:"<<slog.sifra<<endl;
		zadnji=novi;
	}
	dat.close();
	dat.clear();

}

void ispis(podaci *lista){
	podaci *tekuci=lista->sljedeci;
	while(tekuci){
		cout<<"Sifra:                       "<<tekuci->sifra<<endl;
		cout<<"Prezime i ime:               "<<tekuci->prez_ime<<endl;
		cout<<"Naslov:                      "<<tekuci->naslov<<endl;
		cout<<"Vrijeme unosa:               "<<tekuci->vrijeme_unosa<<" sekundi"<<endl;
		cout<<"Adresa pok. na sljedeci el.: "<<int((size_t)tekuci->sljedeci)<<endl<<endl;
		tekuci=tekuci->sljedeci;
	}
}
void generiranje_zapisa(){
		int broj_zapisa;
		dat.open("datoteka.dat",ios::out|ios::app|ios::binary);
		cout<<"Koliko zapisa zelite generirati? "; cin>>broj_zapisa;
		for(int i=1;i<=broj_zapisa;i++){
			brojac++;
			slog.sifra=rand()%1000*1000;
			slog.prez_ime[0]=char(rand()%26+65);
			for(int j=1;j<=6;j++)	slog.prez_ime[j]=char(rand()%26+97);
			slog.prez_ime[7]= ' ';
			slog.prez_ime[8]=char(rand()%26+65);
			for(int j=9;j<=16;j++)	slog.prez_ime[j]=char(rand()%26+97);
			slog.prez_ime[17]='\0';
			slog.naslov[0]=char(rand()%26+65);
			for(int j=1;j<=10;j++)	slog.naslov[j]=char(rand()%26+97);
			slog.naslov[11]='\0';
			slog.vrijeme_unosa=0;
			dat.write((char*)&slog,sizeof(telement));
		}
		dat.close();
		dat.clear();
}
int main(){
	remove("datoteka.dat");
	int izbor;
	podaci *lista;
	lista=new podaci;
	lista->sljedeci=NULL;
	do{
		cout<<"-----------------------------------"<<endl;
		cout<<"1 - Rucni unos zapisa u datoteku"<<endl;
		cout<<"2 - Generiranje zapisa datoteke"<<endl;
		cout<<"3 - Kopiranje datoteke u listu"<<endl;
		cout<<"4 - Ispis vezane liste"<<endl;
		cout<<"9 - Izlaz iz programa"<<endl;
		cout<<"-----------------------------------"<<endl;
		cout<<"Vas izbor: "; cin>>izbor;
		cout<<"-----------------------------------"<<endl;
		switch(izbor){
			case 1:unos();	break;
			case 2:generiranje_zapisa;	break;
			case 3:datoteka_u_listu(lista);	break;
			case 4:ispis(lista);	break;
		}
		cout<<endl;
	}while(izbor!=9);
	system("pause");
	return 0;
}

  
