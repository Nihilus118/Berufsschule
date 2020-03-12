#include <iostream>
#include <iomanip>
using namespace std;

int anzahl;
double preis = 36.80,rechnung;

int main() {
	cout << "Anzahl: ";
	cin >> anzahl;
	rechnung=preis*anzahl;
	if (anzahl>=100){
		rechnung=rechnung*0.9;
	}
	cout << endl << fixed << setprecision(2) << rechnung << " Euro" << endl;
	
	return 0;
}
