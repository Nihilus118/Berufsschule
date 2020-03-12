#include <iostream>

using namespace std;

int jahr;

int main() {
	cout << "Jahr eingeben: ";
	cin >> jahr;
	cout << endl;
	
	if (jahr%4 == 0){
		if (jahr%100 == 0){
			if (jahr%400 == 0){
				cout << "Schaltjahr";
			}
			else{
				cout << "Kein Schaltjahr";
			}
		}
		else{
			cout << "Schaltjahr";
		}
	}
	else{
		cout << "Kein Schaltjahr.";
	}
	cout << endl;
	
	return 0;
}
