// Problema 1
// Numim perechea(x, y) pereche ordonata daca x < y.
// (a)Sa se verifice daca un vector contine doar perechi ordonate(care satisfact conditia de mai sus) (0.5p).
// (b)Sa se verifice daca oricare x din prima jumatate a vectorul formeaza o pereche ordonata cu oricare y din cea de - a doua jumatate.(1p)

#include <iostream>

void citire_vector(int*& a, int& x)
{
	std::cout << "Introduceti nr. de elemente: " << std::endl;
	std::cin >> x;
	a = new int[x];
	std::cout << "Introduceti elementele vectorului: " << std::endl;
	for (int i = 0; i < x; i++)
		std::cin >> a[i];
}

bool testare_perechi_ordonate(int* a, int x)
{
	bool ok = 1;
	for (int i = 0; i < x - 1; i++)
		if (a[i] >= a[i + 1])
			ok = 0;
	return ok;
}

bool x_FH_perord_y_SH(int* a, int x)
{
	bool ok = 1;
	for (int i = 0; i < x / 2; i++)
		for (int j = x / 2; j < x; j++)
		{
			if (a[i] >= a[j])
				ok = 0;
		}
	return ok;
}

int main()
{
	int* v, n;
	citire_vector(v, n);
	if (testare_perechi_ordonate(v, n))
	{
		std::cout << "Vectorul contine doar perechi ordonate si se pot forma perechi ordonate intre" << std::endl;
		std::cout << "oricare x din prima jumatate si oricare y din a doua jumatate a vectorului." << std::endl;
	}
	else
	{
		if (x_FH_perord_y_SH(v, n))
		{
			std::cout << "Vectorul nu contine doar perechi ordonate dar se pot forma perechi ordonate intre" << std::endl;
			std::cout << " oricare x din prima jumatate si oricare y din a doua jumatate a vectorului." << std::endl;
		}
		else
		{
			std::cout << "Vectorul nu contine doar perechi ordonate si nici nu se pot forma perechi ordonate intre" << std::endl;
			std::cout << "oricare x din prima jumatate si oricare y din a doua jumatate a vectorului." << std::endl;
		}
	}
	delete[] v;
	return 0;
}
