//
// Created by Quayle Rolande on 6/21/22.
//

#ifndef FT_CONTAINERS_RANDOM_ACCESS_ITERATOR_HPP
#define FT_CONTAINERS_RANDOM_ACCESS_ITERATOR_HPP

#include "IteratorTraits.hpp"

namespace ft {
    template<class Iter>
    class RandomAccessIterator {
    public:
        typedef typename iterator_traits<Iter>::value_type       value_type;
        typedef typename iterator_traits<Iter>::pointer          pointer;
        typedef typename iterator_traits<Iter>::reference        reference;
        typedef typename iterator_traits<Iter>::difference_type  difference_type;
        typedef pointer                                              iterator_type;
        typedef std::random_access_iterator_tag                      iterator_category;
    private:
        pointer _it;

    public:
        RandomAccessIterator() : _it(pointer()) {};

        RandomAccessIterator(pointer ptr) : _it(ptr) {};

        template<class Iterator>
        RandomAccessIterator(const RandomAccessIterator<Iterator> &rhs) : _it(rhs.base()) {};

        RandomAccessIterator(const RandomAccessIterator &rhs) {
            _it = rhs._it;
            *this = rhs;
        };

        RandomAccessIterator &operator=(const RandomAccessIterator &rhs) {
            _it = rhs._it;
            return *this;
        };

        /****
        ** Destructor
        */

        ~RandomAccessIterator() {};

        /****
        ** Dereferences
        */

        reference operator*() const {
            return *_it;
        };

        pointer operator->() const {
            return &(operator*());
        };

        reference operator[](difference_type n) const {
            return _it[n];
        };

        /****
        ** Increment and Decrement Operators
        */

        // ++ Prefix
        RandomAccessIterator &operator++() {
            ++_it;
            return *this;
        };

        // Postfix ++
        RandomAccessIterator operator++(int) {
            RandomAccessIterator temp;
            temp._it = _it++;
            return temp;
        };

        // -- Prefix
        RandomAccessIterator &operator--() {
            --_it;
            return *this;
        };

        // Postfix --
        RandomAccessIterator operator--(int) {
            RandomAccessIterator temp;
            temp._it = _it--;
            return temp;
        };

        /****
        ** Arithmetic Operators
        */

        RandomAccessIterator operator+(difference_type n) {
            return (_it + n);
        };

        RandomAccessIterator operator-(difference_type n) {
            return (_it - n);
        };

        difference_type operator-(const RandomAccessIterator &rhs) const {
            return (_it - rhs.base());
        }

        RandomAccessIterator &operator+=(difference_type n) {
            _it += n;
            return *this;
        };

        RandomAccessIterator &operator-=(difference_type n) {
            _it -= n;
            return *this;
        };

        pointer base() const {
            return _it;
        };
    };

    template<typename IteratorL, typename IteratorR>
    inline bool operator==(const RandomAccessIterator<IteratorL> &lhs, const RandomAccessIterator<IteratorR> &rhs) {
        return (lhs.base() == rhs.base());
    }

    template<typename Iterator>
    inline bool operator==(const RandomAccessIterator<Iterator> &lhs, const RandomAccessIterator<Iterator> &rhs) {
        return (lhs.base() == rhs.base());
    }

    template<typename IteratorL, typename IteratorR>
    inline bool operator!=(const RandomAccessIterator<IteratorL> &lhs, const RandomAccessIterator<IteratorR> &rhs) {
        return (lhs.base() != rhs.base());
    }

    template<typename Iterator>
    inline bool operator!=(const RandomAccessIterator<Iterator> &lhs, const RandomAccessIterator<Iterator> &rhs) {
        return (lhs.base() != rhs.base());
    }

    template<typename IteratorL, typename IteratorR>
    inline bool operator<(const RandomAccessIterator<IteratorL> &lhs, const RandomAccessIterator<IteratorR> &rhs) {
        return (lhs.base() < rhs.base());
    }

    template<typename Iterator>
    inline bool operator<(const RandomAccessIterator<Iterator> &lhs, const RandomAccessIterator<Iterator> &rhs) {
        return (lhs.base() < rhs.base());
    }

    template<typename IteratorL, typename IteratorR>
    inline bool operator<=(const RandomAccessIterator<IteratorL> &lhs, const RandomAccessIterator<IteratorR> &rhs) {
        return (lhs.base() <= rhs.base());
    }

    template<typename Iterator>
    inline bool operator<=(const RandomAccessIterator<Iterator> &lhs, const RandomAccessIterator<Iterator> &rhs) {
        return (lhs.base() <= rhs.base());
    }

    template<typename IteratorL, typename IteratorR>
    inline bool operator>(const RandomAccessIterator<IteratorL> &lhs, const RandomAccessIterator<IteratorR> &rhs) {
        return (lhs.base() > rhs.base());
    }

    template<typename Iterator>
    inline bool operator>(const RandomAccessIterator<Iterator> &lhs, const RandomAccessIterator<Iterator> &rhs) {
        return (lhs.base() > rhs.base());
    }

    template<typename IteratorL, typename IteratorR>
    inline bool operator>=(const RandomAccessIterator<IteratorL> &lhs, const RandomAccessIterator<IteratorR> &rhs) {
        return (lhs.base() >= rhs.base());
    }

    template<typename Iterator>
    inline bool operator>=(const RandomAccessIterator<Iterator> &lhs, const RandomAccessIterator<Iterator> &rhs) {
        return (lhs.base() >= rhs.base());
    }

/****
** Arithmetic Operators
*/

    template<typename IteratorL, typename IteratorR>
    inline typename RandomAccessIterator<IteratorL>::difference_type
    operator-(const RandomAccessIterator<IteratorL> &lhs, const RandomAccessIterator<IteratorR> &rhs) {
        return (lhs.base() - rhs.base());
    }

    template<typename Iterator>
    inline typename RandomAccessIterator<Iterator>::difference_type
    operator-(const RandomAccessIterator<Iterator> &lhs, const RandomAccessIterator<Iterator> &rhs) {
        return (lhs.base() - rhs.base());
    }

    template<typename Iterator>
    inline RandomAccessIterator<Iterator>
    operator+(typename RandomAccessIterator<Iterator>::difference_type n, const RandomAccessIterator<Iterator> &rhs) {
        return (RandomAccessIterator<Iterator>(rhs.base() + n));
    }
}

#endif //FT_CONTAINERS_RANDOM_ACCESS_ITERATOR_HPP
