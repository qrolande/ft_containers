//
// Created by Quayle Rolande on 7/3/22.
//

#ifndef FT_CONTAINERS_MAP_HPP
#define FT_CONTAINERS_MAP_HPP

#include "iostream"
#include "../other/libs.hpp"

namespace ft {
    template < class Key,                                           // map::key_type
            class T,                                                // map::mapped_type
            class Compare = std::less<Key>,                         // map::key_compare
            class Alloc = std::allocator<ft::pair<const Key,T> >    // map::allocator_type
    > class map {
    public :
        // Member types
        typedef Key                                                         key_type;
        typedef T                                                           mapped_type;
        typedef ft::pair<const Key, T>                                      value_type;
        typedef Compare                                                     key_compare;
        typedef Alloc                                                       allocator_type;
        typedef ptrdiff_t                                                   difference_type;
        typedef size_t                                                      size_type;
        typedef node<value_type>                                            t_node;
        typedef	typename allocator_type::template rebind<t_node>::other	    node_allocator;

        typedef typename allocator_type::reference                          reference;
        typedef typename allocator_type::const_reference                    const_reference;
        typedef typename allocator_type::pointer                            pointer;
        typedef typename allocator_type::const_pointer                      const_pointer;

        typedef ft::bidirectional_iterator <value_type>                     iterator;
        typedef ft::bidirectional_iterator<const value_type>                const_iterator;
        typedef ft::reverse_iterator<iterator>                              reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>                        const_reverse_iterator;

        class value_compare : public std::binary_function<value_type, value_type, bool> {
            friend class map;

        protected:
            Compare comp;

            value_compare(Compare c) : comp(c) {}

        public:
            typedef bool        result_type;
            typedef value_type  first_argument_type;
            typedef value_type  second_argument_type;

            bool operator()(const value_type &x, const value_type &y) const {
                return comp(x.first, y.first);
            }
        };

    public:
        // Member func
        explicit	map (const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type()) { // empty
            _root = NULL;
            _size = 0;
            _comp = comp;
            _alloc = alloc;
            _end = _empty_node();
            _rend = _empty_node();
        }

        template < class InputIterator >
        map (InputIterator first, InputIterator last, const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type()) { // range
            _root = NULL;
            _size = 0;
            _comp = comp;
            _alloc = alloc;
            _end = _empty_node();
            _rend = _empty_node();
            while (first != last) {
                _add_one(*first);
                first++;
            }
        }

        map (const map & x) {
            _root = NULL;
            _size = 0;
            _comp = key_compare(x._comp);
            _alloc = allocator_type(x._alloc);
            _end = _empty_node();
            _rend = _empty_node();
            const_iterator src_it = x.begin();
            for (; src_it != x.end(); src_it++)
                _add_one(*src_it);
        }

        ~map () {
            _delete_tree();
            if (_end) {
                _alloc.destroy(_end);
                _alloc.deallocate(_end, 1);
                _end = NULL;
            }
            if (_rend) {
                _alloc.destroy(_rend);
                _alloc.deallocate(_rend, 1);
                _rend = NULL;
            }
        }

        map &operator=(const map & x) {
            _root = NULL;
            _size = 0;
            _comp = key_compare(x._comp);
            _alloc = allocator_type(x._alloc);
            _end = _empty_node();
            _rend = _empty_node();
            const_iterator src_it = x.begin();
            for (; src_it != x.end(); src_it++)
                _add_one(*src_it);

            return *this;
        }

        // Iterators
        iterator    begin() {
            if (_size == 0)
                return (end());
            t_node *	tmp = _root;
            while (tmp && tmp->left)
                tmp = tmp->left;
            return iterator(tmp);
        }

        const_iterator  begin() const {
            if (_size == 0)
                return (end());
            t_node *	tmp = _root;
            while (tmp && tmp->left)
                tmp = tmp->left;
            return const_iterator(reinterpret_cast<node<const value_type> *>(tmp));
        }

        iterator    end() {
            return iterator(_end);
        }

        const_iterator  end() const {
            return const_iterator(reinterpret_cast<node<const value_type> *>(_end));
        }

        reverse_iterator rbegin() {
            if (_size == 0)
                return (rend());
            return reverse_iterator(end());
        }

        const_reverse_iterator	rbegin() const {
            if (_size == 0)
                return (rend());
            return const_reverse_iterator(end());
        }

        reverse_iterator    rend() {
            return reverse_iterator(begin());
        }

        const_reverse_iterator  rend() const {
            return const_reverse_iterator(begin());
        }

        // Capacity
        bool        empty() const { return (_size == 0); }
        size_type	size() const { return (_size); }

        size_type	max_size () const {
            size_type	max_size = ~0;

            typename allocator_type::size_type	_alloc_size = _alloc.max_size();
            return (max_size > _alloc_size ? _alloc_size : max_size);
        }

        // Element access
        mapped_type &operator[](const key_type &k) {
            t_node * found;

            if ((found = _search_node(_root, k)))
                return found->data.second;
            value_type	inserted = ft::make_pair(k, mapped_type());
            _add_one(inserted);
            found = _search_node(_root, k);
            return found->data.second;
        }

        // Modifiers
        pair<iterator, bool> insert(const value_type &val) {
            t_node * found;
            if ((found = _search_node(_root, val.first)))
                return ft::make_pair(iterator(found), false);
            _add_one(val);
            return ft::make_pair(iterator(_search_node(_root, val.first)), true);
        }

        iterator insert(iterator position, const value_type &val) {
            (void) position;
            t_node * found;
            if ((found = _search_node(_root, val.first)))
                return iterator(found);
            _add_one(val);
            return iterator(_search_node(_root, val.first));
        }

        template < class InputIterator >
        void    insert(InputIterator first, InputIterator last) {
            while (first != last) {
                _add_one(*first);
                first++;
            }
        }

        void    erase(iterator position) { _delete_one((*position).first); }

        size_type	erase(const key_type & k) {
            if (_search_node(_root, k)) {
                _delete_one(k);
                return 1;
            }
            return (0);
        }
        void		erase(iterator first, iterator last) {
            while (first != last) {
                _delete_one((*first).first);
                first++;
            }
        }

        void    swap(map & x) {
            map	tmp(*this);

            clear();
            if (_end) {
                _alloc.destroy(_end);
                _alloc.deallocate(_end, 1);
                _end = NULL;
            }
            if (_rend) {
                _alloc.destroy(_rend);
                _alloc.deallocate(_rend, 1);
                _rend = NULL;
            }
            new (this) map(x);

            x.clear();

            if (x._end) {
                _alloc.destroy(x._end);
                _alloc.deallocate(x._end, 1);
                x._end = NULL;
            }
            if (x._rend) {
                _alloc.destroy(x._rend);
                _alloc.deallocate(x._rend, 1);
                x._rend = NULL;
            }
            x = tmp;
        }

        void    clear() { _delete_tree(); }

        // Observers
        key_compare	key_comp() const { return _comp; }
        value_compare value_comp() const { return value_compare(_comp); }

        // Operations
        iterator    find(const key_type & k) {
            t_node * found;

            if ((found = _search_node(_root, k)))
                return iterator(found);
            return end();
        }
        const_iterator  find(const key_type & k) const {
            t_node * found;

            if ((found = _search_node(_root, k)))
                return iterator(found);
            return end();
        }

        size_type   count(const key_type & k) const {
            if (_search_node(_root, k))
                return 1;
            return 0;
        }

        iterator lower_bound(const key_type &k)
        {
            iterator it = begin();
            for (; it != end(); it++)
            {
                if (_comp(it->first, k) == false)
                    break;
            }
            return it;
        }

        const_iterator lower_bound(const key_type &k) const
        {
            const_iterator it = begin();
            for (; it != end(); it++)
            {
                if (_comp(it->first, k) == false)
                    break;
            }
            return it;
        }

        iterator upper_bound(const key_type &k)
        {
            iterator it = begin();
            for (; it != end(); it++)
            {
                if (_comp(k, it->first) == true)
                    break;
            }
            return it;
        }

        const_iterator upper_bound(const key_type &k) const
        {
            const_iterator it = begin();
            for (; it != end(); it++)
            {
                if (_comp(k, it->first) == true)
                    break;
            }
            return it;
        }

        pair<iterator, iterator> equal_range(const key_type & k) {
            t_node * found;

            if ((found = _search_node(_root, k)))
                return ft::make_pair(lower_bound(k), upper_bound(k));
            return ft::make_pair(upper_bound(k), upper_bound(k));
        }
        pair<const_iterator, const_iterator> equal_range(const key_type & k) const {
            t_node * found;

            if ((found = _search_node(_root, k)))
                return ft::make_pair(lower_bound(k), upper_bound(k));
            return ft::make_pair(upper_bound(k), upper_bound(k));
        }

        // Allocator
        allocator_type	get_allocator() const { return (_alloc_data); }

    private:
        node_allocator	_alloc;
        allocator_type	_alloc_data;
        key_compare		_comp; // to sort the elements
        size_type		_size; // size of map
        t_node *		_root; // root of binary tree

        t_node *		_end;
        t_node *		_rend;

        void    _add_one(const value_type & element) {
            if (_search_node(_root, element.first))
                return ;
            _root = _add_node(NULL, _root, element);
            _end->parent = _get_max_node(_root);
            _rend->parent = _get_min_node(_root);
            _size++;
        }

        void	_delete_one(const key_type & key) {
            if (!_search_node(_root, key))
                return ;
            _root = _delete_node(_root, key);
            _end->parent = _get_max_node(_root);
            _rend->parent = _get_min_node(_root);
            _size--;
        }

        bool	_is_rightmost_node(t_node * _ptr) const {
            t_node *	tmp = _ptr;

            while (tmp && tmp->parent)
                tmp = tmp->parent;
            while (tmp && tmp->right)
                tmp = tmp->right;
            if (tmp == _ptr)
                return true;
            return false;
        }

        bool    _is_leftmost_node(t_node * _ptr) const {
            t_node *	tmp = _ptr;

            while (tmp && tmp->parent)
                tmp = tmp->parent;
            while (tmp && tmp->left)
                tmp = tmp->left;
            if (tmp == _ptr)
                return true;
            return false;
        }

        int _get_height(t_node *N) const {
            if (N == NULL)
                return 0;
            return N->height;
        }

        int		_max(int a, int b) const {
            return (a > b)? a : b;
        }

        bool    _is_balanced(t_node * node) const {
            if (!node)
                return true;
            if (abs(_get_balance(node)) <= 1 && _is_balanced(node->left) && _is_balanced(node->right))
                return true;
            return false;
        }

        int		_get_balance(t_node * node) const {
            if (!node || (!node->left && !node->right))
                return (0);
            if (!node->left)
                return -node->right->height;
            if (!node->right)
                return node->left->height;
            return node->left->height - node->right->height;
        }

        t_node *_right_rotation(t_node *x)
        {
            t_node *y = x->left;
            x->left = y->right;

            if (y->right)
                y->right->parent = x;
            y->parent = x->parent;
            if (!x->parent)
                _root = y;
            else if (x == x->parent->right)
                x->parent->right = y;
            else
                x->parent->left = y;

            y->right = x;
            x->parent = y;

            x->height = _max(_get_height(x->left), _get_height(x->right)) + 1;
            y->height = _max(_get_height(y->left), _get_height(y->right)) + 1;

            return y;
        }

        t_node *_left_rotation(t_node *x)
        {
            t_node *y = x->right;
            x->right = y->left;

            if (y->left)
                y->left->parent = x;
            y->parent = x->parent;
            if (!x->parent)
                _root = y;
            else if (x == x->parent->left)
                x->parent->left = y;
            else
                x->parent->right = y;

            y->left = x;
            x->parent = y;

            x->height = _max(_get_height(x->left), _get_height(x->right)) + 1;
            y->height = _max(_get_height(y->left), _get_height(y->right)) + 1;

            return y;
        }


        t_node *    _balance_tree(t_node * node, const value_type & val, bool delete_node) {
            node->height = 1 + _max(_get_height(node->left), _get_height(node->right));
            int balance = _get_balance(node);

            if (delete_node) {
                // Left Left Case
                if (balance > 1 && _get_balance(node->left) >= 0)
                    return _right_rotation(node);

                // Left Right Case
                if (balance > 1 && _get_balance(node->left) < 0)
                {
                    node->left = _left_rotation(node->left);
                    return _right_rotation(node);
                }

                // Right Right Case
                if (balance < -1 && _get_balance(node->right) <= 0)
                    return _left_rotation(node);

                // Right Left Case
                if (balance < -1 && _get_balance(node->right) > 0)
                {
                    node->right = _right_rotation(node->right);
                    return _left_rotation(node);
                }
            }
            else {
                // Left Left Case
                if (balance > 1 && _comp(val.first, node->left->data.first))
                    return _right_rotation(node);

                // Right Right Case
                if (balance < -1 && !_comp(val.first, node->right->data.first))
                    return _left_rotation(node);

                // Left Right Case
                if (balance > 1 && !_comp(val.first, node->left->data.first))
                {
                    node->left = _left_rotation(node->left);
                    return _right_rotation(node);
                }

                // Right Left Case
                if (balance < -1 && _comp(val.first, node->right->data.first))
                {
                    node->right = _right_rotation(node->right);
                    return _left_rotation(node);
                }
            }
            return node;
        }

        t_node *	_empty_node() {
            t_node *	ret = _alloc.allocate(1);
            _alloc.construct(ret, t_node());
            ret->left = NULL;
            ret->right = NULL;
            ret->parent = NULL;
            ret->data = value_type();
            ret->height = 0;
            ret->_end = NULL;
            ret->_rend = NULL;
            return ret;
        }

        t_node * _new_node(const value_type & val, t_node * parent) {
            t_node *node = _alloc.allocate(1);
            _alloc.construct(node, t_node());
            node->left = NULL;
            node->right = NULL;
            node->parent = parent;
            node->data = val;
            node->height = 1;
            node->_end = _end;
            node->_rend = _rend;
            return node;
        }

        t_node *	_add_node(t_node * parent, t_node * node, const value_type & val) {
            if (!node)
                return _new_node(val, parent);
            if (_comp(val.first, node->data.first))
                node->left = _add_node(node, node->left, val);
            else if (!_comp(val.first, node->data.first))
                node->right = _add_node(node, node->right, val);
            return _balance_tree(node, val, false);
        }

        t_node * _get_min_node(t_node * node) const {
            t_node * current = node;

            while (current && current->left != NULL)
                current = current->left;

            return current;
        }

        t_node * _get_max_node(t_node * node) const {
            t_node * current = node;

            while (current && current->right != NULL)
                current = current->right;

            return current;
        }

        t_node *	_delete_node(t_node * node, const key_type & key) {
            t_node * tmp;
            if (!node)
                return node;
            else if (!_comp(key, node->data.first) && !_comp(node->data.first, key)) {
                if (!node->left && !node->right) {
                    _alloc.destroy(node);
                    _alloc.deallocate(node, 1);
                    node = NULL;
                }
                else if (!node->left) {
                    tmp = node;
                    node = node->right;
                    node->parent = tmp->parent;
                    _alloc.destroy(tmp);
                    _alloc.deallocate(tmp, 1);
                    tmp = NULL;
                }
                else if (!node->right) {
                    tmp = node;
                    node = node->left;
                    node->parent = tmp->parent;
                    _alloc.destroy(tmp);
                    _alloc.deallocate(tmp, 1);
                    tmp = NULL;
                }
                else {
                    tmp = _get_min_node(node->right);
                    node->data = tmp->data;
                    node->right = _delete_node(node->right, tmp->data.first);
                }
            }
            else if (_comp(key, node->data.first))
                node->left = _delete_node(node->left, key);
            else if (!_comp(key, node->data.first))
                node->right = _delete_node(node->right, key);
            if (!node)
                return node;
            return _balance_tree(node, node->data, true);
        }

        t_node *	_search_node(t_node * node, const key_type & val) const {
            if (!node)
                return (NULL);
            if (!_comp(val, node->data.first) && !_comp(node->data.first, val))
                return node;
            else if (_comp(val, node->data.first))
                return _search_node(node->left, val);
            else if (!_comp(val, node->data.first))
                return _search_node(node->right, val);
            return (NULL);
        }

        void	_delete_tree() {
            while (_root)
                _delete_one(_root->data.first);
        }
    };
    template <class Key, class T, class Compare, class Alloc>
    bool operator==(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
    {
        if (lhs.size() == rhs.size())
            return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
        else
            return false;
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator!=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
    {
        return !(lhs == rhs);
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator<(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
    {
        return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator<=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
    {
        return !(rhs < lhs);
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator>(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
    {
        return (rhs < lhs);
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator>=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
    {
        return !(lhs < rhs);
    }

    template <class Key, class T, class Compare, class Alloc>
    void swap(map<Key, T, Compare, Alloc> &x, map<Key, T, Compare, Alloc> &y)
    {
        x.swap(y);
    }
};

#endif //FT_CONTAINERS_MAP_HPP
