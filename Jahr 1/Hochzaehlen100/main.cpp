#include <iostream>
using namespace std;

int i,a;

int main() {
	//1
	cout << "Aufgabe 1:" << endl << endl;
	for(i=1;i<=100;i++){
		cout << i;
		if(i<100){
			cout << ", ";
		}
	}
	
	//2
	cout << endl << endl << "Aufgabe 2:" << endl;
	cout << endl << "Bitte eine positive Zahl eingeben: ";
	cin >> i;
	
	while(i != 0){
		i--;
		cout << i;
		if (i!=0){
			cout << ", ";
		}
	}
	cout << endl;
	
	//3
	cout << endl << "Aufgabe 3:" << endl << endl;
	a = 1;
	for(i=1;i<20;i++){
		if(i<10){
			cout << a << endl;
			a++;
		}
		else{
			cout << a << endl;
			a--;
		}
	}
	
	//4/6
	cout << endl << "Aufgabe 4/6:" << endl << endl;
	cout << "Bitte Startwert eingeben: ";
	cin >> i;
	cout << "Bitte Stopwert eingeben: ";
	cin >> a;
	
	while(i!=a){
		cout << i << ", ";		
		if(i<a){
			i++;
		}
		else{
			i--;
		}
	}
	cout << i << endl;
	
	//5
	cout << endl << "Aufgabe 5:" << endl;
	a = 0;
	for(int i=0;i<37;i++){
		if(i>=10 && i<19 || i>27){
			a--;
		}
		else{
			a++;
		}
		cout << a << " ";
	}
	
	//7
	cout << endl << endl << "Aufgabe 7:" << endl;
	cout << endl << "Bitte Startwert eingeben: ";
	cin >> i;
	cout << "Bitte Stopwert eingeben: ";
	cin >> a;
	
	do{
		if(i==a){
			break;
		}
		cout << i << ", ";
		if(i<a){
			i++;
		}
		else{
			i--;
		}
	}
	while(i!=a);
	cout << i << endl;
	
	return 0;
}
