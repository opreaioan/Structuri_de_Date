// Problema 3
// Se considera un vector cu nr elemente numere naturale din intervalul [30,80],
// Sa se determine si sa se afiseze elementul care apare de cele mai multe ori.(1p)

#include <iostream>
#include <vector>
#include <algorithm>

void citire_vector(std::vector<int>& v, int n)
{
	int x;
	int i = 0;
	std::cout << "Introduceti elementele vectorului cuprinse in intervalul [30:80]: " << std::endl;
	while (i<n)
	{
		std::cin >> x;
		if ((x >= 30) && (x <= 80))
		{
			v.push_back(x);
			i++;
		}
	}
}

void nr_max_aparitii(std::vector<int> v, int n)
{
	std::vector<int> elem_aparitii;
	int max = 0;
	int nr_aparitii = 0;
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (std::count(elem_aparitii.begin(), elem_aparitii.end(), v[i]) == 0)
		{
			nr_aparitii = std::count(v.begin(), v.end(), v[i]);
			elem_aparitii.push_back(v[i]);
			elem_aparitii.push_back(nr_aparitii);
		}
		if (max < nr_aparitii)
			max = nr_aparitii;
		
	}
	std::cout << "Numarul maxim de aparitii este " << max << " iar elementul care apare (sau elementele care apar) de cele mai multe ori este (sau sunt): "<<std::endl;
		for (int i = 0; i < elem_aparitii.size(); i+=2)
			if (max == elem_aparitii[i+1])
				std::cout << elem_aparitii[i]<< " ";
}


int main()
{
	int nr;
	std::vector<int> v;

	std::cout << "Introduceti nr. de elemente: ";
	std::cin >> nr;

	citire_vector(v, nr);
	nr_max_aparitii(v, nr);

	return 0;
}
