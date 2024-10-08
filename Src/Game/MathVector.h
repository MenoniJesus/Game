#ifndef __MY_LIB_MATH_VECTOR_HEADER_H__
#define __MY_LIB_MATH_VECTOR_HEADER_H__

#include <iostream>
#include <concepts>
#include <type_traits>
#include <ostream>
#include <cmath>
#include <cstdint>

namespace Mylib
{
namespace Math
{

template <typename T, uint32_t dim>
class Vector {
    public:
        Vector() {
            for (uint32_t i = 0; i < dim; ++i) {
                data[i] = T();
            }
        }

        Vector(T x, T y) {
            static_assert(dim == 2, "Constructor only valid for 2D vectors");
            data[0] = x;
            data[1] = y;
        }

        T& operator[](uint32_t index) {
            return data[index];
        }

        const T& operator[](uint32_t index) const {
            return data[index];
        }

    private:
        T data[dim];
};

using Vector2f = Vector<float, 2>;

} // namespace Math
} // namespace Mylib

#endif // __MY_LIB_MATH_VECTOR_HEADER_H__