//Quick reference for include paths, namespaces, & a little example code

#include <climits>
#include <iostream>
#include <iterator>

#include <boost/multiprecision/cpp_int.hpp>
void cpp_int_example()
{
    boost::multiprecision::cpp_int big{ULLONG_MAX};
    big *= 2;
    std::cout << big << '\n';
    boost::multiprecision::cpp_rational small{1};
    small /= big;
    std::cout << small << '\n';
}

#include <boost/safe_numerics/safe_integer.hpp>
void safe_integer_example()
{
    try {
        boost::safe_numerics::safe<int> n{INT_MAX};
        n *= 2;
        std::cout << n << '\n';
    } catch (const std::exception& e) {
        std::cout << e.what() << '\n';
    }
}

#include <boost/range/algorithm.hpp>
#include <boost/range/adaptors.hpp>
void range_example()
{
    std::unordered_map<int, std::string> m{
        {1, "one"}, {2, "two"}, {3, "three"}
    };
    boost::for_each(m | boost::adaptors::map_values, [](auto& x){ x += ":"; });
    boost::copy(m | boost::adaptors::map_values,
            std::ostream_iterator<std::string>(std::cout, ", "));
    boost::copy(m | boost::adaptors::map_keys,
            std::ostream_iterator<int>(std::cout, "; "));
    //push_back(target, m | map_values | filtered(is_even()) | reversed)
    std::cout << '\n';
}

#include <boost/algorithm/string.hpp>
void string_example()
{
    const std::string test{" test "};
    auto fixed { boost::to_upper_copy(boost::trim_copy(test)) };
    std::cout << fixed;
    fixed = test;
    boost::trim(fixed);
    boost::to_upper(fixed);
    std::cout << " ; " << fixed;
    std::cout << '\n';
    //replace_all
    //erase_all
    //find_iterator
    //split_iterator
    //find_all
    //split
    //Prefix many things with "i" for case insensitive
}

//Boost algorithm
//clamp
//hex & unhex
//copy_until & copy_while

//Boost circular_buffer

//Boost container
//static_vector
//small_vector

// lexical cast

#include <boost/process.hpp>

//HOF
//Iostreams
//Iterator

int main()
{
    cpp_int_example();
    safe_integer_example();
    range_example();
    string_example();
}

