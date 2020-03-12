#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

class Kreis{
	private:
		//Geschuetze Eigenschaften
		double radius;
	public:
		//Oeffentliche Methoden (Datenkapselung)
		double umfang();
		double flaeche();
		void eingabe();
		void ausgabe();
};

void Kreis::eingabe(){
	cout << "Kreisradius eingeben: ";
	cin >> radius;
}

double Kreis::umfang(){
	return (2 * M_PI * radius);
}

double Kreis::flaeche(){
	return (M_PI * radius * radius);
}

void Kreis::ausgabe(){
	cout << fixed << setprecision(2) <<
	"Radius: " << radius << endl <<
	"Flaeche: " << flaeche() << endl <<
	"Umfang: " << umfang() << endl;
}

int main() {
	
	Kreis k; //Objekt (Instanz)
	
	k.eingabe();
	k.ausgabe();
	
	return 0;
}
