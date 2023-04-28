//Tema 2 Problema 5

#include <iostream>
#include <queue>
#include <string>

class Stiva 
{
private:
	std::queue<char> q1, q2;
public:
	void push(char x) 
{
		q1.push(x);
	}
	void pop() 
{
		if (q1.empty())
{
			return;
		}
		while (q1.size() > 1) 
{
			q2.push(q1.front());
			q1.pop();
		}
		q1.pop();
		while (!q2.empty()) 
{
			q1.push(q2.front());
			q2.pop();
		}
	}
	char top() 
{
		if (q1.empty()) 
{
			return '\0';
		}

		while (q1.size() > 1) 
{
			q2.push(q1.front());
			q1.pop();
		}

		char top = q1.front();
		q2.push(top);
		q1.pop();

		while (!q2.empty()) 
{
			q1.push(q2.front());
			q2.pop();
		}

		return top;
	}
	bool empty() 
{
		return q1.empty();
	}
};

bool parCorecta(std::string paranteze);

int main()
{
	std::string paranteze = "{[()()]}";
	if (parCorecta(paranteze))
		std::cout << "Parantezarea este corecta." << "\n";
	else std::cout << "Parantezarea nu este corecta." << "\n";

	return 0;
}

bool parCorecta(std::string paranteze)
{
	Stiva stivaParanteze;
	int nivel = 0;
	for (char paranteza : paranteze)
	{
		switch (paranteza)
		{
		case '(':
		{
			if (stivaParanteze.empty() || nivel > 0)
			{
				stivaParanteze.push(paranteza);
				nivel = 1;
				break;
			}
			else
				return false;
		}
		case '[':
		{
			if (stivaParanteze.empty() || nivel > 1)
			{
				stivaParanteze.push(paranteza);
				nivel = 2;
				break;
			}
			else
				return false;
		}
		case '{':
		{
			if (stivaParanteze.empty() || nivel > 2)
			{
				stivaParanteze.push(paranteza);
				nivel = 3;
				break;
			}
			else
				return false;

		}
		case ')':
		{
			if (stivaParanteze.empty() || stivaParanteze.top() != '(')
				return false;
			else
			{
				stivaParanteze.pop();
				break;
			}
		}
		case ']':
		{
			if (stivaParanteze.empty() || stivaParanteze.top() != '[')
				return false;
			else
			{
				stivaParanteze.pop();
				break;
			}
		}
		case '}':
		{
			if (stivaParanteze.empty() || stivaParanteze.top() != '{')
				return false;
			else
			{
				stivaParanteze.pop();
				break;
			}
		}
		}
	}
	return stivaParanteze.empty();
}
