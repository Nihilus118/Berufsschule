#include <iostream>
using namespace std;

class Bankkonto{ //Klassendefinition
	private:
		string name;
		string kontonummer;
		double kontostand;
	public:
		void eingabe();
		void ausgabe();
		void betrag_aendern();
		double betrag_ausgeben();
};

//Methodendefinition
void Bankkonto::eingabe(){
	cout << "Bitte Name eingeben: ";
	getline(cin, name);
	cout << "Bitte Kontonummer eingeben: ";
	cin >> kontonummer;
	cout << "Bitte Kontostand eingeben: ";
	cin >> kontostand;
}

void Bankkonto::ausgabe(){
	cout << "Name: " << name << endl <<
	"Kontonummer: " << kontonummer << endl <<
	"Kontostand: " << kontostand << endl;
}

void Bankkonto::betrag_aendern(){
	double betrag;
	cout << "Um wie viel soll sich der Kontostand veraendern? ";
	cin >> betrag;
	
	kontostand += betrag;
}

double Bankkonto::betrag_ausgeben(){
	return kontostand;
}

int main() {
	
	Bankkonto bk;
	
	bk.kontostand = 5000;
	
	return 0;
}
