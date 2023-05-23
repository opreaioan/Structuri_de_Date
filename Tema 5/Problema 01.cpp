#include <iostream>
#include <stack>
#include <stack>
#include <queue>
#include <unordered_map>
#include <vector>

class NOD {
public:
	int key;
	NOD* st;
	NOD* dr;
	NOD* p;
	NOD(int key/*, NOD* st, NOD* dr, NOD* p*/)
		:key(key), st(nullptr), dr(nullptr), p(nullptr) {}
};
class SearchTree {
public:
	NOD* root;
	SearchTree() :root(nullptr) {}
	SearchTree(int key) {
		root = new NOD(key);
	}
	void INSERT(int key) {
		NOD* curent = root;
		while (curent != nullptr) {
			if (key < curent->key) {
				if (curent->st != nullptr)
					curent = curent->st;
				else {
					curent->st = new NOD(key);
					curent->st->p = curent;
					return;
				}
			}
			else
				if (key > curent->key) {
					if (curent->dr != nullptr)
						curent = curent->dr;
					else {
						curent->dr = new NOD(key);
						curent->dr->p = curent;
						return;
					}
				}
				else
					return;
		}
	}
	void PRINT_TREE(int opt) {
		std::cout
			<< "Introduceti optiunea: 1 - PREORDER, "
			<< "2 - INORDER, 3 - POSTORDER, 4 - BFS\n"
			<< "\t>>";

		switch (opt) {
		case 1: {
			std::cout << "PREORDER: ";
			PREORDER();
			break;
		}
		case 2: {
			std::cout << "INORDER: ";
			INORDER();
			break;
		}
		case 3: {
			std::cout << "POSTORDER: ";
			POSTORDER();
			break;
		}
		case 4: {
			std::cout << "BFS:\n";
			BFS();
			break;
		}

		}
	}
	void PREORDER() {
		if (root == nullptr) {
			std::cout << "Arbore nul\n";
			return;
		}
		std::stack<NOD*> stiva;
		stiva.push(this->root);
		while (!stiva.empty()) {
			NOD* curent = stiva.top();
			stiva.pop();
			std::cout << curent->key << " ";
			if (curent->dr != nullptr)
				stiva.push(curent->dr);
			if (curent->st != nullptr)
				stiva.push(curent->st);
		}
		std::cout << "\n";
	}
	void INORDER() {
		if (root == nullptr) {
			std::cout << "Arbore nul\n";
			return;
		}
		std::stack<NOD*> stiva;
		NOD* curent = this->root;
		while (curent != nullptr || !stiva.empty()) {
			while (curent != nullptr) {
				stiva.push(curent);
				curent = curent->st;
			}
			curent = stiva.top();
			stiva.pop();
			std::cout << curent->key << " ";
			curent = curent->dr;
		}
		std::cout << "\n";
	}
	void POSTORDER() {
		if (root == nullptr) {
			std::cout << "Arbore nul\n";
			return;
		}
		std::stack<NOD*> stiva;
		std::vector<NOD*> rezultat;
		int poz = 0;
		stiva.push(this->root);
		while (!stiva.empty()) {
			NOD* curent = stiva.top();
			stiva.pop();
			rezultat.emplace_back(curent);
			if (curent->st != nullptr)
				stiva.push(curent->st);
			if (curent->dr != nullptr)
				stiva.push(curent->dr);
		}
		std::cout << "\n";
		for (int i = rezultat.size() - 1; i >= 0; i--)
			std::cout << rezultat[i]->key << " ";
	}
	void BFS() {
		if (root == nullptr) {
			std::cout << "Arbore nul\n";
			return;
		}
		std::queue<NOD*> coada;
		std::unordered_map<int, std::vector<NOD*>> elementePeNiveluri;
		coada.push(root);
		int nivel = 0;

		while (!coada.empty()) {
			int n = coada.size();
			while (n > 0) {
				NOD* curent = coada.front();
				elementePeNiveluri[nivel].push_back(curent);
				std::cout << curent->key << " ";
				coada.pop();
				if (curent->st != nullptr)
					coada.push(curent->st);
				if (curent->dr != nullptr)
					coada.push(curent->dr);
				n--;
			}
			nivel++;
			std::cout << "\n";
		}
		/*for (auto& it : elementePeNiveluri) {
			std::vector<NOD*>& elemente = it.second;
			for (auto& it2 : elemente)
				std::cout << it2->key << " ";
			std::cout << "\n";
		}*/
	}
};

int main() {
	SearchTree T;
	T.INSERT(10);
	T.INSERT(5);
	T.INSERT(15);
	T.INSERT(3);
	T.INSERT(7);
	T.INSERT(12);
	T.INSERT(17);
	T.INSERT(1);
	T.INSERT(4);
	int opt;

	T.PRINT_TREE(opt);
}
