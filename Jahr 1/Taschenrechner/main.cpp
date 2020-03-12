#include <iostream>
using namespace std;

int main() {
	int wahl,m,n,r;
	double zahl1,zahl2;

	cout << "Bitte geben sie die erste Zahl ein: ";
	cin >> zahl1;
	cout << endl << "Bitte geben sie noch eine Zahl ein: ";
	cin >> zahl2;
	cout << endl << "Wahlen sie die Rechenart.\n+ = 1; - = 2; * = 3; / = 4; ggT = 5" << endl;
	cin >> wahl;
	cout << endl;
	
	switch(wahl){
		case 1: 
			cout << zahl1 << " + " << zahl2 << " = " << zahl1+zahl2 << endl;
			break;
		case 2: 
			cout << zahl1 << " - " << zahl2 << " = " << zahl1-zahl2 << endl;
			break;
		case 3: 
			cout << zahl1 << " * " << zahl2 << " = " << zahl1*zahl2 << endl;
			break;
		case 4: 
			if (zahl2 != 0){
				cout << zahl1 << " / " << zahl2 << " = " << zahl1/zahl2 << endl;
			}
			else{
				cout << "Man kann nicht durch 0 teilen!" << endl;
			}
			break;
		case 5:
			m = zahl1;
			n = zahl2;
			do{
				r = m % n;
				if(r == 0){
					cout << "Ergebnis: " << n << endl;
				}
				else{
					m = n;
					n = r;
				}
			}
			while(r != 0);
			break;
		default:
			cout << "Bitte ein gueltige Rechenart waehlen!" << endl;
			break;
	}
	return 0;
}
