#include <iostream>

int main()
{
	enum class Color : char { RED, BLUE };
	enum class Fruit { BANANA, APPLE };
	Color a = Color::RED;
	Fruit b = Fruit::BANANA;
/*
	if (a == b) // Fonctionne en C++03 mais pas en C++11 avec un enum classique
		std::cout << "a et b sont egaux" << std::endl;
	else
		std::cout << "a et b ne sont pas egaux" << std::endl;
*/
	std::cout << sizeof(a) << std::endl; // 1
	std::cout << sizeof(b) << std::endl; // sizeof int - 4

	return 0;
}
