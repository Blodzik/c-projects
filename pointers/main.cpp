#include <iostream>
#include <random>
#include <span>
#include <iomanip>

using namespace std;

void tabLos(int *t,int n)
{
    random_device rd;
    uniform_int_distribution<> ud(1,9);
    cout<<"\n adres początku tablicy: "<<t<<endl;
    for(int i=0;i<n;i++)
    {
        //t[i] = ud(rd);
        *(t + i) = ud(rd);
    }
    cout << "\n adres wskaźnika po zakończeniu pętli: " << t << endl;
}

void elementyTablicy1w(span<int> t)
{
    for (const auto& e : t) cout << " " << e;
}

struct Przedmiot {
    int numer; string nazwa;
};

void elem_tab2w(int** t,int lw,int lk)
{
    cout<<"\n elementy tablicy 2-wym.:"<<endl;
    for (int i = 0; i < lw; i++)
    {
        cout << endl;
        for (int j = 0; j < lk; j++)
            cout<<setw(3)<<*(*(t+i)+j); //cout << setw(3) << t[i][j];
    }
}

int main() {
    // cout << "\n\n";
    // double d=10.234;
    // cout << "\n d=" << d;
    //
    // double *w1=&d;
    // cout<<"\n *w1="<<*w1;
    // *w1=20.567;
    //
    // cout << "\n po zmianie na 20.567 przez *w1, d=" << d;
    // cout << "\n adres d: " << &d;
    // cout << "\n adres w1: " << w1;
    //
    // auto w2=w1;
    // cout << "\n adres w2=" << w2;
    //
    // cout << "\n *w2=" << *w2;
    // cout << "\n typ w2: " << typeid(w2).name() ;
    // cout << "\n rozmiar wskaźnika w2: " << sizeof(w2) <<endl;


    constexpr size_t n = 10; // Rozmiar tablicy
    int t1[n]{}; // Tworzymy tablicę z 10 elementami (zainicjalizowane na 0)

    // Wypełnij tablicę losowymi liczbami
    tabLos(t1, n);

    // Wyświetl zawartość tablicy
    cout << "\nZawartość tablicy: ";
    for (const auto& e : t1) {
        cout << " " << e;
    }

    // Wyświetl zawartość tablicy za pomocą "span"
    cout << "\nZawartość tablicy za pomocą 'span': ";
    elementyTablicy1w(t1);

    // Próba dostępu do elementu poza zakresem
    cout << "\nElement nr 10 tablicy (poza zakresem!): ";
    cout << "\nt1[10]: " << t1[10]; // NIEBEZPIECZNE! Tablica ma tylko 10 elementów (indeksy 0-9)

    span<int> sp1{t1}; // Tworzymy "span" dla tablicy t1
    cout << "\nspan[10]: " << sp1[10]; // Nadal NIEBEZPIECZNE, wychodzi poza zakres tablicy!

    Przedmiot p1{ 1,"pierwszy" };
    Przedmiot* wp1 = &p1;
    cout<<"\n wp1: " << wp1->numer << " " << wp1->nazwa << endl;

    int t2[12]{};
    void (*wft)(int* t, int r);
    wft = tabLos;
    wft(t2, 12);
    cout << "\n t2 z użyciem wskaźnika do funkcji:";
    auto wft2 = elementyTablicy1w;
    wft2(t2);

    constexpr size_t n2 = 6;
    int tab21[n2]{}; int tab22[n2]{}; int tab23[n2]{};
    int* tab2[] = {tab21,tab22,tab23};

    wft(tab21, n2); // Wypełnianie przez wskaźnik
    tabLos(tab22, n2); // Wypełnianie przez nazwę funkcji
    wft(tab23, n2);

    elem_tab2w(tab2,3,6);

    return 0;

}