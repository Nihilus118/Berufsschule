#include <iostream>
#include <iomanip>
using namespace std;

double laenge,breite,flaeche;
const float pi = 3.141593;

int main() {
	cout << "Laenge: ";
	cin >> laenge;
	cout << endl << "Breite: ";
	cin >> breite;
	flaeche = (laenge*laenge)/(4*pi);
	
	cout << left << setw(16) << endl << "Laenge"
	<< setw(16) << "Breite"
	<< setw(16) << "Stempelflaeche"
	<< setw(16) << "Volumen" << endl
	<< setw(16) << laenge
	<< setw(16) << breite
	<< setw(16) << flaeche
	<< setw(16) << flaeche*breite << endl;
	return 0;
}
