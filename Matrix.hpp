#pragma once
/*
 * 2D matrix
 * using template
 * fast and powerfull
 */

#include <iostream>
#include <cassert>
#include <array>


template<typename T, size_t row, size_t col>
class Matrix
{
	private:
		size_t _row, _col;
		std::array<T, row*col> _matrix;
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
template<typename T, size_t row, size_t col>
Matrix<T,row,col>::Matrix():_row(row), _col(col)
{}

template<typename T, size_t row, size_t col>
Matrix<T,row,col>::Matrix(T x):_row(row), _col(col)
{
	for(auto & i: _matrix)
	{
		i = x;
	}
}
template<typename T, size_t row, size_t col>
Matrix<T,row,col>::~Matrix()
{}

// ******************************************************************************
//get the position
template<typename T, size_t row, size_t col>
std::size_t const Matrix<T,row,col>::getPos(std::size_t x, std::size_t y) const
{
	return x*col + y;
}

// ******************************************************************************
//print the matrix
template<typename T, size_t row, size_t col>
void const Matrix<T,row,col>::print() const
{
	for(size_t i=0; i<_row; i++)
	{
		for(size_t j=0; j<_col; j++)
		{
			std::cout<<_matrix[getPos(i,j)]<<" ";
		}
		std::cout<<"\n";
	}
}

// ******************************************************************************
//getter setter
template<typename T, size_t row, size_t col>
T const Matrix<T, row, col>::get(std::size_t r, std::size_t c) const
{
	assert(r < _row && c < _col);
	return _matrix[getPos(r,c)];
}
template<typename T, size_t row, size_t col>
T const Matrix<T, row, col>::get(std::size_t x) const
{
	assert(x<_matrix.size());
	return _matrix[x];
}
template<typename T, size_t row, size_t col>
void Matrix<T, row,col>::set(T value, std::size_t r, std::size_t c)
{
	_matrix[getPos(r,c)] = value;
}
template<typename T, size_t row, size_t col>
void Matrix<T, row,col>::set(T value, std::size_t x)
{
	_matrix[getPos(x)] = value;
}

// ******************************************************************************
//transposing
template<typename T, size_t row, size_t col>
Matrix<T, row, col> Matrix<T, row, col>::Tr()
{
	Matrix<T, row, col> mat{*this};
	//mat.T_();
	mat.Tr_();
	return mat;
}
template<typename T, size_t row, size_t col>
void Matrix<T, row, col>::Tr_()
{
	size_t middle = _row;
	_row = _col;
	_col = middle;	
}
// ******************************************************************************
//opertor overloading
template<typename T, size_t row, size_t col>
Matrix<T, row, col> Matrix<T, row, col>::operator+=(Matrix<T,row,col> const& mat)
{
	for(std::size_t i = 0; i < _matrix.size(); i++)
		_matrix[i] += mat.get(i);

	return *this;
}	
template<typename T, size_t row, size_t col>
Matrix<T, row, col> Matrix<T, row, col>::operator-=(Matrix<T,row,col> const& mat)
{
	for(std::size_t i = 0; i < _matrix.size(); i++)
		_matrix[i] -= mat.get(i);

	return *this;
}	
template<typename T, size_t row, size_t col>
Matrix<T, row, col> Matrix<T, row, col>::operator*=(Matrix<T,row,col> const& mat)
{
	for(std::size_t i = 0; i < _matrix.size(); i++)
		_matrix[i] *= mat.get(i);

	return *this;
}	
template<typename T, size_t row, size_t col>
Matrix<T, row, col> Matrix<T, row, col>::operator/=(Matrix<T,row,col> const& mat)
{
	for(std::size_t i = 0; i < _matrix.size(); i++)
		_matrix[i] /= mat.get(i);

	return *this;
}

//operator overloading with value

template<typename T, size_t row, size_t col>
Matrix<T, row, col> Matrix<T, row,col>::operator+=(T value)
{
	for(auto &i : _matrix)
		i += value;
	return *this;
}
template<typename T, size_t row, size_t col>
Matrix<T, row, col> Matrix<T, row,col>::operator-=(T value)
{
	for(auto &i : _matrix)
		i -= value;
	return *this;
}	
template<typename T, size_t row, size_t col>
Matrix<T, row, col> Matrix<T, row,col>::operator*=(T value)
{
	for(auto &i : _matrix)
		i *= value;
	return *this;
}	
template<typename T, size_t row, size_t col>
Matrix<T, row, col> Matrix<T, row,col>::operator/=(T value)
{
	for(auto &i : _matrix)
		i /= value;
	return *this;
}	

