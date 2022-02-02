#pragma once

#include <iostream>

template<typename T, typename U>
struct my_pair
{
    template<typename A, typename B>
    friend inline my_pair<A, B> make_my_pair(A&&, B&&);

    // Swap
    template<typename A, typename B>
    friend inline void swap(my_pair<A, B>& lhs, my_pair<A, B>& rhs) noexcept(noexcept(lhs.swap(rhs)));

    // Output Operator
    template <typename A, typename B>
    friend std::ostream& operator << (std::ostream&, const my_pair<A, B>&);

    // Relational Operators
    template <typename A, typename B>
    friend inline bool operator == (const my_pair<A, B>&, const my_pair<A, B>&);

    template <typename A, typename B>
    friend inline bool operator != (const my_pair<A, B>&, const my_pair<A, B>&);

    template <typename A, typename B>
    friend inline bool operator < (const my_pair<A, B>&, const my_pair<A, B>&);

    template <typename A, typename B>
    friend inline bool operator <= (const my_pair<A, B>&, const my_pair<A, B>&);

    template <typename A, typename B>
    friend inline bool operator > (const my_pair<A, B>&, const my_pair<A, B>&);

    template <typename A, typename B>
    friend inline bool operator >= (const my_pair<A, B>&, const my_pair<A, B>&);

    using first_type  = T;
    using second_type = U;

    T first; U second;

    constexpr my_pair() = default;
    constexpr my_pair(const T& f, const U& s);
    constexpr my_pair(const my_pair& obj);
    constexpr my_pair operator = (const my_pair& obj);
    ~my_pair() {}

    inline void swap(my_pair& obj) noexcept 
                           (noexcept(std::swap(first, obj.first)) &&
                            noexcept(std::swap(second, obj.second))
                           );
    
};

template<typename T, typename U>
constexpr my_pair<T, U>::my_pair(const T& f, const U& s)
    : first  { f },
      second { s }
{
}

template<typename T, typename U>
constexpr my_pair<T, U>::my_pair(const my_pair& obj)
    : first { obj.first },
      second { obj.second }
{
}

template<typename T, typename U>
constexpr my_pair<T, U> my_pair<T, U>::operator = (const my_pair& obj)
{
    if (this != &obj)
    {
        first  = obj.first;
        second = obj.second;
    }

    return *this;
}

template<typename T, typename U>
void my_pair<T, U>::swap(my_pair& obj) noexcept 
                                  (noexcept(std::swap(first, obj.first)) &&
                                   noexcept(std::swap(second, obj.second)))
{
    std::swap(first, obj.first);
    std::swap(second, obj.second);
}

template <typename A, typename B>
std::ostream& operator << (std::ostream& os, const my_pair<A, B>& obj)
{
    os << "First: "  << obj.first << ' '
       << "Second: " << obj.second;

    return os;
}

template <typename A, typename B>
inline bool operator == (const my_pair<A, B>& lhs, const my_pair<A, B>& rhs)
{
    return lhs.first == rhs.first && lhs.second == rhs.second;
}

template <typename A, typename B>
inline bool operator != (const my_pair<A, B>& lhs, const my_pair<A, B>& rhs)
{
    return !(lhs == rhs);
}

template <typename A, typename B>
inline bool operator < (const my_pair<A, B>& lhs, const my_pair<A, B>& rhs)
{
    return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
}

template <typename A, typename B>
inline bool operator <= (const my_pair<A, B>& lhs, const my_pair<A, B>& rhs)
{
    return !(rhs < lhs);
}

template <typename A, typename B>
inline bool operator > (const my_pair<A, B>& lhs, const my_pair<A, B>& rhs)
{
    return rhs < lhs;
}

template <typename A, typename B>
inline bool operator >= (const my_pair<A, B>& lhs, const my_pair<A, B>& rhs)
{
    return !(lhs < rhs);
}

template<typename A, typename B>
inline void swap(my_pair<A, B>& lhs, my_pair<A, B>& rhs) noexcept(noexcept(lhs.swap(rhs)))
{
    lhs.swap(rhs);
}

template<typename A, typename B>
inline my_pair<A, B> make_my_pair(A&& obj_a, B&& obj_b)
{
    return my_pair<A, B>(std::forward<A>(obj_a), std::forward<B>(obj_b));
}
