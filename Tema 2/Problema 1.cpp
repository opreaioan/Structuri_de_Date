//Tema 2 - Stive, cozi, liste înlănţuite
//Problema 1
//Implementarea unei liste dublu înlănţuite.Să se implementeze o listă
//dublu înlănţuită cu funcţionalităţile descrise în continuare.Se cere utilizarea
//unei structuri node care are trei câmpuri : un câmp pentru informaţie(de tip
//int) şi două câmpuri de tip pointer la node pentru legăturile către elementele
//precedent şi următor.Se cere utilizarea unei structuri List care are ca membri
//două variabile de tip node∗ reprezentând primul respectiv ultimul element
//din listă, o variabilă de tip int reprezentând numărul de elemente din listă şi
//funcţiile push_front(key), push_back(key), pop_front(), pop_back(), find(key)
//erase(node∗Nod), remove(int key), insert(node ∗Nod, int val), empty(), clear(),
//print(), size()
//De asemenea să se implementeze următoarele funcţii, care nu fac parte din structură:
//palindrom(List L), compare(List L1, ListL2)

#include <iostream>
#include <string>
#include <stdexcept>

class node
{
public:
	int info = 0;
	node* next = nullptr;
	node* prev = nullptr;
};

class List
{
public:
	node* head = nullptr;
	node* tail = nullptr;
	int Size = 0;

	//1 - push_front(key) - adaugă cheia key în capul listei (0.20 p)
	void push_front(int key)
	{
		Size++;
		node* newNode = new node;
		newNode->info = key;
		newNode->next = head;
		if (head != nullptr)
		{
			head->prev = newNode;
		}
		else
			tail = newNode;
		head = newNode;
		//std::cout << "S-a adaugat cu succes element in capatul listei." << "\n";
	}

	//2 - push_back(key) - adaugă cheia key la finalul listei(0.20 p)
	void push_back(int key)
	{
		Size++;
		node* newNode = new node;
		newNode->info = key;
		newNode->prev = tail;
		if (tail != nullptr)
		{
			tail->next = newNode;
		}
		else
			head = newNode;
		tail = newNode;
		//std::cout << "S-a adaugat cu succes element la sfarsitul listei." << "\n";
	}

	//3 - pop_front() - şterge primul element din listă(0.20 p)
	void pop_front()
	{
		if (Size > 1)
		{
			node* aux = head;
			head = head->next;
			head->prev = nullptr;
			delete aux;
			Size--;
			//std::cout << "S-a sters cu succes elementul din capatul listei." << "\n";
		}
		else
			if (Size == 1)
			{
				node* aux = head;
				head = nullptr;
				tail = nullptr;
				delete aux;
				Size--;
				//std::cout << "S-a sters cu succes singurul element din lista." << "\n";
			}
		/*else
			std::cout << "Lista este vida." << "\n";*/
	}

	//4 - pop_back() - şterge ultimul element din listă(0.20 p)
	void pop_back()
	{
		if (Size > 1)
		{
			node* aux = tail;
			tail = tail->prev;
			tail->next = nullptr;
			delete aux;
			Size--;
			//std::cout << "S-a sters cu succes elementul de la sfarsitul listei." << "\n";
		}
		else
			if (Size == 1)
			{
				node* aux = tail;
				head = nullptr;
				tail = nullptr;
				delete aux;
				Size--;
				//std::cout << "S-a sters cu succes singurul element din lista." << "\n";
			}
		/*else
			std::cout << "Lista este vida." << "\n";*/
	}
	//5 - find(key) - caută o cheie key în listă - returnează pointer la nodul cu
	//cheia key sau NULL (0.20 p)
	node* find(int key)
	{
		node* it = head;
		node* gasit = nullptr;
		while (it != nullptr)
		{
			if (it->info == key)
				gasit = it;
			it = it->next;
		}
		if (gasit != nullptr)
			std::cout << "Elementul a fost gasit si s-a returnat adresa nodului." << "\n";
		else
			std::cout << "Elementul nu a fost gasit si s-a returnat NULL." << "\n";
		return gasit;
	}

	//6 - erase(node∗Nod) - şterge un element Nod din listă(NU implică căutare).
	//Nodul transmis ca parametru a fost în prealabil găsit cu find sau identificat
	//prin parcurgerea listei. (0.20 p)
	void erase(node* Nod)
	{
		if (Size > 2 && Nod != head && Nod != tail)
		{
			node* aux_next = Nod->next;
			node* aux_prev = Nod->prev;

			aux_prev->next = aux_next;
			aux_next->prev = aux_prev;

			delete Nod;
			Size--;
		}
		else
			if (Nod == head)
				pop_front();
			else
				if (Nod == tail)
					pop_back();
				else
					std::cout << "Lista este vida." << "\n";
	}

