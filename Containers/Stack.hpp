//
// Created by Quayle Rolande on 6/4/22.
//

#ifndef FT_CONTAINERS_STACK_HPP
#define FT_CONTAINERS_STACK_HPP

#include "Vector.hpp"

namespace ft {
	template < class Type, class Container = ft::vector <Type> >
	class stack {
	protected:
		Container c;
	public:
		typedef typename Container::value_type  value_type;
		typedef typename Container::size_type   size_type;
		typedef          Container              container_type;

		explicit stack(const Container &cont = Container()): c(cont) {}
		stack(const stack<Type, Container>& other_cont): c(other_cont.c) {}
		~stack() { c.clear(); }

		bool                empty() const               { return c.empty(); }
		size_type           size() const                { return c.size(); }
		value_type&         top()                       { return c.back(); }
		const value_type&   top() const                 { return c.back(); }
		void                push(const value_type& x)   { c.push_back(x); }
		void                pop()                       { c.pop_back(); }

		bool                eq(const stack<Type, Container>& other_cont) const { return (c == other_cont.c);}
		bool                eq_not(const stack<Type, Container>& other_cont) const { return (c != other_cont.c);}
		bool                less(const stack<Type, Container>& other_cont) const { return (c < other_cont.c);}
		bool                more(const stack<Type, Container>& other_cont) const { return (c > other_cont.c);}
		bool                less_and_eq(const stack<Type, Container>& other_cont) const { return (c <= other_cont.c);}
		bool                more_and_eq(const stack<Type, Container>& other_cont) const { return (c >= other_cont.c);}

	};
		template <class T, class C>
		bool operator==(const stack<T, C>&x, const stack<T, C>&y) {return (x.eq(y));}

		template <class T, class C>
		bool operator<(const stack<T, C>&x, const stack<T, C>&y) {return (x.less(y));}

		template <class T, class C>
		bool operator!=(const stack<T, C>&x, const stack<T, C>&y) {return (x.eq_not(y));}

		template <class T, class C>
		bool operator>(const stack<T, C>&x, const stack<T, C>&y) {return (x.more(y));}

		template <class T, class C>
		bool operator>=(const stack<T, C>&x, const stack<T, C>&y) {return (x.more_and_eq(y));}

		template <class T, class C>
		bool operator<=(const stack<T, C>&x, const stack<T, C>&y) {return (x.less_and_eq(y));}

}

#endif //FT_CONTAINERS_STACK_HPP
