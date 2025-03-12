#include<iostream>
using namespace std;
template <size_t N,size_t D>
struct is_divide{
    constexpr static bool val =(N%D==0);
};
template <size_t N ,size_t D>
struct check_prime{
   constexpr static bool val=!is_divide<N,D>::val && check_prime<N,D-1>::val;
};
template <size_t N>
struct check_prime<N,1> {
   constexpr static bool val=true;
};
template<size_t N>
struct is_prime{
    constexpr static bool val = check_prime<N, N/2>::val ;
};
template<>
struct is_prime<0>{
    constexpr static bool val = false;
};
template <>
struct is_prime<1> {
    constexpr static bool val = false;
};
template <>
struct is_prime<2> {
    constexpr static bool val = true;
};
template <>
struct is_prime<3> {
    constexpr static bool val = true;
};
int main(){
   cout<<is_prime<6>::val;
}