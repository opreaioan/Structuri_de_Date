/*Problema 8 - Magazine 
Se considera nr_mag magazine. Fiecare are un numar de produse.
Sa se verifice care magazin are cele mai multe produse exclusive (nu apar decât
în magazinul respectiv). Cititi dintr-un fisier în câte un vector de std::string
produsele pentru fiecare magazin. Afisati în final magazinul cu cele mai multe
produse exclusive si care sunt aceste produse.*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <unordered_map>

class Magazin {
public:
	std::string Nume;
	int nrProduse = 0;
	int produseUnice = 0;
	std::vector<std::string> Produse;
};

typedef std::unordered_map<std::string, int> Map_produse;
typedef std::vector<Magazin> Magazine;

void citireProduseMagazine(Magazine& magazine, int& nr_mag, Map_produse& produse);
int maxUnice(Magazine& magazine, Map_produse& produse);
void afisareMagazin(Magazin& magazin);
void afisareMagazine(std::vector<Magazin>& magazine);

int main() {
	Magazine magazine;
	Map_produse produse;
	int nr_mag;
	citireProduseMagazine(magazine, nr_mag, produse);
	int max = maxUnice(magazine, produse);
	if (max > 0) {
		std::cout << "Magazinul/magazinele cu cele mai multe produse unice este/sunt:\n";
		for (int i = 0; i < magazine.size(); i++)
			if (magazine[i].produseUnice == max)
				std::cout << magazine[i].Nume << " ";
	}
	else
		std::cout << "Nu exista magazine cu produse unice!";
	return 0;
}
void citireProduseMagazine(Magazine& magazine, int& nr_mag, Map_produse& produse) {
	std::ifstream f("Problema 08.txt");
	if (!f.is_open()) {
		std::cout << "Eroare la citire din fisier!";
		exit(1);
	}
	f >> nr_mag;
	while (!f.eof()) {
		Magazin magazin;
		f >> magazin.Nume >> magazin.nrProduse;
		for (int i = 0; i < magazin.nrProduse; i++) {
			std::string produs;
			f >> produs;
			produse[produs]++;
			magazin.Produse.push_back(produs);
		}
		magazine.push_back(magazin);
	}
}
int maxUnice(Magazine& magazine, Map_produse& produse) {
	int max_unice = 0;
	for (int i = 0; i < magazine.size(); i++) {
		for (auto el : magazine[i].Produse)
			if (produse[el] == 1)
				magazine[i].produseUnice++;
		if (magazine[i].produseUnice > max_unice)
			max_unice = magazine[i].produseUnice;
	}
	return max_unice;
}
void afisareMagazin(Magazin& magazin) {
	std::cout << magazin.Nume << " are " << magazin.nrProduse << " produse, dintre care " << magazin.produseUnice << " unice:\n";
	for (auto produs : magazin.Produse)
		std::cout << produs << " ";
	std::cout << "\n\n";
}
void afisareMagazine(std::vector<Magazin>& magazine) {
	for (int i = 0; i < magazine.size(); i++)
		afisareMagazin(magazine[i]);
}
