#include <iostream>
#include <vector>
#include <random>
#include <iomanip>
#include <algorithm>>

using namespace std;

vector<int> w1{};

void elementyWektora(vector<int> v)
{
    cout << "\n aktualny rozmiar wektora: " << v.size() << endl;
    for (const auto& e : v) cout << e << " "; // od C++11;
}

vector<int> najmniejsze(vector<vector<int>> w)
{
    vector<int> vmin{};
    for (int i = 0; i < w.size(); ++i)
        vmin.push_back(*(min_element(w[i].begin(), w[i].end())));
    return vmin;
}

vector<int> parzyste(vector<vector<int>> w) {
    vector<int> vparz{};

    for (int i = 0; i < w.size(); i++) {

        for (int j = 0; j < w[i].size(); j++) {
            if (w[i][j] % 2 == 0) {
                vparz.push_back(w[i][j]);
            }
        }
    }
    return vparz;
}

// vector<vector<int>> usunNajm(vector<vector<int>> w) {
//     vector<vector<int>> wPoUsun{};
//
//     for (int i = 0; i < w.size(); i++) {
//         w.erase(*min_element(w[i].begin(), w[i].end()));
//     }
//     wPoUsun = w;
//     return wPoUsun;
// }

vector<vector<int>> usunNajm(vector<vector<int>> w) {
    for (int i = 0; i < w.size(); i++) {
        if (!w[i].empty()) { // Sprawdź, czy wektor nie jest pusty
            auto minIt = min_element(w[i].begin(), w[i].end()); // Znajdź iterator do najmniejszego elementu
            w[i].erase(minIt); // Usuń najmniejszy element
        }
    }
    return w;
}

int main () {

    int n1, n2, n3;
    n1 = 0;
    n2 = 1;
    w1.push_back(n1); w1.push_back(n2);
    for (int i = 1; i <= 14; i++)
    {
        n3 = n1 + n2;
        w1.push_back(n3);
        n1 = n2;
        n2 = n3;
    }

    w1.pop_back();

    w1.at(0) = 24;
    w1[1] = 23;
    auto it = w1.begin();
    *(it + 2) = 22;

    elementyWektora(w1);
    cout<<"\n capacity="<<w1.capacity()<<endl;

    cout << "\n" << *w1.begin();
    cout << "\n" << *(w1.end() - 1);

    random_device rd;
    uniform_int_distribution<int> ud(50, 70);
    it = w1.begin() + 4;
    for (int i = 1; i <= 3; i++) {
        it = w1.insert(it, ud(rd));
        cout << "\n wstawiono: " << *it;
        ++it;
    }
    cout << "\n wektor w po wstawieniu trzech elementów: ";
    elementyWektora(w1);

    vector<int> w2(w1);

    w2.resize(6);

    vector<int> w3;
    w3 = w1;

    auto it3 = w3.begin();
    w3.erase(it3 + 3, it3 + 6);
    it3 = w3.begin();
    w3.erase(it3);
    cout << "\n w3 po usunięciu elementów: 1, 3-5: ";
    elementyWektora(w3);


    vector<vector<int>> ww;
    ww.push_back(w1);
    ww.push_back(w2);
    ww.push_back(w3);
    ww.push_back({ 1, 2, 3, 4 });
    for (int i = 0; i<ww.size(); i++)
    {
        cout << "\n";
        for (int j = 0; j < ww[i].size(); j++)
            cout << setw(3) << ww[i][j];
    }

    vector<int> wmin = najmniejsze(ww);
    cout << "\n wektor najmniejszych wartości z ww:";
    elementyWektora(wmin);

    sort(w1.begin(), w1.end(), [](int a, int b){ return a > b; });
    elementyWektora(w1);

    w2.clear();
    cout << "\n wektor w2 po użyciu metody clear(): ";
    elementyWektora(w2);

    cout << "\n czy w2 pusty? " << boolalpha << w2.empty() << endl;

    vector<int> wparz = parzyste(ww);
    cout << "\n wektor parzystych wartosci z ww: ";
    elementyWektora(wparz);

    vector<vector<int>> ww2;
    ww2 = ww;
    for (int i = 0; i<ww.size(); i++)
    {
        cout << "\n";
        for (int j = 0; j < ww[i].size(); j++)
            cout << setw(3) << ww[i][j];
    }

    vector<vector<int>> wPoUsun = usunNajm(ww);
    cout << "\n wektor wPoUsun z ww: ";
    for (int i = 0; i < wPoUsun.size(); i++) {
        cout << "\n";
        for (int j = 0; j < wPoUsun[i].size(); j++) {
            cout << setw(3) << wPoUsun[i][j];
        }
    }

    return 0;
}
