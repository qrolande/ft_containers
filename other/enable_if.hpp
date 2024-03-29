//
// Created by Quayle Rolande on 6/27/22.
//

#ifndef FT_CONTAINERS_ENABLE_IF_HPP
#define FT_CONTAINERS_ENABLE_IF_HPP

namespace ft {
    template<bool B, class T = void>
    struct enable_if {};

    template<class T>
    struct enable_if<true, T> {
        typedef T type;
    };
}

#endif //FT_CONTAINERS_ENABLE_IF_HPP
