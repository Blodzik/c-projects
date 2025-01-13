// #include <iostream>
// #include <vector>
// #include <fstream>
// #include <algorithm>
//
// using namespace std;
//
// struct S {
//     float wartosc;
//     bool prawda;
// };
//
// void wyswietlKontener(const vector<S>& v) {
//     for (int i = 0; i < v.size(); i++) {
//         cout << "Wartosc: " << v[i].wartosc << endl;
//         cout << "Prawda: " << v[i].prawda << endl;
//     }
// }
//
// int main() {
//     vector<S> vec;
//
//     S s1{32.25, true};
//     S s2{102.74, false};
//
//     vec.push_back(s1);
//     vec.push_back(s2);
//
//     ofstream myfile("zadanie.txt");
//     for (int i = 0; i < 2; i++) {
//         myfile << vec[i].wartosc  << " " << vec[i].prawda << endl;
//     }
//     myfile.close();
//
//     for (int i = 0; i < 2; i++) {
//         S* nowaWart = new S;
//         cout << "Podaj wartosc typu float dla obiektu " << (i + 1) << ": ";
//         cin >> nowaWart->wartosc;
//         cout << "Podaj prawda typu bool dla obiektu " << (i + 1) << ": ";
//         cin >> nowaWart->prawda;
//
//         vec.insert(vec.begin(), *nowaWart);
//         delete nowaWart;
//         nowaWart = nullptr;
//     }
//
//     myfile.open("zadanie.txt");
//     for (int i = 0; i < 2; i++) {
//         myfile << vec[i].wartosc  << " " << vec[i].prawda << endl;
//     }
//
//     vector<S> vec2;
//     ifstream wPliku("zadanie.txt");
//     S temp;
//     while (wPliku >> temp.wartosc >> temp.prawda) {
//         vec2.push_back(temp);
//     }
//     wPliku.close();
//
//     //cout << "Zawartosc starego kontenera: " << endl;
//     //wyswietlKontener(vec);
//
//     cout << "Dane przed sortowaniem: " << endl;
//     wyswietlKontener(vec2);
//
//     sort(vec2.begin(), vec2.end(), [](const S& a, const S& b){
//         return a.wartosc > b.wartosc;
//     });
//     cout << "Dane po sortowaniu: " << endl;
//     wyswietlKontener(vec2);
//
//
//
//     return 0;
// }

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

struct Osoba {
    string imie;
    int wiek;
};

void wyswietlWektor(vector<Osoba> osoba) {
    for (int i = 0; i < osoba.size(); i++ ) {
        cout << osoba[i].imie << " " << osoba[i].wiek << endl;
    }
}

int main() {
    vector<Osoba> osoba;

    Osoba o1{"Nazar", 18};
    Osoba o2("Adrian", 17);

    osoba.push_back(o1);
    osoba.push_back(o2);

    ofstream otworzPlik("osoba.txt");
    for (int i = 0; i < 2; i++) {
        otworzPlik << osoba[i].imie << "  " << osoba[i].wiek << endl;
    }
    otworzPlik.close();


    for (int i = 0; i < 2; i++) {
        Osoba* nowaOsoba = new Osoba;
        cout << "Wprowadz imie osoby numer: " << (i + 1) << " : ";
        cin >> nowaOsoba->imie;
        cout << "Wprowadz wiek osoby numer: " << (i + 1) << " : ";
        cin >> nowaOsoba->wiek;

        osoba.insert(osoba.begin(), *nowaOsoba);
        delete nowaOsoba;
        nowaOsoba = nullptr;
    }

    otworzPlik.open("osoba.txt");
    for (int i = 0; i < 4; i++) {
        otworzPlik << osoba[i].imie << "  " << osoba[i].wiek << endl;
    }
    otworzPlik.close();

    vector<Osoba> osoba2;

    ifstream wczytajPlik("osoba.txt");
    Osoba temp;
    while (wczytajPlik >> temp.imie >> temp.wiek) {
        osoba2.push_back(temp);
    }
    wczytajPlik.close();

    sort(osoba2.begin(), osoba2.end(), [](Osoba a, Osoba b) {
        return a.wiek < b.wiek;
    });

    wyswietlWektor(osoba2);

    return 0;
}