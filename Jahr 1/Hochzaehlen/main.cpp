#include <iostream>
using namespace std;

int i;

int main() {
	//For-Schleife
	cout << "For-Schleife: " << endl;
	for (i = 1; i<=10; i++){
		cout << i << endl;
	}
	
	//While-Schleife
	cout << endl << "While-Schleife: " << endl;
	i = 0;
	while(i<10){
		i++;
		cout << i << endl;
	}
	
	//Do-While-Schleife
	cout << endl << "Do-While-Schleife: " << endl;
	i = 0;
	do{
		i++;
		cout << i << endl;
	}
	
	while(i<10);
	
	return 0;
}
