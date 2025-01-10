#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Produkt {
    int id;
    string nazwa;
    float cena;
};

int main() {
    Produkt p1{41, "p41", 44.49};
    Produkt p2{51, "p51", 5.99};

    ofstream plik("produkty.txt");
    plik << p1.id << " " << p1.nazwa << " " << p1.cena << endl;
    plik << p2.id << " " << p2.nazwa << " " << p1.cena << endl;
    plik.close();

    Produkt produkty[2];
    ifstream otworz("produkty.txt");

    for (int i = 0; i < 2; i++) {
        otworz >> produkty[i].id >> produkty[i].nazwa >> produkty[i].cena;
    }
    otworz.close();

    for (int i = 0; i < 2; i++) {
        cout << "Produkt: " << i + 1 << produkty[i].id << " " << produkty[i].nazwa << " " << produkty[i].cena << endl;

    }

    return 0;
}