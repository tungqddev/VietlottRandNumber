#include <iostream>
#include <vector>
#include "string"
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <thread>

using namespace std;

void main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	time_t rawtime = time(NULL);
	struct tm timeinfo;
	char buffer[80];
	char timeloopbuf[9];
	time(&rawtime);
	localtime_s(&timeinfo,&rawtime);

	strftime(buffer, sizeof(buffer), "%d-%m-%Y", &timeinfo);
	std::string str(buffer);

	strftime(timeloopbuf, sizeof(timeloopbuf), "%Y%m%d", &timeinfo);
	std::string timeloop(timeloopbuf);

	std::string::size_type sz;   // alias of size_t
	int timeloopdec = std::stoi(timeloop, &sz);

	static vector<int> generatedValues;
	int num;
	while (generatedValues.size() < 6)
	{
		for (int i = 0; i < timeloopdec; i++)
		{
			srand((int)time(0));
			num = rand() % 45;
		}

		if (num == 0)
			num = 45;
		if ((std::find(generatedValues.begin(), generatedValues.end(), num) != generatedValues.end()))
		{
			continue;
		}
			generatedValues.push_back(num);
			//srand((int)time(0));
			//num = rand() % 100;
			//std::this_thread::sleep_for(std::chrono::milliseconds(num));
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
