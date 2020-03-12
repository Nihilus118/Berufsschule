#include "Artikel.h"
#include <iostream>
#include <iomanip>

using namespace std;

Artikel::Artikel(){
	bezeichnung = "Artikel";
	nummer = 0;
	verkaufspreis = 0.0;
	menge = 0;
}

Artikel::~Artikel(){
	cout << endl << "Objekt zerstoert" << endl;
}

void Artikel::eingabe(){
	cout << "Bitte Artikelbezeichnung eingeben: ";
	cin >> bezeichnung;
	cout << "Bitte Artikelnummer eingeben: ";
	cin >> nummer;
	cout << "Bitte Preis angeben: ";
	cin >> verkaufspreis;
	cout << "Bitte Menge eingeben: ";
	cin >> menge;
	cout << endl;
}

void Artikel::ausgabe(){
	cout << fixed << setprecision(2) <<
	"Bezeichnung: " << bezeichnung << endl <<
	"Artikelnummer: " << nummer << endl <<
	"Preis: " << verkaufspreis << endl <<
	"Menge: " << menge << endl <<
	"Lagerwert: " << lagerwertberechnung() << " Euro" << endl << endl;
}

long double Artikel::lagerwertberechnung(){
	return menge * verkaufspreis;
}

