#include <catch2/catch_test_macros.hpp>
// #include <catch2/benchmark/catch_benchmark.hpp>
#include <matrix2d.hpp>
// #include <linear.hpp>

TEST_CASE("test MATRIX2D", "[MATRIX2D]") {
    SECTION("INITIALIZATION")
    {
        matrix::Matrix2D<double> mat{10,10};
        REQUIRE(mat.size() == 100);
        REQUIRE(mat.getColumns() == 10);
        REQUIRE(mat.getRows() == 10);
        for(size_t i=0; i<mat.getRows(); i++)
        {
            for(size_t j=0; j<mat.getColumns(); j++)
            {
                REQUIRE(mat.at(i,j) == 0);
            }
        }
        mat = matrix::Matrix2D<double>{5,4, 3.99};
        REQUIRE(mat.size() == 20);
        REQUIRE(mat.getColumns() == 4);
        REQUIRE(mat.getRows() == 5);
        for(size_t i=0; i<mat.getRows(); i++)
        {
            for(size_t j=0; j<mat.getColumns(); j++)
            {
                REQUIRE(mat.at(i,j) == 3.99);
            }
        }
        
        mat = matrix::Matrix2D<double>{2, 2, {1,2,3,4}};
        REQUIRE(mat.size() == 4);
        REQUIRE(mat.getColumns() == 2);
        REQUIRE(mat.getRows() == 2);
        double index = 1;
        for(size_t i=0; i<mat.getRows(); i++)
        {
            for(size_t j=0; j<mat.getColumns(); j++)
            {
                REQUIRE(mat.at(i,j) == index);
                index++;
            }
        }
        
        mat = matrix::Matrix2D<double>{matrix::Matrix1D<double>{{1,2,3,4,5}}};
        REQUIRE(mat.size() == 5);
        REQUIRE(mat.getColumns() == 5);
        REQUIRE(mat.getRows() == 1);
        index = 1;
        for(size_t i=0; i<mat.getRows(); i++)
        {
            for(size_t j=0; j<mat.getColumns(); j++)
            {
                REQUIRE(mat.at(i,j) == index);
                index++;
            }
        }
    }

    SECTION("Transpose")
    {
        matrix::Matrix2D<double> mat{2, 3, {1,2,3,4,5,6}};
        matrix::Matrix2D<double> result{3, 2, {1,4,2,5,3,6}};
        REQUIRE(mat.Tr() == result);
        mat = matrix::Matrix2D<double>{matrix::Matrix1D<double>{{1,2,3,4,5}}};
        mat = mat.Tr();
        REQUIRE(mat.getRows() == 5);
        REQUIRE(mat.getColumns() == 1);
    }

    SECTION("Dot Product")
    {
        matrix::Matrix2D<double> mat{2, 2, {1,2,3,4}};
        matrix::Matrix2D<double> result{2, 2, {(1*1+2*3), (1*2+2*4), (3*1+4*3), (3*2+4*4)}};
        REQUIRE(mat.dot(mat) == result);
        mat = matrix::Matrix2D<double>{matrix::Matrix1D<double>{{1,2,3,4,5}}};
        REQUIRE(mat.dot(mat.Tr()) == matrix::Matrix2D<double>{1,1,(1+4+9+16+25)});
    }
   
    SECTION("matrix to matrix operation")
    {
        matrix::Matrix2D<double> mat{10,10, 2.3};
        matrix::Matrix2D<double> mat2{10,10, 3.3};
        matrix::Matrix2D<double> result{10,10, 2.3};
        mat += mat2;
        REQUIRE(mat == result+mat2);
        mat -= mat2;
        REQUIRE(mat == (result+mat2)-mat2);
        mat *= mat2;
        REQUIRE(mat == result*mat2);
        mat /= mat2;
        REQUIRE(mat == (result*mat2)/mat2);

    }

    SECTION("matrix to scalar operation")
    {
       matrix::Matrix2D<double> mat{10,10, 2.3};
        matrix::Matrix2D<double> result{10,10, 2.3};
        mat += 3;
        REQUIRE(mat == result+3);
        mat -= 3;
        REQUIRE(mat == (result+3)-3);
        mat *= 3;
        REQUIRE(mat == result*3);
        mat /= 3;
        REQUIRE(mat == (result*3)/3);

    }
}