#include <iostream>
#include <iomanip>
#include <cstdlib>		// srand, rand
#include <ctime>
using namespace std;

int main(){
	
	//5 Reihen
	for (int i = 1; i <= 5; i++){
		//5 Zahlen pro Reihe
		for (int a = 0; a <= 5; a++){
			//Format ueberall identisch
			cout <<  left << setw(4);
			//Je nach Reihe verschiedene Zufallszahlen
			switch (i){
				case 1:
					cout << rand() % 15 + 1 << " ";
					break;
				case 2:
					cout << rand() % 30 + 16 << " ";
					break;
				case 3:
					cout << rand() % 45 + 31 << " ";
					break;
				case 4:
					cout << rand() % 50 + 46 << " ";
					break;
				case 5:
					cout << rand() % 75 + 51 << " ";
					break;
			}
		}
		//Neue Reihe anfangen
		cout << endl;
	}
	
	return 0;
}
