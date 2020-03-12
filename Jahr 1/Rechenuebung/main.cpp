#include <iostream>
using namespace std;

double zahl1,zahl2,ergebnis,eingabe;

int main() {
	cout << "Geb eine Zahl ein: ";
	cin >> zahl1;
	cout << endl << "Geb noch eine Zahl ein: ";
	cin >> zahl2;
	
	ergebnis = zahl1 * zahl2;
	
	cout << endl << "Geb das Ergebnis von Zahl1*Zahl2 ein: ";
	cin >> eingabe;
	
	if (ergebnis != eingabe){
		if (ergebnis < eingabe){
			cout << endl << "Eingabe war zu gross!";
		}
		else{
			cout << endl << "Eingabe war zu klein!";
		}
	}
	else{
		cout << endl << "Richtig!";
	}
	
	return 0;
}
