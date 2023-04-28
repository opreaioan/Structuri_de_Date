// Problema 2
// Sa se verifice si sa se afiseze daca un vector este superior sau inferior.
// Un vector este superior daca acesta contine mai multe elemente cu valoarea mai
// mare decat media aritmetica a intregului vector si inferior altfel.(1p)

#include <iostream>
#include <vector>

void citire_vector(std::vector<float>& v, int& n)
{
	int x;
	std::cout << "Introduceti nr. de elemente: ";
	std::cin >> n;

	std::cout << "Introduceti elementele vectorului: " << std::endl;
	for (int i = 0; i < n; i++)
	{
		std::cin >> x;
		v.push_back(x);
	}
		
}

float media_aritmetica(std::vector<float> v, int n)
{
	float media = 0;
	for (int i = 0; i < n; i++)
		media += v[i];
	return (media / n);
}

bool superior_sau_inferior(std::vector<float> v, int n)
{
	bool ok = 1;
	int superior = 0;
	float media = media_aritmetica(v, n);
	for (int i = 0; i < n; i++)
		if (v[i] > media)
			superior++;
	if (superior > n / 2)
		return ok;
	else return (!ok);
}

int main()
{
	int n;
	std::vector<float> v;

	citire_vector(v, n);
	if (superior_sau_inferior(v,n))
		std::cout << "Vectorul este superior";
	else 
		std::cout << "Vectorul este inferior";
	return 0;
}
