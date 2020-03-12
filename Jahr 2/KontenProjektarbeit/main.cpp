#include <iostream>
//Laden der Klassen
#include ".\girokonto.cpp"
#include ".\sparkonto.cpp"

using namespace std;

int main() {
    //Objekte erstellen
    //Konto konto1;
    Sparkonto spar1;
    Girokonto giro1;

    spar1.eingabe();
    giro1.eingabe();
    cout << endl;
    spar1.zinsberechnung();
    spar1.zahlung();
    spar1.ueberweisen(giro1);
    spar1.ausgabe();
    giro1.zinsberechnung();
    giro1.zahlung();
    giro1.ueberweisen(spar1);
    giro1.ausgabe();

    return 0;
}
