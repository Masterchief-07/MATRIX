#pragma once
/*
 * 2D matrix
 * using template
 * fast and powerfull
 */

#include <iostream>
#include <cassert>
#include <array>


template<typename T, int row, int col>
class Matrix
{
	private:
		std::array<T, row*col> m_matrix;
		std::size_t  const getPos(std::size_t r, std::size_t c) const; //matrix position
		T const get(std::size_t r, std::size_t c) const;
		T const get(std::size_t r) const;
		void set(T value, std::size_t r, std::size_t c);
		void set(T value, std::size_t x);
	public:
		Matrix();
		Matrix(T x);
		~Matrix();
		//print the matrix
		void const print() const;
		//transposition
		Matrix<T, row, col> Tr();
		void Tr_();
		//operator overloading
		Matrix<T, row, col> operator+=(Matrix<T,row,col> const& mat); 
		Matrix<T, row, col> operator-=(Matrix<T,row,col> const& mat); 
		Matrix<T, row, col> operator*=(Matrix<T,row,col> const& mat); 
		Matrix<T, row, col> operator/=(Matrix<T,row,col> const& mat);
		friend Matrix<T, row, col> operator+(Matrix<T,row,col> mat, Matrix<T,row,col> const& mat2){ mat+=mat2; return mat;}
		friend Matrix<T, row, col> operator-(Matrix<T,row,col> mat, Matrix<T,row,col> const& mat2){ mat-=mat2; return mat;}
		friend Matrix<T, row, col> operator*(Matrix<T,row,col> mat, Matrix<T,row,col> const& mat2){ mat*=mat2; return mat;}
		friend Matrix<T, row, col> operator/(Matrix<T,row,col> mat, Matrix<T,row,col> const& mat2){ mat/=mat2; return mat;}
		//operator overloading with value
		Matrix<T, row, col> operator+=(T value);
		Matrix<T, row, col> operator-=(T value);
		Matrix<T, row, col> operator*=(T value);
		Matrix<T, row, col> operator/=(T value);
		friend Matrix<T, row, col> operator+(Matrix<T,row,col> mat, T value){ mat+=value; return mat;}
		friend Matrix<T, row, col> operator-(Matrix<T,row,col> mat, T value){ mat-=value; return mat;}
		friend Matrix<T, row, col> operator*(Matrix<T,row,col> mat, T value){ mat*=value; return mat;}
		friend Matrix<T, row, col> operator/(Matrix<T,row,col> mat, T value){ mat/=value; return mat;}
};

// ******************************************************************************
//constructor
template<typename T, int row, int col>
Matrix<T,row,col>::Matrix()
{}

template<typename T, int row, int col>
Matrix<T,row,col>::Matrix(T x)
{
	for(auto & i: m_matrix)
	{
		i = x;
	}
}
template<typename T, int row, int col>
Matrix<T,row,col>::~Matrix()
{}

// ******************************************************************************
//get the position
template<typename T, int row, int col>
std::size_t const Matrix<T,row,col>::getPos(std::size_t x, std::size_t y) const
{
	return x*col + y;
}

// ******************************************************************************
//print the matrix
template<typename T, int row, int col>
void const Matrix<T,row,col>::print() const
{
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			std::cout<<m_matrix[getPos(i,j)]<<" ";
		}
		std::cout<<"\n";
	}
}

// ******************************************************************************
//getter setter
template<typename T, int row, int col>
T const Matrix<T, row, col>::get(std::size_t r, std::size_t c) const
{
	assert(r < row && c < col);
	return m_matrix[getPos(r,c)];
}
template<typename T, int row, int col>
T const Matrix<T, row, col>::get(std::size_t x) const
{
	assert(x<m_matrix.size());
	return m_matrix[x];
}
template<typename T, int row, int col>
void Matrix<T, row,col>::set(T value, std::size_t r, std::size_t c)
{
	m_matrix[getPos(r,c)] = value;
}
template<typename T, int row, int col>
void Matrix<T, row,col>::set(T value, std::size_t x)
{
	m_matrix[getPos(x)] = value;
}

//transposing
template<typename T, int row, int col>
Matrix<T, row, col> Matrix<T, row, col>::Tr()
{
	Matrix<T, row, col> mat = *this;
	mat.T_();
	return mat;
}
template<typename T, int row, int col>
void Matrix<T, row, col>::Tr_()
{
	int middle = row;
	row = col;
	col = middle;	
}
// ******************************************************************************
//opertor overloading
template<typename T, int row, int col>
Matrix<T, row, col> Matrix<T, row, col>::operator+=(Matrix<T,row,col> const& mat)
{
	for(std::size_t i = 0; i < m_matrix.size(); i++)
		m_matrix[i] += mat.get(i);

	return *this;
}	
template<typename T, int row, int col>
Matrix<T, row, col> Matrix<T, row, col>::operator-=(Matrix<T,row,col> const& mat)
{
	for(std::size_t i = 0; i < m_matrix.size(); i++)
		m_matrix[i] -= mat.get(i);

	return *this;
}	
template<typename T, int row, int col>
Matrix<T, row, col> Matrix<T, row, col>::operator*=(Matrix<T,row,col> const& mat)
{
	for(std::size_t i = 0; i < m_matrix.size(); i++)
		m_matrix[i] *= mat.get(i);

	return *this;
}	
template<typename T, int row, int col>
Matrix<T, row, col> Matrix<T, row, col>::operator/=(Matrix<T,row,col> const& mat)
{
	for(std::size_t i = 0; i < m_matrix.size(); i++)
		m_matrix[i] /= mat.get(i);

	return *this;
}

//operator overloading with value

template<typename T, int row, int col>
Matrix<T, row, col> Matrix<T, row,col>::operator+=(T value)
{
	for(auto &i : m_matrix)
		i += value;
	return *this;
}
template<typename T, int row, int col>
Matrix<T, row, col> Matrix<T, row,col>::operator-=(T value)
{
	for(auto &i : m_matrix)
		i -= value;
	return *this;
}	
template<typename T, int row, int col>
Matrix<T, row, col> Matrix<T, row,col>::operator*=(T value)
{
	for(auto &i : m_matrix)
		i *= value;
	return *this;
}	
template<typename T, int row, int col>
Matrix<T, row, col> Matrix<T, row,col>::operator/=(T value)
{
	for(auto &i : m_matrix)
		i /= value;
	return *this;
}	

