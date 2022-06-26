//
// Created by Quayle Rolande on 6/21/22.
//

#ifndef FT_CONTAINERS_RANDOM_ACCESS_ITERATOR_HPP
#define FT_CONTAINERS_RANDOM_ACCESS_ITERATOR_HPP

#include "IteratorTraits.hpp"

template <class Iter> class RandomAccessIterator {
public:
    typedef typename ft::IteratorTraits<Iter>::value_type       value_type;
    typedef typename ft::IteratorTraits<Iter>::pointer          pointer;
    typedef typename ft::IteratorTraits<Iter>::reference        reference;
    typedef typename ft::IteratorTraits<Iter>::difference_type  difference_type;
    typedef pointer                                             iterator_type;
    typedef std::random_access_iterator_tag                     iterator_category;
private:
    pointer _current;

public:
    RandomAccessIterator(): _current(){};

    explicit RandomAccessIterator(pointer other) : _current(other){};

    RandomAccessIterator(const RandomAccessIterator<value_type> & other): _current(&(*other)){};

    virtual ~RandomAccessIterator(){};

    RandomAccessIterator<value_type> & operator=(const RandomAccessIterator<value_type> & other){
        _current = &(*other);
        return (*this);
    }

    RandomAccessIterator & operator++(){
        _current++;
        return (*this);
    }

    RandomAccessIterator  operator++(int){
        RandomAccessIterator tmp = *this;
        ++_current;
        return tmp;
    }


    RandomAccessIterator & operator--(){
        _current--;
        return (*this);
    }

    RandomAccessIterator  operator--(int){
        RandomAccessIterator tmp = *this;
        _current--;
        return tmp;
    }

    RandomAccessIterator  operator+(const difference_type & other) const{
        return _current + other;
    }

    RandomAccessIterator  operator-(const difference_type & other) const{
        return _current - other;
    }

    RandomAccessIterator &operator+=(const difference_type & other){
        _current = _current + other;
        return (*this);
    }

    RandomAccessIterator &operator-=(const difference_type & other){
        _current = _current - other;
        return *this;
    }

    pointer operator->() const{
        return _current;
    }

    reference operator*()const{
        return *_current;
    }

    reference operator[](difference_type i) const{
        return *(_current + i);
    }
};

template<typename First, typename Second>
bool operator==(const RandomAccessIterator<First>& lhs, const RandomAccessIterator<Second>& rhs){
    return &(*lhs) == &(*rhs);
}

template<typename First, typename Second>
bool operator!=(const RandomAccessIterator<First>& lhs, const RandomAccessIterator<Second>&rhs){
    return &(*lhs) != &(*rhs);
}

template<typename First, typename Second>
bool operator<(const RandomAccessIterator<First>& lhs, const RandomAccessIterator<Second>&rhs){
    return &(*lhs) < &(*rhs);
}

template<typename First, typename Second>
bool operator>(const RandomAccessIterator<First>& lhs, const RandomAccessIterator<Second>&rhs){
    return &(*lhs) > &(*rhs);
}

template<typename First, typename Second>
bool operator<=(const RandomAccessIterator<First>& lhs, const RandomAccessIterator<Second>&rhs){
    return &(*lhs) <= &(*rhs);
}

template<typename First, typename Second>
bool operator>=(const RandomAccessIterator<First>& lhs, const RandomAccessIterator<Second>&rhs){
    return &(*lhs) >= &(*rhs);
}

template<typename First, typename Second>
typename RandomAccessIterator<First>::difference_type operator-(const RandomAccessIterator<First> &lhs, const RandomAccessIterator<Second>&rhs){
    return &(*lhs) - &(*rhs);
}

template<typename First, typename Second>
typename RandomAccessIterator<First>::difference_type operator+(const RandomAccessIterator<First> &lhs, const RandomAccessIterator<Second>&rhs){
    return &(*lhs) + &(*rhs);
}
//
//template<typename G>
//RandomAccessIterator<G> operator+(const typename RandomAccessIterator<G>::difference_type & lhs, const typename RandomAccessIterator<G> & rhs){
//    return lhs+rhs;
//}
//
//template<typename G>
//RandomAccessIterator<G> operator-(const typename RandomAccessIterator<T>::difference_type & lhs, const typename RandomAccessIterator<G> & rhs){
//    return lhs-rhs;
//}

#endif //FT_CONTAINERS_RANDOM_ACCESS_ITERATOR_HPP
