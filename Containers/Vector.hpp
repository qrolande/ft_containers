//
// Created by Quayle Rolande on 6/8/22.
//

#ifndef FT_CONTAINERS_VECTOR_HPP
#define FT_CONTAINERS_VECTOR_HPP

#include "iostream"
#include "memory"
#include "../other/libs.hpp"

namespace ft {
	template<class T,class Allocator = std::allocator<T> >
	class vector {
	public:
		// types:
		typedef T                                                  value_type;
		typedef std::size_t                                        size_type;
		typedef std::ptrdiff_t                                     difference_type;
        typedef Allocator                                          allocator_type;

		typedef typename allocator_type::pointer                   pointer;
		typedef typename allocator_type::const_pointer             const_pointer;
		typedef typename allocator_type::reference                 reference;
		typedef typename allocator_type::const_reference           const_reference;

        typedef ft::random_access_iterator<value_type>             iterator;
        typedef ft::random_access_iterator<const value_type>       const_iterator;
        typedef ft::reverse_iterator<iterator>                     reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>               const_reverse_iterator;

		//_2_Constructors and destructors
		explicit vector(const allocator_type& alloc = allocator_type()):
            _alloc(alloc),
            _start(0),
			_size(0),
			_capacity(0) {};

		explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()):
			_size(n),
			_capacity(n),
			_alloc(alloc)
		{
			_start = _alloc.allocate(n);
			for(size_type i = 0; i < n; i++)
				_alloc.construct(_start + i, val); //заполняем каждый элемент вектора дефолтным значением.(0, "")
		};

		vector(const vector& right):_size(0), _capacity(0) { *this = right; };

        template<class InputIter>
        vector(InputIter input1, InputIter second, const allocator_type & alloc = allocator_type(), typename enable_if<!is_integral<InputIter>::value>::type* = 0): _alloc(alloc){
            if (input1 > second)
                throw std::length_error("vector");
            _size = second - input1;
            _capacity = _size;
            _start = _alloc.allocate(_capacity);
            for(difference_type i = 0; i < static_cast<difference_type>(_size); i++){
                _alloc.construct(_start + i, *(input1 + i));
            }
        }

		~vector(){
			for (size_type i = 0; i < _size; i++){
				_alloc.destroy(_start + i);
			}
			if (_capacity != 0)
				_alloc.deallocate(_start, _capacity);
		};

		//__Assignment_operator
		vector &operator=(const vector& x){
			if (this == &x)
				return (*this);
			for (size_t i = 0; i < this->_size; i++)
				this->_alloc.destroy(_start + i);
			this->_size = x._size;
			if (this->_capacity < this->_size){
				if (this->_capacity != 0)
					this->_alloc.deallocate(_start, _capacity);
				this->_capacity = this->_size;
				this->_start = this->_alloc.allocate(this->_capacity);
			}
			for (size_type i = 0; i < this->_size; i++)
				this->_alloc.construct(_start + i, x[i]);
			return (*this);
		}

		//_3_Capacity
		size_type size() const{ return (this->_size); };
		size_type max_size() const{ return (this->_alloc.max_size()); }; //максимально возможный размер выделенной памяти
		size_type capacity() const { return (this->_capacity); };
		bool empty() const{ return (this->_size == 0); };


		//внутренняя функция резерв, позволяет нам зарезервировать память
		void reserve(size_type n){
			if (n > this->max_size())
				throw (std::length_error("vector too long"));
			pointer new_arr = _alloc.allocate(n);
			try{
				for(size_type i = 0; i < _size; i++)
					_alloc.construct(new_arr + i, *(_start + i));
			} catch (std::exception &e){
				size_type i = 0;
				while (new_arr + i != NULL && i < this->_size) {
					_alloc.destroy(new_arr + i);
					i++;
				}
				_alloc.deallocate(new_arr, n);
				throw ;
			}
			for (size_type i = 0; i < _size; i++){
				_alloc.destroy(_start + i);
			}
			if (_capacity != 0)
				_alloc.deallocate(_start, _capacity);
			_capacity = n;
			_start = new_arr;
		};

		//функция resize увеличивает или уменьшает аллоцированную память до необходимого нам значения.
		void resize(size_type resize_size, value_type value = value_type()){
			if (resize_size < this->_size){
				for(size_type i = resize_size; i < this->_size; i++)
					_alloc.destroy(_start + i);
				this->_size = resize_size;
			} else if (resize_size > this->_size){
				if (this->_capacity < resize_size){
					if (this->_capacity * 2 > resize_size)
						this->reserve(_capacity * 2);
					else
						this->reserve(resize_size);
				}
				for (size_type i = this->_size; i < resize_size; i++){
					_alloc.construct(_start + i, value);
					this->_size++;
				}
			}
		};

		//_4_Element_access
		//возвращают ссылку на первый элемент вектора
		reference front(){ return(*(_start)); };
		const_reference front() const { return(*(_start)); };

