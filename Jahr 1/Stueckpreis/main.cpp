#include <iostream>
#include <iomanip>
using namespace std;

int anzahl;
double stueckpreis,gesamtpreis;

int main() {
	cout << "Stueckpreis: ";
	cin >> stueckpreis;
	cout << endl << "Anzahl: ";
	cin >> anzahl;
	gesamtpreis = anzahl * stueckpreis;
	
	cout << endl << fixed << setprecision(2) <<
	setw(15) << "Stueckpreis" <<
	setw(15) << "Anzahl" <<
	setw(15) << "Gesamtpreis" << endl <<
	setw(15) << stueckpreis <<
	setw(15) << anzahl <<
	setw(15) << gesamtpreis << endl;
	return 0;
}
