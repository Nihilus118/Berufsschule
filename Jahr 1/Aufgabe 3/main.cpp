#include <iostream>
#include <cmath>
using namespace std;

int main(){
	double km_alt=0;
	double km_neu=0;
	double liter=0;
	double verbrauch=0;
	
	cout << "km_alt: : ";
	cin >> km_alt;
	
	cout << "km_neu: ";
	cin >> km_neu;
	
	cout << "Liter: ";
	cin >> liter;
	
	verbrauch=liter/(km_neu-km_alt)*100;
	verbrauch=round(verbrauch*100)/100;
	cout << "So viel verbraucht das Auto auf 100km: "<< verbrauch << endl;
	
	if (verbrauch<5){
		cout << "Guter Verbrauch" << endl;
	}
	if (verbrauch>5 && verbrauch<10){
		cout << "Normaler Verbrauch" << endl;
	}
	else {
		cout << "Werkstatt" << endl;
	}
	
	return 0;
}