		//возращает ссылку на последний элемент вектора
		reference back(){ return(*(_start + _size - 1)); };
		const_reference back() const { return(*(_start + _size - 1)); };

		//Элементы доступа без защиты
		reference operator[](size_type i){ return (*(_start + i)); };
		const_reference operator[](size_type i) const { return (*(_start + i)); };

		//Элементы доступа с защитой
		reference at(size_type i){
			if (i >= _size){
				throw std::out_of_range("index out of range");
			}
			return (*(_start + i));
		};
		const_reference at(size_type i) const{
			if (i >= _size){
				throw std::out_of_range("index out of range");
			}
			return (*(_start + i));
		};

        // Iterators
        iterator begin() {return (iterator(_start)); };                                             //итератор на первый элемент
        const_iterator begin() const { return(const_iterator(_start)); };                           // конст итератор на первый элемент
        iterator end(){ return(iterator(_start + _size)); };                                        // итератор на последний элемент
        const_iterator end() const { return(const_iterator(_start + _size)); };                     // конст итератор на последний элемент
        reverse_iterator rbegin(){ return (reverse_iterator(_start + _size)); };                    // реверс итератор на конец
        const_reverse_iterator rbegin() const { return (const_reverse_iterator(_start + _size)); }; // конст реверс итератор на конец
        reverse_iterator rend(){ return (reverse_iterator(_start)); };                              // итератор на первый элемент
        const_reverse_iterator rend() const { return (const_reverse_iterator(_start)); };           // конст итератор на первый элемент


		//_4_Modifiers:

        template<class inputIter>
        void assign(inputIter first1, inputIter second, typename enable_if<!is_integral<inputIter>::value>::type* = 0){
            if (first1 > second)
                throw std::logic_error("vector");
            difference_type count = second - first1;
            clear();
            if (count > static_cast<difference_type>(capacity())){
                _alloc.deallocate(_start, _capacity);
                _start = _alloc.allocate(count);
                _capacity = count;
            }
            iterator pos = begin();
            while (first1 < second){
                _alloc.construct(&(*pos), *first1);
                pos++;
                first1++;
            }
            _size = count;
        }

        void clear(){
//            for(size_type i = 0; i < _size; i++){
//                _alloc.destroy(_start + i);
//            }
//            _size = 0;
            resize(0);
        };

        void assign (size_type count, const value_type &val){
            clear();
            if (count > _capacity){
                _alloc.deallocate(_start, _capacity);
                _start = _alloc.allocate(count);
                _capacity = count;
            }
            for(size_type i = 0; i < count; i++){
                _alloc.construct(_start + i, val);
            }
            _size = count;
        };

        void push_back(const value_type& value){
            if (_size == _capacity){
                if (_capacity == 0)
                    reserve(1);
                else
                    reserve(_capacity * 2);
            }
            _alloc.construct(_start + _size, value);
            _size++;
        };

        void pop_back(){
            _alloc.destroy(_start + _size - 1);
            _size--;
        };

        template<class Input>
        void insert(iterator position, Input start, Input last, typename enable_if<!is_integral<Input>::value>::type* = 0){
            if (position < begin() || position > end() || start > last)
                throw std::logic_error("vector");
            size_t distance = static_cast<size_t>(position - begin());
            size_t countElements = static_cast<size_t>(last - start);
            if (_size + countElements > _capacity){
                size_t capacity1 = _capacity * 2 >= _size + countElements ? _capacity * 2 : _size + countElements;
                pointer newArr = _alloc.allocate(capacity1);
                std::uninitialized_copy(begin(), position, iterator(newArr));
                try{
                    for (size_t i = 0; i < countElements; start++, i++)
                        _alloc.construct(newArr + distance + i, *start);
                } catch (...){
                    for (size_t i = 0; i < countElements + distance; ++i)
                        _alloc.destroy(newArr + i);
                    _alloc.deallocate(newArr, capacity1);
                    throw;
                }
                std::uninitialized_copy(position, end(), iterator(newArr + distance + countElements));
                for (size_t i = 0; i < _size; i++)
                    _alloc.destroy(_start + i);
                _alloc.deallocate(_start, _capacity);
                _size += countElements;
                _capacity = capacity1;
                _start = newArr;
            } else {
                for (size_t i = _size; i > static_cast<size_t>(distance); i--){
                    _alloc.destroy(_start + i + countElements - 1);
                    _alloc.construct(_start + i + countElements - 1, *(_start + i - 1));
                }
                for (size_t i = 0; i <static_cast<size_t>(countElements); i++, start++){
                    _alloc.destroy(_start + i + countElements);
                    _alloc.construct(_start + distance + i, *start);
                }
                _size += countElements;
            }
        };

