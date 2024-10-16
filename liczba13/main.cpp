#include <iostream>
#include <random>

using namespace std;

int main() {
    random_device rd{};
    uniform_int_distribution<> ud(11, 15);
    
    char powtarzanie;
    
    do {
        int numerGenerowania = 0;
        int nie13 = 0;
        int losowa;
        
        while (numerGenerowania < 14) {
            losowa = ud(rd);
            cout << losowa << ", ";
            numerGenerowania++;
            
            if (losowa != 13) {
                nie13++;
                if (nie13 == 10) {
                    break;
                }
            }
        }
        
        cout << "\nIlosc generowan: " << numerGenerowania << endl;
        cout << "Ilosc liczb nie-13: " << nie13 << endl;
        
        cout << "Czy powtarzac(t/n): ";
        cin >> powtarzanie;
    } while (powtarzanie == 't' || powtarzanie == 'T');
}

