#include <iostream>
#include <random>

using namespace std;

int main() {
    bool stop = false;
    char letters[3] = {'A', 'B', 'C'};
    
    char decision;
    
    random_device rd{};
    uniform_int_distribution<> ud(0, 2);
    
    int round = 0;
    
    
    do {
        cout << "Czy chcesz zagrac gre? Wpisz 't' dla TAK albo 'n' dla NIE: ";
        cin >> decision;
        
        if (decision == 'n' || decision == 'N') {
            stop = true;
        } else if (decision == 't' || decision == 'T') {
            round++;
            
            if(round < 5) {
                char letter1 = letters[ud(rd)];
                char letter2 = letters[ud(rd)];
                char letter3 = letters[ud(rd)];
                
                
                cout << "Wylosowane litery: " << letter1 << ", " << letter2 << ", " << letter3 << endl;
                cout << "Proba: " << round << endl;
                
                if(letter1 == letter2 and letter2 == letter3) {
                    cout << "Wygrales!! " << endl;
                    stop = true;
                } else {
                    cout << "Brak wygranej sproboj ponownie. " << endl;
                }
            }
            else  {
                stop = true;
                cout << "Osignales limit prob." << endl;
            }
        }
        
    } while(!stop);
    
    return 0;
}
