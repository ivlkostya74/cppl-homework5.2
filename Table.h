#pragma once
#include <iostream>
#include <windows.h>

template<class T>
class Table
{
	
private:
	T** elements = nullptr;
	int rows = 0;
	int cols = 0;
	int size = 0;
public:
	Table(int r, int c): rows{r},cols{c}
	{
		
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


	Table(const Table& t)
	{

		this->rows = t.rows;
		this->cols = t.cols;


		elements = new T * [this->rows] {};
		for (int i = 0; i < this->rows; i++)
		{
			elements[i] = new T[this->cols]{};
		}
		

		for (size_t i = 0; i < t.rows; i++)
		{
			for (size_t j = 0; j < t.cols; j++)
			{
				this->elements[i][j] = t.elements[i][j];
			}
		}
		std::cout << std::endl;

		};


	T& operator()(int i, int j)
	{
		if (i >= rows || i < 0) throw std::out_of_range("out_of_range index i(one)");
		if (j >= cols || j < 0) throw std::out_of_range("out_of_range index j(one)");

		return elements[i][j];
	};


	
	int Size() const
	{
		return rows * cols;
	}
	
	class ArrayRow
	{
	public:
		ArrayRow(T* r, const int c) : rows(r), cols(c) { }

		T& operator[](int i)
		{
			if (i >= cols || i < 0) throw std::out_of_range("out_of_range index j(two)");
			return rows[i];
		}
	private:
		T* rows;
		int cols = 0;
	};
	ArrayRow operator[](const int i) const
	{
		if (i >= rows || i < 0) throw std::out_of_range("out_of_range index i(one)");

		return ArrayRow(elements[i], cols);
	};
	void printArr()
	{
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < cols; j++)
			{
				std::cout << elements[i][j] << '\t';
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	};

	Table& operator=(const Table t2)
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

	
	


};