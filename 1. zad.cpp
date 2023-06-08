#include<iostream>
using namespace std;

char dani[7][20]= {"Ponedjeljak", "Utorak", "Srijeda", "Cetvrtak", "Petak", "Subota", "Nedjelja"};
char jos = 'da';
int izbor;

void prvi(){
	for (int i=0; i<7 ; i++){
		cout << dani[i] << "  ";
	}
	cout << endl;
}

void drugi(){
	char **tjedan = new char *[7];
	tjedan[0] = "Ponedjeljak";
	tjedan[1] = "Utorak";
	tjedan[2] = "Srijeda";
	tjedan[3] = "Cetvrtak";
	tjedan[4] = "Petak";
	tjedan[5] = "Subota";
	tjedan[6] = "Nedjelja";
	
	for (int i = 0 ; i<7 ; i++){
		cout << tjedan[i] << "  ";
	}
	cout << endl;
}

void treci(){
	float broj[3] = {3.55,7.48,8.33};
	float suma = 0;
	for (int i=0 ; i<3 ; i++){
		suma = suma + broj[i];
	}
	cout << "Suma je " << suma << endl;
}

void cetvrto(){
	double *broj = new double [3];
	double suma;
	broj[0] = 3.55;
	broj[1] = 7.48;
	broj[2] = 8.33;
	
	suma = broj[0] + broj[1] + broj[2];
	
	cout << "Suma je " << suma << endl;
	
}

void peto(){
	
	char polje[3][15] = {"monitor", "radni stol", "olovka"};
	for (int i =0 ; i<3 ; i++) cout << polje[i] << "  ";
	cout << endl;
}

void sesto(){
	char **polje = new char *[3];
	polje[0] = "monitor";
	polje[1] = "radni stol";
	polje[2] = "olovka";
	
	for (int i = 0; i<3 ; i++) cout << polje[i] << "  ";
	cout << endl;
}


int main(){

	do{
	cout << endl;
	cout << "Izbornik: " << endl;
	cout << "1. Staticko polje" << endl;
	cout << "2. Dinamicko polje" << endl;
	cout << "3. Staticko polje-brojevi" << endl;
	cout << "4. Dinamicko polje-brojevi" << endl;
	cout << "5. Staticko polje - monitor" << endl;
	cout << "6. Dinamicko polje - monitor" << endl;
	cout << "0. Kraj" << endl;
	cout << "Izbor: ";
	cin >> izbor;
	cout << endl;
	switch(izbor){
		case 1: prvi();break;
		case 2:drugi();break;
		case 3: treci();break;
		case 4: cetvrto();break;
		case 5: peto();break;
		case 6: sesto();break;
	}
	
	}while(izbor != 0);
 	system("pause");
	return 0;
}
