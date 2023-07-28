#pragma once
#include <iostream>
#include <windows.h>

template<class T>
class Table
{
public:
	Table(int r, int c)
	{
		rows = r;
		cols = c;
		elements = new T * [rows];
		for (int i = 0; i < rows; ++i)
			elements[i] = new T[cols]();
	}

	~Table()
	{
		for (int i = 0; i < rows; ++i)
			delete[] elements[i];
		delete[] elements;
		elements = nullptr;
	}

	const T* operator[](const int row) const
	{
		if ((row < 0) || (row >= rows)) throw std::runtime_error("Некорректный индекс обращения к таблице по индексу");
		return elements[row];
	}

	T* operator[](const int row)
	{
		if ((row < 0) || (row >= rows)) throw std::runtime_error("Некорректный индекс обращения к таблице в операторе присвоения по индексу");
		return elements[row];
	}

	Table& operator=(Table t2)
	{
		if (this != &t2) 
		{
			for (int i = 0; i < rows; ++i)
				delete[] elements[i];
			delete[] elements;
			elements = new T * [t2.rows];
			for (int i = 0; i < t2.rows; ++i)
				elements[i] = new T[t2.cols]();
			rows = t2.rows;
			cols = t2.cols;
			for (int i = 0; i < rows; ++i)
				for (int j = 0; j < cols; ++j)
					elements[i][j] = t2[i][j];
		}

		return *this;
	}

	Table(Table& t)
	{
		elements = new T * [t.rows];
		for (int i = 0; i < t.rows; ++i)
			elements[i] = new T[t.cols]();
		rows = t.rows;
		cols = t.cols;
		for (int i = 0; i < rows; ++i)
			for (int j = 0; j < cols; ++j)
				elements[i][j] = t[i][j];
	}

	int Size() const
	{
		return rows * cols;
	}

private:
	T** elements = nullptr;
	int rows = 0;
	int cols = 0;
};