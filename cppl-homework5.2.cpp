#include "Table.h"
#include <iostream>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int row = 5;
	int col = 3;

	Table<int> newTable(row, col);

	newTable[0][0] = 4;
	newTable[1][2] = 5;

	std::cout << newTable[0][0] << std::endl;
	std::cout << newTable[1][2] << std::endl;

	std::cout << std::endl;
	std::cout << newTable.Size() << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
			std::cout << newTable[i][j] << "\t";
		std::cout << std::endl;
	}

	Table<int> nt(newTable);

	std::cout << std::endl;
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
			std::cout << nt[i][j] << "\t";
		std::cout << std::endl;
	}

	std::cout << std::endl;

	row = 4;
	col = 2;

	Table<int> newTable2(row, col);

	newTable2[0][1] = 3;
	newTable2[1][1] = 2;
	newTable2[3][0] = 10;

	try
	{
		std::cout << "newTable2[8][1] = 4;" << std::endl;
		newTable2[8][1] = 4;
	}
	catch (std::runtime_error& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	std::cout << std::endl;
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
			std::cout << newTable2[i][j] << "\t";
		std::cout << std::endl;
	}

	nt = newTable2;

	std::cout << std::endl;
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
			std::cout << nt[i][j] << "\t";
		std::cout << std::endl;
	}

	std::cout << std::endl;

	const Table<int> newTable3(nt);

	std::cout << newTable3[1][1] << std::endl;
	std::cout << newTable3[3][0] << std::endl;

	std::cout << std::endl;

	try
	{
		std::cout << "std::cout << newTable3[10][10] << std::endl;" << std::endl;
		std::cout << newTable3[10][10] << std::endl;
	}
	catch (std::runtime_error& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	return 0;
}