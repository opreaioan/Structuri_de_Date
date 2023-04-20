/*Problema 9 - Anagrame.
Se consider  un sir de cuvinte citite dintr-un fisier.
Scrieti o functie, care sa grupeze anagramele. Se considera
anagrama un cuvânt obtinut prin rearanjarea literelor altui
cuvânt. Folositi structurile de date din stl învatate,
asa încât sa obtineti eficienta cea mai buna. (1.5p)
(punctaj în functie de rezolvare)
Exemplu: Se considera cuvintele
{car, rac, cos, amin, arc, soc, polca, lac, cal, pocal,mina, copil, anim}.
Atunci se vor grupa: {car, rac, arc}, {cos, soc},{amin, mina, anim},
{lac, cal}, {pocal, polca}, {copil}. */

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
typedef std::unordered_map<int, std::vector<std::string>> tabelaAnagrame;
long string_to_int(std::string& s);
void Anagrame(int cheie, std::string& valoare, tabelaAnagrame& anagrame);

int main() {
	tabelaAnagrame anagrame;
	std::string sir;
	std::ifstream f("cuvintePb9.txt");
	while (!f.eof()) {
		f >> sir;
		Anagrame(string_to_int(sir), sir, anagrame);
	}
	for (auto it = anagrame.begin(); it != anagrame.end(); it++) {
		std::cout << "{";
		for (auto el : it->second) {
			std::cout << el;
			if (el != it->second.back())
				std::cout << ", ";
		}
		std::cout << "} ";
	}
}
long string_to_int(std::string& s) {
	tabelaAnagrame anagrame;
	int sum = 0;
	for (char c : s)
		sum += (int)c;
	return (sum + s.length());
}
void Anagrame(int cheie, std::string& valoare, tabelaAnagrame& anagrame) {
	anagrame[cheie].push_back(valoare);
}
