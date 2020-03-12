#include <iostream>
using namespace std;

int add(int z1, int z2){
	return z1 + z2;
}

bool geradeZ(int zahl){
	return (zahl % 2 == 0);
}

double durchSch(int z1, int z2, int z3){
	return ((z1 + z2 + z3) / 3.0);
}

int max(int z1, int z2){
	if (z1 > z2){
		return z1;
	} else {
		return z2;
	}
}

int main() {
	int i, zahl, erg = 0, maxZahl = 0;
	cout << endl << "Aufgabe 1" << endl << endl; //1
	cout << add(2,3) << endl;
	
	cout << endl << "Aufgabe 2" << endl << endl; //2
	cout << add(add(2,3),3) << endl;
	
	cout << endl << "Aufgabe 3" << endl << endl; //3
	cout << "Wie oft soll addiert werden? ";
	cin >> i;
	for (int z = 0; z < i; z++){
		cout << "Zahl eingeben: ";
		cin >> zahl;
		erg = add(erg, zahl);
	}
	cout << erg << endl;
	
	cout << endl << "Aufgabe 4" << endl << endl; //4
	if(geradeZ(erg)){
		cout << "Ergebnis ist eine ganze Zahl." << endl;
	} else {
		cout << "Ergebnis ist keine ganze Zahl." << endl;
	}
	
	cout << endl << "Aufgabe 5" << endl << endl; //5
	cout << durchSch(2,5,7) << endl;
	
	cout << endl << "Aufgabe 6" << endl << endl; //6
	cout << "Wie viele Zahlen wollen sie vergleichen? ";
	cin >> i;
	for (int z = 0; z < i; z++){
		cout << "Zahl eingeben: ";
		cin >> zahl;
		maxZahl = max(zahl, maxZahl);
	}
	cout << "Groesste Zahl ist " << maxZahl << endl;
	
	return 0;
}
