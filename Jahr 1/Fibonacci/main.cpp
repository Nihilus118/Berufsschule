#include <iostream>
using namespace std;

int main() {
	
	int Fibonacci [] = {0, 1}, grenze;
	
	cout << "Wie weit soll die Fibonacci-Reihe gehen? Bitte Stopwert eingeben: ";
	cin >> grenze;
	cout << endl;
	
	do{
		cout << Fibonacci [0] << " + " << Fibonacci [1] << " = " << Fibonacci [0] + Fibonacci [1] << endl;
		int tauschVariable = Fibonacci [1];
		Fibonacci [1] = Fibonacci [0] + Fibonacci [1];
		Fibonacci [0] = tauschVariable;
	} while (Fibonacci[1] < grenze);
	
	return 0;
}
