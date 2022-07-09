//
// Created by Quayle Rolande on 6/21/22.
//

#ifndef FT_CONTAINERS_REVERSE_ITERATOR_HPP
#define FT_CONTAINERS_REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft{
    template <typename Iterator>
    class reverse_iterator
    {
    protected:
        Iterator _it;
    public:
        typedef Iterator 												iterator_type;
        typedef typename iterator_traits<Iterator>::iterator_category 	iterator_category;
        typedef typename iterator_traits<Iterator>::value_type 			value_type;
        typedef typename iterator_traits<Iterator>::difference_type 	difference_type;
        typedef typename iterator_traits<Iterator>::pointer 			pointer;
        typedef typename iterator_traits<Iterator>::reference 			reference;

        reverse_iterator() : _it() {}

        explicit reverse_iterator(iterator_type it) : _it(it) {}

        template <class Iter>
        reverse_iterator(const reverse_iterator<Iter> &rev_it) : _it(rev_it.base()) {}

        template <typename U>
        reverse_iterator &operator=(const reverse_iterator<U> &rit) {
            _it = rit.base();
            return (*this);
        }

        iterator_type base() const {
            return _it;
        }

        reference operator*() const {
            iterator_type tmp = _it;
            --tmp;
            return *tmp;
        }

        pointer operator->() const {
            return &(**this);
        }

        reference operator[](difference_type n) const {
            return (*(*this + n));
        }

        reverse_iterator operator+(difference_type n) const {
            return (reverse_iterator(*this) += n);
        }

        reverse_iterator &operator+=(difference_type n) {
            _it -= n;
            return (*this);
        }

        reverse_iterator &operator++() {
            --_it;
            return (*this);
        }

        reverse_iterator operator++(int) {
            reverse_iterator tmp(*this);
            --_it;
            return (tmp);
        }

        reverse_iterator operator-(difference_type n) const {
            return (reverse_iterator(*this) -= n);
        }

        reverse_iterator &operator-=(difference_type n) {
            _it += n;
            return (*this);
        }

        reverse_iterator &operator--() {
            ++_it;
            return (*this);
        }

        reverse_iterator operator--(int) {
            reverse_iterator tmp(*this);
            _it++;
            return (tmp);
        }
    };
    template <class Iter>
    bool operator==(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs) {
        return (lhs.base() == rhs.base());
    }

    template <class Iter>
    bool operator!=(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs) {
        return (lhs.base() != rhs.base());
    }

    template <class Iter>
    bool operator<(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs) {
        return (lhs.base() > rhs.base());
    }

    template <class Iter>
    bool operator<=(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs) {
        return (lhs.base() >= rhs.base());
    }

    template <class Iter>
    bool operator>(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs) {
        return (lhs.base() < rhs.base());
    }

    template <class Iter>
    bool operator>=(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs) {
        return (lhs.base() <= rhs.base());
    }

    template <typename Iter>
    reverse_iterator<Iter> operator+(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter> &rev_it) {
        return (rev_it + n);
    }

    template <class Iter>
    typename reverse_iterator<Iter>::difference_type operator-(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs) {
        return (rhs.base() - lhs.base());
    }
}

#endif //FT_CONTAINERS_REVERSE_ITERATOR_HPP
