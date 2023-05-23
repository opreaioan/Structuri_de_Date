#include <iostream>
#include <vector>
#include <stack>
#include <queue>


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
			std::cout << "INVALID INPUT!\n";
			return nullptr;
		}
		else {
			NOD* curent = subTreeRoot;
			while (curent->dr) {
				curent = curent->dr;
			}
			std::cout << "MAX is " << curent->key << "\n";
			return curent;
		}

	}
	NOD* FIND(int key) {
		NOD* curent = root;

	}
	void PRINT_TREE(int opt) {
		/*std::cout
			<< "Introduceti optiunea: 1 - PREORDER, "
			<< "2 - INORDER, 3 - POSTORDER, 4 - BFS\n"
			<< "\t>>";*/

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
		for (int i = rezultat.size() - 1; i >= 0; i--)
			std::cout << rezultat[i]->key << " ";
		std::cout << "\n";

	}
	void BFS() {
		if (root == nullptr) {
			std::cout << "Arbore nul\n";
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
	int opt;
	std::cout

		<< "1. INSERT\n"
		<< "2. MAXIM\n"
		<< "3. MINIM\n"
		<< "4. SUCCESOR\n"
		<< "5. PREDECESOR\n"
		<< "6. FIND\n"
		<< "7. DELETE\n"
		<< "8. ERASE\n"
		<< "9. PRINT TREE\n"
		<< "10. CONSTRUCT\n"
		<< "11. EMPTY\n"
		<< "12. CLEAR\n"
		<< "Option >> ";

	std::cin >> opt;
	switch (opt) {
	case 1: {
		std::cout << "Insert key >> ";
		int key;
		std::cin >> key;
		T.INSERT(key);
		break;
	}
	case 2: {
		std::cout << "Subtree root >> ";
		int subRootKey;
		std::cin >> subRootKey;
		T.MAXIM(T.FIND(subRootKey));
	}
	}

	/*
			 10
		   /    \
		  5     15
		 / \    / \
		3   7  12  17
	   / \
	  1   4

	*/

}
