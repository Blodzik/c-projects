#include <iostream>
#include<random>
#include<cmath>

using namespace std;

int main()
{
    double a, b, c;

    cout << "Enter a: ";
    cin >> a;

    cout << "Enter b: ";
    cin >> b;

    cout << "Enter c: ";
    cin >> c;

    if (a == 0) {
        if (b == 0) {
            cout << "Nie ma miejsc zerowych" << endl;
        }
        else {
            cout << "Rownanie liniowe: " << -c / b << endl;
        }
    }
    else {
        double x1, x2;
        double delta = pow(b, 2) - 4 * a * c;
        cout << "Delta: " << delta << endl;
        if (delta < 0) {
            cout << "Nie ma miejsc zerowych" << endl;
        }
        else if (delta == 0) {
            cout << "Istnieje jedno miejsce zerowe: " << -b / 2 * a;
        }
        else {
            x1 = (-b - delta) / 2 * a;
            x2 = (-b + delta) / 2 * a;
            cout << "Istnieja dwa miejsca zerowe: " << "x1: " << x1 << "; x2: " << x2 << endl;
        }
    }
}

