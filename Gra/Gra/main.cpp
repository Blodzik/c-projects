#include <iostream>
#include <string>

using namespace std;

void rysujPlansze(char plansza[3][3]) {
    cout << "\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << " " << plansza[i][j];
            if (j < 2) cout << " |";
        }
        cout << "\n";
        if (i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

bool sprawdzWygrana(char znak, char plansza[3][3]) {
    for (int i = 0; i < 3; ++i) {
        // Sprawdza wiersze i kolumny
        if ((plansza[i][0] == znak && plansza[i][1] == znak && plansza[i][2] == znak) ||
            (plansza[0][i] == znak && plansza[1][i] == znak && plansza[2][i] == znak)) {
            return true;
        }
    }
    // Sprawdza przekątne
    return (plansza[0][0] == znak && plansza[1][1] == znak && plansza[2][2] == znak) ||
           (plansza[0][2] == znak && plansza[1][1] == znak && plansza[2][0] == znak);
}

bool sprawdzRemis(char plansza[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (plansza[i][j] != 'X' && plansza[i][j] != 'O') return false;
        }
    }
    return true;
}

int main() {
    string gracz1, gracz2;
    cout << "Gracz 1, podaj swoje imie: ";
    cin >> gracz1;
    cout << "Gracz 2, podaj swoje imie: ";
    cin >> gracz2;

    // Inicjalizacja planszy z numerami pól od 1 do 9
    char plansza[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

    char aktywnyZnak = 'X';
    string aktywnyGracz = gracz1;
    bool czyKoniec = false;

    do {
        rysujPlansze(plansza);

        int ruch;
        bool poprawnyRuch = false;
        
        // Pobieranie ruchu gracza i walidacja
        do {
            cout << aktywnyGracz << " (" << aktywnyZnak << "), wybierz numer pola (1-9): ";
            cin >> ruch;
            ruch--; // Konwersja na indeks 0-8

            int x = ruch / 3;
            int y = ruch % 3;

            if (ruch >= 0 && ruch < 9 && plansza[x][y] != 'X' && plansza[x][y] != 'O') {
                plansza[x][y] = aktywnyZnak;
                poprawnyRuch = true;
            } else {
                cout << "Pole jest już zajęte lub nieprawidłowe, wybierz inne pole.\n";
            }
        } while (!poprawnyRuch);

        // Sprawdzenie warunków zakończenia gry
        if (sprawdzWygrana(aktywnyZnak, plansza)) {
            rysujPlansze(plansza);
            cout << "Gratulacje " << aktywnyGracz << "! Wygrywasz!\n";
            czyKoniec = true;
        } else if (sprawdzRemis(plansza)) {
            rysujPlansze(plansza);
            cout << "Remis!\n";
            czyKoniec = true;
        } else {
            // Zmiana gracza
            if (aktywnyZnak == 'X') {
                aktywnyZnak = 'O';
                aktywnyGracz = gracz2;
            } else {
                aktywnyZnak = 'X';
                aktywnyGracz = gracz1;
            }
        }
    } while (!czyKoniec);

    return 0;
}
