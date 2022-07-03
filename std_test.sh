echo STD_TEST run!
c++ -Wall -Wextra -Werror -std=c++98 tests/std_main.cpp -o std_con
./std_con
rm std_con