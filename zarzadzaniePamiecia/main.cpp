#include <iostream>
#include <random>
#include <iomanip>
using namespace std;
random_device rd;
// int* tab1w(int le, int min, int max)
// {
//     uniform_int_distribution<> ud(min, max);
//     int* t = new int[le];
//     for (int i = 0; i < le; ++i)
//     {
//         *(t + i) = ud(rd); // t[i] = ud(rd);
//     }
//     return t;
// }
//
// void wyswietl(int* t, int le)
// {
//     for (int i = 0; i < le; i++) cout<< *(t + i) << " "; // cout << t[i] << " ";
//
//     cout << endl;
// }

int** tab2w(int lw, int lk, int min, int max)
{
    uniform_int_distribution<> ud(min, max);
    int** t = new int* [lw];
    for (int i = 0; i < lw; ++i)
    {
        *(t+i) = new int[lk];
        for (int j = 0; j < lk; ++j) *(*(t + i) + j) = ud(rd);
    }
    return t;
}

void wyswietl(int** t, int lw, int lk)
{
    for (int i = 0; i < lw; ++i)
    {
        cout << endl;
        for (int j = 0; j < lk; ++j)
            cout << setw(3) << *(*(t + i) + j); // cout << setw(3) << t[i][j]);
    }
}

int main()
{
    // setlocale(LC_CTYPE, "polish");
    // cout<<" \n podaj liczbę elementów: ";
    // int n; cin>>n;
    // int min = 0, max = 9;
    // int* t1 = tab1w(n,min,max);
    // int* t2 = tab1w(n+3,min,max);

    //wyswietl(t1,n); //w funkcji main()
    //wyswietl(t2,n+3); //w funkcji main()



    int w, k;
    cout << "\n podaj liczbę wierszy: "; cin >> w;
    cout << "podaj liczbę kolumn: "; cin >> k;
    int min = 1;
    int max = 20;
    int* *t3=tab2w(w,k,min,max);


    wyswietl(t3,w,k);
}