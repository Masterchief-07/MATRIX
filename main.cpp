#include <iostream>
#include "Matrix.hpp"

int main()
{
	std::cout<<"begin \n";
	//const size_t X=5, Y=3;
	Matrix::Matrix<double> matrix{10,2, 4.f};
	matrix.print();

	std::cout<<"test equality\n";
	Matrix::Matrix<double> matrix2{10,2, 4.f};
	bool t = matrix == matrix2;
	std::cout << t << "\n";

	std::cout<<"add +=\n";
	matrix+=matrix2;
	matrix.print();

	std::cout<<"subst -=\n";
	matrix-=matrix2;
	matrix.print();
	std::cout<<"multi *=\n";
	matrix*=matrix2;
	matrix.print();
	std::cout<<"divide /=\n";
	matrix/=matrix2;
	matrix.print();
	//test iterator
	std::cout<<"iterator\n";
	for(auto it = matrix.begin(); it != matrix.end(); ++it)
	{
		std::cout<<*it<<" ";
	}
	std::cout<<"\n";
	//test range based loop
	std::cout<<"range based loop\n";
	for(auto i: matrix)
	{
		std::cout<<i<<" ";
	}
	std::cout<<"\n";
	
	/*
	std::cout<<"op2 add: \n";
	auto matrix3 = matrix + matrix2;
	matrix3.print();
	std::cout<<"op2 subst: \n";
	matrix3 = matrix - matrix2;
	matrix3.print();
	std::cout<<"op2 multi: \n";
	matrix3 = matrix * matrix2;
	matrix3.print();
	std::cout<<"op2 divide: \n";
	matrix3 = matrix / matrix2;
	matrix3.print();

	double value = 3.6f;
	std::cout<<"op3 add \n";
	matrix+=value;
	matrix.print();
	std::cout<<"op3 subst \n";
	matrix-=value;
	matrix.print();
	std::cout<<"op3 multi \n";
	matrix*=value;
	matrix.print();
	std::cout<<"op3 divide \n";
	matrix/=value;
	matrix.print();

	std::cout<<"tranposing \n";
	auto matrix4 = matrix.Tr();
	matrix4.print();
	std::cout<<"tranposing \n";
	matrix4.Tr_();
	matrix4.print();
	*/
	return 0;
}
