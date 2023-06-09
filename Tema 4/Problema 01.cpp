/*Problema 1 – Arbore sintactic.
Se citeste din fisier o expresie aritmetica formata din numere, variabile si operatorii de baza (+, -, *, /) si paranteze.
Ex: 4+x*((5-1+2)*3+2*(y-1))
a.	Sa se construiasca un arbore sintactic corespunzator expresiei. (2p)
b.	Sa se afiseze arborele pe niveluri. (0.5p)
c.	Pentru variabile sa se ceara valori (double) si apoi sa se evalueze expresia.
Permiteti repetarea acestui pas. (acelasi arbore dar valori diferite pentru variabile) (2p)*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>

typedef std::vector<std::string> vector;
class Nod {
public:
	std::string info;
	Nod* st, * dr;
	Nod() :st(nullptr), dr(nullptr) {	}
	Nod(std::string info) {
		this->info = info;
		this->st = this->dr = nullptr;
	}
};

void citireDate(std::string& expresie);
int prioritate(std::string c);
bool areDoarLitere(std::string s);
bool areDoarCifre(std::string s);
vector FormaPolonezaPostfixata(std::string expresie);
Nod* ArboreSintactic(vector expresie);
void afiseazaArbore(Nod* root);
double evaluare(vector postfixata);
int hArbore(Nod* rad);

int main() {
	vector postfixata;
	std::string expresie;
	citireDate(expresie);
	postfixata = FormaPolonezaPostfixata(expresie);
	Nod* rad = ArboreSintactic(postfixata);
	std::cout << "Forma poloneza postfixata: ";
	for (std::string i : postfixata)
		std::cout << i << " ";
	std::cout << "\n";
	std::cout << "Arborele sintactic: \n";
	afiseazaArbore(rad);
	std::cout << "Evaluarea expresiei se va repeta";
	std::cout << "pana la introducerea caracterului \"0\".\n";
	std::string optiune;
	do {
		std::cout << evaluare(postfixata);
		std::cout << "\nOptiune>>";
		std::cin >> optiune;
		if (std::stoi(optiune) == 0)
			break;
	} while (1);
	return 0;
}
void citireDate(std::string& expresie) {
	std::ifstream f("Problema 01.txt");
	std::getline(f, expresie);
	//std::cout << expresie;
}
int prioritate(std::string c) {
	if (c == "(") return 0;
	else
		if (c == "+" || c == "-") return 1;
		else
			if (c == "*" || c == "/") return 2;
	return 0;
}
bool areDoarLitere(std::string s) {
	for (int i = 0; i < s.length(); i++)
		if (!std::isalpha(s[i]))
			return 0;
	return 1;
}
bool areDoarCifre(std::string s) {
	for (int i = 0; i < s.length(); i++)
		if (!std::isdigit(s[i]))
			return 0;
	return 1;
}
vector FormaPolonezaPostfixata(std::string expresie) {
	vector polish;
	std::stack<std::string> op_stack;
	std::string number, curent;
	for (int i = 0; i < expresie.length(); i++) {
		curent = expresie[i];
		if (std::isdigit(expresie[i])) {
			while (std::isdigit(expresie[i])) {
				number += expresie[i];
				i++;
			}
			polish.push_back(number);
			number.clear();
			i--;
		}
		else
			if (std::isalpha(expresie[i]))
				polish.push_back(curent);
			else
				if (curent == "(")
					op_stack.push(curent);
				else
					if (curent == ")") {
						while (!op_stack.empty() && (op_stack.top() != "(")) {
							polish.push_back(op_stack.top());
							op_stack.pop();
						}
						if (!op_stack.empty())
							op_stack.pop();
					}
					else {
						while (!op_stack.empty() && prioritate(op_stack.top()) >= prioritate(curent)) {
							polish.push_back(op_stack.top());
							op_stack.pop();
						}
						op_stack.push(curent);
					}
		curent.clear();
	}
	while (!op_stack.empty()) {
		polish.push_back(op_stack.top());
		op_stack.pop();
	}
	return polish;
}
Nod* ArboreSintactic(vector expresie) {
	std::stack<Nod*> s;
	for (int i = 0; i < expresie.size(); i++) {
		std::string curent = expresie[i];
		if (areDoarCifre(curent) || areDoarLitere(curent)) {
			Nod* operand = new Nod(curent);
			s.push(operand);
		}
		else {
			Nod* dreapta = s.top();
			s.pop();
			Nod* stanga = s.top();
			s.pop();
			Nod* op = new Nod;
			op->info = curent;
			op->dr = dreapta;
			op->st = stanga;
			s.push(op);
		}
	}
	return s.top();
}
void afiseazaArbore(Nod* rad) {
	if (rad == nullptr)
		return;
	std::queue<Nod*> q;
	q.push(rad);
	while (!q.empty()) {
		int n = q.size();
		while (n > 0) {
			Nod* p = q.front();
			q.pop();
			std::cout << p->info << " ";
			if (p->st != nullptr)
				q.push(p->st);
			if (p->dr != nullptr)
				q.push(p->dr);
			n--;
		}
		std::cout << "\n";
	}
}
double evaluare(vector postfixata) {
	std::stack<double> s;
	for (int i = 0; i < postfixata.size(); i++) {
		std::string curent = postfixata[i];
		if (areDoarCifre(curent)) {
			double operand = std::stod(curent);
			s.push(operand);
		}
		else
			if (areDoarLitere(curent)) {
				double operand;
				std::cout << "introduceti valoarea lui " << curent << " de tip double >> ";
				std::cin >> operand;
				s.push(operand);
			}
			else {
				double dreapta = s.top();
				s.pop();
				double stanga = s.top();
				s.pop();
				if (curent == "+")
					s.push(stanga + dreapta);
				else
					if (curent == "-")
						s.push(stanga - dreapta);
					else
						if (curent == "*")
							s.push(stanga * dreapta);
						else
							if (curent == "/")
								s.push(stanga / dreapta);
			}
	}
	return s.top();
}
int hArbore(Nod* rad) {
	if (rad == nullptr) {
		return 0;
	}
	return std::max(hArbore(rad->st), hArbore(rad->dr)) + 1;
}
