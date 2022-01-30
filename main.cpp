#include <iostream>
#include "Matrix.hpp"

int main()
{
	using namespace MATRIX;

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

	std::cout<<"array init\n";
	Matrix<double, 2,4> matrix5 = {{1,2,3,4,6,7,8,9}};
	Matrix<double, 4,1> matrix6{{5,6,7,8}};
	matrix5.print();
	matrix6.print();

	std::cout<<"dot product\n";
	auto matrix7 = matrix5.dot(matrix6);
	matrix7.print();

	std::cout<<"Matrix8: \n";
	Matrix<double, 3,3> matrix8 = {{1.f,2.f,3.f,4.f,5.f,6.f,7.f,8.f,9.f}};
	matrix8.print();
	auto shape = matrix8.shape();
	std::cout<<"shape: "<<shape.first << " " << shape.second <<"\n";
	std::cout<<"size: "<<matrix8.size()<<"\n";
	std::cout<<"matrix8 norm: "<<matrix8.norm()<<"\n";

	std::cout<<"min: "<<matrix8.min()<<"\n";
	std::cout<<"max: "<<matrix8.max()<<"\n";
	std::cout<<"mean: "<<matrix8.mean()<<"\n";
	std::cout<<"sum: "<<matrix8.sum()<<"\n";
	auto argmin = matrix8.argMin();
	auto argmax = matrix8.argMax();
	std::cout<<"argmin x: "<<argmin.first<<" y: "<<argmin.second<<" \n";
	std::cout<<"argmax x: "<<argmax.first<<" y: "<<argmax.second<<" \n";


	return 0;
}
