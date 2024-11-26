// #include <iostream>
// #include <tuple>
// #include <string>
// using namespace std;
//
// struct ksiazka {
//     int id;
//     string tytul;
//     string autor;
//     float cena;
//     inline static int liczba = 0;
//
//     void wypisz() const { // Dodano 'const'
//         cout << tytul << endl << autor << endl << cena << endl;
//         liczba++;
//     }
// };
//
// int main() {
//     ksiazka ksiazka1{1, "Pan Tadeusz", "Adam Mickiewicz", 19.99};
//     ksiazka ksiazka2{2, "Quo Vadis", "Henryk Sienkiewicz", 25.50};
//
//     ksiazka ksiazka3{ksiazka1};
//     ksiazka3.id = 3;
//
//     ksiazka1.wypisz();
//     ksiazka2.wypisz();
//     ksiazka3.wypisz();
//
//     cout << ksiazka1.liczba << endl;
//
//     ksiazka biblioteka[5]; // Zmieniono rozmiar na 5
//     biblioteka[0] = {5, "Lalka", "Boleslaw Prus", 30.00};
//     biblioteka[1] = ksiazka1;
//     biblioteka[2] = ksiazka2;
//     biblioteka[3] = ksiazka3;
//
//     auto nowa_ksiazka = make_tuple(6, "Krzyżacy", "Henryk Sienkiewicz", 35.00);
//     tie(biblioteka[4].id, biblioteka[4].tytul, biblioteka[4].autor, biblioteka[4].cena) = nowa_ksiazka;
//     ++ksiazka::liczba;
//
//     cout << "\n\nBiblioteka:" << endl;
//     for (const auto& ksiazka : biblioteka) {
//         ksiazka.wypisz();
//     }
//
//     return 0;
// }

#include <iostream>
#include <string>
#include <compare> // Wymagana biblioteka dla operatora <=> w C++20

using namespace std;

struct Produkt {
    int id{};
    string nazwa{};
    float cena{};

    inline static int liczba{};

    void wypisz() const {
        cout << "\n" << id << " " << nazwa << " " << cena << endl;
    }

    // Operator porównania trójstanowego
    auto operator<=>(const Produkt& rhs) const noexcept {
        partial_ordering cmp;

        // Porównywanie według nazwy (string)
        if (cmp = (nazwa <=> rhs.nazwa); cmp != 0)
            return cmp;

        // Jeśli nazwy są takie same, porównaj cenę (float)
        if (cmp = (cena <=> rhs.cena); cmp != 0)
            return cmp;

        // Jeśli ceny są takie same, porównaj ID (int)
        return id <=> rhs.id;
    }

    // Operator == - kompilator automatycznie generuje porównanie wszystkich pól
    bool operator==(const Produkt& rhs) const = default;
};

int main() {
    // Tworzenie obiektów
    Produkt p1{1, "Laptop", 2999.99};
    Produkt p3{3, "Laptop", 2500.50};

    // Porównywanie obiektów za pomocą operatorów
    cout << "\n p1==p1 ? " << boolalpha << (p1 == p1);   // true (ten sam obiekt)
    cout << "\n p1!=p3 ? " << boolalpha << (p1 != p3);   // true (różne ceny i ID)
    cout << "\n p1<p3 ? " << boolalpha << (p1 < p3);     // false (cena p3 jest mniejsza)
    cout << "\n p1>p3 ? " << boolalpha << (p1 > p3);     // true (cena p1 jest większa)

    // Wyświetlenie danych obiektów
    cout << "\n\nDane obiektów:";
    p1.wypisz();
    p3.wypisz();

    return 0;
}