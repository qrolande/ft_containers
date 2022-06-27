//
// Created by Quayle Rolande on 6/27/22.
//

#ifndef FT_CONTAINERS_IS_INTEGRAL_HPP
#define FT_CONTAINERS_IS_INTEGRAL_HPP

#include <iostream>

namespace ft {
    template < class Type, bool val >
    struct is_integral_base {
        typedef Type value_type;
        const static bool value = val;
//        typedef is_integral_base type;
        operator value_type() const {
            return value;
        }
    };
    template <class T> struct is_integral : public ft::is_integral_base<T, false> {};
    template <> struct is_integral<bool>: public ft::is_integral_base<bool, true> {};
    template <> struct is_integral<char>: public ft::is_integral_base<bool, true> {};
    template <> struct is_integral<signed char>: public ft::is_integral_base<bool, true> {};
    template <> struct is_integral<unsigned char>: public ft::is_integral_base<bool, true> {};
    template <> struct is_integral<wchar_t>: public ft::is_integral_base<bool, true> {};
    template <> struct is_integral<short>: public ft::is_integral_base<bool, true> {};
    template <> struct is_integral<char16_t>: public ft::is_integral_base<bool, true> {};
    template <> struct is_integral<char32_t>: public ft::is_integral_base<bool, true> {};
    template <> struct is_integral<unsigned short>: public ft::is_integral_base<bool, true> {};
    template <> struct is_integral<int>: public ft::is_integral_base<bool, true> {};
    template <> struct is_integral<unsigned int>: public ft::is_integral_base<bool, true> {};
    template <> struct is_integral<long>: public ft::is_integral_base<bool, true> {};
    template <> struct is_integral<unsigned long>: public ft::is_integral_base<bool, true> {};
    template <> struct is_integral<long long>: public ft::is_integral_base<bool, true> {};
    template <> struct is_integral<unsigned long long>: public ft::is_integral_base<bool, true> {};
}

#endif //FT_CONTAINERS_IS_INTEGRAL_HPP
