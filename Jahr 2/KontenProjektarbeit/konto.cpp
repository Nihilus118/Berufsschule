//BASISKLASSE KONTO

#pragma once  //um Mehrfachen Include zu verhindern
#include <iostream>

using namespace std;

class Konto {  //Basisklassendefinition
   private:
    string name;
    string vorname;
    long kontonr;
    double kontostand;

   public:
    Konto() {  //Konstruktor
        name = "Mustermann";
        vorname = "Max";
        kontonr = 0;
        kontostand = 0;
    }
    ~Konto() {  //Destruktor
        cout << "Objekt Konto geloescht." << endl;
    }
    //Setter
    void setName(string n) {
        name = n;
    }
    void setVorname(string n) {
        vorname = n;
    }
    void setKontonr(long n) {
        kontonr = n;
    }
    void setKontostand(double n) {
        kontostand = n;
    }
    //Getter
    string getName() {
        return name;
    }
    string getVorname() {
        return vorname;
    }
    long getKontonr() {
        return kontonr;
    }
    double getKontostand() {
        return kontostand;
    }
    void eingabe() {  //Eingabe
        cout << "Bitte Vornamen eingeben: ";
        cin >> vorname;
        cout << "Bitte Nachname eingeben: ";
        cin >> name;
        cout << "Bitte Kontonummer eingeben: ";
        cin >> kontonr;
        cout << "Bitte Kontostand eingeben: ";
        cin >> kontostand;
    }
    void ausgabe() {  //Ausgabe
        cout << "Kontoinhaber: " << vorname << " " << name << endl
             << "Kontonummer: " << kontonr << endl
             << "Kontostand: " << kontostand << " Euro" << endl;
    }

    void ueberweisen(Konto& zielk) {  //Das "&" hinter "Konto" sorgt für eine Referenzübergabe
        double betrag;
        cout << "Wie viel soll ueberwiesen werden?" << endl;

        cin >> betrag;
        if (betrag > 0) {  //Keine negativueberweisungen moeglich

            zielk.setKontostand(zielk.getKontostand() + betrag);

            kontostand = kontostand - betrag;

            cout << "Ueberweisung erfolgreich." << endl;

        } else {
            cout << "Der Betrag ist ungueltig." << endl
                 << endl;
        }
    }

    void zahlung() {
        char antw, antw2;
        double betrag;
        cout << "Wollen Sie eine Einzahlung(E) oder eine Auszahlung(A) auf das Konto " << kontonr << " vornehmen oder Nichts(N)?" << endl;
        cin >> antw;
        switch (antw) {
            case 'E':
                cout << "Wie viel soll Eingezahlt werden?" << endl;
                cin >> betrag;
                kontostand = kontostand + betrag;
                break;
            case 'A':
                cout << "Wie viel soll Ausgezahlt werden?" << endl;
                cin >> betrag;
                kontostand = kontostand - betrag;
                break;
            default:
                cout << "Keine Aenderung am Kontostand vorgenommen" << endl
                     << endl;
                break;
        }
    }
};
