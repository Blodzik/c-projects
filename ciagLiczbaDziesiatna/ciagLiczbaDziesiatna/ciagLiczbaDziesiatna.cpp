#include <iostream>
#include <random>
#include <string>
#include <cmath>

using namespace std;

int main (){
	random_device rd{};
	uniform_int_distribution<> ud(0, 1);
	const int r = 8;
	int bit;
	int liczba10{};

	for (int i = 0; i < r; i++) {
		bit = ud(rd);
		cout << bit;
		liczba10 += bit * pow(2, r - 1 - i);
	}

	cout << "\nliczba10=" << liczba10 << endl;
}