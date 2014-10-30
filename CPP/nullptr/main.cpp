#include <iostream>
int main()
{
	int* pi = nullptr;
	float* pf = nullptr;
	if (!pi) std::cout << "pi est nul." << std::endl;
	if (pf == nullptr) std::cout << "pf est nul." << std::endl;
	return 0;
}
