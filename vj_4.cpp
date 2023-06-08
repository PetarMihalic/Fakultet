#include <iostream>
#include <fstream>
#include "biblioteka_vrijeme.cc"
 
using namespace std;
 
struct tpodaci {
    int sifra;
    char naziv[30];
    int br_kom;
    float vrijeme_unosa;
};
 
void unos(){
    fstream dat;
    tpodaci podaci;
    dat.open("datoteka.dat", ios::out | ios::app | ios::binary);
    vrijeme_pocetak();
    cout<<"Sifra predmeta: ";cin>>podaci.sifra;
    cout<<"Naziv predmeta: ";cin>>podaci.naziv;
    cout<<"Broj komada: ";cin>>podaci.br_kom;
    vrijeme_kraj();
    podaci.vrijeme_unosa=(int)vrijeme_proteklo()/10;
    dat.write((char*)&podaci, sizeof(podaci));
    dat.close();
}
 
void provjera(){
    fstream dat;
    tpodaci podaci;
    dat.open("datoteka.dat", ios::in | ios::binary);
    int sifra;
    bool postoji=false;
    cout<<"Sifra predmeta: ";cin>>sifra;
    while(true){
        dat.read((char*)&podaci, sizeof(podaci));
        if(dat.eof()) break;
        if(podaci.sifra==sifra) postoji=true;
    }
    dat.close();
    if(!postoji){
        dat.open("datoteka.dat", ios::out | ios::app | ios::binary);
        podaci.sifra=sifra;
        vrijeme_pocetak();
        cout<<"Naziv predmeta: ";cin>>podaci.naziv;
        cout<<"Broj komada: ";cin>>podaci.br_kom;
        vrijeme_kraj();
        podaci.vrijeme_unosa=(int)vrijeme_proteklo()/10;
        dat.write((char*)&podaci, sizeof(podaci));
        }
    if(postoji) cout<<"Element s unesenom sifrom vec postoji!"<<endl;
    dat.close();
}
 
void ispis(){
    fstream dat;
    tpodaci podaci;
    dat.open("datoteka.dat", ios::in | ios::binary);
    int brojac=0, suma=0;
    while(true){
        dat.read((char*)&podaci, sizeof(podaci));
        if(dat.eof()) break;
        cout<<"Sifra predmeta: "<<podaci.sifra<<endl;
        cout<<"Naziv predmeta: "<<podaci.naziv<<endl;
        cout<<"Broj komada: "<<podaci.br_kom<<endl;
        cout<<"Vrijeme unosa: "<<podaci.vrijeme_unosa<<endl;
        cout<<"---------------------------------------"<<endl;
        brojac++;
        suma=suma+podaci.sifra;
    }
    cout<<endl;
    cout<<"Ukupan broj elemenata: "<<brojac<<endl;
    cout<<"Zbroj svih sifri: "<<suma<<endl;
    dat.close();
}
 
void trazi(){
    fstream dat;
    tpodaci podaci;
    int trazi;
    cout<<"Unesite sifru trazenog predmeta: ";cin>>trazi;
    dat.open("datoteka.dat", ios::in | ios::binary);
    bool nadjen=false;
    while(true){
        dat.read((char*)&podaci, sizeof(podaci));
        if(dat.eof()) break;
        if(podaci.sifra==trazi){
            nadjen=true;
            cout<<"Naziv predmeta: "<<podaci.naziv<<endl;
            cout<<"Broj komada: "<<podaci.br_kom<<endl;
        }
    }
    if(!nadjen) cout<<"Element s trazenom sifrom ne postoji!"<<endl;
    dat.close();
}
 
int main(){
    fstream dat;
    dat.open("datoteka.dat", ios::trunc | ios::out | ios::binary);
    int odabir;
    do{
    cout<<"---------------------------------------"<<endl;
        cout<<"1. Unos u datoteku"<<endl;
        cout<<"2. Unos s provjerom"<<endl;
        cout<<"3. Ispis sadrzaja cijele datoteke"<<endl;
        cout<<"4. Pretrazivanje datoteke"<<endl;
        cout<<"9. Izlaz iz programa"<<endl;
        cout<<"---------------------------------------"<<endl;
        cout<<"Vas odabir? ";cin>>odabir;
        switch(odabir){
            case 1: unos();break;
            case 2: provjera();break;
            case 3: ispis();break;
            case 4: trazi();break;
            default: break;
        }
    }while(odabir!=9);
    return 0;
}
