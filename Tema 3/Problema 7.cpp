/*Problema 7 - Duplicate apropiate. 
Se citeste dintr-un fisier un numar de valori reale si
se stocheaza într-un vector. Sa se determine în mod eficient, daca exista doua
numere egale în vector, aflate la o distanta  mai mica sau egala cu o valoare data
dist. Puteti folosi unordered_set sau alta structura care permite rezolvare
eficienta.(1p)*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <string>

typedef std::vector<float> vector;
typedef std::unordered_map<std::string, unsigned> unomap;

void citireDate(vector& v);
bool verificaDistanta(vector& v, unsigned& dist);

int main()
{
	vector v;
	unsigned dist;
	citireDate(v);
	std::cout << "Introduceti distanta: ";
	std::cin >> dist;
	verificaDistanta(v, dist);
	return 0;
}

void citireDate(vector& v) {
	float nr;
	std::ifstream f("floatsPb7.txt");
	while (!f.eof()) {
		f >> nr;
		v.push_back(nr);
	}
}
bool verificaDistanta(vector& v, unsigned& dist) {
	unomap distante;
	bool gasit = false;
	for (int i = 0; i < v.size(); i++) {
		std::string s = std::to_string(v[i]);
		if (distante.find(s)==distante.end())
			distante[s] = i;
		else
			if (i - distante[s] <= dist) {
				std::cout << "Gasit!";
				return true;
			}
	}
	std::cout << "Negasit!";
	return gasit;
}
