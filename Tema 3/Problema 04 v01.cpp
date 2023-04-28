#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>
#include <sstream>

struct pair_hash
{
	template <class T1, class T2>
	std::size_t operator() (const std::pair<T1, T2>& pair) const {
		return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
	}
};

typedef std::unordered_map<std::pair<std::string, std::string>, int, pair_hash > map;

void citireSiruri(std::string s, map& aparitiiCompetitii);
void competitiv(const map& ac);

int main()
{
	map ac;
	std::string fisier_liste = "concurentiPb4.txt";
	citireSiruri(fisier_liste, ac);
	competitiv(ac);
}

void citireSiruri(std::string s, map& aparitiiCompetitii) {

	std::ifstream f(s);
	std::string nume, prenume, linie;
	while (!f.eof()) {
		std::getline(f, linie);
		std::stringstream ss(linie);
		if (!(ss >> nume >> prenume)) continue;
		std::pair<std::string, std::string> key = std::make_pair(nume, prenume);
		aparitiiCompetitii[key]++;
	}
	f.close();
}
void competitiv(const map& ac) {
	std::cout << "Au participat la mai multe competitii:" << "\n";
	for (const auto& element : ac)
		if (element.second > 1)
			std::cout << element.first.first << " " << element.first.second << "\n";
}