        //добавление одного элемента на определенное место
        iterator insert(iterator position, const value_type& val){
            if (position < begin() || position > end())
                throw std::logic_error("vector");
            difference_type distance = position - begin();
            if (_size == _capacity){
                if (_capacity == 0){
                    _capacity = 1;
                } else {
                    _capacity = _capacity * 2;
                }
                pointer newArr = _alloc.allocate(_capacity);
                std::uninitialized_copy(begin(), position, iterator(newArr));
                _alloc.construct(newArr + distance, val);
                std::uninitialized_copy(position, end(), iterator(newArr + distance + 1));
                for (size_t i = 0; i < _size; i++){
                    _alloc.destroy(_start + i);
                }
                _alloc.deallocate(_start, _size);
                _size++;
                _start = newArr;
            } else {
                for(size_type i = _size - 1; i > static_cast<size_type>(distance); i--){
                    _alloc.destroy(_start + i);
                    _alloc.construct(_start + i, *(_start + i - 1));
                }
                _alloc.destroy(&(*position));
                _alloc.construct(&(*position), val);
                _size++;
            }
            return (begin() + distance);
        };

        //вставка n элементов val на определенное место
        void insert(iterator position, size_type n, const value_type& val){
            if (n == 0)
                return;
            else if (max_size() - _size < n){
                throw std::length_error("vector");
            }
            difference_type distance = position - begin();
            if (_size + n > _capacity){
                size_type newCap = _capacity * 2 >= _size + n ? _capacity * 2 : _size + n;
                pointer newArr = _alloc.allocate(newCap);
                std::uninitialized_copy(begin(), position, iterator(newArr));
                for(size_type i = 0; i < n; i++){
                    _alloc.construct(newArr + distance + i, val);
                }
                std::uninitialized_copy(position, end(), iterator(newArr + distance + n));
                for(size_type i = 0; i < _size; i++){
                    _alloc.destroy(_start + i);
                }
                _alloc.deallocate(_start, _capacity);
                _size += n;
                _capacity = newCap;
                _start = newArr;
            }
            else{
                for (size_type i = _size; i > static_cast<size_type>(distance); i--){
                    _alloc.destroy(_start + i + n - 1);
                    _alloc.construct(_start + i + n - 1, *(_start + i - 1));
                }
                for (size_type i = 0; i < n; i++){
                    _alloc.destroy(_start + i + distance);
                    _alloc.construct(_start + i + distance, val);
                }
                _size += n;
            }
        }

        iterator erase(iterator position){
            size_type distance = position - begin();
            for (size_type i = distance; i < _size - 1; ++i){
                _alloc.destroy(_start + i);
                _alloc.construct(_start + i, *(_start + i + 1));
            }
            _size--;
            _alloc.destroy(_start + _size - 1);
            return iterator(_start + distance);
        }

        iterator erase(iterator _first, iterator _last) {
            difference_type start = std::distance(begin(), _first);
            difference_type copy = std::distance(_last, end());
            bool lastEnd = (_last == end());
            while (_first != _last){
                _alloc.destroy(&(*_first));
                _first++;
            }
            size_type i = start;
            while(_last < end()){
                if (this->_start + start)
                    _alloc.destroy(_start + i);
                _alloc.construct(_start + i, *_last);
                i++;
                _last++;
            }
            for (size_type i = start + copy; i < _size; i++)
                _alloc.destroy(_start + i);
            _size = start + copy;
            if (lastEnd == true)
                return end();
            else
                return iterator(_start + start);
        }

        void swap (vector &x){
            allocator_type	tmp_alloc = _alloc;
            pointer			tmp_start = _start;
            size_type		tmp_size = _size;
            size_type		tmp_capacity = _capacity;

            _alloc = x._alloc;
            _start = x._start;
            _size = x._size;
            _capacity = x._capacity;

            x._alloc = tmp_alloc;
            x._start = tmp_start;
            x._size = tmp_size;
            x._capacity = tmp_capacity;
		};


	protected:
		Allocator	_alloc;     // аллокатор для выделения памяти
		pointer		_start;     // поинтер на начало
		size_type   _size;      // размер
		size_type   _capacity;  // емкость
	};

    template <typename T, class Alloc>
    bool  operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
        if (lhs.size() == rhs.size())
            return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
        else
            return false;
    }

    template <typename T, class Alloc>
    bool  operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
        return !(lhs == rhs);
    }

    template <typename T, class Alloc>
    void swap (const vector<T,Alloc> & lhs, const vector<T,Alloc> & rhs) {
        lhs.swap(rhs);
    }

    template <typename T, class Alloc>
    bool  operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
        return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }

    template <typename T, class Alloc>
    bool  operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
        return !(rhs < lhs);
    }

    template <typename T, class Alloc>
    bool  operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
        return (rhs < lhs);
    }

    template <typename T, class Alloc>
    bool  operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
        return !(lhs < rhs);
    }
}

#endif //FT_CONTAINERS_VECTOR_HPP
