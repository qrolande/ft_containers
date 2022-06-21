//
// Created by Quayle Rolande on 6/21/22.
//

#ifndef FT_CONTAINERS_REVERSE_ITERATOR_HPP
#define FT_CONTAINERS_REVERSE_ITERATOR_HPP

#include "../iterators/IteratorTraits.hpp"

namespace ft{
    template <class Iter> class ReverseIterator {
    public:
        typedef Iter iterator_type;
        typedef typename IteratorTraits <Iter>::iterator_category iterator_category;
        typedef typename IteratorTraits <Iter>::value_type value_type;
        typedef typename IteratorTraits <Iter>::difference_type difference_type;
        typedef typename IteratorTraits <Iter>::pointer pointer;
        typedef typename IteratorTraits <Iter>::reference reference;
    private:
        iterator_type current_iter;
    public:
        ReverseIterator() : current_iter(){ };

        explicit ReverseIterator(iterator_type it) : current_iter(it){};

        template <class Iterator1>
        ReverseIterator(const ReverseIterator<Iterator1>& reverse_it){
            current_iter = reverse_it.current_iter;
        };

        iterator_type base() const { return (this->current_iter); };

        reference operator*() const{
            iterator_type temp = current_iter;
            return (*--temp);
        };

        ReverseIterator operator+(difference_type i) const{ return (ReverseIterator(current_iter - i)); };

        ReverseIterator & operator++(){
            --current_iter;
            return (*this);
        };

        ReverseIterator operator++(int){
            ReverseIterator temp = *this;
            --(*this);
            return temp;
        };

        ReverseIterator & operator+=(difference_type i){
            this->current_iter -= i;
            return (*this);
        };

        ReverseIterator operator-(difference_type i) const{
            return (ReverseIterator(this->current_iter + i));
        };

        ReverseIterator& operator--() {
            ++current_iter;
            return (*this);
        };

        ReverseIterator operator--(int){
            ReverseIterator temp = *this;
            ++(*this);
            return (temp);
        };

        ReverseIterator& operator-=(difference_type i){
            current_iter += i;
            return (*this);
        };

        pointer operator->() const{
            return &(operator*());
        };

        reference operator[](difference_type i) const{
            return (current_iter[-i - 1]);
        };
    };
    template <class Iter>
    bool operator==(const ReverseIterator<Iter>&lhs, const ReverseIterator<Iter>&rhs){
        return (lhs.base() == rhs.base());
    };
    template <class Iter>
    bool operator!=(const ReverseIterator<Iter>&lhs, const ReverseIterator<Iter>&rhs){
        return (!(lhs == rhs));
    };
    template <class Iter>
    bool operator<(const ReverseIterator<Iter>&lhs, const ReverseIterator<Iter>&rhs);
    template <class Iter>
    bool operator>(const ReverseIterator<Iter>&lhs, const ReverseIterator<Iter>&ths);
    template <class Iter>
    bool operator<=(const ReverseIterator<Iter>&lhs, const ReverseIterator<Iter>&rhs);
    template <class Iter>
    bool operator>=(const ReverseIterator<Iter>&lhs, const ReverseIterator<Iter>&rhs);
    template<class Iter>
    ReverseIterator<Iter> operator+(typename ReverseIterator<Iter>::difference_type i, const ReverseIterator<Iter>& reverse_it){
        return (reverse_it + i);
    };
    template<class Iter>
    typename ReverseIterator<Iter>::difference_type operator-(const ReverseIterator<Iter>&lhs, const ReverseIterator<Iter>&rhs){
        return (lhs.base() - rhs.base());
    }
}

#endif //FT_CONTAINERS_REVERSE_ITERATOR_HPP
