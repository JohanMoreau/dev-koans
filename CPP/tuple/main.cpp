#include <tuple>
#include <vector>
#include <typeinfo>
#include <iostream>

template<typename T>
struct as_vector
{
	using type = std::vector<T>;
};

template<typename... Ts>
struct as_vector< std::tuple<Ts...> >
{
	using type = std::tuple< typename as_vector<Ts>::type... >;
};

template<typename T>
using as_vector_t = typename as_vector<T>::type;

int main()
{
	as_vector_t<int> x;
	as_vector_t< std::tuple<int,float,void**> > t;
	as_vector_t< std::tuple<int,std::tuple<char,float>,void**> > u;

	std::cout << typeid(x).name() << std::endl;
	std::cout << typeid(t).name() << std::endl;
	std::cout << typeid(u).name() << std::endl;
}
