#include <iostream>
#include <iomanip>
using namespace std;

//Aufgabe 1
class Spritverbrauch{
	private:
		double kmAlt;
		double kmNeu;
		double lVerbr;
	public:
		Spritverbrauch();
		~Spritverbrauch();
		void eingabe();
		void ausgabe();
		double verbrauchDurchs();
};

Spritverbrauch::Spritverbrauch(){
	kmAlt = 0;
	kmNeu = 0;
	lVerbr = 0;
}

void Spritverbrauch::eingabe(){
	cout << "Alten Kilometerstand eingeben: ";
	cin >> kmAlt;
	cout << "Neuen Kilometerstand eingeben: ";
	cin >> kmNeu;
	cout << "Verbrauch (in Liter): ";
	cin >> lVerbr;
	cout << endl;
}

void Spritverbrauch::ausgabe(){
	cout <<
	"Alter KM-Stand: " << kmAlt << endl <<
	"Neuer KM-Stand: " << kmNeu << endl <<
	"Verbrauch (in Liter): " << lVerbr << endl <<
	"Verbrauch im Schnitt: " << verbrauchDurchs() << endl;
}

double Spritverbrauch::verbrauchDurchs(){
	return (lVerbr/(kmNeu - kmAlt)) * 100.00;
}

Spritverbrauch::~Spritverbrauch(){
	cout << endl << "Objekt geloescht" << endl;
}

//Aufgabe 2
class Bussgeld{
	private:
		double tempLimit;
		double tempGefahren;
	public:
		Bussgeld();
		~Bussgeld();
		void eingabe();
		void ausgabe();
		double strafe();	
};

Bussgeld::Bussgeld(){
	tempLimit = 0;
	tempGefahren = 0;
}

void Bussgeld::eingabe(){
	cout << "Bitte Tempolimit eingeben: ";
	cin >> tempLimit;
	cout << "Bitte gefahrene Geschwindigkeit eingeben: ";
	cin >> tempGefahren;
	cout << endl;
}

void Bussgeld::ausgabe(){
	cout << fixed << setprecision(2) << 
	"Tempolimit: " << tempLimit << endl <<
	"Tempo gefahren: " << tempGefahren << endl <<
	"Strafe: " << strafe() << " Euro" << endl;
}

double Bussgeld::strafe(){
	double zuSchnell = tempGefahren - tempLimit;
	if(zuSchnell > 0){
		if(zuSchnell <= 10){
			return 10.0;
		}
		else if(zuSchnell <= 20){
			return 30.0;
		}
		else if(zuSchnell <= 30){
			return 80.0;
		}
		else if(zuSchnell > 30){
			return 600.0;
		}
	} else {
		return 0.00;
	}
}

Bussgeld::~Bussgeld(){
	cout << endl << "Objekt geloescht" << endl;
}

int main() {
	//Aufgabe 1
	Spritverbrauch sVerb;
	
	sVerb.eingabe();
	sVerb.ausgabe();
	
	//Aufgabe 2
	Bussgeld bg;
	
	bg.eingabe();
	bg.ausgabe();
	
	return 0;
}
