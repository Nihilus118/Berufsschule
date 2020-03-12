#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int zapfs;
	string kraftstoff;
	double preis,liter,rechnung;
	
	cout << "Zapfsaeule waehlen (1-4)): ";
	cin >> zapfs;
	cout << endl << "Wie viel wurde getankt: ";
	cin >> liter;
	
	switch(zapfs){
		case 1:
			kraftstoff = "Benzin";
			preis = 1.399;
			break;
		case 2:
			kraftstoff = "Super";
			preis = 1.429;
			break;
		case 3:
			kraftstoff = "SuperPlus";
			preis = 1.509;
			break;
		case 4:
			kraftstoff = "Diesel";
			preis = 1.209;
			break;
		default:
			cout << "Bitte eine gueltige Zapfsaeule angeben!" << endl;
			break;
	}
	rechnung = liter * preis;
	cout << endl << "Sie haben " << kraftstoff << " getankt.\nGesamtpreis: " <<
	fixed << setprecision(2) << rechnung << " Euro" << endl;
	return 0;
}
