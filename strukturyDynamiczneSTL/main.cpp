#include <iostream>
#include <stack>
#include <queue>
#include <random>
#include <vector>

using namespace std;

struct element {
    int id;
    string nazwa;
};

// struct MinHeap {
//     bool operator()(int a, int b) {
//         return a > b;
//     }
// };

//
// struct CompareNazwa {
//     bool operator()(const element& e1, const element& e2) {
//         return e1.nazwa > e2.nazwa; }
// };

//ZADANIE NR2
// int silnia(int n) {
//     stack<int> stos;
//     int wynik = 1;
//
//
//     for (int i = n; i > 0; i--) {
//         stos.push(i);
//         cout << "Dodano do stosu: " << i << endl;
//     }
//
//     while (!stos.empty()) {
//         int top = stos.top();
//         stos.pop();
//         wynik *= top;
//         cout << "Pobrano ze stosu: " << top << ", aktualny wynik: " << wynik << endl;
//     }
//
//     return wynik;
// }

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {

    //stack
    // stack<element> stos;
    // cout << "Czy pusty " << boolalpha << stos.empty() << endl;
    // for (int i = 0; i <= 5; i++) {
    //     stos.push({ i, "s" + to_string(i) }); // dodanie 5 elementów
    //     cout << "\n dodano element...";
    //     cout<<"\ntop:"<<stos.top().id<<" "<<stos.top().nazwa<<",ilosc: "<< stos.size();
    // }
    //
    // for (int i = 0; i < 3; i++) {
    //     stos.pop();
    // }
    // cout <<"\n top: " << stos.top().id << " " << stos.top().nazwa<< " , liczba elementów: " << stos.size();



    //queue
    // queue<element> q;
    //
    // for (int i = 1; i <= 5; i++) {
    //     q.push({ i, "q" + to_string(i) }); // dodanie 5 elementów
    //     cout << "\n dodano element...";
    //     cout << "\n początek: " << q.front().id << " " << q.front().nazwa
    //     <<" koniec: "<<q.back().id<<" "<<q.back().nazwa << " , ilosc: " << q.size();
    // }
    //
    // for (int i = 1; i <= 5; i++) {
    //     q.pop(); // usunięcie 5 elementów
    //     cout << "\n usunieto element...";
    //     if(q.empty()) cout<<"\n kolejka pusta...";
    //     else{
    //         cout << "\n początek: " << q.front().id << " " << q.front().nazwa
    //         <<" koniec: "<<q.back().id<<" "<<q.back().nazwa << " , ilosc: " << q.size();
    //     }
    // }


    //priority queue
    // cout << "\n\n kolejka typu priority_queue...\n";
    // priority_queue<element, vector<element>, CompareNazwa> pq;
    // queue<element> q2({{6,"e6"},{3,"e3"},{8,"e8"},{4,"e4"}});
    // while(!q2.empty()) { pq.push({ q2.front()}); q2.pop(); }
    // cout<<"\n"<<pq.top().id<<" "<<pq.top().nazwa<<" "<<pq.size();
    // pq.push({ 2, "e2" }); pq.push({ 5, "e5" });
    // cout<<pq.top().id<<" "<<pq.top().nazwa<<" "<<pq.size();
    // pq.pop();
    // cout<<pq.top().id<<" "<<pq.top().nazwa<<" "<<pq.size();


    //ZADANIE NR1
    // queue<element> kolejka;
    // int wybor;
    // cout << "Symulator kolejki zadan..." << endl;
    // if (kolejka.empty()) {
    //     cout << "Kolejka pusta." << endl;
    // }
    //
    // do {
    //     do {
    //         cout << "Wybierz rodzaj operacji \n (1) - Dodaj zadanie. \n (2) - Usun zadanie. \n (3) Koniec." << endl;
    //         cin >> wybor;
    //     } while (wybor != 1 && wybor != 2 && wybor !=3);
    //
    //     if (wybor == 1) {
    //         int rozmiar = kolejka.size() + 1;
    //         kolejka.push({rozmiar, "zadanie" + to_string(rozmiar)});
    //         cout << "Dodano zadanie." << endl;
    //         cout << "Stan kolejki zadan: \nPierwszy: " << kolejka.front().id << " " << kolejka.front().nazwa << endl;
    //         cout << "Ostatni: " << kolejka.back().id << " " << kolejka.back().nazwa << endl;
    //         cout << "Zadania w kolejce: " << endl;
    //         queue<element> kolejka2 = kolejka;
    //         while (!kolejka2.empty()) {
    //             cout << kolejka2.front().id << " " << kolejka2.front().nazwa << endl;
    //             kolejka2.pop();
    //         }
    //         cout << "Liczba zadan: " << kolejka.size() << endl;
    //     } else if (wybor == 2) {
    //         if (!kolejka.empty()) {
    //             cout << "Usunieto zadanie: " << kolejka.front().id << kolejka.front().nazwa << endl;
    //             kolejka.pop();
    //             cout << "Zadania w kolejce: ";
    //             queue<element> kolejka2 = kolejka;
    //             while (!kolejka2.empty()) {
    //                 cout << kolejka2.front().id << " " << kolejka2.front().nazwa << endl;
    //                 kolejka2.pop();
    //             }
    //             cout << "Liczba zadan: " << kolejka.size() << endl;
    //         } else {
    //             cout << "Kolejka pusta." << endl;
    //         }
    //     }
    // } while (wybor != 3);



    //ZADANIE NR2
    // int liczba;
    // cout << "Podaj liczbe: ";
    // cin >> liczba;
    //
    // cout << "\nObliczanie silni dla n = " << liczba << "...\n";
    // int wynik = silnia(liczba);
    //
    // cout << "\nWynik: " << liczba << "! = " << wynik << endl;



    //ZADANIE NR3
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 19);


    priority_queue<int, vector<int>, greater<int>> pq;


    cout << "Dodane elementy: ";
    for (int i = 0; i < 6; i++) {
        int num = dist(gen);
        pq.push(num);
        cout << num << " ";
    }
    cout << endl;


    cout << "Najmniejszy element (top): " << pq.top() << endl;

    for (int i = 0; i < 3; i++) {
        cout << "\nUsuwanie elementu: " << pq.top();
        pq.pop();
        if (!pq.empty()) {
            cout << " | Nowy najmniejszy element: " << pq.top();
        } else {
            cout << " | Kolejka jest pusta!";
        }
    }
    cout << endl;



    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.