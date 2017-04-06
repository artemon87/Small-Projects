#include <iostream>
#include <string>
using namespace std;

int main()
{
	cout << "Please print the name you would like to reverse" << endl;
	char word[20];
	cin >> word;
	cout << "That name is " << word << endl;
	//int a=0;
	int len;
	len = strlen(word) - 1;
	for (int i = 0; i <= strlen(word) - 1; ++i)
	{
		//++a;
		char letter = word[len];
		--len;
		cout << letter << "";


	}
	hello(word);
	cout << endl;
	cout << "Number of letters " << len << endl;
	int some{ 2 };
	cout << some << endl;
	string s("Hello");
	cout << s;
	int hello(char words)
	{
		if (words == "Artem")
		{
			cout << "Your last name is Kovtunenko" << endl;
			return 0;
		}
		else
		{
			cout << "Your last name is unknown" << endl;
			return 0;
		}

		return 0;
	}