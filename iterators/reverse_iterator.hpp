//
// Created by Quayle Rolande on 6/21/22.
//

#ifndef FT_CONTAINERS_REVERSE_ITERATOR_HPP
#define FT_CONTAINERS_REVERSE_ITERATOR_HPP

#include "IteratorTraits.hpp"

namespace ft{
    template <class Iter> class ReverseIterator {
    public:
        typedef Iter                                                    iterator_type;
        typedef typename iterator_traits <Iter>::iterator_category   iterator_category;
        typedef typename iterator_traits <Iter>::value_type          value_type;
        typedef typename iterator_traits <Iter>::difference_type     difference_type;
        typedef typename iterator_traits <Iter>::pointer             pointer;
        typedef typename iterator_traits <Iter>::reference           reference;
    private:
        iterator_type _it;
    public:
        ReverseIterator() : _it() {}

        explicit ReverseIterator(iterator_type it) : _it(it) {}

        template 	< class Other >
        ReverseIterator(const ReverseIterator<Other>& other) : _it(other.base()) {};

        template <typename U>
        ReverseIterator &operator=(const ReverseIterator<U> &rit) {
            _it = rit.base();
            return (*this);
        }

        iterator_type base() const {
            return _it;
        }

        reference operator*() const {
            iterator_type tmp;
            tmp = _it;
            tmp--;
            return *tmp;
        }

        ReverseIterator operator+(difference_type n) const {
            return ReverseIterator(_it - n);
        }

        ReverseIterator &operator++() {
            _it--;
            return *this;
        }

        ReverseIterator operator++(int) {
            ReverseIterator tmp = *this;
            _it--;
            return tmp;
        }

        ReverseIterator &operator+=(difference_type n) {
            _it -= n;
            return *this;
        }

        ReverseIterator operator-(difference_type n) const {
            ReverseIterator rev_it = *this;
            return (rev_it -= n);
        }

        ReverseIterator &operator--() {
            _it++;
            return *this;
        }

        ReverseIterator operator--(int) {
            ReverseIterator tmp = *this;
            _it++;
            return tmp;
        }

        ReverseIterator &operator-=(difference_type n) {
            _it += n;
            return *this;
        }

        pointer operator->() const {
            return &(operator*());
        }

        reference operator[](difference_type n) const {
            return (*(_it - (n + 1)));
        }

    };
    template <class Iter>
    bool operator==(const ReverseIterator<Iter> &lhs, const ReverseIterator<Iter> &rhs) {
        return (lhs.base() == rhs.base());
    }

    template <class Iter>
    bool operator!=(const ReverseIterator<Iter> &lhs, const ReverseIterator<Iter> &rhs) {
        return (lhs.base() != rhs.base());
    }

    template <class Iter>
    bool operator<(const ReverseIterator<Iter> &lhs, const ReverseIterator<Iter> &rhs) {
        return (lhs.base() > rhs.base());
    }

    template <class Iter>
    bool operator<=(const ReverseIterator<Iter> &lhs, const ReverseIterator<Iter> &rhs) {
        return (lhs.base() >= rhs.base());
    }

    template <class Iter>
    bool operator>(const ReverseIterator<Iter> &lhs, const ReverseIterator<Iter> &rhs) {
        return (lhs.base() < rhs.base());
    }

    template <class Iter>
    bool operator>=(const ReverseIterator<Iter> &lhs, const ReverseIterator<Iter> &rhs) {
        return (lhs.base() <= rhs.base());
    }

    template <typename Iter>
    ReverseIterator<Iter> operator+(typename ReverseIterator<Iter>::difference_type n, const ReverseIterator<Iter> &rev_it) {
        return (rev_it + n);
    }

    template <class Iter>
    typename ReverseIterator<Iter>::difference_type operator-(const ReverseIterator<Iter> &lhs, const ReverseIterator<Iter> &rhs) {
        return (rhs.base() - lhs.base());
    }
}

#endif //FT_CONTAINERS_REVERSE_ITERATOR_HPP
