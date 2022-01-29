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
		size_t _size;
		std::array<T, row*col> _matrix;
		std::size_t  _getPos(std::size_t const& r, std::size_t const& c) const; //matrix position
		T const get(std::size_t r, std::size_t c) const;
		T const get(std::size_t r) const;
		void 	set(T value, std::size_t x);
	public:
		Matrix();
		Matrix(T x);
		Matrix(Matrix<T, row, col>const& x);
		Matrix(std::array<T> const& x);
		template <size_t x>
		Matrix(Matrix<T, x, x>const& a);
		~Matrix();
		//print the matrix
		void print() const;
		//dot product
		template<size_t rowB>
		Matrix<T, row, rowB> dot(Matrix<T, col, rowB> const& x);
		//transposition
		Matrix<T, col, row> Tr();
		//ITERATOR
		auto begin() 	{return _matrix.begin();}
		auto end()	 	{return _matrix.end();}
		auto cbegin()	const {return _matrix.cbegin();}
		auto cend()	 	const {return _matrix.cend();}
		auto rbegin() 	{return _matrix.rbegin();}
		auto rend()	 	{return _matrix.rend();}
		//accesseur
		const T at(std::size_t const& r, std::size_t const& c)const { return _matrix.at(_getPos(r, c));}
		void 	set(T value, std::size_t r, std::size_t c);
		//operator overloading
		std::array<T, col> 		operator[](size_t po);
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
Matrix<T,row,col>::Matrix():_row(row), _col(col),_size{row*col}
{}

template<typename T, size_t row, size_t col>
Matrix<T,row,col>::Matrix(T x):Matrix{}
{	
	_matrix.fill(x);
}
template<typename T, size_t row, size_t col>
Matrix<T,row,col>::~Matrix()
{}
template<typename T, size_t row, size_t col>
Matrix<T, row, col>::Matrix(Matrix<T, row, col>const& x):Matrix{}
{
	auto jt = x.cbegin();
	for(auto it = begin(); it!= end(); ++it, ++jt)
	{
		*it = *jt;
	}
}

template<typename T, size_t row, size_t col>
template<size_t a>
Matrix<T, row, col>::Matrix(Matrix<T, a, a>const& x):_row(a),_col(a),_size{a*a}
{
	x.print();
	for(size_t i=0; i < row; i++)
	{	
		for(size_t j=0; j < col; ++j)
		{
			set(x.at(j,i), i, j);
		}

	}
}

// ******************************************************************************
//get the position
template<typename T, size_t row, size_t col>
std::size_t Matrix<T,row,col>::_getPos(std::size_t const& r, std::size_t const& c) const
{
	return r*col + c;
}

// ******************************************************************************
//print the matrix
template<typename T, size_t row, size_t col>
void Matrix<T,row,col>::print() const
{
	for(size_t i=0; i<_row; i++)
	{
		for(size_t j=0; j<_col; j++)
		{
			std::cout<<_matrix[_getPos(i,j)]<<" ";
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
	return _matrix.at(_getPos(r,c));
}
template<typename T, size_t row, size_t col>
T const Matrix<T, row, col>::get(std::size_t x) const
{
	assert(x<_matrix.size());
	return _matrix.at(x);
}
template<typename T, size_t row, size_t col>
void Matrix<T, row,col>::set(T value, std::size_t r, std::size_t c)
{
	_matrix[_getPos(r,c)] = value;
}
template<typename T, size_t row, size_t col>
void Matrix<T, row,col>::set(T value, std::size_t x)
{
	_matrix[x] = value;
}

// ******************************************************************************
//transposing
template<typename T, size_t row, size_t col>
Matrix<T, col, row> Matrix<T, row, col>::Tr()
{
	Matrix<T, col, row> mat{};
	for(size_t i = 0;  i < col; ++i)
	{
		for(size_t j = 0; j < row; ++j)
		{
			mat.set(get(j,i),i,j);
		}
	}
	return mat;
}
// ******************************************************************************
//Dot product
template<typename T, size_t row, size_t col>
template<size_t rowB>
Matrix<T, row, rowB> Matrix<T, row, col>::dot(Matrix<T, col, rowB> const& x)
{
	Matrix<T, row, rowB> mat;
	for(size_t i = 0;  i < row; ++i)
	{
		for(size_t k = 0; k < rowB; ++k)
		{
			T sum = 0;
			for(size_t j = 0; j < col; ++j)
			{
				sum += this->at(i,j) * x.at(j,k);
			}
			mat.set(sum, i, k);
		}
	}
	return mat;
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

