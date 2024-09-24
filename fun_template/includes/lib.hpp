#ifndef _LIP_HPP_
#define _LIB_HPP_

using namespace std;

namespace lib
{

template < typename T ,typename U, typename ...Ts>
auto max (const T& a,const U& b,const Ts & ...values)
{
    static_assert(std::is_arithmetic<T>::value,"T must be an arithmetic type.");
    static_assert(std::is_arithmetic<U>::value,"U must be an arithmetic type.");
    static_assert((std::is_arithmetic<Ts>::value && ...),"All Ts must be arithmetic types.");

    auto max_num=a;
    if (b > a)
    max_num=b;
    if constexpr(sizeof... (values) >0)
    {
     max_num= max(max_num,values...);
    }
    return max_num;
}


template < typename T ,typename U, typename ...Ts>
auto min (const T& a,const U& b,const Ts & ...values)
{
    static_assert(std::is_arithmetic<T>::value,"T must be an arithmetic type.");
    static_assert(std::is_arithmetic<U>::value,"U must be an arithmetic type.");
    static_assert((std::is_arithmetic<Ts>::value && ...),"All must be an arithmetic type.");

    auto min_num=a;
    if (b < a)
    min_num=b;
    if constexpr(sizeof... (values) >0)
    {
     min_num= min(min_num,values...);
    }
    return min_num ;
}


template < typename T , typename U, typename ...Ts > 
auto sub (const T& a, const U & b, const Ts & ...values)
{
    static_assert(std::is_arithmetic<T>::value,"T must be an arithmetic type.");
    static_assert(std::is_arithmetic<U>::value,"U must be an arithmetic type.");
    static_assert((std::is_arithmetic<Ts>::value && ...),"All must be an arithmetic type.");
    
    auto r = a - b; 
    if constexpr (sizeof...(values) > 0) 
    {
        r = sub(r, values...);
    }
    return r;
}

class Custom {
public:
    Custom(std::string b) 
    {
        m_b=b; 
    } 

    // Overload the subtraction operator
    Custom operator-(const Custom& other) const {
        return Custom(this->m_b + " - " + other.m_b);
    }

    // Overload the output operator for convenience
    friend std::ostream& operator<<(std::ostream& os, const Custom& c) {
        return os << c.m_b;
    }

private:
    std::string m_b;
};

}



#endif