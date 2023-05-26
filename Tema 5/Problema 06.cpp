#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <iomanip>

int main() {
	std::ifstream f("Problema 06.txt");
	std::map<std::string, unsigned> dictionar;
	std::string linie, cuvant;
	int max = 0;
	if (!f.is_open()) {
		std::cerr << "Eroare la deschidere fisier!";
	}
	while (!f.eof()) {
		std::getline(f, linie);
		std::string::iterator c = linie.begin();
		for (; c != linie.end(); c++) {
			if (std::isalpha(*c)) {
				cuvant += *c;
				if (std::next(c) == linie.end()) {
					dictionar[cuvant]++;
					cuvant.clear();
				}
			}
			else
				if (!cuvant.empty()) {
					dictionar[cuvant]++;
					cuvant.clear();
				}
		}
	}
	f.close();
	std::map<std::string, unsigned>::iterator it = dictionar.begin();
	for (; it != dictionar.end(); it++) {
		std::cout
			<< std::left<<"\t|"
			<< std::setw(15) << it->first << " "
			<< std::right << it->second<<" |\n"
			<< "\t|------------------|\n";
	}
	return 0;
}
