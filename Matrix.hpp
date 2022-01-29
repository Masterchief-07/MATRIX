/*
	Matrix is a 3Dim matrices
	lightweight and performant
	
*/

#pragma once

#include <cassert>
#include <ostream>

namespace Matrix
{
	template<typename T = double>
	class Matrix
	{
		private:
			//priv variables
			size_t _x, _y;
			const size_t _size;
			T *_arr;
			//priv func
			size_t const _getIndex(size_t const x, size_t const y) const { assert(x < _x && y < _y); return x*_y + y;}

		public:
		//constructor
			Matrix(size_t x, size_t y = 1): _x{x}, _y{y}, _size{x*y}
			{
				_arr = new T[_size];
			}
			Matrix(size_t x, size_t y, T val):Matrix(x,y)
			{
				for(size_t i=0; i < _size; ++i)
					_arr[i] = val;
			}
			~Matrix(){delete[] _arr;}
		//utils func
			void print();
			T const get(size_t const& x, size_t const& y) const;
			void set(size_t const& x, size_t const& y, T const& val);
			size_t const getX() const{ return _x;}
			size_t const getY() const{ return _y;}
		//operator overload
			Matrix<T>* operator+=(Matrix<T> const& a);
			Matrix<T>* operator-=(Matrix<T> const& a);
			Matrix<T>* operator/=(Matrix<T> const& a);
			Matrix<T>* operator*=(Matrix<T> const& a);

			//Matrix<T> operator+(Matrix<T>& a, Matrix<T>& b);
			//Matrix<T> operator-(Matrix<T>& a, Matrix<T>& b);
			//Matrix<T> operator*(Matrix<T>& a, Matrix<T>& b);
			//Matrix<T> operator/(Matrix<T>& a, Matrix<T>& b);

			bool operator==(Matrix<T> const& c);
			bool operator!=(Matrix<T> const& c);
			bool operator>=(Matrix<T> const& c) = delete;
			bool operator>(Matrix<T> const& c) = delete;
			bool operator<=(Matrix<T> const& c) = delete;
			bool operator<(Matrix<T> const& c) = delete;
			

	};

	template<typename T>
	void Matrix<T>::print()
	{
		for(size_t i=0; i < _x; ++i)
		{
			for(size_t j=0; j < _y; ++j)
			{
				std::cout<<_arr[_getIndex(i,j)];
			}
			std::cout<<"\n";
		}
	}

	//***************utils func**************//
	template<typename T>
	T const Matrix<T>::get(size_t const& x, size_t const& y) const
	{	
		return _arr[_getIndex(x, y)];
	}
	template<typename T>
	void Matrix<T>::set(size_t const& x, size_t const& y, T const& val)
	{
		_arr[_getIndex(x, y)] = val;
	}

	//***************operator**************//
	template<typename T>
	bool Matrix<T>::operator==(Matrix<T> const& c)
	{
		if(!(_x == c.getX() && _y == c.getY()))
			return false;
		for(size_t i = 0; i < _x; ++i)
		{
			for(size_t j = 0;  j < _y; ++j)
			{
				if(this->get(i, j) != c.get(i, j))
					return false;
			}
		}
		return true;
	}

	template<typename T>
	bool Matrix<T>::operator!=(Matrix<T> const& c)
	{
		return !(*this == c);
	}

	template<typename T>
	Matrix<T>* Matrix<T>::operator+=(Matrix<T> const& a)
	{
		assert(_x == a.getX() && _y == a.getY());
		for(size_t i = 0; i < _x; ++i)
		{
			for(size_t j = 0;  j < _y; ++j)
			{
				_arr[_getIndex(i,j)] += a.get(i,j);
			}
		}
		return this;
	}
	template<typename T>
	Matrix<T>* Matrix<T>::operator-=(Matrix<T> const& a)
	{
		assert(_x == a.getX() && _y == a.getY());
		for(size_t i = 0; i < _x; ++i)
		{
			for(size_t j = 0;  j < _y; ++j)
			{
				_arr[_getIndex(i,j)] -= a.get(i,j);
			}
		}
		return this;
	}
	template<typename T>
	Matrix<T>* Matrix<T>::operator/=(Matrix<T> const& a)
	{
		assert(_x == a.getX() && _y == a.getY());
		for(size_t i = 0; i < _x; ++i)
		{
			for(size_t j = 0;  j < _y; ++j)
			{
				_arr[_getIndex(i,j)] /= a.get(i,j);
			}
		}
		return this;
	}
	template<typename T>
	Matrix<T>* Matrix<T>::operator*=(Matrix<T> const& a)
	{
		assert(_x == a.getX() && _y == a.getY());
		for(size_t i = 0; i < _x; ++i)
		{
			for(size_t j = 0;  j < _y; ++j)
			{
				_arr[_getIndex(i,j)] *= a.get(i,j);
			}
		}
		return this;
	}
};