/*Se considera 4 vectori de numere A, B, C si D de lungime cel
mult 500 fiecare. Sa se determine toate cvadruplurile de indici (i; j; k; l) pentru
care A[i] + B[j] + C[k] + D[l] = 0. Ce complexitate are algoritmul dvs? Care
este cea mai bun  complexitate pe care o puteti obtine?*/

#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <iomanip>

typedef std::vector<int> vector;
typedef std::unordered_map<int, std::vector<std::pair<short, short>>> unomap;

void citireDate(vector& A, vector& B, vector& C, vector& D);
void afisareVectori(vector& A, vector& B, vector& C, vector& D);
void formareCvadrupluri(vector& A, vector& B, vector& C, vector& D);

int main()
{
	vector A, B, C, D;
	citireDate(A, B, C, D);
	formareCvadrupluri(A, B, C, D);
}

void citireDate(vector& A, vector& B, vector& C, vector& D) {
	std::ifstream f("vectoriPb6.txt");
	int a, b, c, d, i, nr;
	f >> a >> b >> c >> d;
	i = 0;
	while (i < a) {
		f >> nr;
		A.push_back(nr);
		i++;
	}
	i = 0;
	while (i < b) {
		f >> nr;
		B.push_back(nr);
		i++;
	}
	i = 0;
	while (i < c) {
		f >> nr;
		C.push_back(nr);
		i++;
	}
	i = 0;
	while (i < d) {
		f >> nr;
		D.push_back(nr);
		i++;
	}
}
void formareCvadrupluri(vector& A, vector& B, vector& C, vector& D) {
	unomap AB, CD;
	for (int i = 0; i < A.size(); i++)
		for (int j = 0; j < B.size(); j++)
			AB[A[i] + B[j]].push_back(std::make_pair(i, j));
	for (int i = 0; i < C.size(); i++)
		for (int j = 0; j < D.size(); j++)
			CD[C[i] + D[j]].push_back(std::make_pair(i, j));

	for (auto elem1 : AB) {
		for (auto elem2 : CD)
			if (elem1.first == -(elem2.first)) {
				auto it1 = elem1.second.begin();
				auto it2 = elem2.second.begin();

				for (; it1 != elem1.second.end(); it1++)
					for (; it2 != elem2.second.end(); it2++)
						std::cout << "(" << it1->first << "," << it1->second << "," << it2->first << "," << it2->second << ") ";
				std::cout << "\n";
			}

	}
}
