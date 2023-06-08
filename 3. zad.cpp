#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;

struct tstudent{
	int mat_br;
	char prez_ime[35];
	int g_upisa;
};

struct tpredmet{
	int sifra;
	char naziv[15];
};

int main(){
	//3a---------------------------------------------------------
	tstudent student, kopija;
	
	student.mat_br = 30500;
	strcpy(student.prez_ime, "Matic Marko");
	student.g_upisa = 2016;
	
	memcpy(&kopija, &student, sizeof(tstudent));
	
	cout << "Maticni broj: " << kopija.mat_br << endl;
	cout << "Prezime i ime: " << kopija.prez_ime << endl;
	cout << "Godina upisa: " << kopija.g_upisa << endl;
	
	cout << "---------------------------------------------------" << endl;
	//3b---------------------------------------------------------
	
	tstudent *student1 = new tstudent();
	tstudent *student2 = new tstudent();
	
	student1->mat_br = 30500;
	strcpy(student1->prez_ime, "Matic Marko");
	student1->g_upisa = 2016;
	
	memcpy(&student2, &student1, sizeof(tstudent));
	
	cout << "Maticni broj: " << student2->mat_br << endl;
	cout << "Prezime i ime: " << student2->prez_ime << endl;
	cout << "Godina upisa: " << student2->g_upisa << endl;
	cout << "---------------------------------------------------" << endl;
	
	//3c----------------------------------------------------------
	tpredmet predmet, kopijaa;
	
	predmet.sifra = 119;
	strcpy(predmet.naziv, "Matematika");
	
	memcpy(&kopijaa, &predmet, sizeof(tpredmet));
	
	cout << "Sifra predmeta: " << kopijaa.sifra << endl;
	cout << "Naziv predmet: " << kopijaa.naziv << endl;
	cout << "---------------------------------------------------" << endl;
	
	//3d----------------------------------------------------------------
	tpredmet *predmet1 = new tpredmet();
	tpredmet *kopija1 = new tpredmet();
	
	predmet1->sifra = 119;
	strcpy(predmet1->naziv, "Matematika");
	
	memcpy(&kopija1, &predmet1, sizeof(tpredmet));
	
	cout << "Sifra predmeta: " << kopija1->sifra << endl;
	cout << "Naziv predmeta: " << kopija1->naziv << endl;
	cout << "---------------------------------------------------" << endl;
	//3e-----------------------------------------------------------------
	tstudent student3;
	cout << "Maticni broj: ";
	cin >> student3.mat_br;
	cout << "Prezime i ime: ";
	cin >> student3.prez_ime;
	cout << "Godina upisa: ";
	cin >> student3.g_upisa;
	
	cout << endl;
	cout << "Maticni broj: " << student3.mat_br << endl;
	cout << "Prezime i ime: " << student3.prez_ime << endl;
	cout << "Godina upisa: " << student3.g_upisa << endl;
	
	//3f-----------------------------------------------------------------
	
	tstudent *studenti = new tstudent();
	
	cout << endl;
	cout << "Maticni broj: " ;
	cin >> studenti->mat_br;
	cout << "Prezime i ime: ";
	cin >> studenti->prez_ime;
	cout << "Godina upisa: ";
	cin >> studenti->g_upisa;
	cout << endl;
	cout << "Maticni broj: " << studenti->mat_br << endl;
	cout << "Prezime i ime: " << studenti->prez_ime << endl;
	cout << "Godina upisa: " << studenti->g_upisa << endl;
	
	return 0;
}
