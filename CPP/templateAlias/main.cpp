#include <array>
#include <iostream>

template<typename T>
using point3D = std::array<T,3>;

int main()
{
	point3D<int> x{1,2,3};
	std::cout << x.size() << std::endl;
}
