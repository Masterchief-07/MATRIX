#include <catch2/catch_test_macros.hpp>
// #include <catch2/benchmark/catch_benchmark.hpp>
#include <matrix1d.hpp>
// #include <linear.hpp>

TEST_CASE("test MATRIX1D", "[VECTOR]") {

    SECTION("INIT AND FUNCTIONS"){
    matrix::Matrix1D<double> myVect{{1,2,3,4,5,6,7,8,9}};
    matrix::Matrix1D<double> myVect2{{1,2,3,4,5,6,7,8,9}};
    matrix::Matrix1D<double> result{{1,4,9,16,25,36,49,64,81}};
    matrix::Matrix1D<double> myVect3{{0,1,2,3,4,5,6,7,8}};
    REQUIRE(myVect.size() == 9);
    REQUIRE(myVect[0] == 1);
    REQUIRE(myVect[myVect.size()-1] == 9);
    REQUIRE(myVect == myVect2);
    REQUIRE(myVect != myVect3);
    REQUIRE(myVect.dot(myVect2) == result.sum());
    REQUIRE(myVect.normalize().norm() == 1.0);
    REQUIRE(myVect.norm() == std::sqrt(result.sum()));
    }
    SECTION("MATRIX ON MATRIX OPERATION"){
    matrix::Matrix1D<double> myVect{{1,2,3,4,5,6,7,8,9}};
    matrix::Matrix1D<int> myVect2{{1,2,3,4,5,6,7,8,9}};
    myVect+=myVect2;
    for (size_t i=0; i<myVect.size(); i++)
    {
        REQUIRE(myVect[i] == (i+1)+(i+1));
    }
    myVect-=myVect2;
    for (size_t i=0; i<myVect.size(); i++)
    {
        REQUIRE(myVect[i] == (i+1));
    }
    myVect*=myVect2;
    for (size_t i=0; i<myVect.size(); i++)
    {
        REQUIRE(myVect[i] == (i+1)*(i+1));
    }
    myVect/=myVect2;
    for (size_t i=0; i<myVect.size(); i++)
    {
        REQUIRE(myVect[i] == (i+1));
    }
    //---------------------------------------------
    auto result = myVect+myVect2;
    for (size_t i=0; i<myVect.size(); i++)
    {
        REQUIRE(result[i] == (i+1)+(i+1));
    }
    result = myVect-myVect2;
    for (size_t i=0; i<myVect.size(); i++)
    {
        REQUIRE(result[i] == 0);
    }
    result = myVect*myVect2;
    for (size_t i=0; i<myVect.size(); i++)
    {
        REQUIRE(result[i] == (i+1)*(i+1));
    }
    result = myVect/myVect2;
    for (size_t i=0; i<myVect.size(); i++)
    {
        REQUIRE(result[i] == 1);
    }
    }
    SECTION("MATRIX ON SCALAR"){
    matrix::Matrix1D<double> myVect{{1,2,3,4,5,6,7,8,9}};
    myVect+=3;
    for (size_t i=0; i<myVect.size(); i++)
    {
        REQUIRE(myVect[i] == (i+1)+3);
    }
    myVect-=3;
    for (size_t i=0; i<myVect.size(); i++)
    {
        REQUIRE(myVect[i] == (i+1));
    }
    myVect*=3;
    for (size_t i=0; i<myVect.size(); i++)
    {
        REQUIRE(myVect[i] == (i+1)*3);
    }
    myVect/=3;
    for (size_t i=0; i<myVect.size(); i++)
    {
        REQUIRE(myVect[i] == (i+1));
    }
    auto result = myVect + 3;
    for (size_t i=0; i<myVect.size(); i++)
    {
        REQUIRE(result[i] == (i+1)+3);
    }
    result = myVect - 3;
    for (int i=0; i<myVect.size(); i++)
    {
        REQUIRE(result[i] == (i+1) - 3);
    }
    result = myVect * 3;
    for (size_t i=0; i<myVect.size(); i++)
    {
        REQUIRE(result[i] == (i+1)*3);
    }
    result = myVect / 3;
    for (size_t i=0; i<myVect.size(); i++)
    {
        REQUIRE(result[i] == (double)(i+1) / 3.0);
    }
    REQUIRE(3+myVect == myVect+3);
    REQUIRE(3-myVect == myVect-3);
    REQUIRE(3*myVect == myVect*3);
    // REQUIRE(3/myVect == myVect/3);
    }
}
