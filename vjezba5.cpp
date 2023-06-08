#include<iostream>
#include<fstream>
#include<cmath>
#include "biblioteka_vrijeme.cc"
using namespace std;

struct tpodaci{
	int sifra;
	char prezime[15];
	char naslov[15];
};

fstream dat;
tpodaci podaci, podaci1;
int prost_broj, rbz;

int prvi_manji(int x){
	int prost;
	for (int i = x-i; i>1 ; i--){
		prost = 1;
		for (int j = 2 ; j<=sqrt(i) ; j++){
			if (i%j==0){
				prost = 0;
				break;
			}
		}
		if (prost) return i;
	}
	return 0;
}

void kreiranje(){
	int vd;
	cout << "Velicina datoteke u broju zapisa: ";
	cin >> vd;
	podaci.sifra = 0;
	podaci.prezime[0] = '\0';
	podaci.naslov[0] = '\0';
	prost_broj = prvi_manji(vd);
	cout << "Prvi manji prost broj: " << prost_broj << endl <<endl;
	dat.open("podaci1.dat", ios::out | ios::binary);
	for (int i = 0; i<vd ; i++){
		dat.write((char*)&podaci, sizeof(tpodaci));
	}
	dat.close();
	dat.clear();
}

void upis(){
	cout << "Sifra: ";
	cin >> podaci.sifra;
	cout << "Prezime: ";
	unos(podaci.prezime);
	cout << "Naslov: ";
	unos(podaci.naslov);
	
	rbz = podaci.sifra%prost_broj;
	dat.open("podaci1.dat", ios::in | ios::out | ios::binary);
	dat.seekg(rbz*sizeof(tpodaci));
	do{
		dat.read((char*)&podaci1, sizeof(tpodaci));
	}while(podaci1.sifra>0);
	rbz = (dat.tellg()/sizeof(tpodaci))-1;
	dat.seekp(rbz*sizeof(tpodaci));
	dat.write((char*)&podaci, sizeof(tpodaci));
	dat.close();
	dat.clear();
}

void pretrazivanje(){
	bool postoji = false;
	int brojac = 0;
	int sifra;
	cout << "Sifra: ";
	cin >> sifra;
	rbz = sifra%prost_broj;
	dat.open("podaci1.dat", ios::in | ios::binary);
	dat.seekg(rbz*sizeof(tpodaci));
	do{
		dat.read((char*)&podaci, sizeof(tpodaci));
		if ((podaci.sifra%prost_broj) == rbz) brojac++;
		if (dat.eof()) break;
		if (podaci.sifra == sifra){
			postoji = true;
			cout << "NADJENO" << endl;
			cout << "Sifra: " << podaci.sifra << endl;
			cout << "Prezime: " << podaci.prezime << endl;
			cout << "Naslov: " << podaci.naslov << endl;
			
			if (brojac>1) cout << "DUPLIKAT" << endl << endl;
		}
	}while(podaci.sifra>0);
	
	if (!postoji) cout << "NE POSTOJI" << endl << endl;
	//if (brojac>1) cout << "DUPLIAKTI " << endl << endl;
	dat.close();
	dat.clear();
}

void statistika(){
	int brojac = 0;
	dat.open("podaci1.dat", ios::in | ios::binary);
	while(1){
		dat.read((char*)&podaci, sizeof(tpodaci));
		if (dat.eof()) break;
		if (podaci.sifra == 0) brojac++;
	}
	cout << "PRAZNO ZAPISA: " << brojac << endl << endl;
	dat.close();
	dat.clear();
}


int main(){
	int izbor;
	do{
		cout << "------IZBORNIK-------" << endl;
		cout << "1. Kreiranje datoteke "<< endl;
		cout << "2. Unos podataka u dat" << endl;
		cout << "3. Pretrazivanje datoteke" << endl;
		cout << "4. Statistika" << endl;
		cout << "IZBOR: ";
		cin >> izbor;
		cout << endl;
		switch(izbor){
			case 1: kreiranje();break;
			case 2: upis();break;
			case 3: pretrazivanje();break;
			case 4: statistika();break;
		}

	}while(izbor != 9);
	
	
	
	return 0;
}
