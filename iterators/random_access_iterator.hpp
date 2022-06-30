//
// Created by Quayle Rolande on 6/21/22.
//

#ifndef FT_CONTAINERS_RANDOM_ACCESS_ITERATOR_HPP
#define FT_CONTAINERS_RANDOM_ACCESS_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft {
    template<class Iter>
    class random_access_iterator {
    public:
        typedef typename iterator_traits<Iter *>::value_type       value_type;
        typedef typename iterator_traits<Iter *>::pointer          pointer;
        typedef typename iterator_traits<Iter *>::reference        reference;
        typedef typename iterator_traits<Iter *>::difference_type  difference_type;
        typedef pointer                                          iterator_type;
        typedef std::random_access_iterator_tag                  iterator_category;
    private:
        pointer _it;
    public:
        random_access_iterator() : _it(pointer()) {};

        random_access_iterator(pointer ptr) : _it(ptr) {};

        template<class Iterator>
        random_access_iterator(const random_access_iterator<Iterator> &rhs) : _it(rhs.base()) {};

        random_access_iterator(const random_access_iterator &rhs) {
            _it = rhs._it;
            *this = rhs;
        };

        random_access_iterator &operator=(const random_access_iterator &rhs) {
            _it = rhs._it;
            return *this;
        };

        /****
        ** Destructor
        */

        ~random_access_iterator() {};

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
        random_access_iterator &operator++() {
            ++_it;
            return *this;
        };

        // Postfix ++
        random_access_iterator operator++(int) {
            random_access_iterator temp;
            temp._it = _it++;
            return temp;
        };

        // -- Prefix
        random_access_iterator &operator--() {
            --_it;
            return *this;
        };

        // Postfix --
        random_access_iterator operator--(int) {
            random_access_iterator temp;
            temp._it = _it--;
            return temp;
        };

        /****
        ** Arithmetic Operators
        */

        random_access_iterator operator+(difference_type n) {
            return (this->_it + n);
        };

        random_access_iterator operator-(difference_type n) {
            return (this->_it - n);
        };

        difference_type operator-(const random_access_iterator &rhs) const {
            return (this->_it - rhs.base());
        }

        random_access_iterator &operator+=(difference_type n) {
            this->_it += n;
            return *this;
        };

        random_access_iterator &operator-=(difference_type n) {
            this->_it -= n;
            return *this;
        };

        pointer base() const {
            return this->_it;
        };
    };

    template<typename IteratorL, typename IteratorR>
    inline bool operator==(const random_access_iterator<IteratorL> &lhs, const random_access_iterator<IteratorR> &rhs) {
        return (lhs.base() == rhs.base());
    }

    template<typename Iterator>
    inline bool operator==(const random_access_iterator<Iterator> &lhs, const random_access_iterator<Iterator> &rhs) {
        return (lhs.base() == rhs.base());
    }

    template<typename IteratorL, typename IteratorR>
    inline bool operator!=(const random_access_iterator<IteratorL> &lhs, const random_access_iterator<IteratorR> &rhs) {
        return (lhs.base() != rhs.base());
    }

    template<typename Iterator>
    inline bool operator!=(const random_access_iterator<Iterator> &lhs, const random_access_iterator<Iterator> &rhs) {
        return (lhs.base() != rhs.base());
    }

    template<typename IteratorL, typename IteratorR>
    inline bool operator<(const random_access_iterator<IteratorL> &lhs, const random_access_iterator<IteratorR> &rhs) {
        return (lhs.base() < rhs.base());
    }

    template<typename Iterator>
    inline bool operator<(const random_access_iterator<Iterator> &lhs, const random_access_iterator<Iterator> &rhs) {
        return (lhs.base() < rhs.base());
    }

    template<typename IteratorL, typename IteratorR>
    inline bool operator<=(const random_access_iterator<IteratorL> &lhs, const random_access_iterator<IteratorR> &rhs) {
        return (lhs.base() <= rhs.base());
    }

    template<typename Iterator>
    inline bool operator<=(const random_access_iterator<Iterator> &lhs, const random_access_iterator<Iterator> &rhs) {
        return (lhs.base() <= rhs.base());
    }

    template<typename IteratorL, typename IteratorR>
    inline bool operator>(const random_access_iterator<IteratorL> &lhs, const random_access_iterator<IteratorR> &rhs) {
        return (lhs.base() > rhs.base());
    }

    template<typename Iterator>
    inline bool operator>(const random_access_iterator<Iterator> &lhs, const random_access_iterator<Iterator> &rhs) {
        return (lhs.base() > rhs.base());
    }

    template<typename IteratorL, typename IteratorR>
    inline bool operator>=(const random_access_iterator<IteratorL> &lhs, const random_access_iterator<IteratorR> &rhs) {
        return (lhs.base() >= rhs.base());
    }

    template<typename Iterator>
    inline bool operator>=(const random_access_iterator<Iterator> &lhs, const random_access_iterator<Iterator> &rhs) {
        return (lhs.base() >= rhs.base());
    }

/****
** Arithmetic Operators
*/

    template<typename IteratorL, typename IteratorR>
    inline typename random_access_iterator<IteratorL>::difference_type
    operator-(const random_access_iterator<IteratorL> &lhs, const random_access_iterator<IteratorR> &rhs) {
        return (lhs.base() - rhs.base());
    }

    template<typename Iterator>
    inline typename random_access_iterator<Iterator>::difference_type
    operator-(const random_access_iterator<Iterator> &lhs, const random_access_iterator<Iterator> &rhs) {
        return (lhs.base() - rhs.base());
    }

    template<typename Iterator>
    inline random_access_iterator<Iterator>
    operator+(typename random_access_iterator<Iterator>::difference_type n, const random_access_iterator<Iterator> &rhs) {
        return (random_access_iterator<Iterator>(rhs.base() + n));
    }
}

#endif //FT_CONTAINERS_RANDOM_ACCESS_ITERATOR_HPP
