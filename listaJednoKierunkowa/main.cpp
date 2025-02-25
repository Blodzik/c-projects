#include <iostream>
#include <string>

struct Element {
    int id{};
    std::string nazwa{};
    Element* nastepny = nullptr;
};

struct Lista1k {
    Element* head = nullptr;
    int liczbaElementow{};

    void wyswietl();
    void dodaj();
    void usun(int numer);
};

void Lista1k::wyswietl() {
    Element* e = head;
    if (head == nullptr) {
        std::cout << "\nLista jest pusta!";
    } else {
        std::cout << "\nLiczba elementów na liście: " << liczbaElementow;
        while (e != nullptr) {
            std::cout << "\n";
            std::cout << e->id << " " << e->nazwa << " " << e << ", nastepny=" << e->nastepny;
            e = e->nastepny;
        }
    }
    std::cout << "\n";
}

void Lista1k::dodaj() {
    Element* nowy = new Element;
    std::cout << "\nWpisz id: ";
    std::cin >> nowy->id;
    std::cout << "Wpisz nazwę: ";
    std::cin >> nowy->nazwa;
    nowy->nastepny = nullptr;

    if (head == nullptr) {
        head = nowy;
    } else {
        Element* temp = head;
        while (temp->nastepny != nullptr) {
            temp = temp->nastepny;
        }
        temp->nastepny = nowy;
    }
    ++liczbaElementow;
}

void Lista1k::usun(int numer) {
    if (numer < 1 || numer > liczbaElementow) {
        std::cout << "Brak elementu o numerze " << numer << " na liscie";
        return;
    }
    Element* temp = head;
    if (numer == 1) {
        head = head->nastepny;
        delete temp;
    } else {
        Element* poprzedni = nullptr;
        for (int i = 1; i < numer; i++) {
            poprzedni = temp;
            temp = temp->nastepny;
        }
        poprzedni->nastepny = temp->nastepny;
        delete temp;
    }
    --liczbaElementow;
    std::cout << "Element o numerze " << numer << " zostal usuniety \n";
}

int main() {
    Lista1k lista;
    lista.wyswietl();
    std::cout << "\nDodawanie elementów\n";
    for (int i = 1; i <= 4; ++i) {
        lista.dodaj();
    }
    lista.wyswietl();

    int numeryDoUsuniecia[] = {2, 5, 4, 1, 4, 1};
    for (int numer : numeryDoUsuniecia) {
        lista.usun(numer);
        lista.wyswietl();
    }
    return 0;
}