// Problema 6
// Se considera un vector de n puncte. Fiecare punct este un element de tipul
// unei structuri cu doua campuri, reprezentand coordonatele spatiale (x; y).
// Sa se afiseze perechile de 4 puncte care pot forma un dreptunghi. Daca nu exista 
// astfel de pereche se va afisa un mesaj corespunzator (2p)
	
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdio>

struct punct
{
	int x, y;
};

void citire_vector(std::vector<punct>& a, int& n)
{
	punct c;
	std::cout << "Introduceti numarul de puncte: " << std::endl;
	std::cin >> n;
	std::cout << "Introduceti coordonatele punctelor: " << std::endl;
	for (int i = 0; i < n; i++)
	{
		std::cin >> c.x >> c.y;
		a.push_back(c);
	}
}

double distanta(punct A, punct B)
{
	double dist = std::sqrt(std::pow(A.x - B.x, 2) + std::pow(A.y - B.y, 2));
	return dist;
}

bool dreptunghi(punct A, punct B, punct C, punct D)
{
	return distanta(A, B) == distanta(C, D) && distanta(A, D) == distanta(B, C) && distanta(A, C) == distanta(B, D);
}

int main()
{
	std::vector<punct> v;
	int n, i, j, k, l;
	int optiune;
	std::cout << "Pentru citirea vectorului de la tastatura introduceti \"1\":" << "\n";
	optiune = getchar();
	
	if (optiune == 49)
		citire_vector(v, n);
	else
		v = { {2,8}, {2,6}, {4,12}, {4,2}, {16,6}, {14,2}, {14,12}, {16,8} };

	if (v.size() > 3)
	{
		for (i = 0; i < v.size() - 3; i++)
			for (j = i + 1; j < v.size() - 2; j++)
				for (k = j + 1; k < v.size() - 1; k++)
					for (l = k + 1; l < v.size(); l++)

						if (dreptunghi(v[i], v[j], v[k], v[l]))
						{
							std::cout << "Perechea de puncte " << "(" << v[i].x << "," << v[i].y << ") " << "(" << v[j].x << "," << v[j].y << ") ";
							std::cout << "(" << v[k].x << "," << v[k].y << ") " << "(" << v[l].x << "," << v[l].y << ") ";
							std::cout << "formeaza un dreptunghi." << std::endl;
						}
	}
	else std::cout << "S-a introdus un numar de puncte invalid pentru a forma un dreptunghi.";

	return 0;
}