	//7 - remove(int key) - şterge toate apariţiile cheii key(implică căutare) (0.20 p)
	void remove(int key)
	{
		node* it = head;
		bool ok = 0;

		while (it != nullptr)
		{
			node* aux = it;
			it = it->next;
			if (aux->info == key)
				erase(aux);
			ok = 1;
		}
		if (ok)
			std::cout << "A fost efectuata cel putin o stergere din lista." << "\n";
		else
			std::cout << "Cheia cautata nu apare in lista." << "\n";
		return;
	}

	//8 - insert(node ∗Nod, int val) - inserează un element cu cheia val înainte de
	//nodul indicat de Nod. (0.5 p)
	void insert(node* Nod, int val)
	{
		if (head != NULL)
		{
			if (Nod == head)
				push_front(val);
			else
			{
				node* newNode = new node;
				newNode->info = val;
				node* aux_prev = Nod->prev;
				newNode->next = Nod;
				newNode->prev = Nod->prev;
				aux_prev->next = newNode;
				Nod->prev = newNode;
				Size++;
				std::cout << "S-a inserat cu succes element inaintea nodului indicat." << "\n";
			}
		}
		else std::cout << "Nodul indicat nu poate indica un element inexistent." << "\n";
	}

	//9 - empty() - verifică dacă lista e vidă(0.20 p)
	bool empty()
	{
		if (Size)
		{
			std::cout << "Lista nu este vida." << "\n";
			return 0;
		}
		else
		{
			std::cout << "Lista este vida." << "\n";
			return 1;
		}
	}

	//10 - clear() - goleşte lista. (0.20 p)
	void clear()
	{
		bool ok = 0;
		while (head != NULL)
		{
			pop_front();
			ok = 1;
		}
		if (head == NULL && ok)
			std::cout << "Lista a fost golita cu succes." << "\n";
		else std::cout << "Lista a fost vida. Nu s-a efectuat nicio modificare." << "\n";
	}

	//11 - funcţia print() - afişează elementele listei(0.20 p)
	void print()
	{
		if (head != NULL)
		{
			node* it = head;
			while (it != NULL)
			{
				std::cout << it->info << " ";
				it = it->next;
			}
			std::cout << "\n";
		}
		else std::cout << "Lista este vida." << "\n";
	}

	//12 - funcţia size() - returnează numărul de elemente din listă.
	int size()
	{
		return Size;
	}

};

//13 - palindrom(List L) - verifică dacă lista este palindrom(0.5 p)
bool palindrom(List L)
{
	bool pal = 1;
	int i = 1;
	node* itstg = L.head;
	node* itdr = L.tail;

	while (itstg != NULL && i < L.size() / 2)
	{
		if (itstg->info != itdr->info)
		{
			pal = 0;
			break;
		}
		i++;
		itstg = itstg->next;
		itdr = itdr->prev;
	}
	return pal;
}

//14 - compare(List L1, ListL2) - returnează 1 dacă L1 şi L2 sunt identice şi
// 0 altfel. (0.20 p)
bool compare(List L1, List L2)
{
	bool identice = 1;

	node* it_L1 = L1.head;
	node* it_L2 = L2.head;
	if (L1.size() == L2.size())
	{
		while (it_L1 != NULL)
		{
			if (it_L1->info != it_L2->info)
			{
				identice = 0;
				break;
			}
			it_L1 = it_L2->next;
			it_L2 = it_L2->next;
		}
	}
	else identice = 0;
	return identice;
}

node* get_node(List* lista);
void mesaj();

