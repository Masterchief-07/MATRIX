#pragma once
#include <algorithm>
#include <vector>
#include <cassert>
#include <cmath>
#include <concepts>

template<typename T>
concept SCALAR = (std::is_integral_v<T> || std::is_floating_point_v<T>) && std::is_scalar_v<T>;

namespace krain
{
    template<typename T>
    requires SCALAR<T>
    class Vector{
        private:
        std::vector<T> m_data;
        static void assertSameSize(const Vector<T> x, const Vector<T> y)
        {
            assert(x.size() == y.size());
        }

        public:
        Vector(const std::vector<T>& data):m_data{data}
        {

        }
        Vector(const Vector<T>& data):m_data{data.m_data}
        {

        }
        size_t size() const{
            return m_data.size();
        }

        T norm() const
        {
            return std::sqrt(this->dot(*this));
        }

        T dot(const  Vector<T>& data) const
        {
            assertSameSize(*this, data);
            T result = 0;
            for (size_t i=0; i<this->size(); i++)
            {
                result += (*this)[i] * data[i];
            }
            return result;
        }

        Vector<T> normalize() const
        {
            Vector result = (*this)/(*this).norm();
            return result;
        }

        T sum() const
        {
            T result = 0;
            for(const auto& x: this->m_data)
                result += x;
            return result;
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
        Vector<T>& operator+=(const T& a)
        {
            for (size_t i=0; i<this->size(); i++)
            {
                this->m_data[i] += a;
            }
            return *this;
        }
        Vector<T>& operator-=(const T& a)
        {
            for (size_t i=0; i<this->size(); i++)
            {
                this->m_data[i] -= a;
            }
            return *this;
        }Vector<T>& operator*=(const T& a)
        {
            for (size_t i=0; i<this->size(); i++)
            {
                this->m_data[i] *= a;
            }
            return *this;
        }Vector<T>& operator/=(const T& a)
        {
            for (size_t i=0; i<this->size(); i++)
            {
                this->m_data[i] /= a;
            }
            return *this;
        }
        Vector<T>& operator+=(const Vector<T>& a)
        {
            assertSameSize(*this, a);
            for (size_t i=0; i<this->size(); i++)
            {
                this->m_data[i] += a.m_data[i];
            }
            return *this;
        }
        Vector<T>& operator-=(const Vector<T>& a)
        {
            assertSameSize(*this, a);
            for (size_t i=0; i<this->size(); i++)
            {
                this->m_data[i] -= a.m_data[i];
            }
            return *this;
        }
        Vector<T>& operator*=(const Vector<T>& a)
        {
            assertSameSize(*this, a);
            for (size_t i=0; i<this->size(); i++)
            {
                this->m_data[i] *= a.m_data[i];
            }
            return *this;
        }
        Vector<T>& operator/=(const Vector<T>& a)
        {
            assertSameSize(*this, a);
            for (size_t i=0; i<this->size(); i++)
            {
                this->m_data[i] /= a.m_data[i];
            }
            return *this;
        }
        Vector<T>& operator^(double i)
        {
            for(size_t i=0; i < this->size(); i++)
            {
                (*this)[i] = std::pow((*this)[i], i);
            }
        }
        //-------------------------------------------------------------------------------------------------------
        friend Vector<T> operator+ (Vector<T> a, const T& b)
        {
            return a+=b;   
        }
        friend Vector<T> operator- (Vector<T> a, const T& b)
        {
            return a-=b;   
        }
        friend Vector<T> operator* (Vector<T> a, const T& b)
        {
            return a*=b;   
        }
        friend Vector<T> operator/ (Vector<T> a, const T& b)
        {
            return a/=b;   
        }
        
        friend Vector<T> operator+ (const T& b, Vector<T> a)
        {
            return a+=b;   
        }
        friend Vector<T> operator- (const T& b, Vector<T> a)
        {
            return a-=b;   
        }
        friend Vector<T> operator* (const T& b, Vector<T> a)
        {
            return a*=b;   
        }
        friend Vector<T> operator/ (const T& b, Vector<T> a)
        {
            return a/=b;   
        }

        friend Vector<T> operator+ (Vector<T> a, const Vector<T>& b)
        {
            assertSameSize(a, b);
            return a+=b;   
        }
        friend Vector<T> operator- (Vector<T> a, const Vector<T>& b)
        {
            assertSameSize(a, b);
            return a-=b;   
        }
        friend Vector<T> operator* (Vector<T> a, const Vector<T>& b)
        {
            assertSameSize(a, b);
            return a*=b;   
        }
        friend Vector<T> operator/ (Vector<T> a, const Vector<T>& b)
        {
            assertSameSize(a, b);
            return a/=b;   
        }
        //-------------------------------------------------------------------------------------------------------
        bool operator==(const Vector<T>& a) const
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

        bool operator!=(const Vector<T>& a) const
        {
            return !(*this==a);
        }
       
    };
}