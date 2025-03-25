#include <iostream>
#include <iomanip>
#include <cmath>
#include <queue>

using namespace std;

//Definicja wezla
struct avlNode {
    int key{ 0 };
    int height{ 0 };
    avlNode* left{ nullptr };
    avlNode* right{nullptr};
};

// Funkcja licząca liczbę węzłów w drzewie
int countNodes(avlNode *node) {
    if (!node) return 0;
    return 1 + countNodes(node->left) + countNodes(node->right);
}

// Funkcja wyszukiwania klucza w drzewie AVL
bool searchAVL(avlNode* root, int key, int& comparisons) {
    avlNode* current = root;
    comparisons = 0;

    while (current != nullptr) {
        comparisons++;
        if (key == current->key)
            return true;
        else if (key < current->key)
            current = current->left;
        else
            current = current->right;
    }

    return false;
}

// Funkcja testująca wyszukiwanie kluczy i obliczająca średni udział sprawdzonych węzłów
void testSearchAVL(avlNode* root, int keys[], int numKeys) {
    int totalNodes = countNodes(root);
    cout << "\nLiczba węzłów w drzewie: " << totalNodes << endl;

    for (int i = 0; i < numKeys; i++) {
        int comparisons = 0;
        bool found = searchAVL(root, keys[i], comparisons);
        double percentage = (double)comparisons / totalNodes * 100;

        cout << "Klucz " << keys[i] << (found ? " znaleziony" : " NIE znaleziony")
             << " | Porównań: " << comparisons
             << " | Sprawdzono " << fixed << setprecision(2) << percentage << "% węzłów\n";
    }
}

//procedura obliczania wysokosci drzewa
int calculateHeight(avlNode* node)
{
    static int height = 0;
    if (node != nullptr)
    {
        int hl = calculateHeight(node->left);
        int hr = calculateHeight(node->right);
        if (hl > hr) height = hl + 1;
        else height = hr + 1;
    }
    else height = 0;
    return height;
}

//procedura odczytania wysokosci dla wskazanego wezla drzewa
int getNodeHeight(avlNode* node) {
    if (node == nullptr) return 0;
    else return node->height;
}

//procedura obrotu w lewo
avlNode* LeftRotate(avlNode* node) //node->węzeł sprawdzony różnicą wysokości = 2
{
    avlNode* nodeUp = node->right; //nodeUp->przesunięty na miejsce węzła node
    node->right = nodeUp->left;
    nodeUp->left = node;
    //wysokości uaktualniane od niższego poziomu, najpierw node, potem nodeUp
    node->height = max(getNodeHeight(node->left),getNodeHeight(node->right))+1;
    nodeUp->height =
   max(getNodeHeight(nodeUp->left),getNodeHeight(nodeUp->right)) + 1;
    return nodeUp;
}

//procedura obrotu w prawo
avlNode* RightRotate(avlNode* node)
{
    avlNode* nodeUp = node->left;
    node->left = nodeUp->right;
    nodeUp->right = node;
    node->height = max(getNodeHeight(node->left),getNodeHeight(node->right)) + 1;
    nodeUp->height =
   max(getNodeHeight(nodeUp->left), getNodeHeight(nodeUp->right)) + 1;
    return nodeUp;
}

//rownowazenie drzewa
avlNode* balanceAVL(avlNode* node)
{
    int hl = getNodeHeight(node->left);
    int hr = getNodeHeight(node->right);
    if (hl - hr == 2) //left wyższe -> obrót w prawo
    {
        int hll = getNodeHeight(node->left->left);
        int hlr = getNodeHeight(node->left->right);
        // jeżeli prawe poddrzewo lewego wyższe przed obrotem w prawo
        if (hll - hlr == -1) node->left = LeftRotate(node->left); //obrót dodatkowy
        node = RightRotate(node); //obrót główny
    }
    else if (hl - hr == -2) //prawe wyższe -> obrót w lewo
    {
        int hrl = getNodeHeight(node->right->left);
        int hrr = getNodeHeight(node->right->right);
        // jeżeli lewe poddrzewo prawego wyższe przed obrotem w lewo
        if (hrr-hrl == -1) node->right = RightRotate(node->right); //obrót dodatkowy
        node = LeftRotate(node);
    }
    return node;
}

