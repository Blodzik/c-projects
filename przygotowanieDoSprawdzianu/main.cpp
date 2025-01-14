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

// #include <iostream>
// #include <vector>
// #include <string>
// #include <fstream>
// #include <algorithm>
//
// using namespace std;
//
// struct Osoba {
//     string imie;
//     int wiek;
// };
//
// void wyswietlWektor(vector<Osoba> osoba) {
//     for (int i = 0; i < osoba.size(); i++ ) {
//         cout << osoba[i].imie << " " << osoba[i].wiek << endl;
//     }
// }
//
// int main() {
//     vector<Osoba> osoba;
//
//     Osoba o1{"Nazar", 18};
//     Osoba o2("Adrian", 17);
//
//     osoba.push_back(o1);
//     osoba.push_back(o2);
//
//     ofstream otworzPlik("osoba.txt");
//     for (int i = 0; i < 2; i++) {
//         otworzPlik << osoba[i].imie << "  " << osoba[i].wiek << endl;
//     }
//     otworzPlik.close();
//
//
//     for (int i = 0; i < 2; i++) {
//         Osoba* nowaOsoba = new Osoba;
//         cout << "Wprowadz imie osoby numer: " << (i + 1) << " : ";
//         cin >> nowaOsoba->imie;
//         cout << "Wprowadz wiek osoby numer: " << (i + 1) << " : ";
//         cin >> nowaOsoba->wiek;
//
//         osoba.insert(osoba.begin(), *nowaOsoba);
//         delete nowaOsoba;
//         nowaOsoba = nullptr;
//     }
//
//     otworzPlik.open("osoba.txt");
//     for (int i = 0; i < 4; i++) {
//         otworzPlik << osoba[i].imie << "  " << osoba[i].wiek << endl;
//     }
//     otworzPlik.close();
//
//     vector<Osoba> osoba2;
//
//     ifstream wczytajPlik("osoba.txt");
//     Osoba temp;
//     while (wczytajPlik >> temp.imie >> temp.wiek) {
//         osoba2.push_back(temp);
//     }
//     wczytajPlik.close();
//
//     sort(osoba2.begin(), osoba2.end(), [](Osoba a, Osoba b) {
//         return a.wiek < b.wiek;
//     });
//
//     wyswietlWektor(osoba2);
//
//     return 0;
//}

// #include <iostream>
// #include <string>
// #include <vector>
// #include <fstream>
// #include <algorithm>
//
// using namespace std;
//
// struct Film {
//     string tytul;
//     int rok;
// };
//
// void wyswietlWektor(vector<Film> filmy) {
//     for (int i = 0; i < filmy.size(); i++) {
//         cout << filmy[i].tytul << " " << filmy[i].rok << endl;
//     }
// }
//
// int main() {
//     vector<Film> filmy;
//
//     Film film1{"ForestGump", 1994};
//     Film film2{"GreenMile", 1999};
//
//     filmy.push_back(film1);
//     filmy.push_back(film2);
//
//     ofstream otworzPlik("filmy.txt");
//     for (int i = 0; i < filmy.size(); i++) {
//         otworzPlik << filmy[i].tytul << " " << filmy[i].rok << endl;
//     }
//     otworzPlik.close();
//
//     for (int i = 0; i < 2; i++) {
//         Film* nowyFilm = new Film;
//         cout << "Wprowadz tytul filmu numer " << (i + 1) << " : ";
//         cin >> nowyFilm->tytul;
//         cout << "Wprowadz rok filmu numer " << (i + 1) << " : ";
//         cin >> nowyFilm->rok;
//
//         filmy.insert(filmy.begin(), *nowyFilm);
//         delete nowyFilm;
//         nowyFilm = nullptr;
//     }
//
//     otworzPlik.open("filmy.txt");
//     for (int i = 0; i < filmy.size(); i++) {
//         otworzPlik << filmy[i].tytul << " " << filmy[i].rok << endl;
//     }
//     otworzPlik.close();
//
//     vector<Film> filmy2;
//
//     ifstream wyswietlPlik("filmy.txt");
//     Film temp;
//     while (wyswietlPlik >> temp.tytul >> temp.rok) {
//         filmy2.push_back(temp);
//     }
//     wyswietlPlik.close();
//
//     sort(filmy2.begin(), filmy2.end(), [](const Film a, const Film b) {
//         return a.rok < b.rok;
//     });
//
//     wyswietlWektor(filmy2);
//
//     return 0;
// }


#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

struct Student {
    string imie;
    float srednia;
};

void wyswietlListe(list<Student> studenty) {
    for (const auto& student : studenty) {
        cout << student.imie << " " << student.srednia << endl;
    }
}

int main() {
    Student student1{"Jogn", 4.54};
    Student student2{"Joe", 3.14};

    list<Student> studenty;

    studenty.push_back(student1);
    studenty.push_back(student2);

    ofstream otworzPlik("studenci.txt");
    for (const auto& student : studenty) {
        otworzPlik << student.imie << " " << student.srednia << endl;
    }
    otworzPlik.close();

    for (int i = 0; i < 2; i++) {
        Student* nowyStudent = new Student;
        cout << "Wprowadz imie studenta numer " << (i+1) << " : ";
        cin >> nowyStudent->imie;
        cout << "Wprowadz srednia studenta numer " << (i+1) << " : ";
        cin >> nowyStudent->srednia;

        studenty.insert(studenty.begin(), *nowyStudent);
        delete nowyStudent;
        nowyStudent = nullptr;
    }

    otworzPlik.open("studenci.txt");
    for (const auto& student : studenty) {
        otworzPlik << student.imie << " " << student.srednia << endl;
    }
    otworzPlik.close();

    list<Student> studenty2;
    ifstream wyswietlPlik("studenci.txt");
    Student temp;
    while (wyswietlPlik >> temp.imie >> temp.srednia) {
        studenty2.push_back(temp);
    }
    wyswietlPlik.close();

    studenty2.remove_if([] (Student& student) {
        return student.srednia < 3.0;
    });

    wyswietlListe(studenty2);

    return 0;
}