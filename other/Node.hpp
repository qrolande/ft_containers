//
// Created by Quayle Rolande on 7/3/22.
//

#ifndef FT_CONTAINERS_NODE_HPP
#define FT_CONTAINERS_NODE_HPP

#include "iostream"

namespace ft {
    template < class T > class node {
    public:
        T data;
        node *parent;
        node *left;
        node *right;
        node *_end;
        node *_rend;
        int height;

        node() : data(T()), parent(NULL), left(NULL), right(NULL), _end(NULL), _rend(NULL), height(0) {}

        node(T &new_data) : data(new_data), parent(NULL), left(NULL), right(NULL), _end(NULL), _rend(NULL), height(0) {}

        node(const node &src) : data(src.data), parent(src.parent), left(src.left), right(src.right), _end(src._end),
                                _rend(src._rend), height(src.height) {}

        node &operator=(const node &src) {
            new(this) node(src);

            return *this;
        }

        operator node<const T>() {
            node<const T> ret(data);

            ret.parent = reinterpret_cast<node<const T> *>(parent);
            ret.left = reinterpret_cast<node<const T> *>(left);
            ret.right = reinterpret_cast<node<const T> *>(right);
            ret._end = reinterpret_cast<node<const T> *>(_end);
            ret._rend = reinterpret_cast<node<const T> *>(_rend);
            ret.height = height;
            return ret;
        }
    };
};

#endif //FT_CONTAINERS_NODE_HPP