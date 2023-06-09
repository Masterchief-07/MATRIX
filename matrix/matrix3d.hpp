#pragma once
#include<concepts>

template<typename T>
concept SCALAR = (std::is_integral_v<T> || std::is_floating_point_v<T>) && std::is_scalar_v<T>;

namespace matrix
{
    template<typename T>
    requires SCALAR<T>
    class Matrix3D{

    };
}