#include <iostream>
using namespace std;

//Schaltjahresfunktion
bool schaltjahr(int j){
	if (j % 4 != 0){
		return false;
	}
	else{
		if (j % 100 != 0){
			return true;
		}
		else{
			if (j % 400 != 0){
				return false;
			}
			else{
				return true;
			}
		}
	}
}

int datumscheck(int tag, int monat, int jahr){
	//Jahr pruefen
	if(jahr < 1600){
		return 1;
	}
	
	//Monat pruefen und festlegen wie viele Tage dieser haben darf
	switch(monat){
		//Februar
		case 2:
			if (schaltjahr(jahr)){
				if(tag > 0 && tag < 30){
					cout << "Monat hat 29 tage" << endl;
					return 0;
				}
				else{
					return 3;
				}
			}
			else{
				if(tag > 0 && tag < 29){
					cout << "Monat hat 28 tage" << endl;
					return 0;
				}
				else{
					return 3;
				}
			}
			break;
		//Monate mit 31 tagen
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			if(tag > 31 || tag < 1){
				return 3;
			}
			else{
				return 0;
			}
			break;
		//Monate mit 30 tagen
		case 4: case 6: case 9: case 11:
			if(tag > 30 || tag < 1){
				return 3;
			}
			else{
				return 0;
			}
			break;
		//Monat existiert nicht
		default:
			return 2;
	}
}

//Funktionsdefinition Zeller fuer Wochentagsbestimmung
int wochentag(int tag, int monat, int jahr) {
	//Pruefne ob Januar oder Februar
    if (monat == 1 || monat == 2) {
        monat = monat + 12;
        jahr = jahr - 1;
    }
    
    //Ergebnis der Zelerfunktion zurueckgeben
    return(tag +((13*(monat + 1))/5)+jahr%100+((jahr%100)/4)+((((jahr/100))/4) + 5*(jahr/100)))%7;
}


string zahlZuTag(int tag){
	//Zahl von "int wochentag" zu String uebersetzen
	switch (tag){
		case 0:
			return "Samstag";
		case 1:
			return "Sonntag";
		case 2:
			return "Montag";
		case 3:
			return "Dienstag";
		case 4:
			return "Mittwoch";
		case 5:
			return "Donnerstag";
		case 6:
			return "Freitag";		
	}
}

string datumscheckRueckgabe(int rueckgabe){
	switch (rueckgabe){
		case 0:
			return "Datum ist ok";
		case 1:
			return "Jahr ist nicht ok";
		case 2:
			return "Monat ist nicht ok";
		case 3:
			return "Tag ist nicht ok";
		default:
			return "Unbekannter Wert";
	}
}

int main() {
	int tag, monat, jahr;
	cout << "Bitte Tag eingeben: ";
	cin >> tag;
	cout << "Bitte Monat eingeben: ";
	cin >> monat;
	cout << "Bitte Jahr eingeben: ";
	cin >> jahr;
	
	//Datum pruefen
	if (datumscheck(tag, monat, jahr) == 0){
		//Datum ist ok also Wochentag berechnen und ausgeben
		cout << endl << "Der " << tag << "." << monat << "." << jahr << " ist ein " << zahlZuTag(wochentag(tag, monat, jahr)) << endl;
	}
	else{
		//Datum falsch, also Fehlermeldung ausgeben
		cout << endl << datumscheckRueckgabe(datumscheck(tag, monat, jahr)) << endl;
	}
	
	return 0;
}
