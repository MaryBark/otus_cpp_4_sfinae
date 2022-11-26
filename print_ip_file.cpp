#include <iostream>
#include <type_traits>
#include <list>
#include <vector>
#include <tuple>
#include <string>

static const char OctetSeparator = '.';


template <typename T>
static std::enable_if_t<std::is_integral_v<T>, void> PrintIp(T value)
{
    static const size_t constexpr SizeInOctets = sizeof(T);
    for (size_t i = SizeInOctets; i--;)
    {
        std::cout << (value >> (i << 3) & 0xFF);
        if (i > 0)
            std::cout << OctetSeparator;
    }
    std::cout << std::endl;
}

static void PrintIp(const std::string& value)
{
    std::cout << value << std::endl;
}


template <typename>
struct is_std_vector_or_list : std::false_type {};

template <typename T, typename... Args>
struct is_std_vector_or_list<std::vector<T, Args...>> : std::true_type {};

template <typename T, typename... Args>
struct is_std_vector_or_list<std::list<T, Args...>> : std::true_type {};


template <typename T>
static void PrintIp(std::enable_if_t<is_std_vector_or_list<T>::value, const T&> container)
{
    for (auto it = container.begin(); it != container.end(); ++it)
    {
        std::cout << *it;
        if (it != std::prev(container.end()))
            std::cout << OctetSeparator;
    }
    std::cout << std::endl;
}

template <size_t I>
struct PrintTuple
{
    template <typename Type0, typename... Types>
    static constexpr void Print(const std::tuple<Type0, Types...>& tuple)
    {
        auto element = std::get<sizeof...(Types) + 1 - I>(tuple);
        static_assert (std::is_same_v<Type0, decltype(element)>, "different types in tuple!");

        std::cout << element;
        if (I > 1)
            std::cout << OctetSeparator;

        PrintTuple<I - 1>::Print(tuple);
    }
};

template <>
struct PrintTuple<0>
{
    template <typename... Types>
    static constexpr void Print(const std::tuple<Types...>&) {}
};

template <typename... Types>
static void PrintIp(const std::tuple<Types...>& tuple)
{
    PrintTuple<sizeof...(Types)>::Print(tuple);
    std::cout << std::endl;
}
