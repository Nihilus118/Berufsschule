//KLASSE GIROKONTO

#pragma once
#include <iostream>
#include ".\konto.cpp"  //Basisklasse laden

using namespace std;

class Girokonto : public Konto {  //Vererbung von Basisklasse
   private:
    float sollzins;

   public:
    Girokonto() {
        sollzins = 0;
    }
    ~Girokonto() {
        cout << "Objekt Girokonto geloescht." << endl;
    }
    void setSollzins(float n) {
        sollzins = n;
    }
    float getSollzins() {
        return sollzins;
    }
    void eingabe() {
        cout << "Ihr Girokonto" << endl
             << endl;
        Konto::eingabe();
        cout << "Bitte Sollzins eingeben: ";
        cin >> sollzins;
    }
    void ausgabe() {
        cout << "Ihr Girokonto" << endl
             << endl
             << "Sollzins: " << sollzins << " %" << endl;
        Konto::ausgabe();
    }
    //Berechnung der Sollzinsen
    void zinsberechnung() {
        if (getKontostand() < 0) {  //Nur berechnen wenn Kontostand im negativen ist
            setKontostand((getKontostand() / 100) * sollzins + getKontostand());

        } else {
            cout << "Sollzinsen fuer " << getKontonr() << " nicht berechnet, Kontostand muss negativ sein." << endl;
        }
    }
};
