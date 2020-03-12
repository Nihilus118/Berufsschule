#include <iostream>
#include <iomanip>
using namespace std;

int m,n;

int main() {
	for(m=1;m<=10;m++){
		for(n=1;n<=10;n++){
			cout << right << setw(4) << m*n;
		}
		cout << endl;
	}
	return 0;
}
