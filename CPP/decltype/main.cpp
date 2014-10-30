#include <vector>

int main()
{
	std::vector<int> v{1,2,3};
	auto a = v[0]; // copie de v[0] : int
	decltype(v[0]) b = v[0]; // référence de v[0] : int&
	// auto peut être décoré (et pas decltype)
	auto& c = v[0];
	auto const& d = v[0];
	auto* p = &v[0];
}

