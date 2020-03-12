#include <iostream>
using namespace std;

class Kfz{
	private:
		string hersteller;
		string fahrgestellnummer;
		int baujahr;
	public:
		Kfz();
		Kfz(string h, string f, int b);
		~Kfz();
		void eingabe();
		void ausgabe();
};
