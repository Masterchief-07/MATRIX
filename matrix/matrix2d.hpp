#pragma once
#include <concepts>
#include <vector>
#include <cmath>
#include <matrix1d.hpp>

namespace matrix
{
    template<typename T>
    requires SCALAR<T>
    class Matrix2D{
        private:
            size_t m_rows, m_columns;
            std::vector<T> m_data;
            static void assertSameSize(const Matrix2D<T> x, const Matrix2D<T> y)
            {
                assert(x.m_rows == y.m_rows);
                assert(x.m_columns == y.m_columns);
                assert(x.size() == y.size());
            }
            size_t getIndex(size_t rows, size_t columns) const
            {
                assert(m_rows > rows);
                assert(m_columns > columns);
                return rows*m_columns + columns;
            }
        public:
        Matrix2D(size_t rows, size_t columns):m_rows{rows}, m_columns{columns}, m_data(rows*columns, 0)
        {

        }
        Matrix2D(size_t rows, size_t columns, const T& value):m_rows{rows}, m_columns{columns}, m_data(rows*columns, value)
        {

        }
        Matrix2D(size_t rows, size_t columns, std::vector<T> const& data):m_rows{rows}, m_columns{columns}, m_data(data)
        {
            assert(rows*columns == data.size());
        }
        Matrix2D(const Matrix2D<T>& data):m_rows{data.m_rows}, m_columns{data.m_columns}, m_data{data.m_data}
        {

        }
        Matrix2D(const Matrix1D<T>& data):m_rows{1}, m_columns{data.size()}, m_data{data.getRawData()}
        {

        }
        size_t size() const{
            return m_data.size();
        }

        inline size_t getRows() const { return m_rows;}
        inline size_t getColumns() const { return m_columns;}

        T& at(size_t rows, size_t columns)
        {
            return m_data[getIndex(rows, columns)];
        }

        T at(size_t rows, size_t columns) const
        {
            return m_data[getIndex(rows, columns)];
        }

        Matrix2D<T> Tr() const
        {
            if (m_rows == 1 || m_columns == 1)
            {
                return Matrix2D{m_columns, m_rows, this->m_data};
            }
            Matrix2D<T> mat{m_columns, m_rows};
            for(size_t i = 0;  i < m_columns; ++i)
            {
                for(size_t j = 0; j < m_rows; ++j)
                {
                    mat.at(i,j) = this->at(j,i);
                }
            }
            return mat;
        }

        Matrix1D<T> sumRows()
        {
            Matrix1D<T> result{m_rows};
            for(size_t i=0; i<m_rows; i++)
            {
                for(size_t j=0; j<m_columns; j++)
                {
                    result[i]+= this->at(i,j);
                }
            }
            return result;
        }

        Matrix1D<T> sumColumns()
        {
            Matrix1D<T> result{m_columns};
            for(size_t i=0; i<m_columns; i++)
            {
                for(size_t j=0; j<m_rows; j++)
                {
                    result[i]+= this->at(j,i);
                }
            }
            return result;
        }

        Matrix2D<T> dot(const Matrix2D<T>& matrix2)const
        {
            assert(matrix2.m_rows == this->m_columns);
            Matrix2D<T> result{this->m_rows, matrix2.m_columns};
            for(size_t i = 0;  i < result.m_rows; ++i)
            {
                for(size_t k = 0; k < result.m_columns; ++k)
                {
                    T sum = 0;
                    for(size_t j = 0; j < this->m_columns; ++j)
                    {
                        sum += this->at(i,j) * matrix2.at(j,k);
                    }
                    result.at(i, k) = sum;
                }
            }
            return result;
        }

