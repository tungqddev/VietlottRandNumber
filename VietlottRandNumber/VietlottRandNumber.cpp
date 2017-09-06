#include <iostream>
#include <vector>
#include "string"
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

void main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	time_t rawtime = time(NULL);
	struct tm timeinfo;
	char buffer[80];
	time(&rawtime);
	localtime_s(&timeinfo,&rawtime);

	strftime(buffer, sizeof(buffer), "%d-%m-%Y", &timeinfo);
	std::string str(buffer);

	static vector<int> generatedValues;
	int num;
	while (generatedValues.size() < 7)
	{
		srand(time(NULL));
		num = rand() % 45;
		if ((std::find(generatedValues.begin(), generatedValues.end(), num) != generatedValues.end()))
		{
			continue;
		}
		if (num == 0)
			generatedValues.push_back(45);
		else
			generatedValues.push_back(num);

	}
	SetConsoleTextAttribute(hConsole, 10);
	system("color 0");
	std::cout << "DU DOAN KET QUA VIETLOTT NGAY " << str;
	std::cout << endl;

	SetConsoleTextAttribute(hConsole, 14);
	for (int i = 0; i < 40; ++i)
		std::cout << "*";
	std::cout <<endl;

	SetConsoleTextAttribute(hConsole, 14);
	for (int i = 0; i < 10; ++i)
		std::cout << ">";
	std::cout << " ";

	SetConsoleTextAttribute(hConsole, 11);
	for (auto i = generatedValues.begin(); i != generatedValues.end(); ++i)
		std::cout << *i << ' ';

	SetConsoleTextAttribute(hConsole, 14);
	for (int i = 0; i < 10; ++i)
		std::cout << "<";

	std::cout << endl;
	SetConsoleTextAttribute(hConsole, 14);
	for (int i = 0; i < 40; ++i)
		std::cout << "*";
	std::cout << endl;

	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "Author:TungQD";

	cin.get();
}
