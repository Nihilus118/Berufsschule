#include <iostream>
#include <iomanip>
using namespace std;

double dm_euro(double mark){
	return mark * 0.51;
}

double dm_dollar(double mark){
	return mark * 0.58;
}

int main() {
	double mark;
	
	cout << "Bitte die menge DM eingeben: ";
	cin >> mark;
	
	cout << fixed << setprecision(2) << endl << mark << " Mark sind " << dm_euro(mark) << " Euro und " << dm_dollar(mark) << " Dollar." << endl;	
	
	return 0;
}
