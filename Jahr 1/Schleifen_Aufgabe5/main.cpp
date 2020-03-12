#include <iostream>

using namespace std;

int main() {
	int i,x = -1,k=0;
	
	for(i=1;k<=4;i=i+x){
		if(i==10 || i==1){
			x = -x;
			k++;
		}
		cout << i <<" ";
	}
	
	return 0;
}
