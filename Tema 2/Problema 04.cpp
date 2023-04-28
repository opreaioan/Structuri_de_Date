//Tema 2 Problema 4

#include <iostream>
#include <stack>
#include <string>

bool parCorecta(std::string paranteze);

int main()
{
	std::string paranteze= "{{[()()]}";
	if (parCorecta(paranteze))
		std::cout << "Parantezarea este corecta."<<"\n";
	else std::cout << "Parantezarea nu este corecta." << "\n";
	
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
	return stivaParanteze.empty();
}
