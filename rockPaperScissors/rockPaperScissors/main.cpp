#include <iostream>
#include <random>
#include <string>

using namespace std;

string showResult (string resp, int round) {
    cout << resp << endl;
    cout << round << endl;
    return resp;
}

bool caseSensitiveCharCompare(char a, char b) {
    return tolower(a) == tolower(b);
}

int main() {
    bool stop = false;
    char decision;
    char playAgain;
    char letters[3] = {'R', 'P', 'S'};
    
    random_device rd{};
    uniform_int_distribution<> ud(0, 2);
    
    int round = 1;
    
    do {
        cout << "Enter rock, paper or scissors(r, p, s): ";
        cin >> decision;
        
        char randDecision = letters[ud(rd)];
        
        if (caseSensitiveCharCompare(decision, randDecision)) {
                    showResult("Tie", round++);
        } else if ((decision == 'r' || decision == 'R') && randDecision == 'S') {
            showResult("You win! Rock beats Scissors", round++);
        } else if ((decision == 'p' || decision == 'P') && randDecision == 'R') {
            showResult("You win! Paper beats Rock", round++);
        } else if ((decision == 's' || decision == 'S') && randDecision == 'P') {
            showResult("You win! Scissors beats Paper", round++);
        } else {
            showResult("You lose!", round++);
        }
        
        cout << "Play again (y/n): ";
        cin >> playAgain;
        
        if (playAgain == 'n' || playAgain == 'N') {
            stop = true;
        }
        
    } while(!stop);
    
    return 0;
}
