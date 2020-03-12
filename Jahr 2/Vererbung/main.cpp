#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Kfz { //Klasse Kfz
	private:
		int nummer;
		string hersteller;
	public:
		Kfz(){
			nummer = 0;
			hersteller = "";
		}
		~Kfz(){
			cout << "Objekt von KFZ geloescht" << endl;
		}
		void setNr(int n){
			nummer = n;
		}
		int getNr(){
			return nummer;
		}
		void setHers(string n){
			hersteller = n;
		}
		string getHers(){
			return hersteller;
		}
		void display(){
			cout << "Hersteller: " << hersteller << endl << "Nummer: " << nummer << endl;
		}
};

class Pkw: public Kfz { //Pkw erbt von Kfz
	private:
		string Pkwtyp;
		bool schiebedach;
	public:
		Pkw(){
			Pkwtyp = "";
			schiebedach = false;
		}
		~Pkw(){
			cout << "Objekt von PKW geloescht" << endl;
		}
		void setPkwtyp(string n){
			Pkwtyp = n;
		}
		string getPkwtyp(){
			return Pkwtyp;
		}
		void setSchiebedach(bool n){
			schiebedach = n;
		}
		bool getSchiebedach(){
			return schiebedach;
		}
		void display(){ //Ueberschreibt Funktion display von Kfz
			Kfz::display();
			cout << "Pkwtyp: " << Pkwtyp << endl << "Schiebedach: " << schiebedach << endl;
		}
};

int main() {
	Kfz test;
	
	test.setHers("Mercedes");
	test.setNr(4321);
	test.display(); //Display von Kfz
	
	cout << endl << endl;
	
	Pkw bmw;
	
	bmw.setHers("BMW");
	bmw.setNr(1234);
	bmw.setPkwtyp("5er");
	bmw.setSchiebedach(false);
	bmw.display(); //Display von Pkw

	return 0;
}
