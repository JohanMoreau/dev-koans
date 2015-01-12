# include <string>
namespace exemple {
template <typename T>
T max(T a, T b)
{
    return a < b ? b : a;
}
}
int main()
{
    int i = exemple::max(3, 5);
    char c = exemple::max('e', 'b');
    std::string s = exemple::max(std::string("hello"), std::string("world"));
    float f = exemple::max<float>(1, 2.2f);
    return 0;
}
