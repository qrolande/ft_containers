//
// Created by Quayle Rolande on 6/6/22.
//

#include "iostream"
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include "Containers/Stack.hpp"
#include <sys/time.h>

template<typename T>
class MutantStack : public ft::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T>& src) { *this = src; }
	MutantStack<T>& operator=(const MutantStack<T>& rhs)
	{
		this->_c = rhs._c;
		return *this;
	}
	~MutantStack() {}

	typedef typename ft::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->_c.begin(); }
	iterator end() { return this->_c.end(); }
};

void	stack() {
	struct timeval tp;
	gettimeofday(&tp, NULL);
	long int ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;

	std::cout << "-----TEST-STD_STACK-----\n";
	std::cout << "TEST 1 assert\n";
	{
		typedef std::allocator<char> aloc;
		typedef std::deque<char, aloc> deq;
		typedef std::vector<char, aloc> vec;

		typedef std::stack<char, deq> stack_deq;
		typedef std::stack<char, vec> stack_vec;

		stack_deq s_deq, s_deq0;
		stack_vec s_vec, s_vec0;

		s_deq.push('a');
		s_vec.push('a');
		assert(s_deq.size() == 1 && s_deq.top() == 'a');
		assert(s_vec.size() == 1 && s_vec.top() == 'a');
		std::cout << "assert 1: passed\n";
		s_deq.push('b');
		s_vec.push('b');
		assert(s_deq.size() == 2 && s_deq.top() == 'b');
		assert(s_vec.size() == 2 && s_vec.top() == 'b');
		std::cout << "assert 2: passed\n";
		s_deq.push('c');
		s_vec.push('c');
		assert(s_deq.size() == 3 && s_deq.top() == 'c');
		assert(s_vec.size() == 3 && s_vec.top() == 'c');
		std::cout << "assert 3: passed\n";
		assert(s_deq == s_deq && s_deq0 < s_deq);
		assert(s_vec == s_vec && s_vec0 < s_vec);
		std::cout << "assert 4: passed\n";
		assert(s_deq != s_deq0 && s_deq > s_deq0);
		assert(s_vec != s_vec0 && s_vec > s_vec0);
		std::cout << "assert 5: passed\n";
		assert(s_deq0 <= s_deq && s_deq >= s_deq0);
		assert(s_vec0 <= s_vec && s_vec >= s_vec0);
		std::cout << "assert 6: passed\n";
		s_deq.pop();
		s_vec.pop();
		assert(s_deq.top() == 'b');
		assert(s_vec.top() == 'b');
		std::cout << "assert 7: passed\n";
		s_deq.pop();
		s_vec.pop();
		assert(s_deq.top() == 'a');
		assert(s_vec.top() == 'a');
		std::cout << "assert 8: passed\n";
		s_deq.pop();
		s_vec.pop();
		assert(s_deq.empty());
		assert(s_vec.empty());
		std::cout << "assert 9: passed\n";

		std::cout << "------------------------\n";
	}
	std::cout << "TEST 2 iterable stack\n";
	{
		std::string temp = "Hello World!";
		MutantStack<char> iterable_stack;
		for (int i = 0; temp[i] != '\0'; i++)
			iterable_stack.push(temp[i]);
		for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++) {
			std::cout << *it;
		}
		std::cout << std::endl;
		std::cout << "------------------------\n";
	}
	std::cout << "TEST 3 inner containers\n";
	{
		ft::stack<int, std::deque<int> > stack_deq_buffer;
		for (int i = 0; i < 10; i++)
			stack_deq_buffer.push(i);
		assert(stack_deq_buffer.size() == 10);
	}
	struct timeval tp2;
	gettimeofday(&tp2, NULL);
	long int ms2 = tp2.tv_sec * 1000 + tp2.tv_usec / 1000;
	long int res = ms2 - ms;
	std::cout << "std_stack SUCCESS! Total time " << res << " ms!\n";
}

int main()
{
	stack();
//	test_vector();
//	test_map();
//	test_set();

	return (0);
}