//5.1
// #include <iostream>
//
// using namespace std;
//
// int main() {
//     float d = 10.234;
//     float* w1 = &d;
//     cout << w1 << endl;
//     cout << *w1 << endl;;
//
//     d = 20.567;
//     cout << w1 << endl;
//     cout << *w1 << endl;;
//
//     auto w2 = &d;
//     cout << w2 << endl;
//     cout << *w2 << endl;
//
//     cout << typeid(w2).name() << endl;
//     cout << sizeof(w2) << endl;
//
//     int a = 20;
//     cout << typeid(a).name() << endl;
//     cout << sizeof(a) << endl;
//
//     return 0;
// }


//5.2
// #include <iostream>
// #include <random>
//
// using namespace std;
//
// void tabLos(int *t, int n) {
//     random_device rd;
//     uniform_int_distribution<int> ud(1, 9);
//     cout << "adres poczatku tablicy: " << t << endl;
//     for (int i = 0; i < n; i++) {
//         *(t + i) = ud(rd);
//     }
//     cout << "adres wskaznika po zakonczeniu petli: " << t << endl;
// }
//
// int main() {
//     constexpr size_t n = 10;
//     int t1[n];
//     tabLos(t1, n);
//     cout << "\n tabLos: ";
//     for (const auto& e : t1) {
//         cout << e << " ";
//     }
//
//     return 0;
// }


//5.3
// #include <iostream>
// #include <string>
//
// using namespace std;
//
// struct Przedmiot {
//     int numer;
//     string nazwa;
// };
//
// int main() {
//     Przedmiot p1{1, "pierwszy"};
//
//     Przedmiot* wp1 = &p1;
//
//     cout << "\n p1: " << wp1->numer << ", " << wp1->nazwa << endl;
// }


//pointers and arrays

// #include <iostream>
//
// using namespace std;
//
// void printNumber(int* numberPtr) {
//     cout << *numberPtr << endl;
// }
//
// void printLetter(char* charPtr) {
//     cout << *charPtr << endl;
// }
//
// void print(void*ptr, char type) {
//     switch (type) {
//         case 'i':
//             cout << *((int*)ptr) << endl;
//             break;
//         case 'c':
//             cout << *((char*)ptr) << endl;
//             break;
//     }
// }
//
// int main() {
//     int luckyNumbers[5] = {2,3,5,7,9};
//     // cout << luckyNumbers << endl;
//     // cout << &luckyNumbers[0] << endl;
//     //
//     // cout << luckyNumbers[2] << endl;
//     // cout << *(luckyNumbers + 2) << endl;
//
//     // for (int i = 0; i < 5; i++) {
//     //     cout << "Number: ";
//     //     cin >> luckyNumbers[i];
//     // }
//     //
//     // for (int i = 0; i < 5; i++) {
//     //     cout << *(luckyNumbers + i) << "  ";
//     // }
//
//     int number = 5;
//     char letter = 'a';
//     printNumber(&number);
//     printLetter(&letter);
//
//     print(&number, 'i');
//     print(&letter, 'c');
//
//     return 0;
// }


#include <iostream>

using namespace std;

int getMin(int numbers[], int size) {
    int min = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }
    return min;
}

int getMax(int numbers[], int size) {
    int max = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }
    return max;
}

void getMinAndMax(int numbers[], int size, int*min, int*max) {
    for (int i = 1; i < size; i++) {
        if (numbers[i] > *max) {
            *max = numbers[i];
        }
        if (numbers[i] < *min) {
            *min = numbers[i];
        }
    }
}

int main() {
    int numbers[5] = {5, 4, -2, 29, 6};
    //cout << "Min is: " << getMin(numbers, 5) << endl;
    //cout << "Max is: " << getMax(numbers, 5) << endl;

    int min = numbers[0];
    int max = numbers[0];

    getMinAndMax(numbers, 5, &min, &max);
    cout << "Min: " << min << ", Max: " << max << endl;

    return 0;
}
