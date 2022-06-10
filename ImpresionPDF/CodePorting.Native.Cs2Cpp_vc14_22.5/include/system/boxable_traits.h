/// @file system/boxable_traits.h
#pragma once

#include <system/exception.h>
#include <system/string.h>
#include <type_traits>

namespace System
{
    /// Template predicate that checks if boxing of the specified type is supported.
    /// @tparam T The type to check
    template <typename T>
    struct IsBoxable : std::integral_constant<bool,
        std::is_arithmetic<T>::value || std::is_enum<T>::value || IsExceptionWrapper<T>::value> {};

    /// IsBoxable<T> specialization for String.
    template<> struct IsBoxable<String> : std::true_type {};
}
