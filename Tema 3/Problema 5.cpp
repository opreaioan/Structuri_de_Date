#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

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
	std::ifstream f("NrNumerePb5.txt");
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
	for (int i = 0; i < Numere.size(); i++) {
		sum += Numere[i];
		int rest = sum - k;
		auto it = pozitiiSume.find(rest);
		if (it != pozitiiSume.end()) {
			for (auto& j : it->second) {
				std::cout << "(" << j + 1 << "," << i << ") ";
			}
		}
		pozitiiSume[sum].push_back(i);
	}
	std::cout << "\n";
	for (auto& it : pozitiiSume)
	{
		std::cout << "pozitiiSume[" << it.first << "]= ";
		std::cout << "{";
		std::vector<int>& indiciNumere = it.second;
		for (int i = 0; i < indiciNumere.size(); i++)
		{
			std::cout << indiciNumere[i];
			if (i < indiciNumere.size() - 1)
				std::cout << ",";

		}

		std::cout << "}\n";
	}
}
