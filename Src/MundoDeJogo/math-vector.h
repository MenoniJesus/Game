#ifndef __MY_LIB_MATH_VECTOR_HEADER_H__
#define __MY_LIB_MATH_VECTOR_HEADER_H__

#include <iostream>
#include <concepts>
#include <type_traits>
#include <ostream>
#include <cmath>
#include <cstdint> // Adicionado para uint32_t

namespace Mylib
{
namespace Math
{

template <typename T, uint32_t dim>
class Vector;

using Vector2f = Vector<float, 2>;

} // namespace Math
} // namespace Mylib

#endif // __MY_LIB_MATH_VECTOR_HEADER_H__