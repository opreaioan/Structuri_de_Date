#include <iostream>
#include <stack>
#include <string>

bool parCorecta(std::string paranteze);

int main()
{

	std::string paranteze;
	std::cout << "Introduceti sirul de paranteze: ";
	std::cin >> paranteze;
	if (parCorecta(paranteze))
		std::cout << "Parantezarea este corecta.";
	else std::cout << "Parantezarea nu este corecta.";
	return 0;
}

bool parCorecta(std::string paranteze)
{
	std::stack<char> stivaParanteze;
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
	if (!stivaParanteze.empty())
		return false;
	else
		return true;
}
