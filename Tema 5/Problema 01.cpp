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
private:
	void PREORDER() {
		std::stack<NOD*> stiva;
		stiva.push(this->root);
		while (!stiva.empty()) {
			NOD* curent = stiva.top();
			stiva.pop();
			std::cout << " " << curent->key << " ";
			if (curent->dr != nullptr)
				stiva.push(curent->dr);
			if (curent->st != nullptr)
				stiva.push(curent->st);
		}
		std::cout << "\n";
	}
	void INORDER() {
		std::stack<NOD*> stiva;
		NOD* curent = this->root;
		while (curent != nullptr || !stiva.empty()) {
			while (curent != nullptr) {
				stiva.push(curent);
				curent = curent->st;
			}
			curent = stiva.top();
			stiva.pop();
			std::cout << " " << curent->key << " ";
			curent = curent->dr;
		}
		std::cout << "\n";
	}
	void POSTORDER() {
		if (root == nullptr)
			return;
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
			std::cout << " " << rezultat[i]->key << " ";
		std::cout << "\n";

	}
	void BFS() {
		std::queue<NOD*> coada;
		coada.push(root);
		int nivel = 0;

		while (!coada.empty()) {
			int n = coada.size();
			while (n > 0) {
				NOD* curent = coada.front();
				std::cout << " " << curent->key << " ";
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
	NOD* root;
public:
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
			std::cout << " INPUT GRESIT!\n";
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
			std::cout << " INPUT GRESIT!\n";
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
	NOD* SUCCESSOR(NOD* node) {
		if (!node) {
			std::cout << " INPUT GRESIT!\n";
			return nullptr;
		}
		else
			if (node->dr)
				return MINIM(node->dr);
			else
				while (node->p) {
					if (node->p->st == node)
						return node->p;
					else
						node = node->p;
				}
		std::cout << " NU ARE SUCCESOR!\n";
		return nullptr;

	}
	NOD* PREDECESSOR(NOD* node) {
		if (!node) {
			std::cout << " INPUT GRESIT!\n";
			return nullptr;
		}
		else
			if (node->st)
				return MAXIM(node->st);
			else
				while (node->p) {
					if (node->p->dr == node)
						return node->p;
					else
						node = node->p;
				}
		std::cout << " NU ARE PREDECESOR!\n";
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
			std::cout << " INPUT GRESIT!\n";
			return;
		}
		NOD* par;
		if (node->p)
			par = node->p;
		else
			par = nullptr;

		/*caz stergere frunza*/
		if (!node->st && !node->dr) {
			if (par)
				if (par->st == node)
					par->st = nullptr;
				else
					par->dr = nullptr;
			else
				root = nullptr;
			//delete node;
		}
		else
			/*caz nu are fiu stang*/
			if (!node->st && node->dr) {
				if (par)
					if (par->st == node) {
						par->st = node->dr;
						node->dr->p = par;
					}
					else {
						par->dr = node->dr;
						node->dr->p = par;
					}
				else {
					root = node->dr;
					node->dr->p = nullptr;
				}
				//delete node;
			}
			else
				/*caz nu are fiu drept*/
				if (node->st && !node->dr) {
					if (par)
						if (par->st == node) {
							par->st = node->st;
							node->st->p = par;
						}
						else {
							par->dr = node->st;
							node->st->p = par;
						}
					else {
						root = node->st;
						node->st->p = nullptr;
					}
					//delete node;
				}
				else
					/*caz are 2 fii*/
					if (node->st && node->dr) {
						NOD* SUCC = SUCCESSOR(node);
						/*caz 1: daca este succesor direct*/
						if (node->dr == SUCC) {
							if (par) {
								par->dr = SUCC;
								SUCC->p = par;
								SUCC->st = node->st;
								node->st->p = SUCC;
							}
							else {
								SUCC->p = nullptr;
								SUCC->st = node->st;
								node->st->p = SUCC;
								root = SUCC;
							}
							//delete node;
						}
						/*caz 2: daca este succesor indirect*/
						if (node->dr != SUCC) {
							if (SUCC->dr) {
								SUCC->p->st = SUCC->dr;
								SUCC->dr->p = SUCC->p;
							}
							if (par) {
								if (par->st == node)
									par->st = SUCC;
								else
									par->dr = SUCC;
								SUCC->p = par;
								SUCC->st = node->st;
								node->st->p = SUCC;
								SUCC->dr = node->dr;
								node->dr->p = SUCC;
							}
							else {

								SUCC->p = nullptr;
								SUCC->st = node->st;
								node->st->p = SUCC;
								SUCC->dr = node->dr;
								node->dr->p = SUCC;
							}
							//delete node;
						}
					}
		delete node;
	}
	void ERASE(NOD* node) {
		DELETE(node->key);
	}
	void PRINT_TREE(int opt) {
		if (root == nullptr) {
			std::cout << " Arbore nul\n";
			return;
		}
		switch (opt) {
		case 1: {
			std::cout << " PREORDINE: ";
			PREORDER();
			break;
		}
		case 2: {
			std::cout << " IN ORDINE: ";
			INORDER();
			break;
		}
		case 3: {
			std::cout << " POSTORDINE: ";
			POSTORDER();
			break;
		}
		case 4: {
			std::cout << " PE NIVELE:\n";
			BFS();
			break;
		}
		}
	}
	NOD* CONSTRUCT(std::vector<int>& v) {
		CLEAR();
		for (int i = 0; i < v.size(); i++) {
			INSERT(v[i]);
		}
		return root;
	}
	void CLEAR() {
		if (!root)
			return;
		NOD* curent = root;
		std::queue<NOD*> coada;
		coada.push(root);

		while (!coada.empty()) {
			int n = coada.size();
			while (n > 0) {
				NOD* curent = coada.front();
				coada.pop();
				if (curent->st != nullptr)
					coada.push(curent->st);
				if (curent->dr != nullptr)
					coada.push(curent->dr);
				delete curent;
				n--;
			}
		}
		root = nullptr;
	}
	bool EMPTY() {
		return !root;
	}
};

int main() {
	SearchTree T;
	T.INSERT(41); T.INSERT(28);	T.INSERT(56);
	T.INSERT(10); T.INSERT(40);	T.INSERT(53);
	T.INSERT(60); T.INSERT(8); T.INSERT(39);
	T.INSERT(55); T.INSERT(9); T.INSERT(58);
	T.INSERT(70); T.INSERT(59);
	T.CLEAR();
	std::vector<int>v{1, 6, 9, 15, 3, 4, 11, 20, 12};
	T.CONSTRUCT(v);
	int opt, prtOpt;
	do {
		std::cout
			<< " |---------------------|\n"
			<< " |    1 - INSERTIE     |\n"
			<< " |    2 - CAUTARE      |\n"
			<< " |    3 - STERGERE     |\n"
			<< " |    4 - MINIM        |\n"
			<< " |    5 - MAXIM        |\n"
			<< " |    6 - SUCCESOR     |\n"
			<< " |    7 - PREDECESOR   |\n"
			<< " |    8 - AFISARE      |\n"
			<< " |    0 - IESIRE       |\n"
			<< " |---------------------|\n\n";
		std::cout << " Option >> ";
		std::cin >> opt;
		switch (opt) {
			/*1 - INSERTIE*/
		case 1: {
			std::cout << " Insert node key >> ";
			int key;
			std::cin >> key;
			T.INSERT(key);
			break;
		}
			  /*2 - CAUTARE*/
		case 2: {
			std::cout << " Insert node key >> ";
			int key;
			std::cin >> key;
			if (T.FIND(key)) {

				std::cout << " Gasit!\n";
			}
			else
				std::cout << " Negasit\n";
			break;
		}
			  /*3 - STERGERE*/
		case 3: {
			std::cout << " Insert node key >> ";
			int key;
			std::cin >> key;
			T.DELETE(key);
			break;
		}
			  /*4 - MINIM*/
		case 4: {
			std::cout << " Subtree root >> ";
			int subRootKey;
			std::cin >> subRootKey;
			if (T.MINIM(T.FIND(subRootKey)))
				std::cout << " " << T.MINIM(T.FIND(subRootKey))->key << "\n";
			break;
		}
			  /*5 - MAXIM*/
		case 5: {
			std::cout << " Subtree root >> ";
			int subRootKey;
			std::cin >> subRootKey;
			if (T.MAXIM(T.FIND(subRootKey)))
				std::cout << " " << T.MAXIM(T.FIND(subRootKey))->key << "\n";
			break;
		}
			  /*6 - SUCCESOR*/
		case 6: {
			std::cout << " Insert node key >> ";
			int key;
			std::cin >> key;
			if (T.SUCCESSOR(T.FIND(key)))
				std::cout << " " << T.SUCCESSOR(T.FIND(key))->key << "\n";
			break;
		}
			  /*7 - PREDECESOR*/
		case 7: {
			std::cout << " Insert node key >> ";
			int key;
			std::cin >> key;
			if (T.PREDECESSOR(T.FIND(key)))
				std::cout << " " << T.PREDECESSOR(T.FIND(key))->key << "\n";
			break;
		}
			  /*8 - AFISARE*/
		case 8: {
			system("cls");
			do {
				std::cout
					<< " 1 - DFS:Preorder (RSD)\n"
					<< " 2 - DFS:InOrder (SRD)\n"
					<< " 3 - DFS:Postorder (SDR)\n"
					<< " 4 - BFS:Levels\n"
					<< " 0 - EXIT\n"
					<< " Option >> ";
				std::cin >> prtOpt;
				T.PRINT_TREE(prtOpt);
				system("pause");
				system("cls");

			} while (prtOpt);
			break;
		}
		}
		system("pause");
		system("cls");
	} while (opt);

	return 0;
}
