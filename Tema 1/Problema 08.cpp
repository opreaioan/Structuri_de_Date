// Problema 8
// Se considera o structura  fractie, cu campurile de tip int numarator si numitor. 
// Aceasta structura dispune de o metoda reductie, care reduce
// fractia (ex: 12/30 devine 2/5), de functii pentru operatii aritmetice, de functii de 
// comparare. De asemenea o functie de transformare in numar zecimal (ex: 2/5 = 0.4). Sa se
// citeasc un vector de fractii. Fiecare dintre acestea sa se reduca. Sa se sorteze
// vectorul cat mai efcient si sa se calculeze suma elementelor sale. Scrieti functii de 
// citire/ afisare pentru fractii. Punctajul maxim se acord  pentru rezolvarea completa ,
// eleganta si efcienta .(3p)

#include <iostream>
#include <vector>
#include <algorithm>

struct fractie
{
	int numarator;
	int numitor;

	int cmmdc(int a, int b)
	{
		int r;
		r = a % b;
		for (; r; a = b, b = r, r = a % b);
		return b;
	}

	fractie reductie()
	{
		fractie redus;
		int aux = cmmdc(numarator, numitor);
		redus.numarator = numarator / aux;
		redus.numitor = numitor / aux;
		return redus;
	}

	fractie suma(fractie f1, fractie f2)
	{
		fractie sum;
		sum.numarator = f1.numarator * f2.numitor + f2.numarator * f1.numitor;
		sum.numitor = f1.numitor * f2.numitor;
		sum = sum.reductie();

		return sum;
	}

	fractie diferenta(fractie f1, fractie f2)
	{
		fractie dif;
		dif.numarator = f1.numarator * f2.numitor - f2.numarator * f1.numitor;
		dif.numitor = f1.numitor * f2.numitor;
		dif = dif.reductie();

		return dif;
	}

	fractie produs(fractie f1, fractie f2)
	{
		fractie prod;
		prod.numarator = f1.numarator * f2.numarator;
		prod.numitor = f1.numitor * f2.numitor;
		prod = prod.reductie();

		return prod;
	}

	fractie cat(fractie f1, fractie f2)
	{
		fractie catul;
		catul.numarator = f1.numarator * f2.numitor;
		catul.numitor = f1.numitor * f2.numarator;
		catul = catul.reductie();

		return catul;
	}

	float real()
	{
		return (float)numarator / (float)numitor;
	}

	bool operator<(fractie other)
	{
		return this->real() < other.real();
	}
	bool operator>(fractie other)
	{
		return this->real() > other.real();
	}
	bool operator==(fractie other)
	{
		return this->real() == other.real();
	}
};

void citireFractii(std::vector<fractie>& v);
void afisareFractii(std::vector<fractie> v);
bool cmp_cres(fractie a, fractie b);

int main()
{
	std::vector<fractie> v;
	//v = { {1,2},{3,4}, {2,2}, {1,6}, {8,2} ,{9,4} };
	fractie sumaElem = { 1,1 };

	citireFractii(v);
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].numitor == 0)
		{
			std::cout << "Eroare! Numitorul nu poate fi zero.";
			return 0;
		}
		else v[i] = v[i].reductie();
	}

	std::sort(v.begin(), v.end(), cmp_cres);
	std::cout << "Vectorul sortat crescator si redus este: " << "\n";
	afisareFractii(v);

	for (int i = 0; i < v.size(); i++)
		if (v[i].numitor == 0)
		{
			std::cout << "Eroare! Numitorul nu poate fi zero.";
			return 0;
		}
		else
		{
			sumaElem = sumaElem.suma(sumaElem, v[i]);
			sumaElem = sumaElem.diferenta(sumaElem, { 1,1 });
		}

	std::cout << "\n" << "Suma sub forma de fractie a elementelor vectorului este " << sumaElem.numarator << "/" << sumaElem.numitor << std::endl;
	float nrReal = sumaElem.real();
	std::cout << "Suma reala a elementelor vectorului este " << nrReal << std::endl;

	/*fractie frac1 = { 18,6 };
	fractie frac2 = { 9,4 };
	frac1 = frac1.reductie();
	frac2 = frac2.reductie();

	fractie adunare = adunare.suma(frac1, frac2);
	fractie scadere = scadere.diferenta(frac1, frac2);
	fractie inmultire = inmultire.produs(frac1, frac2);
	fractie impartire = impartire.cat(frac1, frac2);

	float nrReal = frac2.real();

	std::cout << frac1.numarator << "/" << frac1.numitor << "\n";
	std::cout << frac2.numarator << "/" << frac2.numitor << "\n";
	std::cout << "Suma:" << adunare.numarator << "/" << adunare.numitor << "\n";
	std::cout << "Diferenta:" << scadere.numarator << "/" << scadere.numitor << "\n";
	std::cout << "Produsul:" << inmultire.numarator << "/" << inmultire.numitor << "\n";
	std::cout << "Catul:" << impartire.numarator << "/" << impartire.numitor << "\n";
	std::cout << "Real f2: " << nrReal << "\n";
	if (frac1 < frac2)
		std::cout << "frac1 < frac2 " << "\n";
	else
		if (frac1 > frac2)
			std::cout << "frac1 > frac2 " << "\n";
		else std::cout << "frac1 = frac2 " << "\n";*/

	return 0;
}

void citireFractii(std::vector<fractie>& v)
{
	fractie aux;
	int n, nr, num;
	std::cout << "Introduceti numarul de fractii: ";
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> nr >> num;
		aux.numarator = nr;
		aux.numitor = num;
		v.push_back(aux);
	}
}

bool cmp_cres(fractie a, fractie b)
{
	return a < b;
}

void afisareFractii(std::vector<fractie> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i].numarator << "/" << v[i].numitor << " ";
	}
}
