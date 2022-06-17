//
// Created by Quayle Rolande on 6/8/22.
//

#ifndef FT_CONTAINERS_VECTOR_HPP
#define FT_CONTAINERS_VECTOR_HPP

#include "iostream"
#include "memory"

namespace ft {
	template<class T,class Allocator = std::allocator<T> >
	class vector {
	public:
		// types:
		typedef T                                   value_type;
		typedef std::size_t                         size_type;
		typedef std::ptrdiff_t                      difference_type;
		typedef typename Allocator::allocator_type  allocator_type;

		typedef typename Allocator::pointer         pointer;
		typedef typename Allocator::const_pointer   const_pointer;
		typedef typename Allocator::reference       reference;
		typedef typename Allocator::const_reference const_reference;

//		typedef implementation defined iterator;
//		typedef implementation defined const_iterator;
//		typedef implementation defined size_type;
//		typedef implementation defined difference_type;
//		typedef std::reverse_iterator<iterator> reverse_iterator;
//		typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

		//_2_Constructors and destructors
		explicit vector(const allocator_type& alloc = allocator_type()):
			_start(0),
			_size(0),
			_capacity(0),
			_alloc(alloc) {};

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
				this->_start = this->allocator.allocate(this->_capacity);
			}
			for (size_type i = 0; i < this->_size; i++)
				this->_alloc.construct(_start + i, x[i]);
			return (*this);
		}

		//_3_Capacity
		size_type size() const{ return (this->_size); };
		size_type max_size() const{ return (this->allocator.max_size()); }; //максимально возможный размер выделенной памяти
		size_type capacity() const { return (_capacity); };
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
		reference front(){ return(*_start); };
		const_reference front() const { return(*_start); };

		//возращает ссылку на последний элемент вектора
		reference back(){ return(*(_start + _size - 1)); };
		const_reference back() const { return(*(_start + _size - 1)); };

		//Элементы доступа без защиты
		reference operator[](size_type i){ return (*(_start + i)); };
		const_reference operator[](size_type i) const { return (*(_start + i)); };

		//Элементы доступа с защитой
		reference at(size_type i){
			if (i > _capacity){
				throw std::out_of_range("index out of range");
			}
			return (*(_start + i));
		};
		const_reference at(size_type i) const{
			if (i > _capacity){
				throw std::out_of_range("index out of range");
			}
			return (*(_start + i));
		};

		//_4_Modifiers:

		void swap (vector &x){
			if (this != &x){
				std::swap(_start, x._start);
				std::swap(_size, x._size);
				std::swap(_capacity, x._capacity);
				std::swap(_alloc, x.allocator);
			}
		};


	protected:
		Allocator	_alloc;     // аллокатор для выделения памяти
		pointer		_start;     // поинтер на начало
		size_type   _size;      // размер
		size_type   _capacity;  // емкость
	};
}

#endif //FT_CONTAINERS_VECTOR_HPP
