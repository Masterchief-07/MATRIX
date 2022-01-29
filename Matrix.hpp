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
			size_t _getIndex(size_t x, size_t y){ return x*_y + y;}

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
};