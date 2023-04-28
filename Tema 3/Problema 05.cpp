/* Problema 5
Scrieti un program care citeste Nr elemente numere
naturale dintr-un fisier si le plaseaza intr-un vector Numere. Avand
acest vector, se permit oricate citiri a unei valori k (intr-un do-while). Pentru
fiecare k se afiseaza toate perechile de indici (start; stop) (start<= stop) pentru
care subsirul Numere[start] + Numere[start + 1] + . . . + Numere[stop] = k.
Rezolvati problema in mod eficient, folosind unordered_map. (1.5p) */

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <iomanip>

typedef std::vector<int> vector;
typedef std::unordered_map<int, std::vector<int>> unomap;

void citireDate(vector& Numere);
void gasesteSecventeSuma(int k, vector& Numere);

int main() {
	vector Numere;
	int k;
	citireDate(Numere);
	std::cout << "Introduceti k. Pentru iesire introduceti \"0\"\n";
	do {
		std::cin >> k;
		gasesteSecventeSuma(k, Numere);
	} while (k != 0);

	return 0;
}

void citireDate(vector& Numere) {
	std::ifstream f("Problema 05.txt");
	int nr, Nr = 0;
	if (!f >> Nr) {
		std::cout << "Eroare la deschidere sau citire din fisier!";
		exit(1);
	}
	f >> Nr;
	while (f >> nr && Numere.size() < Nr)
		Numere.push_back(nr);
	if (Numere.size() < (Nr)) std::cout << "Atentie: nu s-au putut citi \"Nr\" numere din fisier!\nAdaugati inca " << Nr - Numere.size() << " numere.\n";
	f.close();
}
void gasesteSecventeSuma(int k, vector& Numere) {
	unomap pozitiiSume;
	pozitiiSume[0].push_back(-1);
	int sum = 0;
	int contorPrint = 0;
	for (int i = 0; i < Numere.size(); i++) {
		sum += Numere[i];
		int rest = sum - k;
		auto it = pozitiiSume.find(rest);
		if (it != pozitiiSume.end()) {
			for (auto& j : it->second) {
				std::cout << std::right << "(" << std::setw(2) << j + 1 << "," << std::setw(2) << i << ") ";
				contorPrint += 1;
				if (contorPrint > 10) {
					std::cout << "\n";
					contorPrint = 0;
				}
			}
		}
		pozitiiSume[sum].push_back(i);
	}
	std::cout << "\n\n";
	for (auto& it : pozitiiSume) {
		std::cout << "pozitiiSume[" << it.first << "]= ";
		std::cout << "{";
		std::vector<int>& indiciNumere = it.second;
		for (int i = 0; i < indiciNumere.size(); i++) {
			std::cout << indiciNumere[i];
			if (i < indiciNumere.size() - 1)
				std::cout << ",";
		}
		std::cout << "}\n";
	}
}
