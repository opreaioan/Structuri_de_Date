#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

typedef std::vector<int> vector;

class Arbore {
public:
	vector chei, st, dr;
	Arbore(std::string file) {
		std::string info, line;
		std::ifstream f(file);
		std::getline(f, line);
		std::stringstream ss(line);
		while (ss >> info) {
			try {
				int num = std::stoi(info);
				chei.push_back(num);
			}
			catch (std::invalid_argument) {
				chei.push_back(-1);
			}
		}
		ss.clear();
		std::getline(f, line);
		ss.str(line);
		while (ss >> info) {
			try {
				int num = std::stoi(info);
				st.push_back(num);
			}
			catch (std::invalid_argument) {
				st.push_back(-1);
			}
		}
		ss.clear();
		std::getline(f, line);
		ss.str(line);
		while (ss >> info) {
			try {
				int num = std::stoi(info);
				dr.push_back(num);
			}
			catch (std::invalid_argument) {
				dr.push_back(-1);
			}
		}
		f.close();
	}
	friend std::ostream& operator<<(std::ostream& os, Arbore t) {
		os << "Chei: ";
		for (int i = 0; i < t.chei.size(); i++) {
			os << t.chei[i] << " ";
		}
		os << "\n";
		os << "Subarbore stang: ";
		for (int i = 0; i < t.st.size(); i++) {
			os << t.st[i] << " ";
		}
		os << "\n";
		os << "Subarbore drept: ";
		for (int i = 0; i < t.dr.size(); i++) {
			os << t.dr[i] << " ";
		}
		os << "\n";
		return os;
	}
	int getNod() {
		int key = 0;
		std::cout << "Rad. subarbore >> ";
		std::cin >> key;
		for (int i = 0; i < this->chei.size(); i++) {
			if (key == this->chei[i])
				return i;
		}
		return -1;
	}
	void RSD(int nod = 0) {
		if (nod == -1) {
			return;
		}
		std::cout << chei[nod] << " ";
		RSD(st[nod]);
		RSD(dr[nod]);
	}
	void SRD(int nod = 0) {
		if (nod == -1) {
			return;
		}
		SRD(st[nod]);
		std::cout << chei[nod] << " ";
		SRD(dr[nod]);
	}
	void SDR(int nod = 0) {
		if (nod == -1) {
			return;
		}
		SDR(st[nod]);
		SDR(dr[nod]);
		std::cout << chei[nod] << " ";
	}
	void afisareFrunzeSD() {
		std::cout << "Frunze st->dr: ";
		for (int i = 0; i < chei.size(); i++) {
			if (st[i] == -1 && dr[i] == -1) {
				std::cout << chei[i] << " ";
			}
		}
		std::cout << "\n";
	}
};
int calculeazaHSub(int nod, Arbore& t);
void comparaArbori(Arbore& t1, Arbore& t2);
bool esteComplet(Arbore& t);
int calculeazaASub(Arbore& t, int nod, int rad = 0, int level = 0);

int main() {
	std::string path1("Problema_02 Arbore_01.txt");
	std::string path2("Problema_02 Arbore_02.txt");
	Arbore T1(path1), T2(path2);
	std::cout << T1;
	std::cout << "Inaltimea subarborelui->\t";
	std::cout << calculeazaHSub(T1.getNod(), T1);
	std::cout << "\n" << "RSD: ";
	T1.RSD();
	std::cout << "\n" << "SRD: ";
	T1.SRD();
	std::cout << "\n" << "SDR: ";
	T1.SDR();
	std::cout << "\n";
	T1.afisareFrunzeSD();
	comparaArbori(T1, T2);
	std::cout << "\n";
	esteComplet(T1);
	std::cout << "\n";
	std::cout << "Adancimea subarborelui->\t";
		std::cout << calculeazaASub(T1, T1.getNod());
		std::cout << "\n";
	system("pause");
	return 0;
}

int calculeazaHSub(int nod, Arbore& t) {
	if (nod == -1) {
		return -1;
	}
	return std::max(calculeazaHSub(t.st[nod], t),
		calculeazaHSub(t.dr[nod], t)) + 1;
}
void comparaArbori(Arbore& t1, Arbore& t2) {
	if (t1.chei.size() != t2.chei.size() ||
		t1.st.size() != t2.st.size() ||
		t1.dr.size() != t2.dr.size()) {
		std::cout << "Arborii nu sunt identici!";
		return;
	}
	for (int i = 0; i < t1.chei.size(); i++) {
		if (t1.chei[i] != t2.chei[i] ||
			t1.st[i] != t2.st[i] ||
			t1.dr[i] != t2.dr[i]) {
			std::cout << "Arborii nu sunt identici!";
			return;
		}
	}
	std::cout << "Arborii sunt identici!";
}
bool esteComplet(Arbore& t) {
	int contor = 0;
	while (contor < t.chei.size() / 2) {
		if (2 * contor + 1 > t.chei.size() - 1)
			break;
		else
			if (t.st[contor] != 2 * contor + 1) {
				std::cout << "Arborele nu este complet!";
				return false;
			}
			else
				if (2 * contor + 2 > t.chei.size() - 1)
					break;
				else
					if (t.dr[contor] != 2 * contor + 2) {
						std::cout << "Arborele nu este complet!";
						return false;
					}
		contor++;
	}
	std::cout << "Arborele este complet!";
	return true;
}
int calculeazaASub(Arbore& t, int nod, int rad, int level) {
	if (rad == -1) {
		return -1;
	}
	int l;
	if (rad == nod) {
		return level;
	}
	l = calculeazaASub(t, nod, t.st[rad], level + 1);
	if (l != -1)
		return l;
	return calculeazaASub(t, nod, t.dr[rad], level + 1);
}