//procedura wstawiania wezlow
avlNode* insertAVL(int keyValue, avlNode* node)
{
    if (node == nullptr)
    {
        cout << "\n\n wstawianie klucza: " << keyValue << endl;
        node = new avlNode;
        node->key = keyValue;
        node->left = nullptr;
        node->right = nullptr;
    }
    else if(keyValue == node->key) return node; //węzeł już istnieje w drzewie
    else if(keyValue < node->key) {node->left = insertAVL(keyValue, node->left);}
    else { node->right = insertAVL(keyValue, node->right); }
    node->height = max(getNodeHeight(node->left),getNodeHeight(node->right)) + 1;
    //aktualizacja rekurencyjna całej ścieżki wstawiania
    node = balanceAVL(node); // balans dla każdego na ścieżce wstawiania
    return node;
}

//procedura wyswietlania drzewa
void printTree(avlNode* node)
{
    if (node == nullptr) { cout << "\n drzewo jest puste...\n"; return; }
    queue<avlNode*> q{}; //kolejka węzłów do wyświetlenia
    q.push(node);
    int height = calculateHeight(node); //wysokość drzewa
    int level=1; //level korzenia = 1
    int printedNodesNumber = 0;
    int distanceToNode = pow(2, height - level)-1;//odstęp do 1. węzła w poziomie
    int nodesInLevel = 1; // maksymalna liczba węzłów w poziomie, dla korzenia = 1
    cout << " ";
    while (level <= height)
    {
        node = q.front(); //pobranie węzła z kolejki
        q.pop(); //usunięcie węzła z kolejki
        for (size_t i = 0; i < distanceToNode; ++i) cout << " ";
        if (node != nullptr) {
            cout << setw(2) << node->key; //wyświetleniw węzła
            q.push(node->left); q.push(node->right); //dodanie dzieci do kolejki
        }
        else {
            cout << "__"; //wyświetlenie pustego węzła
            q.push(node); q.push(node); //dodanie pustych dzieci do kolejki
        }
        ++printedNodesNumber;
        if (printedNodesNumber == nodesInLevel) {
            cout << "\n"<<" ";
            ++level;
            printedNodesNumber = 0;
            nodesInLevel = pow(2, level - 1);
            distanceToNode = pow(2, height - level) - 1;
        }
        else if (printedNodesNumber == 1) distanceToNode = distanceToNode * 2 + 1;
    }
    while (q.size()) q.pop(); //usuwanie pozostałych pustych węzłów z kolejki
}

//procedura inicjowania wstawiania wezlod do drzewa
avlNode* buildAVL(int n, avlNode* node, int* t)
{
    for (int i = 0; i < n; i++)
    {
        //cout << "wpisz wartosc: "; int keyValue; cin >> keyValue;
        //node = insertAVL(keyValue, node);
        node = insertAVL(t[i], node);
        cout << "\n\n drzewo po wstawieniu: " << endl;
        printTree(node);
    }
    return node;
}

int main() {
    int t[]={ 8, 10, 5, 6, 1, 7, 3, 9, 4, 2 }; // tablica elementów wstawianych do drzewa
    int n = 10 ; // liczba wstawianych elementów
    avlNode* avlRoot = nullptr; //wskaźnik do drzewa
    avlRoot = buildAVL(n, avlRoot, t); //inicjowanie wstawiania do drzewa
    cout << "\n\n AVL: \n";
    printTree(avlRoot); //wyświetlanie drzewa


    // Klucze do przetestowania wyszukiwania
    int keysToSearch[] = { 11, 4, 13, 22 };
    int numSearchKeys = sizeof(keysToSearch) / sizeof(keysToSearch[0]);

    // Testowanie wyszukiwania
    testSearchAVL(avlRoot, keysToSearch, numSearchKeys);
    return 0;
}