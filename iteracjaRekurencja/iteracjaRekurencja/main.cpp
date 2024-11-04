#include <iostream>

using namespace std;

//iteracja
int sum(int n) {
    int wynik = 0;
    
    for(int i = 1; i < n + 1; i++){
        wynik = wynik + i;
    }
    return wynik;
}

//rekurecnja
int sum2(int n) {
    if(n == 0) {
        return 0;
    } else {
        return n + sum(n - 1);
    }
}

//silnia iteracja
int sil(int n) {
    int wynik = 1;
    
    for(int i = 1; i < n + 1; i++) {
        wynik = wynik * i;
    }
    
    return wynik;
}

//silnia rekurencja
int sil2(int n) {
    if(n == 0) {
        return 1;
    } else {
        return n * sil(n - 1);
    }
}

int main() {
    cout << sum(10) << endl;
    cout << sum2(10) << endl;
    
    cout << sil(9) << endl;
    cout << sil(9) << endl;
}
