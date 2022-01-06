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
		T const at(int pos) const;
		T const at(int row, int colomn) const;

		//setting value in the matrix
		void set(int pos, double value);
		void set(int row, int column, double value);

		//void printArray
		void print();

		//operator
		Matrix<T>& operator+= (Matrix<T> const& mat);
		Matrix<T>& operator-= (Matrix<T> const& mat);
		Matrix<T>& operator/= (Matrix<T> const& mat);
		Matrix<T>& operator*= (Matrix<T> const& mat);
		Matrix<T> operator+ (Matrix<T> const& mat);
		Matrix<T> operator- (Matrix<T> const& mat);
		Matrix<T> operator/ (Matrix<T> const& mat);
		Matrix<T> operator* (Matrix<T> const& mat);
	private:
		int m_dimX, m_dimY;
		std::vector<T> *m_matrix;

		//comput position
		int const getPos(int x) const;
		int const getPos(int row, int column) const ;
		//get row or column
		int const getRow() const;
		int const getCol() const;
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
int const Matrix<T>::getPos(int row, int column)const 
{
	assert(row<m_dimX && column<m_dimY);
	return row*(m_dimY) + column;
}

template<typename T>
int const Matrix<T>::getPos(int pos) const
{
	assert(pos<(m_dimY*m_dimX));
	return pos;
}

//get data at position x
template<typename T>
T const Matrix<T>::at(int pos) const
{
	return m_matrix->at(getPos(pos));
}

template<typename T>
T const Matrix<T>::at(int posX, int posY) const
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
	for(int i=0; i<m_dimX; i++)
	{	
		for(int j=0; j < m_dimY; j++)
		{
			std::cout<<this->at(i,j)<<" ";
		}
		std::cout<<"\n";
	}
	/*for(auto const& i: (*m_matrix))
		std::cout<<i<<" ";
	std::cout<<"\n";
	*/
}

//get row et columns
template<typename T>
int const Matrix<T>::getRow() const
{
	return m_dimX;
}

template<typename T>
int const Matrix<T>::getCol() const
{
	return m_dimY;
}

//operator

template<typename T>
Matrix<T>& Matrix<T>::operator+= (Matrix<T> const& mat)
{
	assert(mat.getRow() == m_dimX && mat.getCol() == m_dimY);
	for(long unsigned int i=0; i<m_matrix->size(); i++)
		(*m_matrix)[i]+=mat.at(i);
	return *this;
}
template<typename T>
Matrix<T>& Matrix<T>::operator-= (Matrix<T> const& mat)
{	
	assert(mat.getRow() == m_dimX && mat.getCol() == m_dimY);
	for(long unsigned int i=0; i<m_matrix->size(); i++)
		(*m_matrix)[i]-=mat.at(i);
	return *this;
}
template<typename T>
Matrix<T>& Matrix<T>::operator/= (Matrix<T> const& mat)
{
	assert(mat.getRow() == m_dimX && mat.getCol() == m_dimY);
	for(long unsigned int i=0; i<m_matrix->size(); i++)
		(*m_matrix)[i]/=mat.at(i);
	return *this;
}
template<typename T>
Matrix<T>& Matrix<T>::operator*= (Matrix<T> const& mat)
{
	assert(mat.getRow() == m_dimX && mat.getCol() == m_dimY);
	for(long unsigned int i=0; i < m_matrix->size(); i++)
		(*m_matrix)[i]*=mat.at(i);
	return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator+ (Matrix<T> const& mat)
{
	auto matrix(*this);
	matrix+=mat;
	return matrix;
}
template<typename T>
Matrix<T> Matrix<T>::operator- (Matrix<T> const& mat)
{
	auto matrix(*this);
	matrix-=mat;
	return matrix;
}
template<typename T>
Matrix<T> Matrix<T>::operator/ (Matrix<T> const& mat)
{
	auto matrix(*this);
	matrix/=mat;
	return matrix;
}
template<typename T>
Matrix<T> Matrix<T>::operator* (Matrix<T> const& mat)
{
	Matrix<T> matrix = *this;
	matrix*=mat;
	return matrix;
}

