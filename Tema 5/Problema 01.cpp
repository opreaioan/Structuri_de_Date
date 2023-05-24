#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib>

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
		if (!root)
			root = new NOD(key);
		else {
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
	}
	NOD* MAXIM(NOD* subTreeRoot) {
		if (!subTreeRoot) {
			std::cout << " INVALID INPUT!\n";
			return nullptr;
		}
		else {
			NOD* curent = subTreeRoot;
			while (curent->dr) {
				curent = curent->dr;
			}
			return curent;
		}

	}
	NOD* MINIM(NOD* subTreeRoot) {
		if (!subTreeRoot) {
			std::cout << " INVALID INPUT!\n";
			return nullptr;
		}
		else {
			NOD* curent = subTreeRoot;
			while (curent->st) {
				curent = curent->st;
			}
			return curent;
		}
	}
	NOD* SUCCESSOR(NOD* nod) {
		if (!nod) {
			std::cout << " INVALID INPUT!\n";
			return nullptr;
		}
		else
			if (nod->dr)
				return MINIM(nod->dr);
			else
				while (nod->p) {
					if (nod->p->st == nod)
						return nod->p;
					else
						nod = nod->p;
				}
		std::cout << " NO SUCCESSOR!\n";
		return nullptr;

	}
	NOD* PREDECESSOR(NOD* nod) {
		if (!nod) {
			std::cout << " INVALID INPUT!\n";
			return nullptr;
		}
		else
			if (nod->st)
				return MAXIM(nod->st);
			else
				while (nod->p) {
					if (nod->p->dr == nod)
						return nod->p;
					else
						nod = nod->p;
				}
		std::cout << " NO PREDECESSOR!\n";
		return nullptr;
	}
	NOD* FIND(int key) {
		NOD* curent = root;
		while (curent) {
			if (key < curent->key)
				curent = curent->st;
			else
				if (key > curent->key)
					curent = curent->dr;
				else
					return curent;
		}
		return curent;
	}
	void DELETE(int key) {
		NOD* node = FIND(key);
		if (!node) {
			std::cout << " INVALID INPUT!\n";
			return;
		}
		if (!node->st && !node->dr) {
			if (node->p)
				if (node->p->st == node)
					node->p->st = nullptr;
				else
					node->p->dr = nullptr;
			else root = nullptr;
			delete node;
		}
		else
			if (!node->st && node->dr) {
				if (node->p)
					if (node->p->st == node) {
						node->p->st = node->dr;
						node->dr->p = node->p;
					}
					else {
						node->p->dr = node->dr;
						node->dr->p = node->p;
					}
				else
					root = node->dr;
				delete node;
			}
			else
				if (node->st && !node->dr) {
					if (node->p)
						if (node->p->st == node) {
							node->p->st = node->st;
							node->st->p = node->p;
						}
						else {
							node->p->dr = node->st;
							node->st->p = node->p;
						}
					else
						root = node->st;
					delete node;
				}

	}
	void PRINT_TREE(int opt) {
		switch (opt) {
		case 1: {
			std::cout << " PREORDER: ";
			PREORDER();
			break;
		}
		case 2: {
			std::cout << " INORDER: ";
			INORDER();
			break;
		}
		case 3: {
			std::cout << " POSTORDER: ";
			POSTORDER();
			break;
		}
		case 4: {
			std::cout << " BFS:\n";
			BFS();
			break;
		}
		}
	}
	void PREORDER() {
		if (root == nullptr) {
			std::cout << " Arbore nul\n";
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
			std::cout << " Arbore nul\n";
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
			std::cout << " Arbore nul\n";
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
		for (int i = rezultat.size() - 1; i >= 0; i--)
			std::cout << rezultat[i]->key << " ";
		std::cout << "\n";

	}
	void BFS() {
		if (root == nullptr) {
			std::cout << " Arbore nul\n";
			return;
		}
		std::queue<NOD*> coada;
		coada.push(root);
		int nivel = 0;

		while (!coada.empty()) {
			int n = coada.size();
			while (n > 0) {
				NOD* curent = coada.front();
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
	}
};

int main() {
	SearchTree T;
	T.INSERT(41); T.INSERT(28);	T.INSERT(56);
	T.INSERT(10); T.INSERT(40);	T.INSERT(53);
	T.INSERT(60); T.INSERT(8); T.INSERT(39);
	T.INSERT(55); T.INSERT(9);
	int opt;
	do {
		std::cout
			<< " |-----------------------|\n"
			<< " |   1.INSERT            |\n"
			<< " |   2.MAXIM             |\n"
			<< " |   3.MINIM             |\n"
			<< " |   4.SUCCESOR          |\n"
			<< " |   5.PREDECESOR        |\n"
			<< " |   6.FIND              |\n"
			<< " |   7.DELETE            |\n"
			<< " |   8.ERASE             |\n"
			<< " |   9.PRINT TREE        |\n"
			<< " |   10.CONSTRUCT        |\n"
			<< " |   11.EMPTY            |\n"
			<< " |   12.CLEAR            |\n"
			<< " |   0.EXIT              |\n"
			<< " |-----------------------|\n\n";
		std::cout << " Option >> ";
		std::cin >> opt;
		switch (opt) {
			/*1. INSERT*/
		case 1: {
			std::cout << " Insert node key >> ";
			int key;
			std::cin >> key;
			T.INSERT(key);
			break;
		}
			  /*2. MAXIM*/
		case 2: {
			std::cout << " Subtree root >> ";
			int subRootKey;
			std::cin >> subRootKey;
			if (T.MAXIM(T.FIND(subRootKey)))
				std::cout << T.MAXIM(T.FIND(subRootKey))->key << "\n";
			break;
		}
			  /*3. MINIM*/
		case 3: {
			std::cout << " Subtree root >> ";
			int subRootKey;
			std::cin >> subRootKey;
			if (T.MINIM(T.FIND(subRootKey)))
				std::cout << T.MINIM(T.FIND(subRootKey))->key << "\n";
			break;
		}
			  /*4. SUCCESOR*/
		case 4: {
			std::cout << " Insert node key >> ";
			int key;
			std::cin >> key;
			if (T.SUCCESSOR(T.FIND(key)))
				std::cout << T.SUCCESSOR(T.FIND(key))->key << "\n";
			break;
		}
			  /*5. PREDECESOR*/
		case 5: {
			std::cout << " Insert node key >> ";
			int key;
			std::cin >> key;
			if (T.PREDECESSOR(T.FIND(key)))
				std::cout << T.PREDECESSOR(T.FIND(key))->key << "\n";
			break;
		}
		case 6: {
			if (T.FIND(5)) {
				NOD* x = T.FIND(5);
				std::cout << x->key << "\n";
			}
			else
				std::cout << " Negasit\n";
			break;
		}

		}
		system("pause");
		system("cls");
	} while (opt != 0);

	return 0;
}
