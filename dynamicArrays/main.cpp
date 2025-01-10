// #include <iostream>
//
// using namespace std;
//
// int main() {
//     int size;
//     cout << "Size: ";
//     cin >> size;
//
//     int* myArray = new int[size];
//
//     for (int i = 0; i < size; i++) {
//         cout << "Array[" << i << "]: ";
//         cin >> myArray[i];
//     }
//
//     for (int i = 0; i < size; i++) {
//         //cout << myArray[i] << " ";
//         cout << *(myArray + i) << " ";
//     }
//
//     delete[] myArray;
//     myArray = nullptr;
//
//     return 0;
// }

// #include <iostream>
// #include <stdlib.h>
//
// using namespace std;
//
// int main() {
//     int rows, cols;
//     cout << "rows, cols: ";
//     cin >> rows >> cols;
//
//     int** table = new int*[rows];
//
//     for (int i = 0; i < rows; i++) {
//         table[i] = new int[cols];
//     }
//
//     table[1][2] = 88;
//
//     for (int i = 0; i < rows; i++) {
//         delete[] table[i];
//     }
//     delete[] table;
//     table = nullptr;


// #include <iostream>
// #include <random>
// #include <iomanip>
//
// using namespace std;
//
// random_device rd;
//
// int* tab1w(int le, int min, int max) {
//     uniform_int_distribution<int> ud(min, max);
//
//     int* t = new int[le];
//
//     for (int i = 0; i < le; i++) {
//         *(t + i) = ud(rd);
//     }
//
//     return t;
// }
//
// void wyswietl(int* t, int le) {
//     for (int i = 0; i < le; i++) {
//         cout << *(t + i) << " ";
//     }
//     cout << endl;
// }
//
// int main() {
//     int n;
//     cout << "Podaj liczbe elementow: ";
//     cin >> n;
//     int min = 10;
//     int max = 100;
//
//     int* t1 = tab1w(n, min, max);
//     int* t2 = tab1w(n - 3, min, max);
//
//     wyswietl(t1, n);
//     wyswietl(t2, n - 3);
//
//     return 0;
// }

#include <iostream>
#include <random>
#include <fstream>

using namespace std;
random_device rd;

int* tab1w(int le, int min, int max) {
    uniform_int_distribution<int> ud(min, max);

    int* t = new int[le];

    for (int i = 0; i < le; i++) {
        int num = ud(rd);
        while (num % 2 != 0) {
            num = ud(rd);
        }
        *(t + i) = num;
    }
    return t;
}

void wyswietl(int* t, int le) {
    for (int i = 0; i < le; i++ ) {
        cout << *(t + i) << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Podaj liczbe elementow: ";
    cin >> n;

    int min = 10;
    int max = 100;

    int* t1 = tab1w(n, min, max);
    int* t2 = tab1w(n - 2, min, max);

    ofstream plik("tablica.txt");
    plik << n << endl;
    for (int i = 0; i < n; i++) {
        plik << *(t1 + i) << " ";
    }
    plik << endl;

    plik << n - 2 << endl;
    for (int i = 0; i < n - 2; i++) {
        plik << *(t2 + i) << " ";
    }
    plik << endl;

    plik.close();

    ifstream otworz("tablica.txt");
    int size1, size2;

    otworz >> size1;

    int* t3 = new int[size1];
    for (int i = 0; i < size1; i++) {
        otworz >> t3[i];
    }

    otworz >> size2;
    int* t4 = new int[size2];
    for (int i = 0; i < size2; i++) {
        otworz >> t4[i];
    }
    plik.close();

    cout << "Tablica t3 z pliku: " << endl;
    wyswietl(t3, size1);

    cout << "Tablica t4 z pliku: " << endl;
    wyswietl(t4, size2);

    delete[] t3;
    delete[] t4;
    t3 = nullptr;
    t4 = nullptr;

    //wyswietl(t1, n);
    //wyswietl(t2, n - 2);

    delete[] t1;
    delete[] t2;
    t1 = nullptr;
    t2 = nullptr;

    return 0;
}