        // ------------------------------------OPERATOR OVERLOAD----------------------------
        Matrix2D<T>& operator+=(const T& a)
        {
            for (auto & i:this->m_data)
            {
                i += a;
            }
            return *this;
        }
        Matrix2D<T>& operator-=(const T& a)
        {
            for (auto & i:this->m_data)
            {
                i -= a;
            }
            return *this;
        }Matrix2D<T>& operator*=(const T& a)
        {
            for (auto & i:this->m_data)
            {
                i *= a;
            }
            return *this;
        }Matrix2D<T>& operator/=(const T& a)
        {
            for (auto & i:this->m_data)
            {
                i /= a;
            }
            return *this;
        }
        Matrix2D<T>& operator+=(const Matrix2D<T>& a)
        {
            this->assertSameSize(*this, a);
            for (size_t i=0; i<this->size(); i++)
            {
                this->m_data[i] += a.m_data[i];
            }
            return *this;
        }
        Matrix2D<T>& operator-=(const Matrix2D<T>& a)
        {
            this->assertSameSize(*this, a);
            for (size_t i=0; i<this->size(); i++)
            {
                this->m_data[i] -= a.m_data[i];
            }
            return *this;
        }
        Matrix2D<T>& operator*=(const Matrix2D<T>& a)
        {
            this->assertSameSize(*this, a);
            for (size_t i=0; i<this->size(); i++)
            {
                this->m_data[i] *= a.m_data[i];
            }
            return *this;
        }
        Matrix2D<T>& operator/=(const Matrix2D<T>& a)
        {
            this->assertSameSize(*this, a);
            for (size_t i=0; i<this->size(); i++)
            {
                this->m_data[i] /= a.m_data[i];
            }
            return *this;
        }
        Matrix2D<T>& operator^(int value)
        {
            for(auto &i:this->m_data)
            {
                i = std::pow(i, value);
            }
            return *this;
        }
        //-------------------------------------------------------------------------------------------------------
        friend Matrix2D<T> operator+ (Matrix2D<T> a, const T& b)
        {
            return a+=b;   
        }
        friend Matrix2D<T> operator- (Matrix2D<T> a, const T& b)
        {
            return a-=b;   
        }
        friend Matrix2D<T> operator* (Matrix2D<T> a, const T& b)
        {
            return a*=b;   
        }
        friend Matrix2D<T> operator/ (Matrix2D<T> a, const T& b)
        {
            return a/=b;   
        }
        
        friend Matrix2D<T> operator+ (const T& b, Matrix2D<T> a)
        {
            return a+=b;   
        }
        friend Matrix2D<T> operator- (const T& b, Matrix2D<T> a)
        {
            return a-=b;   
        }
        friend Matrix2D<T> operator* (const T& b, Matrix2D<T> a)
        {
            return a*=b;   
        }
        friend Matrix2D<T> operator/ (const T& b, Matrix2D<T> a)
        {
            return a/=b;   
        }

        friend Matrix2D<T> operator+ (Matrix2D<T> a, const Matrix2D<T>& b)
        {
            assertSameSize(a, b);
            return a+=b;   
        }
        friend Matrix2D<T> operator- (Matrix2D<T> a, const Matrix2D<T>& b)
        {
            assertSameSize(a, b);
            return a-=b;   
        }
        friend Matrix2D<T> operator* (Matrix2D<T> a, const Matrix2D<T>& b)
        {
            assertSameSize(a, b);
            return a*=b;   
        }
        friend Matrix2D<T> operator/ (Matrix2D<T> a, const Matrix2D<T>& b)
        {
            assertSameSize(a, b);
            return a/=b;   
        }
        //-------------------------------------------------------------------------------------------------------
        bool operator==(const Matrix2D<T>& a) const
        {
            this->assertSameSize(*this, a);
            for(size_t i=0; i<a.size(); i++)
            {
                if(this->m_data[i] != a.m_data[i])
                {
                    return false;
                }
            }
            return true;
        }

        bool operator!=(const Matrix2D<T>& a) const
        {
            return !(*this==a);
        }

        //-----------------------OSTREAM------------------
        friend std::ostream& operator<<(std::ostream& os, const Matrix2D<T>& obj)
        {
            os << "[";
            for(size_t i=0; i<obj.m_rows; i++)
            {
                os<<"[";
                for(size_t j=0; j<obj.m_columns; j++)
                {
                    os<<obj.at(i, j);
                    if(j < obj.m_columns-1)
                        os<<", ";
                }
                    os<<"]";
                if(i < obj.m_rows-1)
                {
                    os<<"\n";
                }
            }
            os << "]";
            return os;
        }



    };
}