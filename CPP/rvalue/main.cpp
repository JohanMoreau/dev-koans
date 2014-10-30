#include <iostream>

void foo(int const &) { std::cout << "lvalue\n";}
void foo(int &&) { std::cout << "rvalue\n";}
int bar() {return 1337;}
void chu(int && x) { foo(x); }
void chu1(int && x) { foo( std::forward<int>(x) ); }

//template<typename T> void foo(T&&) {std::cout << "ok\n";}

int main()
{
	int x = 3;
	int & y = x;
	int const& z = bar();
	foo(x); //lvalue
	foo(y); //lvalue
	foo(z); //lvalue
	foo(4); //rvalue 
	foo(bar()); //rvalue
	chu(bar()); //lvalue
	chu1(bar()); //lvalue
}
