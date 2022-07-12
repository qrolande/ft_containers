//
// Created by Quayle Rolande on 6/27/22.
//

#ifndef FT_CONTAINERS_PAIR_HPP
#define FT_CONTAINERS_PAIR_HPP

namespace ft {
    template < class T1, class T2 >
    struct pair {

    public:

        typedef T1	first_type;
        typedef T2	second_type;

        first_type	first;
        second_type	second;

        pair () : first(first_type()), second(second_type()) {}
        template < class U, class V >
        pair (const pair<U,V> &pr) : first(pr.first), second(pr.second) {}
        pair (const first_type &a, const second_type &b) : first(a), second(b) {}

        pair	&operator=(const pair &pr) {
            new (this) pair(pr);
            return *this;
        }

        operator pair<const T1, const T2>() const {
            return pair<const T1, const T2>(const_cast<const T1>(first), const_cast<const T2>(second));
        }
    };

    template <class T1, class T2>
    bool operator==(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs) { return (lhs.first == rhs.first && lhs.second == rhs.second); }

    template <class T1, class T2>
    bool operator!=(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs) { return (!(lhs == rhs)); }

    template <class T1, class T2>
    bool operator<(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs) { return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second)); }

    template <class T1, class T2>
    bool operator<=(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs) { return (!(rhs < lhs)); }

    template <class T1, class T2>
    bool operator>(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs) { return (rhs < lhs); }

    template <class T1, class T2>
    bool operator>=(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs) { return (!(lhs < rhs)); }

    template < class T1, class T2 >
    pair<T1, T2> make_pair(T1 x, T2 y) {
        return (pair<T1, T2>(x, y));
    }
}

#endif //FT_CONTAINERS_PAIR_HPP
