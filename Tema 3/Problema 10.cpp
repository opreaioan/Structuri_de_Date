/*Problema 10 – Aruncarea zarurilor.
Se considera 3 zaruri care sunt aruncate de un numar N de ori.
Practic pentru fiecare aruncare se genereaza 3 numere aleatoare
în multimea {1,…,6}. Pentru fiecare triplet de numere (n1, n2, n3),
ni Є (1,6) citit de la tastatura sa se indice de câte ori a fost
aruncat tripletul. Atentie permutari ale aceluiasi triplet nu
trebuie considerate separat. (2p)*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

typedef std::unordered_map<unsigned short, unsigned short> aruncate;
typedef std::vector<unsigned short> Zaruri;

int Aruncat(Zaruri& zaruri, aruncate& Aruncate);

int main() {
	aruncate Aruncate;
	Zaruri zaruri;
	unsigned short N, zar1, zar2, zar3;
	std::cout << "Introduceti numarul de aruncari: ";
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> zar1 >> zar2 >> zar3;
		zaruri.push_back(zar1);
		zaruri.push_back(zar2);
		zaruri.push_back(zar3);
		std::sort(zaruri.begin(), zaruri.end());
		std::cout << "Combinatia {" << zar1 << "," << zar2;
		std::cout << "," << zar3 << "} a fost aruncata de ";
		std::cout << Aruncat(zaruri, Aruncate) << " ori anterior\n";
		zaruri.clear();
	}
	return 0;
}

int Aruncat(Zaruri& zaruri, aruncate& Aruncate) {
	int key = zaruri[0];
	for (int i = 1; i < 2; i++)
		key += zaruri[i] * 10;
	return Aruncate[key]++;
}
