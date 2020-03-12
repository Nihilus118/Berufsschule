#include <iostream> //Konsolen In-/Output
#include <string> //Stringverarbeitung
#include <iomanip> //Konsolenmanipulation
using namespace std;

int main() {
	//Variablen
	string artikelnummer;
	int stueckzahl;
	double stueckpreis;
	double gesamtpreis;
	//Einlesen ueber Tastatur
	cout << "Artikelnummer: ";
	cin >> artikelnummer;
	
	cout << "Stueckzahl: ";
	cin >> stueckzahl;
	
	cout << "Stueckpreis: ";
	cin >> stueckpreis;
	
	gesamtpreis=stueckzahl*stueckpreis;
	
	system("cls"); //Loeschen der aktuellen Ausgabe
	
	cout << left << setw(20) << "Artikelnummer: "
		 << setw(20) << "Stueckzahl: "
		 << setw(20) << "Stueckpreis: " 
		 << setw(20) << "Gesamtpreis: " << endl
		 << setw(20) << artikelnummer
		 << setw(20) << stueckzahl
		 << setw(20) << fixed << setprecision(2) << stueckpreis
		 << setw(20) << fixed << setprecision(2) << gesamtpreis << endl;
	return 0;
}
