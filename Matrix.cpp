#include "Matrix.hpp"

//constructeur
Matrix::Matrix(): m_dimX(1), m_dimY(1)
{
	m_matrix = new std::vector<double>(1);
}

Matrix::Matrix(int dimY):m_dimX(1), m_dimY(dimY)
{
	assert(dimY>0);
	m_matrix = new std::vector<double>(dimY, 0.f);
	std::cout<<"m_matrix.size: "<<m_matrix->size()<<"\n";
}

Matrix::Matrix(int dimX, int dimY):m_dimX(dimX), m_dimY(dimY)
{
	assert(dimX>0 &&  dimY>0);
	m_matrix = new std::vector<double>(dimY * dimX, 0.f);
	std::cout<<"m_matrix.size: "<<m_matrix->size()<<"\n";
}

//destructor
Matrix::~Matrix()
{
	delete m_matrix;
}

//comput the position
int Matrix::getPos(int row, int column)
{
	assert(row<m_dimX && column<m_dimY);
	return row*m_dimX + column;
}

int Matrix::getPos(int pos)
{
	assert(pos<m_dimY);
	return pos;
}

//get data at position x
double Matrix::at(int pos)
{
	return m_matrix->at(getPos(pos));
}

double Matrix::at(int posX, int posY)
{
	return m_matrix->at(getPos(posX, posY)); 

}

//setting data at position

void Matrix::set(int pos, double value)
{
	(*m_matrix)[getPos(pos)] = value;
}

void Matrix::set(int row, int column, double value)
{
	(*m_matrix)[getPos(row, column)] = value;
}

