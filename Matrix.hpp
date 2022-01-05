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
class Matrix
{
	public:
		Matrix();
		Matrix(int dimY);
		Matrix(int row, int colomn);
		~Matrix();

		//getting value in the matrix
		double at(int pos);
		double at(int row, int colomn);

		//setting value in the matrix
		void set(int pos, double value);
		void set(int row, int column, double value);
	private:
		int m_dimX, m_dimY;
		std::vector<double> *m_matrix;

		//comput position
		int getPos(int x);
		int getPos(int row, int column);
};
