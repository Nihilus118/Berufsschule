#include <iostream>
using namespace std;

bool schaltjahr(int j) {
    if (j % 4 != 0) {
        return false;
    } else {
        if (j % 100 != 0) {
            return true;
        } else {
            if (j % 400 != 0) {
                return false;
            } else {
                return true;
            }
        }
    }
}

int main() {
    int jahr;

    cout << "Bitte zu pruefendes Jahr eingeben: ";
    cin >> jahr;
    cout << endl;

    if (schaltjahr(jahr)) {
        cout << "Bei " << jahr << " handelt es sich um ein Schaltjahr." << endl;
    } else {
        cout << "Bei " << jahr << " handelt es sich um kein Schaltjahr." << endl;
    }

    return 0;
}
