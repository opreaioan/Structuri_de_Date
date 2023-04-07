/*Implementare tabela de dispersie - liste înlantuite. Construiti o clasa HashTable (sau HashMap) potrivita , care sa includa operatiile de insertie, cautare si stergere. Elementele stocate vor fi de tip (cheie, valoare). Folositi pair din stl. Rezolvarea coliziunilor se va realiza prin liste înlantuite (folositi std::list). Daca factorul de încarcare al tabelei depaseste 1.0, se cere redimensionarea tabelei (aproximativ dublul dimensiunii initiale) si redistribuirea elementelor în noua tabela (rehashing). În functia main cititi dintr-un fisier
n elemente de tip pereche (cheie-valoare) (n>20), repartizati elementele în tabel , apoi permiteti cautarea, adaugarea sau stergerea de elemente (meniu). De asemenea permiteti parcurgerea si afisarea perechilor < cheie; valoare > pentru toate elementele din tabel . (3p).
Punctaj suplimentar - pentru implementarea unei funcµii de hashig pentru siruri de caractere - 0.5p*/
#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <string>
#include <stdexcept>
#include <conio.h>

class HashTable
{
private:
	std::vector<std::list<std::pair<int, int>>> tabela;
	int Size = 0;
	int Capacity = 0;
public:

	HashTable(int n) {
		tabela = std::vector<std::list<std::pair<int, int>>>(n, std::list<std::pair<int, int>>());
		Capacity = n;
	}
	float loadFactor();
	int funcHash(int cheie);
	void reHash();
	bool cautaElem(int cheie);
	void adaugaElem(int cheie, int valoare);
	void stergeElem(int cheie);
	void print();
};
void meniu();

int main()
{
	std::ifstream f("hashtablePb1.txt");
	int n, first, second, opt;
	std::string optiune;
	f >> n;
	HashTable x(n);
	for (int i = 0; i < n; i++)
	{
		f >> first, f >> second;
		first = abs(first);
		x.adaugaElem(first, second);
	}
	f.close();
	meniu();
	do {
		std::cout << "Optiune: ";
		std::cin >> optiune;
		try {
			opt = std::stoi(optiune);
		}
		catch (const std::invalid_argument& ia) {
			std::cerr << "Optiune invalida." << "\n";
			opt = -1;
			system("cls");
			meniu();
			continue;
		}
		switch (opt) {
		case 1: {
			std::cout << "Introduceti cheia de cautat: "; int cheie;
			std::cin >> cheie;
			if (x.cautaElem(cheie)) std::cout << "Gasita!" << "\n";
			else std::cout << "Cheie invalida sau inexistenta!" << "\n";
			break;
		}
		case 2: {
			std::cout << "Introduceti cheia si valoarea de adaugat: "; int cheie, valoare;
			std::cin >> cheie >> valoare;
			if (!x.cautaElem(cheie) && cheie >= 0)
				x.adaugaElem(cheie, valoare);
			else std::cout << "Cheie invalida sau deja existenta!" << "\n";
			break;
		}
		case 3: {
			std::cout << "Introduceti cheia de sters: "; int cheie;
			std::cin >> cheie;
			if (x.cautaElem(cheie) && cheie >= 0)
				x.stergeElem(cheie);
			else std::cout << "Cheie invalida sau inexistenta!" << "\n";
			break;
		}
		case 4: {
			x.print();
			break;
		}
		}
		std::cout << "Apasati orice tasta pentru a continua..." << "\n";
		_getch();
		system("cls");
		meniu();
	} while (opt != 0);
	return 0;
}

float HashTable::loadFactor() {
	return (float)Size / Capacity;
}
int HashTable::funcHash(int cheie) {
	return cheie % Capacity;
}
void HashTable::reHash() {
	int newCap = Capacity * 2;
	std::vector<std::list<std::pair<int, int>>> tabelaNoua(newCap, std::list<std::pair<int, int>>());
	for (int i = 0; i < Capacity; i++)
		for (auto element : tabela[i]) {
			int pozNoua = element.first % newCap;
			tabelaNoua[pozNoua].push_back(std::make_pair(element.first, element.second));
		}
	Capacity = newCap;
	tabela = tabelaNoua;
	tabelaNoua.clear();
}
bool HashTable::cautaElem(int cheie) {
	if (cheie >= 0) {
		int pozitie = funcHash(cheie);
		for (auto elem : tabela[pozitie])
			if (elem.first == cheie)
				return 1;
	}
	return 0;
}
void HashTable::adaugaElem(int cheie, int valoare) {
	int pozitie = funcHash(cheie);
	tabela[pozitie].push_back(std::make_pair(cheie, valoare));
	++Size;
	if (loadFactor() > 1)
		reHash();
}
void HashTable::stergeElem(int cheie) {
	int pozitie = funcHash(cheie);
	int initSize = tabela[pozitie].size();
	if (!tabela[pozitie].empty()) {
		tabela[pozitie].remove_if([=](const std::pair<int, int>& p) {
			return p.first == cheie;
			});
	}
	if (initSize > tabela[pozitie].size()) Size--;
}
void HashTable::print() {
	for (int i = 0; i < Capacity; i++) {
		std::cout << "[" << i << "]";
		for (auto element : tabela[i]) {
			std::cout << "->(" << element.first << "," << element.second << ")";
		}
		std::cout << std::endl;
	}
}
void meniu() {
	std::cout << "1 Cauta element" << "\n";
	std::cout << "2 Adauga element" << "\n";
	std::cout << "3 Sterge element" << "\n";
	std::cout << "4 Afiseaza hashtable" << "\n";
	std::cout << "0 Iesire" << "\n";
}
