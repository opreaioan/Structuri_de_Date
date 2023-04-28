// Problema 5
// Un numar de baza b este retinut într-un std:pair<int, int> ce contine valoarea
// si baza de numeratie în care acesta este reprezentat.Se citesc mai multe
// astfel de numere reprezentate în baze diferite. Sa se determine perechile de
// valori egale.(1.5p)

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

void citire_vector(std::vector<std::pair<int, int>>& v)
{
	int n;
	int numar, baza;
	std::cout << "Cate numere doriti sa introduceti ?" << std::endl;
	std::cin >> n;
	std::cout << "Introduceti numarul si baza separate de spatiu apoi \"Enter\" pentru confirmare." << std::endl;
		for (int i = 0; i < n; i++)
		{
			std::cin >> numar >> baza;
			v.push_back(std::make_pair(numar, baza));
		}
}

int conversie_b10(int numar, int baza)
{
	int putere = 0, zecimal = 0;
	if (baza == 10) return numar;
	else
	{
		bool este_neg = false;
		if (numar < 0)
		{
			numar = abs(numar);
			este_neg = true;
		}
		while (numar > 0)
		{
			int aux = numar % 10;
			zecimal += aux * pow(baza, putere);
			putere++;
			numar /= 10;
		}
		if (este_neg) return (zecimal * (-1));
		else return zecimal;
	}
}

int main()
{
	std::vector<std::pair<int, int>> nr_baza;
	std::vector<int> nr_baza_10;
	std::vector<int> aparitii;
	citire_vector(nr_baza);
	for (int i = 0; i < nr_baza.size(); i++)
	{
		nr_baza_10.push_back(conversie_b10(nr_baza[i].first, nr_baza[i].second));
	}
	int j = 0;
	while (j < nr_baza_10.size())
	{
		if ((std::count(nr_baza_10.begin(), nr_baza_10.end(), nr_baza_10[j]) > 1) && (std::count(aparitii.begin(), aparitii.end(), nr_baza_10[j]) == 0))
		{
			aparitii.push_back(nr_baza_10[j]);
			std::cout << "Avem urmatorul set de perechi egale:" << std::endl;
			std::cout << "(" << nr_baza[j].first << "," << nr_baza[j].second << ")"
				<< " ";
			for (int i = j + 1; i < nr_baza_10.size(); i++)
				if (nr_baza_10[j] == nr_baza_10[i])
					std::cout << "(" << nr_baza[i].first << "," <<
					nr_baza[i].second << ")" << " ";
		}
		j++;
	}
	return 0;
}
