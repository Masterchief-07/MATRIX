#pragma once
#include <algorithm>
#include <vector>
#include <cassert>
#include <cmath>
#include <concepts>

template<typename T>
concept SCALAR = (std::is_integral_v<T> || std::is_floating_point_v<T>) && std::is_scalar_v<T>;

namespace matrix
{
    template<typename T>
    requires SCALAR<T>
    class Matrix1D{
        private:
        std::vector<T> m_data;
        static void assertSameSize(const Matrix1D<T> x, const Matrix1D<T> y)
        {
            assert(x.size() == y.size());
        }

        public:
        Matrix1D(size_t size):m_data(size, 0){}
        Matrix1D(size_t size, const T& data):m_data(size, data){}
        Matrix1D(const std::vector<T>& data):m_data{data}
        {

        }
        Matrix1D(const Matrix1D<T>& data):m_data{data.m_data}
        {

        }
        size_t size() const{
            return m_data.size();
        }

        T norm() const
        {
            T result{0};
            for (const auto&i : m_data)
                result += std::pow(i, 2);
            return std::sqrt(result);
        }

        T dot(const  Matrix1D<T>& data) const
        {
            assertSameSize(*this, data);
            T result = 0;
            for (size_t i=0; i<this->size(); i++)
            {
                result += (*this)[i] * data[i];
            }
            return result;
        }

        Matrix1D<T> normalize() const
        {
            Matrix1D result = (*this)/(*this).norm();
            return result;
        }

        T sum() const
        {
            T result = 0;
            for(const auto& x: this->m_data)
                result += x;
            return result;
        }

        std::vector<T>& getRawData()
        {
            return m_data;
        }
        std::vector<T> getRawData() const
        {
            return m_data;
        }
        //-------------------------------------------------------------------------------------------------------
        T& operator[](size_t index)
        {
            return m_data[index];
        }

        T operator[](size_t index) const
        {
            return m_data[index];
        }
        Matrix1D<T>& operator+=(const T& a)
        {
            for (size_t i=0; i<this->size(); i++)
            {
                this->m_data[i] += a;
            }
            return *this;
        }
        Matrix1D<T>& operator-=(const T& a)
        {
            for (size_t i=0; i<this->size(); i++)
            {
                this->m_data[i] -= a;
            }
            return *this;
        }Matrix1D<T>& operator*=(const T& a)
        {
            for (size_t i=0; i<this->size(); i++)
            {
                this->m_data[i] *= a;
            }
            return *this;
        }Matrix1D<T>& operator/=(const T& a)
        {
            for (size_t i=0; i<this->size(); i++)
            {
                this->m_data[i] /= a;
            }
            return *this;
        }
        Matrix1D<T>& operator+=(const Matrix1D<T>& a)
        {
            assertSameSize(*this, a);
            for (size_t i=0; i<this->size(); i++)
            {
                this->m_data[i] += a.m_data[i];
            }
            return *this;
        }
        Matrix1D<T>& operator-=(const Matrix1D<T>& a)
        {
            assertSameSize(*this, a);
            for (size_t i=0; i<this->size(); i++)
            {
                this->m_data[i] -= a.m_data[i];
            }
            return *this;
        }
        Matrix1D<T>& operator*=(const Matrix1D<T>& a)
        {
            assertSameSize(*this, a);
            for (size_t i=0; i<this->size(); i++)
            {
                this->m_data[i] *= a.m_data[i];
            }
            return *this;
        }
        Matrix1D<T>& operator/=(const Matrix1D<T>& a)
        {
            assertSameSize(*this, a);
            for (size_t i=0; i<this->size(); i++)
            {
                this->m_data[i] /= a.m_data[i];
            }
            return *this;
        }
        Matrix1D<T>& operator^(double value)
        {
            for(size_t i=0; i < this->size(); i++)
            {
                (*this)[i] = std::pow((*this)[i], value);
            }
        }
        //-------------------------------------------------------------------------------------------------------
        friend Matrix1D<T> operator+ (Matrix1D<T> a, const T& b)
        {
            return a+=b;   
        }
        friend Matrix1D<T> operator- (Matrix1D<T> a, const T& b)
        {
            return a-=b;   
        }
        friend Matrix1D<T> operator* (Matrix1D<T> a, const T& b)
        {
            return a*=b;   
        }
        friend Matrix1D<T> operator/ (Matrix1D<T> a, const T& b)
        {
            return a/=b;   
        }
        
        friend Matrix1D<T> operator+ (const T& b, Matrix1D<T> a)
        {
            return a+=b;   
        }
        friend Matrix1D<T> operator- (const T& b, Matrix1D<T> a)
        {
            return a-=b;   
        }
        friend Matrix1D<T> operator* (const T& b, Matrix1D<T> a)
        {
            return a*=b;   
        }
        friend Matrix1D<T> operator/ (const T& b, Matrix1D<T> a)
        {
            return a/=b;   
        }

        friend Matrix1D<T> operator+ (Matrix1D<T> a, const Matrix1D<T>& b)
        {
            assertSameSize(a, b);
            return a+=b;   
        }
        friend Matrix1D<T> operator- (Matrix1D<T> a, const Matrix1D<T>& b)
        {
            assertSameSize(a, b);
            return a-=b;   
        }
        friend Matrix1D<T> operator* (Matrix1D<T> a, const Matrix1D<T>& b)
        {
            assertSameSize(a, b);
            return a*=b;   
        }
        friend Matrix1D<T> operator/ (Matrix1D<T> a, const Matrix1D<T>& b)
        {
            assertSameSize(a, b);
            return a/=b;   
        }
        //-------------------------------------------------------------------------------------------------------
        bool operator==(const Matrix1D<T>& a) const
        {
            assertSameSize(*this, a);
            for(size_t i=0; i<a.size(); i++)
            {
                if(this->m_data[i] != a[i])
                {
                    return false;
                }
            }
            return true;
        }

        bool operator!=(const Matrix1D<T>& a) const
        {
            return !(*this==a);
        }
        //-----------------------OSTREAM------------------
        friend std::ostream& operator<<(std::ostream& os, const Matrix1D<T>& obj)
        {
            os << "[";
            for(size_t i=0; i<obj.size(); i++)
            {
                os<<obj[i];
                if (i<obj.size()-1)
                    os<<", ";
            }
            os << "]";
            return os;
        }

    };
}