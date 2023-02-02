// C++11, variadic template can be implemented using recursive template specialization
#include <iostream>

template <typename T>
void print(T t)
{
    std::cout << t << std::endl;
}

template <typename T, typename... Args>
void print(T t, Args... args)
{
    std::cout << t << " ";
    print(args...);
}

// C++17

template <typename T, typename... Args>
void print(T t, Args... args)
{
    (std::cout << ... << t);
    (print(args...), ...);
}

/*C++20 version of the function only requires
 the function parameter pack, without the need for the first template argument T. This is because std::cout << ... << args will automatically
deduce the type of each argument.*/

template <typename... Args>
void print(Args... args)
{
    (std::cout << ... << args);
}
