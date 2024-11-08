#include <iostream>
#include <unistd.h> // for usleep on Linux/macOS
using namespace std;

const int n = 12;
char lab[n][n];
int tabRuchow[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int xStart, yStart, xKoniec, yKoniec;
bool czyKoniec = false;

char lab2[n][n] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0},
    {0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0},
    {0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0},
    {0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0},
    {0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 0},
    {0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0},
    {0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

// Function to clear the screen and redraw the labyrinth
void rysujLabirynt() {
    // Clear the console (ANSI escape codes for Unix/macOS)
    cout << "\033[2J\033[1;1H";
    cout << "\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << lab[i][j];
        }
        cout << endl;
    }
}

// Placeholder for the maze-solving function
void szukajWyjscia(int x, int y) {
    // Jeśli dotarliśmy do punktu końcowego, ustawiamy `czyKoniec` na true i kończymy
    if (x == xKoniec && y == yKoniec) {
        czyKoniec = true;
        return;
    }

    // Oznaczamy aktualną pozycję jako odwiedzoną ('*')
    lab[x][y] = '*';
    rysujLabirynt(); // Wyświetlamy labirynt po każdym kroku
    usleep(200000);  // Opóźnienie, aby zobaczyć każdy krok

    // Przechodzimy przez każdy możliwy ruch
    for (int i = 0; i < 4; i++) {
        int nowyX = x + tabRuchow[i][0];
        int nowyY = y + tabRuchow[i][1];

        // Sprawdzamy, czy nowa pozycja jest w granicach i możliwa do przejścia
        if (nowyX >= 0 && nowyX < n && nowyY >= 0 && nowyY < n && lab[nowyX][nowyY] == ' ') {
            szukajWyjscia(nowyX, nowyY); // Rekurencyjnie przechodzimy dalej

            // Jeśli znaleźliśmy wyjście, kończymy przeszukiwanie
            if (czyKoniec) return;
        }
    }

    // Jeśli nie znaleźliśmy wyjścia z tej pozycji, cofamy się
    lab[x][y] = ' ';
}

int main() {
    // Initialize the maze
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            lab[i][j] = (lab2[i][j] == 0) ? '#' : ' ';
        }
    }

    // Draw initial labyrinth state
    rysujLabirynt();
    cout << "\n\nEnter start x-coordinate (0-11): ";
    cin >> xStart;
    cout << "\nEnter start y-coordinate (0-11): ";
    cin >> yStart;
    lab[xStart][yStart] = 'S';

    cout << "\nEnter exit x-coordinate (0-11): ";
    cin >> xKoniec;
    cout << "\nEnter exit y-coordinate (0-11): ";
    cin >> yKoniec;
    lab[xKoniec][yKoniec] = 'E';

    // Draw labyrinth with start and end marked
    rysujLabirynt();
    cout << "\nSearching for exit...\n";
    usleep(1000000); // Wait for 1 second to simulate searching

    // Call the search function
    szukajWyjscia(xStart, yStart);

    // Display result
    if (czyKoniec) {
        cout << "\n\nPath to exit found!";
    } else {
        cout << "\n\nNo path to exit!";
    }
    cout << "\n\n";
    return 0;
}
