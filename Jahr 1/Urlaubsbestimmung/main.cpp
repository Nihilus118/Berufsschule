#include <iostream>

using namespace std;

int alter,urlaub;
string behinderung;

int main() {
	cout << "Alter eingeben: ";
	cin >> alter;
	cout << endl << "Behinderung (ja/nein): ";
	cin >> behinderung;
	
	if (alter < 18){
		//jugendliche
		if (alter < 16){
			//<16
			urlaub = 30;
		}
		else if (alter <17){
			//16
			urlaub = 27;
		}
		else{
			//17
			urlaub = 25;
		}
	}
	else{
		//Erwachsen
		urlaub = 24;
	}
	if (behinderung == "ja"){
		urlaub = urlaub + 5;
	}
	cout << endl << "Dein Urlaub betraegt " << urlaub << " Tage" << endl;
	
	return 0;
}
