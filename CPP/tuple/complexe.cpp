#include <tuple>
#include <iostream>
#include <vector>


template<bool B>
using bool_ = std::integral_constant<bool,B>;

template<int N>
using int_ = std::integral_constant<std::size_t,N>;

using true_ = bool_<true>;
using false_ = bool_<false>;

namespace detail
{
  template<typename T>  false_  is_vector(T const&) { return false_{}; }  
  
  template<typename T, typename A> 
  true_ is_vector( std::vector<T,A> const&)
  { 
    return true_{}; 
  }
}

template<typename T> 
using is_vector_t = decltype( detail::is_vector(std::declval<T>()) );

template<typename T> struct as_vector
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

template<typename T> struct soa
{
  using data_type = as_vector_t<T>;

  soa(std::size_t n) : soa(n, detail::is_vector(data_)) {}

  soa(std::size_t n, true_ const&) : data_(n) {}
  soa(std::size_t n, false_ const&)  {
    resize(n);
  }

  auto size() const  
  {
    return size(data_);
  }

  void resize(std::size_t n)
  {
    resize(n, data_);
  }

  private:

  template<typename Type, typename Alloc>
  void resize(std::size_t n,  std::vector<Type,Alloc>& d)
  {
    d.resize(n);
  }

  template<typename... Types>
  void resize(std::size_t n,  std::tuple<Types...>& d)
  {
    resize(n,d,int_<0>{}, typename std::tuple_size< std::tuple<Types...> >::type{} );
  }

  template<typename Tuple, std::size_t I, std::size_t N>
  void resize(std::size_t n, Tuple& d, int_<I> const&, int_<N> const& sz)
  {
    resize(n,std::get<I>(d));
    resize(n,d,int_<I+1>{}, sz);
  }

  template<typename Tuple, std::size_t N>
  void resize(std::size_t, Tuple&, int_<N> const&, int_<N> const&)
  {
  }


  template<typename Data>
  auto size(Data const& d) const 
  {
    return size(d, detail::is_vector(d) );
  }

  template<typename Data>
  auto size(Data const& d, true_ const&) const
  {
    return d.size();
  }

  template<typename Data>
  auto size(Data const& d, false_ const&) const 
  {
    return size( std::get<0>(d) );
  }

  data_type data_;
};


using particle = std::tuple<float,int,float>;

int main()
{
	soa<int> i(9);
	soa<particle> p(9);
	std::cout << i.size() << std::endl;
	std::cout << p.size() << std::endl;
}
