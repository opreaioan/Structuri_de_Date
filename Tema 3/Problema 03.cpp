/* Problema 3
Se considera doua siruri de caractere (citite din fisier). Sa se
scrie o functie care are ca parametru cele doua siruri si care returneaza true
daca al doilea este o permutare a primului si false altfel. Implementati folosind
unordered_set din stl. (1p)
*/
/*REZOLVARE CU unordered_set - GOOD ONE! :))) */ 
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

typedef std::unordered_set<char> set;

void citireSiruri(std::string& s1, std::string& s2);
bool estePermutare(std::string s1, std::string s2);

int main()
{
	std::string S1, S2;
	citireSiruri(S1, S2);

	if (estePermutare(S1, S2))
		std::cout << "Este permutare!";
	else std::cout << "Nu este permutare!";
	return 0;
}
void citireSiruri(std::string& s1, std::string& s2) {
	std::ifstream f("Problema 03.txt");
	if (!std::getline(f, s1)) {
		std::cout << "Eroare la deschidere sau citire din fisier!";
		exit(1);
	}
	getline(f, s2);
	f.close();
}
bool estePermutare(std::string s1, std::string s2) {
	if (s1.length() != s2.length()) {
		return 0;
	}
	set setSir1, setSir2;
	int sumSir1 = 0, sumSir2 = 0;
	for (char c : s1) {
		setSir1.insert(c);
		sumSir1 += (int)c;
	}
	for (char c : s2) {
		setSir2.insert(c);
		sumSir2 += (int)c;
	}
	return ((setSir1 == setSir2) && (sumSir1 == sumSir2));
}

/*REZOLVARE CU unordered_map - just for fun!
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

bool estePermutare(std::string s1, std::string s2) {
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
	if (estePermutare(S1, S2)) std::cout << "Este permutare!";
	else std::cout << "Nu este permutare!";
}*/
