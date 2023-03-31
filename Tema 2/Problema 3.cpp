//Tema 2 Problema 3

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>

class node
{
public:
	std::pair<std::string, int>  info = { "" , 0 };
	node* next;
};

class Queue
{
public:
	node* head = nullptr;
	node* tail = nullptr;
	int nr_elem = 0;

	void push(std::string s, int elem)
	{
		std::pair<std::string, int>  el;
		el = make_pair(s, elem);
		nr_elem++;

		node* newNode = new node;
		newNode->info.first = el.first;
		newNode->info.second = el.second;

		if (tail != nullptr)
		{
			tail->next = newNode;
		}
		else
			head = newNode;
		tail = newNode;
	}

	void pop()
	{
		if (!empty())
		{
			node* aux = head;

			if (size() > 1)
				head = head->next;
			else
			{
				head = nullptr;
				tail = nullptr;
			}
			delete aux;
			nr_elem--;

		}
	}

	node* front()
	{
		return head;
	}

	node* back()
	{
		return tail;
	}

	bool empty()
	{
		return head == nullptr;
	}

	void clear()
	{
		while (!empty())
			pop();
	}

	int size()
	{
		return nr_elem;
	}

	void printQ()
	{
		node* it = head;
		if (it)
			while (it)
			{
				std::cout << std::left << std::setw(15) << it->info.first << " " << it->info.second << "\n";
				it = it->next;
			}
		else {
			std::cout << "Coada este vida." << "\n";
			return;
		}
	}
};

void readQ(Queue* coada, std::string s, int& timp, int& nrCandidati)
{
	srand(time(nullptr));
	std::ifstream fInput(s);
	std::string nume;
	fInput >> timp >> nrCandidati;
	int i = 0;
	while (std::getline(fInput >> std::ws, nume) && i < nrCandidati)
	{
		if (!nume.empty())
		{
			int random = rand() % 11 + 5;
			coada->push(nume, random);
			i++;
		}
	}
	fInput.close();
}

void evaluare(Queue* coada,int ore)
{
	int minute = ore * 60;
	node* it = coada->head;
	while (minute >= it->info.second)
	{
		minute -= it->info.second;
		it = it->next;
		coada->pop();
		if (it == nullptr) break;
	}
}

void writeQ(Queue* coada, std::string s)
{
	std::ofstream fOutput(s);
	node* it = coada->head;
	while (it != nullptr)
	{
		fOutput << it->info.first << "\n";
		it = it->next;
	}
	fOutput.close();
}

int main()
{
	Queue* coada = new Queue;

	int ore, minute, nr_candidati;
	std::string z1 = "fisInputPb3.txt";
	std::string z2 = "fisOutputPb3.txt";

	readQ(coada, z1, ore, nr_candidati);
	evaluare(coada, ore);
	writeQ(coada, z2);
	delete coada;
	return 0;
}
