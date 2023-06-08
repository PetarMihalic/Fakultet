#include<iostream>
#include<ctime>
#include "biblioteka_vrijeme.cc"
#include<cmath>
using namespace std;

int izbor;

void prvo(){
	float a, b, c, p, vrijeme;
	float s, h, tmp;
	
	do{
		cout << "A: ";
		cin >> a;
		vrijeme_pocetak();
		cout << "B: ";
		cin >> b;
		cout << "C: ";
		cin >> c;
		vrijeme_kraj();
		cout << endl;
		//cout << vrijeme_proteklo() << " tisucinki"<< endl << endl;
		vrijeme = vrijeme_proteklo()/1000;
		//cout << vrijeme << " sekunde" << endl;
		vrijeme = vrijeme * 100;
		vrijeme = int(vrijeme);
		vrijeme =float(vrijeme)/100;
		
		s = (a+b+c)/2;
		tmp = s*(s-a)*(s-b)*(s-c);
		h = sqrt(tmp);
	}while(tmp <= 0);
		
	h = h*100;
	h = int(h);
	h = float(h)/100;	
	cout << "Povrsina je " << h << endl;
	cout << vrijeme << " sekunde" << endl;
}

void drugo(){
	float a, b, c, tmp, h, s;
	float t1, t2, t3;
	
	do{
		cout << "A: ";
		vrijeme_pocetak();
		cin >> a;
		vrijeme_kraj();
		t1 = vrijeme_proteklo()/1000;
		cout << "B: ";
		vrijeme_pocetak();
		cin >> b;
		vrijeme_kraj();
		t2 = vrijeme_proteklo()/1000;
		cout << "C: ";
		vrijeme_pocetak();
		cin >> c;
		vrijeme_kraj();
		t3 = vrijeme_proteklo()/1000;
		
		t1 = t1*100;
		t1 = int(t1);
		t1 = float(t1)/100;
		
		t2 = t2*100;
		t2 = int(t2);
		t2 = float(t2)/100;
		
		t3 = t3*100;
		t3 = int(t3);
		t3 = float(t3)/100;
		
		cout << "t1: " <<t1 << " t2: " << t2 << " t3: " << t3 << endl;
		
		s = (a+b+c)/2;
		tmp = s*(s-a)*(s-b)*(s-c);
		
	}while(tmp <= 0);
	
	h = sqrt(tmp);
	h = h*100;
	h = int(h);
	h = float(h)/100;
	
	cout << "Povrsina trokuta je " << h << endl;
}

void trece(){
	
	float a, b, c, s, tmp, h;
	float vrijeme;
	
	vrijeme_pocetak();
	do{
		cout << "A: ";
		cin >> a;
		cout << "B: ";
		cin >> b;
		cout << "C: ";
		cin >> c;
		
		s = (a+b+c)/2;
		tmp = s*(s-a)*(s-b)*(s-c);
		
	}while(tmp <= 0);
	cout << endl;
	vrijeme_kraj();
	vrijeme = vrijeme_proteklo()/1000;
	vrijeme = vrijeme*100;
	vrijeme = int(vrijeme);
	vrijeme = float(vrijeme)/100;
	cout << vrijeme << endl;
	h = sqrt(tmp);
	h = h*100;
	h = int(h);
	h = float(h)/100;
	cout << "Povrsina je " << h << endl;
}

void cetvrto(){
	float a, b, c, s, tmp, h;
	float vrijeme;
	
	do{
		cout << "A: ";
		cin >> a;
		vrijeme_pocetak();
		cout << "B: ";
		cin >> b;
		cout << "B: ";
		cin >> c;
		vrijeme_kraj();
		
		vrijeme = vrijeme_proteklo();
		
		cout << "Vrijeme proteklo: " << vrijeme << endl;
		
		s = (a+b+c)/2;
		
		tmp = s*(s-a)*(s-b)*(s-c);
	}while(tmp <=0 );
	
	h = sqrt(tmp);
	cout << "Povrsina je " << int(h) << endl;
}

void peto(){
	float a, b, c, tmp, h, s;
	float t1, t2, t3;
	
	do{
		cout << "A: ";
		vrijeme_pocetak();
		cin >> a;
		vrijeme_kraj();
		t1 = vrijeme_proteklo();
		cout << "B: ";
		vrijeme_pocetak();
		cin >> b;
		vrijeme_kraj();
		t2 = vrijeme_proteklo();
		cout << "C: ";
		vrijeme_pocetak();
		cin >> c;
		vrijeme_kraj();
		t3 = vrijeme_proteklo();

		cout << "t1: " <<t1 << " t2: " << t2 << " t3: " << t3 << endl;
		
		s = (a+b+c)/2;
		tmp = s*(s-a)*(s-b)*(s-c);
		
	}while(tmp <= 0);
	
	h = sqrt(tmp);	
	cout << "Povrsina trokuta je " << int(h) << endl;
}

void sesto(){
	
	float a, b, c, s, tmp, h;
	float vrijeme;
	
	vrijeme_pocetak();
	do{
		cout << "A: ";
		cin >> a;
		cout << "B: ";
		cin >> b;
		cout << "C: ";
		cin >> c;
		
		s = (a+b+c)/2;
		tmp = s*(s-a)*(s-b)*(s-c);
		
	}while(tmp <= 0);
	cout << endl;
	vrijeme_kraj();
	vrijeme = vrijeme_proteklo();
	cout << "Vrijeme je " <<vrijeme << endl;
	h = sqrt(tmp);
	cout << "Povrsina je " << int(h) << endl;
}

int main(){
	
	do{
		cout << endl;
		cout << "Izbornik: " << endl;
		cout << "1. Heron - svo vrijeme" << endl;
		cout << "2. Heron - posebno vrijeme" << endl;
		cout << "3. Heron - broji i kad je S negativan" << endl;
		cout << "4. Heron - svo vrijeme u tisucinkama" << endl;
		cout << "5. Heron - svako posebno u tisucinkama" << endl;
		cout << "6. Heron - broji i kad je S negativan u tisucinkama" << endl;
		cout << "0. Kraj" << endl;
		cout << "Izbor: ";
		cin >> izbor;
		cout << endl;
		switch(izbor){
			case 1:prvo(); break;
			case 2:drugo(); break;
			case 3:trece();break;
			case 4:cetvrto();break;
			case 5:peto();break;
			case 6:sesto();break;
	}
	}while(izbor != 0);
	
	return 0;
}
