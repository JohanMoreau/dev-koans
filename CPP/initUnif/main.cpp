#include <vector>
#include <iostream>

struct employe { int id; int age; float salaire; };

int main()
{
	employe Joe{1, 42, 6000.0f};
	int anArray[]{3, 2, 7};
	std::vector<int> a{1,2,3};
	std::vector<int> b{&anArray[0],&anArray[0]+5};
	std::vector<int> c(5);
	std::vector<int> d{5};
	std::cout << a.size() << std::endl; // 3
	std::cout << b.size() << std::endl; // 5
	std::cout << c.size() << std::endl; // 5
	std::cout << d.size() << std::endl; // 1
	return 0;
}
