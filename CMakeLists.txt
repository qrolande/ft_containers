cmake_minimum_required(VERSION 3.21)
project(ft_containers)

set(CMAKE_CXX_STANDARD 98)

add_executable(ft_containers ../Containers/Stack.hpp ft_main.cpp Containers/Vector.hpp iterators/iterator_traits.hpp iterators/random_access_iterator.hpp iterators/reverse_iterator.hpp other/enable_if.hpp other/libs.hpp other/is_integral.hpp other/equal.hpp other/lexicographical_compare.hpp other/pair.hpp main.cpp)
