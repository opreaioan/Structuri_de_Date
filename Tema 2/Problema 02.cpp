// Problema 2
// Inversare elemente vector.Să se inverseze elementele unui vector utilizănd
// o stivă.Primul element se va intershimba cu ultimul, al doilea cu penultimul, etc. (1p)

#include <iostream>
#include <vector>

class Stiva
{
private:

	int* stiva;
	int varf;
	int capacitate;

public:
	Stiva(int capacitate) {
		this->stiva = new int[capacitate];
		this->varf = -1;
		this->capacitate = capacitate;
	}
	~Stiva() {
		delete[] stiva;
	}
	bool esteGoala() {
		return varf == -1;
	}
	bool estePlina() {
		return varf == capacitate - 1;
	}
	void push(int val) {
		if (estePlina()) {
			std::cout << "Stiva este plina.\n";
			return;
		}
		varf++;
		stiva[varf] = val;
	}
	int pop() {
		if (esteGoala()) {
			std::cout << "Stiva este goala.\n";
			return -1;
		}
		int val = stiva[varf];
		varf--;
		return val;
	}
};

void inversareVector(std::vector<int>& v) {
	int n = v.size();
	Stiva s(n);

	for (int i = 0; i < n; i++) {
		s.push(v[i]);
	}
	for (int i = 0; i < n; i++) {
		v[i] = s.pop();
	}
}

int main() {
	std::vector<int> v{ 6, 5, 4, 3, 2, 1, 0 };
	inversareVector(v);
	std::cout << "Vectorul inversat este:" << "\n";
	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << " ";
	}
	return 0;
}
