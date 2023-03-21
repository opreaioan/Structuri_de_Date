// Problema 7 Varianta 2:
// Se citesc dintr-un fisier un numar de elevi. Fiecare elev are un nume, un prenume si 3
// note, numere naturale. Se va folosi pentru un elev un tuple cu campurile nume si prenume
// de tip string si cu trei campuri de note de tip int. Elevii vor fi memorati intr-un 
// obiect de tip std::vector<std::tuple<std::string, std::string, int, int, int> >. Sa se
// sorteze vectorul de elevi descrescator dupa medie si sa se afiseze frumos, punand in 
// evidenta elevii cu note mai mici decat 5. (2p)

#include <iostream>
#include <vector>
#include <fstream>
#include <tuple>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>

struct elev
{
	std::string sNume, sPrenume;
	int sNota1, sNota2, sNota3;
};

void citireElevi(std::vector<std::tuple <elev>>& elevi);
float medie(int nota1, int nota2, int nota3);
bool cmp_des(std::tuple <elev> a, std::tuple <elev> b);
void afisareElevi(std::vector<std::tuple <elev>> elevi);

int main()
{
	std::vector<std::tuple <elev>> elevi;
	citireElevi(elevi);
	afisareElevi(elevi);
	return 0;
}

void citireElevi(std::vector < std::tuple <elev>>& elevi)
{
	std::string nume, prenume, linie;
	int nota1, nota2, nota3;
	std::ifstream f("fisierEleviPb7.txt");

	while (std::getline(f, linie))
	{
		std::stringstream ss(linie);
		ss >> nume >> prenume >> nota1 >> nota2 >> nota3;

		elevi.push_back(std::make_tuple(elev{ nume,prenume,nota1,nota2,nota3 }));
	}
	f.close();
}

bool cmp_des(std::tuple <elev> a, std::tuple <elev> b)
{
	const auto& c1 = std::get<0>(a);
	const auto& c2 = std::get<0>(b);
	return medie(c1.sNota1, c1.sNota2, c1.sNota3) > medie(c2.sNota1, c2.sNota2, c2.sNota3);
}

void afisareElevi(std::vector<std::tuple <elev>> elevi)
{
	std::sort(elevi.begin(), elevi.end(), cmp_des);
	for (auto i : elevi)
	{
		const auto& c = std::get<0>(i);
		std::cout << std::left << std::setw(10) << c.sNume << std::setw(10) << c.sPrenume;
		std::cout << std::right << c.sNota1 << std::setw(5) << c.sNota2;
		std::cout << std::setw(5) << c.sNota3;
		if (c.sNota1 < 5 || c.sNota2 < 5 || c.sNota3 < 5)
			std::cout << "     acest elev are si note mai mici decat 5.";
		std::cout << "" << std::endl;
	}
}

float medie(int nota1, int nota2, int nota3)
{
	float med = 0;
	med += nota1 + nota2 + nota3;
	return med / 3;
}
