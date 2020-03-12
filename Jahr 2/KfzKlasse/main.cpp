#include ".\KfzKlasse.h"

int main() {
	Kfz k1("BMW", "12345", 2015);
	Kfz k2("Audi","13579", 2011);
	Kfz k3("VW","24579", 2017);
	
	k1.ausgabe();
	k2.ausgabe();
	k3.ausgabe();
	
	return 0;
}
