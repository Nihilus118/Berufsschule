#pragma once
#include <iostream>
#include ".\konto.cpp"  //Basisklasse laden

using namespace std;

class Sparkonto : public Konto {  //Vererbung von Basisklasse
   private:
    float habenzins;

   public:
    Sparkonto() {
        habenzins = 0;
    }
    ~Sparkonto() {
        cout << "Objekt Sparkonto geloescht." << endl;
    }
    void setHabenzins(float n) {
        habenzins = n;
    }
    float getHabenzins() {
        return habenzins;
    }
    void eingabe() {
        cout << "Ihr Sparkonto" << endl
             << endl;
        Konto::eingabe();
        cout << "Bitte Habenzins eingeben: ";
        cin >> habenzins;
        cout << endl;
    }
    void ausgabe() {
        cout << "Ihr Sparkonto" << endl
             << endl;
        Konto::ausgabe();
        cout << "Habenzins: " << habenzins << " %" << endl
             << endl;
    }
    //Berechnung der Habenzinsen
    void zinsberechnung() {
        if (getKontostand() > 0) {  //Nur berechnen wenn Kontostand im positiven ist
            setKontostand((getKontostand() / 100) * habenzins + getKontostand());
        } else {
            cout << "Berechnung fuer " << getKontonr() << " nicht moeglich, Kontostand muss positiv sein." << endl;
        }
    }
};
