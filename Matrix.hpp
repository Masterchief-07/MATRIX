#pragma once
/*
 *
 *a Matrix class
 *Wich can perform matrix operations
 *very simple and powerfull class
 *use a 1d array and convert it into a 2d matrix
 *
 */

#include <vector>
#include <cassert>
#include <iostream>

template<typename T>
class Matrix
{
	public:
		Matrix();
		Matrix(int dimY);
		Matrix(int row, int colomn);
		~Matrix();

		//getting value in the matrix
		T at(int pos);
		T at(int row, int colomn);

		//setting value in the matrix
		void set(int pos, double value);
		void set(int row, int column, double value);

		//void printArray
		void print();
	private:
		int m_dimX, m_dimY;
		std::vector<T> *m_matrix;

		//comput position
		int getPos(int x);
		int getPos(int row, int column);
};



template<typename T>
Matrix<T>::Matrix()
{
	m_matrix = new std::vector<T>(1);
}


template<typename T>
Matrix<T>::Matrix(int dim): m_dimX(1), m_dimY(dim)
{
	assert(dim>0);
	m_matrix = new std::vector<T>(dim, 99999.f);
	std::cout<<"m_matrix.size: "<<m_matrix.size()<<"\n";	
}


template<typename T>
Matrix<T>::Matrix(int dimX, int dimY):m_dimX(dimX), m_dimY(dimY)
{
	assert(dimX>0 &&  dimY>0);
	m_matrix = new std::vector<T>(dimY * dimX, 0.f);
	std::cout<<"m_matrix.size: "<<m_matrix->size()<<"\n";
}

//destructor
template<typename T>
Matrix<T>::~Matrix()
{
	delete m_matrix;
}

//comput the position
template<typename T>
int Matrix<T>::getPos(int row, int column)
{
	assert(row<m_dimX && column<m_dimY);
	return row*(m_dimY) + column;
}

template<typename T>
int Matrix<T>::getPos(int pos)
{
	assert(pos<m_dimY);
	return pos;
}

//get data at position x
template<typename T>
T Matrix<T>::at(int pos)
{
	return m_matrix->at(getPos(pos));
}

template<typename T>
T Matrix<T>::at(int posX, int posY)
{
	return m_matrix->at(getPos(posX, posY)); 

}

//setting data at position

template<typename T>
void Matrix<T>::set(int pos, double value)
{
	(*m_matrix)[getPos(pos)] = value;
}

template<typename T>
void Matrix<T>::set(int row, int column, double value)
{
	(*m_matrix)[getPos(row, column)] = value;
}


//print array
template<typename T>
void Matrix<T>::print()
{
	for(auto const& i: (*m_matrix))
		std::cout<<i<<" ";
	std::cout<<"\n";
}
