#include <iostream>
using namespace std;

int main() {
	int array [] = {2, 17, 10, 9, 16, 3, 9, 16, 5, 1, 17, 14}, durchDrei [(sizeof(array) / sizeof(int))], i, zaehler = 0;
	
	cout << "Groesse des Arrays: " << sizeof(array) / sizeof(int) << endl;
	
	for (i = 0; i < sizeof(array) / sizeof(int); i++){
		if (array[i] % 3 == 0){
			durchDrei[zaehler] = array[i];
			zaehler++;
		}
	}
	
	cout << zaehler << " Zahlen sind durch 3 teilbar. Diese sind:" << endl;
	for (i = 0; i < zaehler; i++){
		cout << durchDrei[i] << endl;
	}
	
	return 0;
}
