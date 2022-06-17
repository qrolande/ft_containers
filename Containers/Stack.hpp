//
// Created by Quayle Rolande on 6/4/22.
//

#ifndef FT_CONTAINERS_STACK_HPP
#define FT_CONTAINERS_STACK_HPP

#include "vector"
#include "memory"

namespace ft {
	template < class Type, class Container = std::vector <Type> >
	class stack {
	protected:
		Container _c;
	public:
		typedef typename Container::value_type  value_type;
		typedef typename Container::size_type   size_type;
		typedef          Container              container_type;

//		stack(): _c() {};
		explicit stack(const Container &cont = Container()): _c(cont) {}
//		explicit stack(const Container& = Container()){};
		stack(const stack<Type, Container>& other_cont): _c(other_cont._c) {}
		~stack() {
			_c.clear();
		}

		bool                empty() const               { return _c.empty(); }
		size_type           size() const                { return _c.size(); }
		value_type&         top()                       { return _c.back(); }
		const value_type&   top() const                 { return _c.back(); }
		void                push(const value_type& x)   { _c.push_back(x); }
		void                pop()                       { _c.pop_back(); }

		bool                eq(const stack<Type, Container>& other_cont) const { return (_c == other_cont._c);}
		bool                eq_not(const stack<Type, Container>& other_cont) const { return (_c != other_cont._c);}
		bool                less(const stack<Type, Container>& other_cont) const { return (_c < other_cont._c);}
		bool                more(const stack<Type, Container>& other_cont) const { return (_c > other_cont._c);}
		bool                less_and_eq(const stack<Type, Container>& other_cont) const { return (_c <= other_cont._c);}
		bool                more_and_eq(const stack<Type, Container>& other_cont) const { return (_c >= other_cont._c);}

	};
		template <class T, class C>
		bool operator==(const stack<T, C>& x, const stack<T, C>& y) {return (x.eq(y));}

		template <class T, class C>
		bool operator<(const stack<T, C>& x, const stack<T, C>& y) {return (x.less(y));}

		template <class T, class C>
		bool operator!=(const stack<T, C>& x, const stack<T, C>& y) {return (x.eq_not(y));}

		template <class T, class C>
		bool operator>(const stack<T, C>& x, const stack<T, C>& y) {return (x.more(y));}

		template <class T, class C>
		bool operator>=(const stack<T, C>& x, const stack<T, C>& y) {return (x.more_and_eq(y));}

		template <class T, class C>
		bool operator<=(const stack<T, C>& x, const stack<T, C>& y) {return (x.less_and_eq(y));}

}

#endif //FT_CONTAINERS_STACK_HPP
