// #include <iostream>
// #include <string>
// #include <fstream>
//
// using namespace std;
//
// struct S {
//     float polWartosc;
//     string nazwa;
// };
//
// int main() {
//     //tworzenie dwoch obiektow statycznych
//     S obiekt1{32.05, "obiekt1"};
//     S obiekt2{33.05, "obiekt2"};
//
//     //zapisywanie obiektow do pliku
//     ofstream plik("zadanie.txt");
//     plik << obiekt1.polWartosc << " " << obiekt1.nazwa << endl;
//     plik << obiekt2.polWartosc << " " << obiekt2.nazwa << endl;
//     plik.close();
//
//     //wczytanie obiektow z pliku
//     S daneZPliku[2];
//
//     ifstream plikDoOdczytu("zadanie.txt");
//     for (int i = 0; i < 2; i++) {
//         plikDoOdczytu >> daneZPliku[i].polWartosc >> daneZPliku[i].nazwa;
//     }
//     plikDoOdczytu.close();
//
//     for (int i = 0; i < 2; i++) {
//         cout << "Polwartosc: " << daneZPliku[i].polWartosc << ", Nazwa: " << daneZPliku[i].nazwa << endl;
//     }
//
//     return 0;
// }






// #include <iostream>
// #include <string>
// #include <fstream>
//
// using namespace std;
//
// struct Produkt {
//     int id;
//     string nazwa;
//     float cena;
// };
//
// int main() {
//     Produkt produkt1{1, "Produkt1", 30.99};
//     Produkt produkt2{2, "Produkt2", 40.99};
//     Produkt produkt3{3, "Produkt3", 20.99};
//
//     ofstream plik("produkty.txt");
//
//     plik << produkt1.id << " " << produkt1.nazwa << " " << produkt1.cena << endl;
//     plik << produkt2.id << " " << produkt2.nazwa << " " << produkt2.cena << endl;
//     plik << produkt3.id << " " << produkt3.nazwa << " " << produkt3.cena << endl;
//     plik.close();
//
//     Produkt produkty[3];
//
//     ifstream odczytPliku("produkty.txt");
//
//     for (int i = 0; i < 3; i++) {
//         odczytPliku >> produkty[i].id >> produkty[i].nazwa >> produkty[i].cena;
//     }
//     odczytPliku.close();
//
//     for (int i = 0; i < 3; i++) {
//         cout << "Produkt " << i + 1 << " : " << "ID: " << produkty[i].id << " Nazwa: " << produkty[i].nazwa << " Cena: " << produkty[i].cena << endl;
//     }
//
//     return 0;
// }





#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct S {
    float polWartosc;
    string nazwa;
};

int main() {
    //tworzenie dwoch obiektow statycznych
    S obiekt1{32.05, "obiekt1"};
    S obiekt2{33.05, "obiekt2"};

    //zapisywanie obiektow do pliku
    ofstream plik("zadanie.txt");
    plik << obiekt1.polWartosc << " " << obiekt1.nazwa << endl;
    plik << obiekt2.polWartosc << " " << obiekt2.nazwa << endl;
    plik.close();

    //wczytanie obiektow z pliku
    S daneZPliku[2];

    ifstream plikDoOdczytu("zadanie.txt");
    for (int i = 0; i < 2; i++) {
        plikDoOdczytu >> daneZPliku[i].polWartosc >> daneZPliku[i].nazwa;
    }
    plikDoOdczytu.close();

    for (int i = 0; i < 2; i++) {
        cout << "Polwartosc: " << daneZPliku[i].polWartosc << ", Nazwa: " << daneZPliku[i].nazwa << endl;
    }

    S* obiekt3 = new S;
    S* obiekt4 = new S;

    cout << "Podaj dane dla obiektu 3 (wartosc, nazwa): ";
    cin >> obiekt3->polWartosc >> obiekt3->nazwa;

    cout << "Podaj dane dla obiektu 4 (wartosc, nazwa): ";
    cin >> obiekt4->polWartosc >> obiekt4->nazwa;

    ofstream dopiszPlik("zadanie.txt");
    dopiszPlik << obiekt3->polWartosc  << obiekt3->nazwa << endl;
    dopiszPlik << obiekt4->polWartosc << obiekt4->nazwa << endl;

    delete obiekt3;
    delete obiekt4;

    float minWartosc;
    cout << "Podaj wartosc minimalna do filtrowania: ";
    cin >> minWartosc;

    cout << "Elementy z pliku, których wartość jest większa niż " << minWartosc << ":" << endl;

    ifstream odczytPliku2("zadanie.txt");
    string linia;
    while (getline(odczytPliku2, linia)) {
        stringstream ss(linia);
        float wartosc;
        string nazwa;
        ss >> wartosc >> nazwa;

        if (minWartosc < wartosc) {
            cout << "Wartosc: " << wartosc << ", Nazwa: " << nazwa << endl;
        }
    }

    odczytPliku2.close();

    return 0;
}