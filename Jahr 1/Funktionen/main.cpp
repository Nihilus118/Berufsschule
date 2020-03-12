#include <iostream>
using namespace std;

double durchschnitt (int z1, int z2, int z3){ 
	return (z1 + z2 + z3) / 3.0;
}

int main() {
	int z1, z2, z3;
	cout << "Bitte die erste Zahl eingeben: ";
	cin >> z1;
	cout << "Bitte die zweite Zahl eingeben: ";
	cin >> z2;
	cout << "Bitte die dritte Zahl eingeben: ";
	cin >> z3;
	
	cout << endl << "Der Durchschnitt der drei Zahlen betraegt: " << durchschnitt(z1, z2, z3) << endl;
		
	return 0;
}
