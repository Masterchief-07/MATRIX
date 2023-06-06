#include <catch2/catch_test_macros.hpp>
// #include <catch2/benchmark/catch_benchmark.hpp>
#include <matrix.hpp>
// #include <linear.hpp>

TEST_CASE("test Vector", "[VECTOR]") {

    krain::Vector<double> myVect{{1,2,3,4,5,6,7,8,9}};
    krain::Vector<double> myVect2{{1,2,3,4,5,6,7,8,9}};
    krain::Vector<double> myVect3{{0,1,2,3,4,5,6,7,8}};
    REQUIRE(myVect.size() == 9);
    REQUIRE(myVect[0] == 1);
    REQUIRE(myVect[myVect.size()-1] == 9);
    REQUIRE(myVect == myVect2);
    REQUIRE(myVect != myVect3);
    // REQUIRE(myVect.dot(myVect2) == )

    // REQUIRE(myVect.normalize().sum() == 1.0);
}

TEST_CASE("TEST VECTOR ON VECTOR", "[VECTOR ON VECTOR]")
{
    krain::Vector<double> myVect{{1,2,3,4,5,6,7,8,9}};
    krain::Vector<double> myVect2{{1,2,3,4,5,6,7,8,9}};
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

TEST_CASE("TEST VECTOR ON SCALAR", "[VECTOR ON SCALAR]")
{
    krain::Vector<double> myVect{{1,2,3,4,5,6,7,8,9}};
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


TEST_CASE("TEST Linear Algebra", "[LINEAR ALGEBRA]")
{

}

