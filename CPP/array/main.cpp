#include <array>

std::array<int, 5> f (std::array<int, 5> const & arr )
{
std::array<int, 5> that{arr};
for (int i=0; i<that.size(); i++)
that[i] += i;
return that;
}

int main()
{
	// NE MARCHE PAS POUR LE MOMENT
	return 0;
}
