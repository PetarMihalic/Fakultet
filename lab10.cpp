#include <iostream>
#include <cstring>
using namespace std;
class cpredmeti_zapis {
public: 
	int sifra;
	string predmet;
	string smjer;
	void unos_predmeta() {
 		cout << "Unesite sifru predmeta: "; cin >> sifra;
		cout << "Unesite naziv predmeta: "; cin >> predmet;
		cout << "Unesite smjer: "; cin >> smjer;
	};
	void ispis_predmeta() {
		cout << "-------------------------------------------" << endl;
		cout << "Sifra predmeta: " << sifra << endl;
		cout << "Naziv predmet: " << predmet << endl;
		cout << "Smjer: " << smjer << endl;
	};
};

class cpredmeti {
public: 
	cpredmeti *sljedeci;
	cpredmeti *prethodni;
	cpredmeti_zapis naziv;
	int mjesto;
	cpredmeti() {
		sljedeci=NULL;
		cout << "Konstruktor" << endl;
	}
	void unos(int mjesto) {
		cpredmeti *trenutni;
		cpredmeti *novi;
		trenutni=this;
		if (mjesto) { //1-kraj
			while (trenutni->sljedeci) 
				trenutni=trenutni->sljedeci;
			novi= new cpredmeti;
			trenutni->sljedeci=novi;
			novi->prethodni=trenutni;
		}
		else { //0-pocetak
			novi=new cpredmeti;
			sljedeci=trenutni->sljedeci;
			novi->prethodni=trenutni;
			novi->sljedeci=sljedeci;
			trenutni->sljedeci=novi;
			sljedeci->prethodni=novi;
		}
		novi->naziv.unos_predmeta();
	};
	void ispis() {
		cpredmeti *trenutni;
		trenutni=this;
		while (trenutni->sljedeci) {
			trenutni=trenutni->sljedeci;
			trenutni->naziv.ispis_predmeta();
			cout << "Pokazivac na sljedeci element: " << trenutni->sljedeci << endl;
			cout << "-------------------------------------------" << endl;
		}
	};
	void pretrazi_smjer (string smjer) {
		cpredmeti *trenutni;
		trenutni=this;
		while (trenutni->sljedeci) {
			trenutni=trenutni->sljedeci;
			if (trenutni->naziv.smjer==smjer) 
				cout << trenutni->naziv.predmet << endl;
		}
	};
	bool pretrazi_sifre (int sifra) {
		bool ima=false;
		cpredmeti *trenutni;
		trenutni=this;
		while (trenutni->sljedeci) {
			trenutni=trenutni->sljedeci;
			if (trenutni->naziv.sifra==sifra) {
				ima=true;
				break;
			}
		}
		return ima;
	}; 
};

cpredmeti *lista_predmeta;

class cprijave_zapis: public cpredmeti {
public:
	int sifra_prijave;
	int sifra_predmeta;
	int maticni_br;
	int rok;
	void unos() {
		cout << "Sifra prijave: "; cin >> sifra_prijave;
		do {
		cout << "Sifra predmeta: "; cin >> sifra_predmeta;
		} while (!(lista_predmeta->pretrazi_sifre(sifra_predmeta))&& cout << "Sifra predmeta ne postoji na listi predmeta!\n");
		cout << "Maticni broj: "; cin >> maticni_br;
		cout << "Rok prijave: "; cin >> rok;
	}
	void ispis(int sifra) {
		cout << "-------------------------------------------" << endl;
		cout << "Sifra prijave: " << sifra_prijave << endl;
		cout << "Sifra predmeta: " << sifra_predmeta << endl;
		cout << "Maticni broj: " << maticni_br << endl;
		cout << "Rok prijave: " << rok << endl;
		cpredmeti *trenutni=lista_predmeta;
		while (trenutni->sljedeci) {
			trenutni=trenutni->sljedeci;
			if (trenutni->naziv.sifra==sifra)  cout << "Prijava za predmet: " << trenutni->naziv.predmet << endl;
		}
	};
};

class cprijave: public cpredmeti {
private: 
	cprijave *sljedeci;
public: 
	cprijave_zapis *prijava;
	cprijave() {
		sljedeci=NULL;
		prijava=new cprijave_zapis;
		cout << "Konstruktor" << endl;
	}
	void unos() {
		cprijave *trenutni;
		cprijave *novi;
		trenutni=this;
		while (trenutni->sljedeci)
			trenutni=trenutni->sljedeci;
		novi=new cprijave;
		trenutni->sljedeci=novi;
		novi->prijava->unos();
	};	
	void ispis() {
		cprijave *trenutni;
		trenutni=this;
		while (trenutni->sljedeci) {
			trenutni=trenutni->sljedeci;
			trenutni->prijava->ispis(trenutni->prijava->sifra_predmeta);
		}
	};
	~cprijave() {
		delete prijava;
	};
};

int brojac; 

int status () {
	if (!lista_predmeta) {
		cout << "0 - glava liste predmeta nije alocirana." << endl;
		return 0;
	}
	else {
		if (brojac==0) {
			cout << "1 - Lista predmeta je prazna." << endl;
			return 1;
		}
		else {
			cout << "2 - Lista predmeta sadrzi " << brojac << " predmeta." << endl;
			return 2;
		}
	}	
}

int main () {
	int x;
	int state;
	cprijave *lista_prijava=NULL;
	int mjesto;
	string naziv;
	do {
	cout << "Izbornik:" << endl; 
	cout << "1. Alokacija glave liste predmeta/Upis predmeta na kraj liste predmeta i ispis liste" << endl;
	cout << "2. Popis predmeta zadanog smjera/Unos na pocetak liste predmeta" << endl;
	cout << "3. Unos u listu prijava/Ispis liste prijava za sve predmete" << endl;
	cout << "Izbor: ";
	cin >> x;
	
	switch (x) {
		case 1: 
			state=status();
			if (!state) lista_predmeta=new cpredmeti;
			else {
				cout << "Unesite predmet na kraj liste: " << endl;
				lista_predmeta->unos(1);
				brojac++;
				lista_predmeta->ispis();
			}
			break;
		case 2: 
			state=status();
			if (!state) break;
			cout << "Upisite naziv smjera: "; 
			cin >> naziv;
			cout << "Popis predmeta tog smjera: " << endl;
			lista_predmeta->pretrazi_smjer(naziv);
			cout << "Upisite novi predmet na pocetak liste: " << endl;
			lista_predmeta->unos(0);
			brojac++;
			lista_predmeta->ispis();
			break;
		case 3: 
			state=status();
			if (state!=2) cout << "Unos prijava nije moguc, nema upisanih predmeta!" << endl;
			if (state!=2) break;
			if (!lista_prijava) {
				lista_prijava=new cprijave;
				break;
			}
			cout << "Unesite novu prijavu: " << endl;
			lista_prijava->unos();
			lista_prijava->ispis();
			break;
	}
	} while (x!=9);
	system ("pause");
	return 0;
}
