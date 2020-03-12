#include <iostream>
using namespace std;

void linie(int laenge){
	int i;
	
	for (i = 0; i < laenge; i++){
		cout << "-";
	}
	cout << endl;
}

void meldung (string text){
	cout << text << endl;
}

int main() {
	int laenge_linie = 40;
	
	meldung("Hallo! Das Programm startet in main().");
	linie(laenge_linie);
	meldung("In der Funktion meldung().");
	linie(laenge_linie);
	meldung("Jetzt das Ende von main().");	
	
	return 0;
}
