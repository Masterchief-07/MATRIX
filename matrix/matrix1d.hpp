#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cmath>
#include <concepts>
#include <algorithm>

template<typename T>
concept SCALAR = (std::is_integral_v<T> || std::is_floating_point_v<T>) && std::is_scalar_v<T>;

namespace matrix
{
    template<typename T>
    requires SCALAR<T>
    class Matrix1D{
        private:
        std::vector<T> m_data;
        template<typename J>
        requires SCALAR<J>
        void assertSameSize(const Matrix1D<T>& x, const Matrix1D<J>& y) const
        {
            assert(x.size() == y.size());
        }

        public:
        Matrix1D(size_t size):m_data(size, 0){}
        Matrix1D(size_t size, const T& data):m_data(size, data){}
        Matrix1D(const std::vector<T>& data):m_data{data}{}
        Matrix1D(const std::vector<T>&& data):m_data{data}{}
        Matrix1D(const Matrix1D<T>& data):m_data{data.m_data}{}
        template<typename J>
        requires SCALAR<J>
        Matrix1D(const Matrix1D<J>& data):m_data(data.size()){
            std::copy(data.cbegin(), data.cend(), m_data.begin());
        }
        size_t size() const{
            return m_data.size();
        }

        std::vector<T>& getRawData()
        {
            return m_data;
        }
        const std::vector<T>& getRawData() const
        {
            return m_data;
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

        T mean() const
        {
            T result = 0;
            for(const auto& i: m_data)
                result += i;
            result /= m_data.size();
            return result;
        }
        //-------------------------------------------------------------------------------------------------------
        auto begin()               {return m_data.begin();}
        auto end()                 {return m_data.end();}
        auto cbegin()  const       {return m_data.cbegin();}
        auto cend()    const       {return m_data.cend();}
        auto rbegin()              {return m_data.rbegin();}
        auto rend()                {return m_data.rend();}
        //-------------------------------------------------------------------------------------------------------
        T& operator[](size_t index)
        {
            return m_data[index];
        }

        T operator[](size_t index) const
        {
            return m_data[index];
        }
        //-------------------------------------------------------------------------------------------------------
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
        //-------------------------------------------------------------------------------------------------------
        template<typename J>
        requires SCALAR<J>
        Matrix1D<T>& operator+=(const Matrix1D<J>& a)
        {
            assertSameSize(*this, a);
            std::transform(
                            a.getRawData().cbegin(), 
                            a.getRawData().cend(),
                            m_data.begin(),
                            m_data.begin(),
                            [](const T& a , const J& b){return b+a;}
                       );
            return *this;
        }
        template<typename J>
        requires SCALAR<J>
        Matrix1D<T>& operator-=(const Matrix1D<J>& a)
        {
            assertSameSize(*this, a);
            std::transform(
                            a.getRawData().cbegin(), 
                            a.getRawData().cend(),
                            m_data.begin(),
                            m_data.begin(),
                            [](const T& a , const J& b){return b-a;}
                       );
            return *this;
        }
        template<typename J>
        requires SCALAR<J>
        Matrix1D<T>& operator*=(const Matrix1D<J>& a)
        {
            assertSameSize(*this, a);
            std::transform(
                            a.getRawData().cbegin(), 
                            a.getRawData().cend(),
                            m_data.begin(),
                            m_data.begin(),
                            [](const T& a , const J& b){return b*a;}
                       );
            return *this;
        }
        template<typename J>
        requires SCALAR<J>
        Matrix1D<T>& operator/=(const Matrix1D<J>& a)
        {
            assertSameSize(*this, a);
            std::transform(
                            a.getRawData().cbegin(), 
                            a.getRawData().cend(),
                            m_data.begin(),
                            m_data.begin(),
                            [](const T& a , const J& b){return b/a;}
                       );
            return *this;
        }
        Matrix1D<T>& operator^(int value)
        {
            std::for_each(m_data.begin(), m_data.end(), [value](const T& a)
            {
                return std::pow(a, value);
            });
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
        //-------------------------------------------------------------------------------------------------------

        template<typename J>
        requires SCALAR<J>
        friend Matrix1D<T> operator+ (Matrix1D<T> a, const Matrix1D<J>& b)
        {
            return a+=b;   
        }
        template<typename J>
        requires SCALAR<J>
        friend Matrix1D<T> operator- (Matrix1D<T> a, const Matrix1D<J>& b)
        {
            return a-=b;   
        }
        template<typename J>
        requires SCALAR<J>
        friend Matrix1D<T> operator* (Matrix1D<T> a, const Matrix1D<J>& b)
        {
            return a*=b;   
        }
        template<typename J>
        requires SCALAR<J>
        friend Matrix1D<T> operator/ (Matrix1D<T> a, const Matrix1D<J>& b)
        {
            return a/=b;   
        }
        //-------------------------------------------------------------------------------------------------------
        template<typename J>
        requires SCALAR<J>
        bool operator==(const Matrix1D<J>& a) const
        {
            const double threshold = 0.000001;
            this->assertSameSize(*this, a);
            for(size_t i=0; i<a.size(); i++)
            {
                bool isEqual = (this->m_data[i] > (a.getRawData()[i]+threshold))
                                ||
                                (this->m_data[i] < (a.getRawData()[i]-threshold));
                if(isEqual)
                {
                    return false;
                }
            }
            return true;
        }

        template<typename J>
        requires SCALAR<J>
        bool operator!=(const Matrix1D<J>& a) const
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