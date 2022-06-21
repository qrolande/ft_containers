//
// Created by Quayle Rolande on 6/21/22.
//

#ifndef FT_CONTAINERS_ITERATORTRAITS_HPP
#define FT_CONTAINERS_ITERATORTRAITS_HPP

#include "iostream"

namespace ft {
    template <class Iter> class IteratorTraits{
    public:
        typedef typename Iter::difference_type      difference_type;
        typedef typename Iter::value_type           value_type;
        typedef typename Iter::pointer              pointer;
        typedef typename Iter::reference            reference;
        typedef typename Iter::iterator_category    iterator_category;
    };

    template <class T> class IteratorTraits<T*>{
    public:
        typedef std::ptrdiff_t                  difference_type;
        typedef T                               value_type;
        typedef T*                              pointer;
        typedef T&                              reference;
        typedef std::random_access_iterator_tag iterator_category;
    };

    template <class T> class IteratorTraits<const T*>{
    public:
        typedef std::ptrdiff_t                  difference_type;
        typedef const T                         value_type;
        typedef const T*                        pointer;
        typedef const T&                        reference;
        typedef std::random_access_iterator_tag iterator_category;
    };
};

#endif //FT_CONTAINERS_ITERATORTRAITS_HPP
