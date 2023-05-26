#include <iostream>
#include <set>
#include <fstream>
#include <vector>

void afisareCres(std::set<int>& set_cresc);
void afisareDes(std::set<int>& set_des);
void inserare(int val, std::set<int>& set_cresc, std::set<int>& set_des);

int main() {
	std::ifstream f("Problema 05.txt");
	std::set<int> cresc, desc;
	std::vector<int> v;
	int n, K, val, max;
	while (!f.eof()) {
		f >> val;
		v.push_back(val);
	}
	for (int i = 0; i < v.size(); i++) {
		cresc.insert(v[i]);
		if (v[i] > v[i + 1]) {
			max = i + 1;
			break;
		}
	}
	for (; max < v.size(); max++)
		desc.insert(v[max]);
	std::cout << "Introduceti K >> ";
	std::cin >> K;
	for (int i = 1; i <= K; i++) {
		int val;
		std::cout << "Valoarea >> ";
		std::cin >> val;
		if (cresc.find(val) == cresc.end()) {
			inserare(val, cresc, desc);
			afisareCres(cresc);
			afisareDes(desc);
		}
	}
	return 0;
}
void inserare(int val, std::set<int>& set_cresc, std::set<int>& set_des) {
	set_cresc.insert(val);
	set_des.insert(val);
}
void afisareCres(std::set<int>& set_des) {
	std::cout << "Operatie de inserare reusita!\n";
	std::set<int>::iterator it = set_des.begin();
	for (; it != set_des.end(); it++) {
		std::cout << *it << " ";
	}
}
void afisareDes(std::set<int>& set_des) {
	std::set<int>::reverse_iterator r_it = set_des.rbegin();
	for (; r_it != set_des.rend(); r_it++) {
		std::cout << *r_it << " ";
		if (std::next(r_it) == set_des.rend())
			std::cout << "\n";
	}
}
