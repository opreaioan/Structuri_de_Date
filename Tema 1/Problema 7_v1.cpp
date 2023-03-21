// Problema 7 Varianta 1:
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

void citireElevi(std::vector<std::tuple <std::string, std::string, int, int, int>>& elevi);
float medie(int nota1, int nota2, int nota3);
bool cmp_des(std::tuple <std::string, std::string, int, int, int> a, std::tuple <std::string, std::string, int, int, int> b);
void afisareElevi(std::vector<std::tuple <std::string, std::string, int, int, int>> elevi);

int main()
{
	std::vector<std::tuple <std::string, std::string, int, int, int>> elevi;
	citireElevi(elevi);
	afisareElevi(elevi);
	return 0;
}

void citireElevi(std::vector<std::tuple <std::string, std::string, int, int, int>>& elevi)
{
	std::string nume, prenume, linie;

	int nota1, nota2, nota3;
	std::ifstream f("fisierEleviPb7.txt");

	while (std::getline(f, linie))
	{
		std::stringstream ss(linie);
		ss >> nume >> prenume >> nota1 >> nota2 >> nota3;
		elevi.emplace_back(nume, prenume, nota1, nota2, nota3);
	}
	f.close();
}

void afisareElevi(std::vector<std::tuple <std::string, std::string, int, int, int>> elevi)
{
	std::sort(elevi.begin(), elevi.end(), cmp_des);
	for (auto i : elevi)
	{
		std::cout << std::left << std::setw(10) << std::get<0>(i) << std::setw(10) << std::get<1>(i);
		std::cout << std::right<< std::get<2>(i) << std::setw(5) << std::get<3>(i);
		std::cout << std::setw(5) << std::get<4>(i);
		if (std::get<2>(i) < 5 || std::get<3>(i) < 5 || std::get<4>(i) < 5)
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

bool cmp_des(std::tuple <std::string, std::string, int, int, int> a, std::tuple <std::string, std::string, int, int, int> b)
{
	return medie(std::get<2>(a), std::get<3>(a), std::get<4>(a)) > medie(std::get<2>(b), std::get<3>(b), std::get<4>(b));
}
