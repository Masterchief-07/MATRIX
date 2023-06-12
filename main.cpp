#include <matrix1d.hpp>
#include <matrix2d.hpp>
int main()
{
    matrix::Matrix1D<int> mat1d{{1, 2,3,4,5,6,7,8}};
    std::cout<<mat1d<<"\n";
    matrix::Matrix2D<int> mat2d{2,4,{1,2,3,4,5,6,7,8}};
    std::cout<<mat2d<<"\n";
    std::cout<<mat2d+mat1d<<"\n";
    return 0;
}