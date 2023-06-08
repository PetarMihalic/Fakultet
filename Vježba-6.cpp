#include <iostream>
#include <fstream>
#include "biblioteka_vrijeme_i_binarno_pretrazivanje.cc"

using namespace std;

struct tpodaci{
	int sifra;
	char prez_ime[30];
	char naslov[20];
	float vrijeme_unosa;
};

fstream dat, ind;

void unos(){
	tpodaci podaci;
	tindeks indeks; //tindeks je u biblioteci
	dat.open("datoteka.dat", ios::in | ios::binary);
	ind.open("datoteka.ind", ios::in | ios::binary);
	if(!dat && !ind){
		dat.close();dat.clear();
		ind.close();ind.clear();
		dat.open("datoteka.dat", ios::out | ios::binary);
		ind.open("datoteka.ind", ios::out | ios::binary);
	}
	else{
		dat.close();dat.clear();
		ind.close();ind.clear();
		dat.open("datoteka.dat", ios::out | ios::in | ios::ate | ios::binary);
		ind.open("datoteka.ind", ios::out | ios::in | ios::ate | ios::binary);
	}
	//do{ //makni komentar ak se trazi da ponovo uneses u slucaju pogresnog unosa
	vrijeme_pocetak();
	cout<<"Sifra autora: ";cin>>podaci.sifra;
	cin.ignore();
	cout<<"Prezime i ime: ";cin.getline(podaci.prez_ime,30);
	cout<<"Naslov rada: ";cin.getline(podaci.naslov,20);
	vrijeme_kraj();
	podaci.vrijeme_unosa=float(int((vrijeme_proteklo()/1000)*10))/10;
	if(podaci.vrijeme_unosa<5) cout<<"Unos se ponistava!"<<endl<<endl;
	//}while(podaci.vrijeme_unosa<5);
	if(podaci.vrijeme_unosa>=5){
		dat.write((char*)&podaci, sizeof(tpodaci));
		indeks.kljuc=podaci.sifra;
		indeks.adresa=(int)dat.tellp()-sizeof(tpodaci);
		ind.write((char*)&indeks, sizeof(tindeks));
		dat.close();dat.clear();
		ind.close();ind.clear();
		preslozi_indeks((char*)"datoteka.ind",indeks);
		cout<<endl;
	}
}

void trazi(){
	tpodaci podaci;
	tindeks indeks;
	int sifra;
	bool postoji=false;
	cout<<"Unesite trazenu sifru: ";cin>>sifra;
	dat.open("datoteka.dat", ios::in | ios::binary);
	ind.open("datoteka.ind", ios::in | ios::binary);
	while(true){
		ind.read((char*)&indeks, sizeof(tindeks));
		if(ind.eof()) break;
		if(indeks.kljuc==sifra){
			dat.seekg(indeks.adresa);
			dat.read((char*)&podaci, sizeof(tpodaci));
			postoji=true;
			cout<<"Prezime i ime: "<<podaci.prez_ime<<endl;
			cout<<"Naslov rada: "<<podaci.naslov<<endl;
			cout<<"Vrijeme unosa: "<<podaci.vrijeme_unosa<<endl;
			cout<<endl;
			break;
		}
	}
	if(!postoji) cout<<"Element ne postoji!"<<endl<<endl;
	dat.close();dat.clear();
	ind.close();ind.clear();
}

void ispis(){
	tpodaci podaci;
	tindeks indeks;
	dat.open("datoteka.dat", ios::in | ios::binary);
	ind.open("datoteka.ind", ios::in | ios::binary);
	while(true){
		ind.read((char*)&indeks, sizeof(tindeks));
		if(ind.eof()) break;
		dat.seekg(indeks.adresa);
		dat.read((char*)&podaci, sizeof(tpodaci));
		cout<<"Sifra autora: "<<podaci.sifra<<endl;
		cout<<"Prezime i ime: "<<podaci.prez_ime<<endl;
		cout<<"Naslov rada: "<<podaci.naslov<<endl;
		cout<<"Vrijeme unosa: "<<podaci.vrijeme_unosa<<endl;
		cout<<"--------------------------------"<<endl;
	}
	dat.close();dat.clear();
	ind.close();ind.clear();
	cout<<endl;
}

void statistika(){
	tindeks indeks;
	int br=0, max=INT_MIN, suma=0;
	ind.open("datoteka.ind", ios::in | ios::binary);
	while(true){
		ind.read((char*)&indeks, sizeof(tindeks));
		if(ind.eof()) break;
		br++;
		suma+=indeks.kljuc;
		if(indeks.kljuc>max) max=indeks.kljuc;
	}
	cout<<"Aritmeticka sredina svih vrijednosti primarnog kljuca je: "<<suma/br<<endl; //Mogucnost 1
	//cout<<"Zbroj svih vrijednosti primarnog kljuca je: "<<suma<<endl; //Mogucnosti 2
	//cout<<"Najveci element je: "<<max<<endl<<endl; //Mogucnost 3
	ind.close();ind.clear();
}

int main(){
	int odabir;
	do{
		cout<<"Unesi 1 za unos u indeksiranu datoteku"<<endl;
		cout<<"Unesi 2 za pretrazivanje indeksirane datoteke"<<endl;
		cout<<"Unesi 3 za ispis maticne datoteke"<<endl;
		cout<<"Unesi 4 za statistiku"<<endl;
		cout<<"Unesi 9 za izlaz iz programa"<<endl;
		cout<<"-----------------------------"<<endl;
		cout<<"Vas odabir: ";cin>>odabir;
		cout<<endl;
		switch(odabir){
			case 1:unos();break;
			case 2:trazi();break;
			case 3:ispis();break;
			case 4:statistika();break;
			default:break;
		}
	}while(odabir!=9);
	return 0;
}
