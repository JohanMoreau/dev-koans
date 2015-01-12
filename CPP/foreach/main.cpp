#include <iostream>
#include <vector>
#include <algorithm>
static void transmit_item(int i)
{
    std::cout << i << std::endl;
}
static void transmit_log(std::vector<int> & log)
{
    for (const auto & i : log)
        transmit_item(i);
    std::sort(std::begin(log), std::end(log));
    std::for_each(log.begin(), log.end(), transmit_item);
}
int main()
{
    std::vector<int> log{20,24,37,42,23,45,37};
    transmit_log(log);
}
