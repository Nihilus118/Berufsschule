#include <iostream>
using namespace std;

int m,n,r;

int main() {
	cout << "Ertste Zahl eingeben: ";
	cin >> m;
	cout << "Zweite Zahl eingeben: ";
	cin >> n;
	
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
	
	return 0;
}
