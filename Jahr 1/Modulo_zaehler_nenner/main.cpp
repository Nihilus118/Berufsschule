#include <iostream>
using namespace std;

int zaehler,nenner,rest;

int main() {
	cout << "Zaehler: ";
	cin >> zaehler;
	cout << endl << "Nenner: ";
	cin >> nenner;
	rest=zaehler%nenner;
	
	if (rest!=0){
		cout << endl << "Rest: " << rest << endl;
	}
	
	return 0;
}
