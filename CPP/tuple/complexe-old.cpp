#include <tuple>
#include <iostream>
#include <vector>


template<bool B>
using bool_ = std::integral_constant<bool,B>;

using true_ = bool_<true>;
using false_ = bool_<false>;

namespace detail
{
  template<typename T>  false_  is_vector(T const&) { return false_{}; }  
  
  template<typename T, typename A> 
  true_ is_vector( std::vector<T,A> const&)
  { 
    return true_{} ; 
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
  data_type data_;

  soa() = default;
  soa(std::size_t n) : soa(n, detail::is_vector(data_)) {}
  soa(std::size_t n, true_ const&) : data_(n) {}
  soa(std::size_t n, false_ const&)  {}

  private:

  
  template<typename Data>
  auto size(Data const& d) const// -> decltype(size(d, detail::is_vector(d)))
  {
    return size(d, detail::is_vector(d) );
  }

  template<typename Data>
  auto size(Data const& d, true_ const&) const// -> decltype(d.size())
  {
    return d.size();
  }

  template<typename Data>
  auto size(Data const& d, false_ const&) const 
    // -> decltype(size( std::get<0>(d) ))
  {
    return size( std::get<0>(d) );
  }

  public :

  auto size() const// -> decltype(this->size(this->data_))
  {
    return size(data_);
  }


};


int main()
{
	soa<int> i(9);
	std::cout << i.size() << std::endl;
}



