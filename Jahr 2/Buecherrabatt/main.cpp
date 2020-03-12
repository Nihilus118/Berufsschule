#include <iostream>
#include <iomanip>
using namespace std;

//OOP (Aufgabe b)
class Buchbestellung{
	private:
		int anzahl;
		double einzelpreis;
	public:
		Buchbestellung();
		void eingabe();
		void ausgabe();
		double bestellpreis();
};

Buchbestellung::Buchbestellung(){
	anzahl = 0;
	einzelpreis = 0.0;
}

void Buchbestellung::eingabe(){
	cout << "Anzahl eingeben: ";
	cin >> anzahl;
	cout << "Einzelpreis eingeben: ";
	cin >> einzelpreis;
}

void Buchbestellung::ausgabe(){
	cout << fixed << setprecision(2) << 
	"Anzahl: " << anzahl << endl <<
	"Einzelpreis: " << einzelpreis << " Euro" << endl <<
	"Bestellpreis: " << bestellpreis() << " Euro" <<endl; 
}

double Buchbestellung::bestellpreis(){
	double preis = anzahl * einzelpreis;
	if(anzahl > 99) {
		return preis * 0.9;
	} else if (anzahl > 25) {
		return preis * 0.92;
	} else {
		return preis;
	}
}

int main() {
	
	//Objekt erzeugen -> Konstruktor wird aufgerufen
	Buchbestellung bb;
	
	//bb.eingabe();
	bb.ausgabe();
	
	return 0;
}