int main()
{
	std::string optiune;
	int opt;
	List* lista = new List;
	List* lista2 = new List;

	lista->push_back(3);
	lista->push_front(2);
	lista->push_back(4);
	lista->push_front(1);

	lista2->push_back(3);
	lista2->push_front(2);
	lista2->push_back(4);
	lista2->push_front(1);

	mesaj();

	do
	{
		std::cout << "Introduceti optiunea: ";
		std::cin >> optiune;
		if (optiune == "EXIT")
			break;

		try
		{
			opt = std::stoi(optiune);
		}
		catch (const std::invalid_argument& ia)
		{
			std::cerr << "Optiune invalida." << "\n";
			opt = 0;
			continue;
		}

		switch (opt)
		{
		case 1:
		{
			int key;
			std::cout << "Introduceti cheia: ";
			std::cin >> key;
			lista->push_front(key);
			break;
		}
		case 2:
		{
			int key;
			std::cout << "Introduceti cheia: ";
			std::cin >> key;
			std::cout << "\n";
			lista->push_back(key);
			break;
		}
		case 3:
		{
			lista->pop_front();
			break;
		}
		case 4:
		{
			lista->pop_back();
			break;
		}
		case 5:
		{
			int key;
			std::cout << "Introduceti cheia cautata: ";
			std::cin >> key;
			std::cout << "\n";
			lista->find(key);
			break;
		}
		case 6:
		{
			lista->erase(get_node(lista));
			break;
		}
		case 7:
		{
			int key;
			std::cout << "Introduceti cheia care trebuie stearsa: ";
			std::cin >> key;
			lista->remove(key);
			break;
		}
		case 8:
		{
			int val;
			std::cout << "Introduceti valoarea de inserat: ";
			std::cin >> val;
			std::cout << "\n";
			lista->insert(get_node(lista), val);
			break;
		}
		case 9:
		{
			lista->empty();
			break;
		}
		case 10:
		{
			lista->clear();
			break;
		}
		case 11:
		{
			lista->print();
			break;
		}
		case 12:
		{
			std::cout << "Lista contine " << lista->size() << " elemente." << "\n";
			break;
		}
		case 13:
		{
			bool ispal = palindrom(*lista);
			if (ispal)
				std::cout << "Lista este palindrom.";
			else std::cout << "Lista nu este palindrom.";
			std::cout << "\n";
			break;
		}
		case 14:
		{
			if (compare(*lista, *lista2))
				std::cout << "Listele sunt identice.";
			else std::cout << "Listele nu sunt identice.";
			std::cout << "\n";
			break;
		}
		default:
			std::cerr << "Optiune invalida. " << "\n";
		}
	} while (optiune != "EXIT");
	return 0;
}

node* get_node(List* lista)
{
	if (lista->head != NULL)
	{
		int n;
		node* it;
		std::cout << "Introduceti pozitia nodului: ";
		do {
			std::cin >> n;
		} while (n<1 || n > lista->Size);
		std::cout << "\n";
		it = lista->head;
		int i = 1;

		do
		{
			if (i == n)
				return it;
			it = it->next;
			i++;
		} while (it != NULL && i <= n);
	}
	else
	{
		//std::cout << "Lista este vida." << "\n";
		return nullptr;
	}
}

void mesaj()
{
	std::cout << "Optiuni de prelucrare lista:" << "\n";
	std::cout << "1  - push_front(key) - adauga cheia key in capul listei" << "\n";
	std::cout << "2  - push_back(key) - adauga cheia key la finalul listei" << "\n";
	std::cout << "3  - pop_front() - sterge primul element din lista" << "\n";
	std::cout << "4  - pop_back() - sterge ultimul element din lista" << "\n";
	std::cout << "5  - find(key) - cauta o cheie key in lista - returneaza pointer la nodul cu" << "\n";
	std::cout << "     cheia key sau NULL" << "\n";
	std::cout << "6  - erase(node*Nod) - sterge un element Nod din lista (NU implica cautare)." << "\n";
	std::cout << "     Nodul transmis ca parametru a fost în prealabil gasit cu find sau identificat" << "\n";
	std::cout << "     prin parcurgerea listei." << "\n";
	std::cout << "7  - remove(int key) - sterge toate aparitiile cheii key (implica cautare)" << "\n";
	std::cout << "8  - insert(node *Nod, int val) - insereaza un element cu cheia val inainte de" << "\n";
	std::cout << "     nodul indicat de Nod." << "\n";
	std::cout << "9  - empty() - verifica daca lista e vida" << "\n";
	std::cout << "10 - clear() - goleste lista." << "\n";
	std::cout << "11 - functia print() - afiseaza elementele listei (0.20 p)" << "\n";
	std::cout << "12 - functia size() - returneaza numarul de elemente din lista." << "\n";
	std::cout << "13 - palindrom(List L) - verifica daca lista este palindrom" << "\n";
	std::cout << "14 - compare(List L1, ListL2) - returneaza 1 daca" << "\n";
	std::cout << "     L1 si L2 sunt identice si 0 altfel." << "\n";

	std::cout << "Pentru testarea functionalitatii, la optiunile 6 si 8" << "\n";
	std::cout << "utilizatorul trebuie sa introduca pozitia nodului in lista." << "\n";
	std::cout << "Aceasta trebuie sa fie un nr. intreg mai mare decat 0 si" << "\n";
	std::cout << "mai mic sau egal decat marimea listei" << "\n";
	std::cout << "----------------------------------------------------------------------------------" << "\n";
}
