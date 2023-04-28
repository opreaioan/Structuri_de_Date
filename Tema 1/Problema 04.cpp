// Problema 4 
// Se considera un vector V cu "nr" elemente numere naturale. Sa se construiasca 
// un al doilea vector W, care contine fiecare element din V, care are în componenta
// doar cifre impare, duplicându-le.(1p)
// Exemplu: V = [1, 2, 5, 13, 27, 3, 57]->W = [1, 1, 5, 5, 13, 13, 3, 3, 57, 57]

#include <iostream>
#include <vector>

std::vector<int> citire_vector()
{
	int nr, x;
	std::vector<int> v;
	std::cout << "Introduceti nr. de elemente: " << std::endl;
	std::cin >> nr;

	std::cout << "Introduceti elementele vectorului: " << std::endl;
	for (int i = 0; i < nr; i++)
	{
		std::cin >> x;
		v.push_back(x);
	}
	return v;
}


void creare_vector_W(std::vector<int> v,std::vector<int> &w)
{
	for (int i = 0; i < v.size(); i++)
	{
		bool ok = 1;
		int aux = v[i];
		do
		{
			if ((aux % 10) % 2 == 0)
			{
				ok = 0;
				break;
			}
			aux /= 10;
		} while (aux != 0);
		if (ok)
		{
			w.push_back(v[i]);
			w.push_back(v[i]);
		}
	}
}

void afisare_W(std::vector<int> w)
{
	for (int i = 0; i < w.size(); i++)
		std::cout <<w[i]<<" ";
}

int main()
{
	std::vector<int> W;
	std::vector<int> V = citire_vector();
	creare_vector_W(V,W);
	afisare_W(W);

	return 0;
}
