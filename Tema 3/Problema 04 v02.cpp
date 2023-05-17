/* Problema 4
Se considera  un numar de competitii sportive la care s-au inscris
concurenti. Pentru fiecare competitie exista o lista cu numele si prenumele
concurentilor (pereche de valori de tip std::string). Aceste liste se citesc dintr-un
fisier. Sa se scrie o functie care indica persoanele care participa la mai mult
de o singura competitie. */

#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>
#include <sstream>

typedef std::unordered_map<std::string, int> map;

void citireSiruri(std::string s, map& aparitiiCompetitii);
void competitiv(const map& ac);

int main()
{
	map ac;
	std::string fisier_liste = "Problema 04.txt";
	citireSiruri(fisier_liste, ac);
	competitiv(ac);
}

void citireSiruri(std::string s, map& aparitiiCompetitii) {

	std::ifstream f(s);
	std::string nume, prenume, linie;
	while (!f.eof()) {
		std::getline(f, linie);
		std::stringstream ss(linie);
		if (!(ss >> nume >> prenume)) continue;
		aparitiiCompetitii[nume + " " + prenume]++;
	}
	f.close();
}
void competitiv(const map& ac) {
	std::cout << "Au participat la mai multe competitii:" << "\n";
	for (auto it = ac.begin(); it != ac.end(); it++)
		if (it->second > 1)
			std::cout << it->first << "\n";
}
