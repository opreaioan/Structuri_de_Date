// Problema 9
// Se considera o matrice matr cu nrows linii si ncols coloane, cu ncols < 10, ale
// carei elemente sunt numere naturale formate dintr - o singura cifra.Se considera 
// ca fiecare coloana col reprezinta un numar in baza col + 2. Sa se scrie o functie
// care plaseaza numerele transformate in baza zece intr - un vector numbers si
// returneaz true, daca matricea a fost valida si false altfel. In cazul in care
// matricea a fost valida sa se afiseze acest vector de numere. Matricea este valida 
// daca toate elementele de pe coloana col sunt numere naturale din intervalul
// [0; col + 1). (2p)

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

void citireMatrice(int**& a, int& nrows, int& ncols);
int convB10(int numar, int baza);
bool prelucrare(int** a, const int nrows, const int ncols, std::vector<int>& numbers);
void afisareMatrice(int** a, int nrows, int ncols);
void afisareVector(std::vector<int> v);

int main()
{
	int** matr, nrows, ncols;
	std::vector<int> numbers;
	citireMatrice(matr, nrows, ncols);

	if (prelucrare(matr, nrows, ncols, numbers))
	{
		std::cout << "\n";
		std::cout << "Matricea este valida." << "\n\n";
		afisareMatrice(matr, nrows, ncols);
		std::cout << "\n";
		std::cout << "numbers = {";
		afisareVector(numbers);
		std::cout << "}" << "\n\n";
	}
	else
		std::cout << "Matricea nu este valida.";

	for (int i = 0; i < nrows; i++)
		delete[] matr[i];
	delete[]matr;

}

void citireMatrice(int**& a, int& nrows, int& ncols)
{
	std::ifstream f("matrice.txt");
	f >> nrows >> ncols;
	a = new int* [nrows];
	for (int i = 0; i < nrows; i++)
		a[i] = new int[ncols];

	for (int i = 0; i < nrows; i++)
		for (int j = 0; j < ncols; j++)
			f >> a[i][j];
	f.close();
}

int convB10(int numar, int baza)
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

bool prelucrare(int** a, const int nrows, const int ncols, std::vector<int>& numbers)
{
	bool valida = 1;
	for (int j = 0; j < ncols; j++)
	{
		int aux = 0;

		for (int i = 0; i < nrows; i++)
		{
			aux += a[i][j];
			aux *= 10;
			if ((a[i][j] < 0) || (a[i][j] >= (j + 1) + 1))
				valida = 0;
		}
		aux /= 10;

		numbers.push_back(convB10(aux, j + 2));
	}
	return valida;
}

void afisareVector(std::vector<int> v)
{
	int i;
	for (i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[i];
}

void afisareMatrice(int** a, int nrows, int ncols)
{
	for (int i = 0; i < nrows; i++)
	{
		if (i == 0)
			std::cout << "/ ";
		else
		{
			if (i == nrows - 1)
				std::cout << "\\ ";
			else std::cout << "| ";
		}
		for (int j = 0; j < ncols; j++)
		{
			if (j == ncols - 1 && i == 0)
				std::cout << a[i][j] << " \\";
			else
			{
				if (j == ncols - 1 && i == nrows - 1)
					std::cout << a[i][j] << " /";
				else
					if (j == ncols - 1)
					{
						std::cout << a[i][j] << " |";
					}

					else
						std::cout << a[i][j] << " ";
			}
		}
		std::cout << "\n";
	}
}
