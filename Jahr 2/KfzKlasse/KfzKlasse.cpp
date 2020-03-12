#include "KfzKlasse.h"

Kfz::Kfz(){
	hersteller = "";
	fahrgestellnummer = "";
	baujahr = 0;
}

Kfz::Kfz(string h, string f, int b){
	hersteller = h;
	fahrgestellnummer = f;
	baujahr = b;
	
}

void Kfz::eingabe(){
	cout << "Hersteller eingeben: ";
	cin >> hersteller;
	cout << "Fahrgestellnummer eingeben: ";
	cin >> fahrgestellnummer;
	cout << "Baujahr eingeben: ";
	cin >> baujahr;
	cout << endl;
}

void Kfz::ausgabe(){
	cout <<
	"Hersteller: " << hersteller << endl <<
	"Fahrgestellnummer: " << fahrgestellnummer << endl <<
	"Baujahr: " << baujahr << endl << endl;
}

Kfz::~Kfz(){
	cout << endl << "Abbau des Objekts vom Typ Kfz (" << hersteller << ")" << endl;
}
