//
// Created by Quayle Rolande on 6/27/22.
//

#ifndef FT_CONTAINERS_EQUAL_HPP
#define FT_CONTAINERS_EQUAL_HPP

namespace ft {
    template < class InputIterator1, class InputIterator2 >
    bool	equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) { // equality
        while (first1 != last1) {
            if (!(*first1 == *first2))
                return false;
            first1++;
            first2++;
        }
        return true;
    }
    template < class InputIterator1, class InputIterator2, class BinaryPredicate >
    bool	equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred) { // predicate
        while (first1 != last1) {
            if (!pred(*first1, *first2))
                return false;
            first1++;
            first2++;
        }
        return true;
    }
}

#endif //FT_CONTAINERS_EQUAL_HPP
