/*Tema 3 Problema 3
Se considera doua siruri de caractere (citite din fisier). Sa se
scrie o functie care are ca parametru cele doua siruri si care returneaza true
daca al doilea este o permutare a primului si false altfel. Implementati folosind
unordered_set din stl. (1p)
*/

#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>

typedef std::unordered_map<char, int> unmap;

void citireSiruri(std::string& s1, std::string& s2) {
	std::ifstream f("siruriPb3.txt");
	if (!std::getline(f, s1)) {
		std::cout << "Eroare la deschidere sau citire din fisier!";
		exit(1);
	}
	getline(f, s2);
	f.close();
}

bool isPermutation(std::string s1, std::string s2) {
	if (s1.length() != s2.length()) {
		return 0;
	}
	unmap mapSir1;
	for (char c : s1) {
		mapSir1[c]++;
	}
	for (char c : s2) {
		// caracterul nu exista in primul sir sau a fost deja folosit, nu e o permutare
		if (mapSir1.find(c) == mapSir1.end() || mapSir1[c] == 0) {
			return 0;
		}
		mapSir1[c]--;
	}
	return 1;
}
int main()
{
	std::string S1, S2;
	citireSiruri(S1, S2);
	if (isPermutation(S1, S2)) std::cout << "Este permutare!";
	else std::cout << "Nu este permutare!";
}
