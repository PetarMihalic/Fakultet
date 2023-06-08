#include<iostream>
#include<cmath>
using namespace std;

int izbor;

void pravokutnik(){
	float a, b, p;
	do{
		cout << "A: ";
		cin >> a;
	}while(a<0);
	
	do{
		cout << "B: ";
		cin >> b;
	}while(b<0);
	
	p = a*b;
	cout << "Povrsina pravokutnika je " << p << endl;
}

void pravokutnik2(){
	float a, b, p;
	
	cout << "A: ";
	cin >> a;
	if (a<0) cout << "Pogreska!" << endl;
	
	cout << "B: ";
	cin >> b;
	if (b<0) cout << "Pogreska!" << endl;
	
	if (a>0 and b>0){
		p = a*b;
		cout << "Povrsina pravokutnika je " << p << endl;
	}
}

void radijus(){
	float r, p;
	float pi = 3.14;
	
	do{
		cout << "Radijus: ";
		cin >> r;
	}while(r<0);
	
	p = (r*r)*pi;
	cout << "Povrsina kruga je " << p << endl;
}

void radijus2(){
	float r, p, pi=3.14;
	
	cout << "Radijus: ";
	cin >> r;
	
	if (r<0) cout << "Pogreska!!" << endl;
	
	if (r>0){
		p = r*r*M_PI;
		cout << "Povrsina kruga je " << p << endl;
	}
}

void trokut(){
	float a, b, p;
	
	do{
		cout << "A: ";
		cin >> a;
	}while(a<0);
	
	do{
		cout << "B: ";
		cin >> b;
	}while(b<0);
	
	p = (a*b)/2;
	cout << "Povrsina trokuta je " << p << endl;
}

void trokut2(){
	float a, b, p;
	
	cout << "A: ";
	cin >> a;
	if (a<0) cout << "Pogreska!!" << endl;
	
	cout << "B: ";
	cin >> b;
	if (b<0) cout << "Pogreska!!" << endl;
	
	if (a>0 and b>0){
		p = (a*b)/2;
		cout << "Povrsina trokuta je " << p << endl;
	}
}

int main(){
	
	do{
		cout << endl;
		cout << "Izbornik: " << endl;
		cout << "1. P pravokutnika" << endl;
		cout << "2. P pravokutnika - bez ponavljanja" << endl;
		cout << "3. P kruga" << endl;
		cout << "4. P kruga - bez ponavljanja" << endl;
		cout << "5. P trokuta" << endl;
		cout << "6. P trokuta - bez ponavljanja" << endl;
		cout << "0. Kraj" << endl;
		cout << "Izbor: ";
		cin >> izbor;
		cout << endl;
		switch(izbor){
			case 1:pravokutnik(); break;
			case 2:pravokutnik2(); break;
			case 3:radijus();break;
			case 4:radijus2();break;
			case 5:trokut();break;
			case 6:trokut2();break;
	}
	}while(izbor != 0);

	return 0;
}
