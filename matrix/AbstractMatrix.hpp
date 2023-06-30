#pragma once

namespace matrix
{
    template<typename T>
    class AbstractMatrix{
        AbstractMatrix<T>() = 0;
        ~AbstractMatrix<T>() = 0;
        public:
        virtual auto begin() = 0;
        virtual auto  end()  = 0;
        virtual auto cbegin() const = 0;
        virtual auto cend() const = 0;

    };
}