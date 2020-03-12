#include <iostream>
#include <iomanip>
using namespace std;

double laenge,breite,flaeche,umfang;

int main() {
	cout << "Laenge: ";
	cin >> laenge;
	cout << endl << "Breite: ";
	cin >> breite;
	flaeche = laenge*breite;
	umfang = 2*(laenge+breite);
	
	cout << endl << left << fixed << setprecision(1) <<
	setw(9) << "Laenge" <<
	setw(9) << "Breite" <<
	setw(9) << "Umfang" <<
	setw(9) << "Flaeche" << endl <<
	setw(9) << laenge <<
	setw(9) << breite << setprecision(2) <<
	setw(9) << umfang <<
	setw(9) << flaeche << endl;
	return 0;
}
