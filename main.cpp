#include <iostream>
#include "Matrix.hpp"

int main()
{
	std::cout<<"begin \n";
	const size_t X=5, Y=3;
	Matrix<double, X, Y> matrix{2.f};
	Matrix<double, X, Y> matrix2{3.f};
	matrix.print();
	matrix2.print();

	std::cout<<"add \n";
	matrix+=matrix2;
	matrix.print();
	std::cout<<"subst \n";
	matrix-=matrix2;
	matrix.print();
	std::cout<<"multi \n";
	matrix*=matrix2;
	matrix.print();
	std::cout<<"divide \n";
	matrix/=matrix2;
	matrix.print();
	
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

	auto matrix5 = matrix.dot(matrix4);
	matrix5.print();
	

	return 0;
}
