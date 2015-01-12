#include <iostream>
#include <vector>
static void transmit_item(int i)
{
    std::cout << i << std::endl;
}
static void transmit_log(const std::vector<int> & log)
{
    for (std::vector<int>::const_iterator it = log.cbegin();
         it != log.cend(); ++it)
        transmit_item(*it);
}
int main()
{
    std::vector<int> log{20,24,37,42,23,45,37};
    transmit_log(log);
}
