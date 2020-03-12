#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>
#include <windows.h>

using namespace std;

//Funktionen
void tippen();
void ausgabe_tippzahlen();
void zahlen_ziehen();
void lottozahlen_ausgeben();
void auswerten();
void lottozahlen_sortieren();

//Variablen
int anzahl, tippfeld[10][6], lotto[6];

int main() {
	tippen();
	zahlen_ziehen();
	ausgabe_tippzahlen();
	lottozahlen_ausgeben();
	auswerten();
	
	return 0;
}

void tippen(){
	int u,v;
	
	cout << "Wie oft wollen sie tippen? ";
	cin >> anzahl;
	 
	for(u=0;u<anzahl;u++){
		cout << endl << u+1 << ". Tipp: " << endl;
		for(v=0;v<6;v++){
			cout << "Zahl " << v+1 << " eingeben: ";
			cin >> tippfeld[u][v];
		}
	}
}

void ausgabe_tippzahlen(){
	int u,v;
	for(u=0;u<anzahl;u++){
		cout << endl << u+1 << ". Tipp: ";
		for(v=0;v<6;v++){
			cout << setw(3) << tippfeld[u][v];
		}
	}
}

void zahlen_ziehen(){
	int maske[50];
	
	time_t sec;
	time(&sec);
	srand(sec);
	
	for(int x=0;x<6;x++){
		lotto[x] = 1+(rand()%49);
		
		if (maske[lotto[x]] == 1){
			x--;
		}
		else{
			maske[lotto[x]] = 1;	
		}		
	}
}

void lottozahlen_ausgeben(){
	cout << endl << "Die Lottozahlen: ";
	for(int x=0; x<6; x++){
		Sleep(2000); //2 Sekunden warten
		cout << lotto[x] << " ";
		Beep(rand()+500,500);
	}
	cout << endl;
}

void auswerten(){
	int korrekt; //Anzahl korrekt getippter Zahlen
	
	for (int x = 0; x < anzahl; x++){
		korrekt = 0;
		for (int i = 0; i < 6; i++){
			for (int z = 0; z < 6; z++){
				if(tippfeld[x][i] == lotto[z]){
					korrekt++;
				}
			}
		}
		cout << "Tipp " << x+1 << ": "	<< korrekt << " Zahlen sind korrekt!" << endl;
	}
}

void lottozahlen_sortieren(){
	bool sortiert;
	
	do{
		sortiert = false; //Solange noch sortiert wurde wird nicht abgebrochen
		for(int i = 0; i < anzahl; i++){
		for(int x = 0; x < 6; x++){
			if(tippfeld[i][x] > tippfeld[i][x + 1]){
				int tauschvariable = tippfeld[i][x];
				tippfeld[i][x] = tippfeld[i][x + 1];
				tippfeld[i][x + 1] = tauschvariable;
				sortiert = true;
				}
			}
		}
	}while(!sortiert);
}
