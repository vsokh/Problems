#include <vector>

using namespace std;

// [[100],[80],[60],[70],[60],[75],[85]]
class StockSpanner
{
public:
    StockSpanner() = default;

    int next(int price) {
        auto it = std::upper_bound(_prices.rbegin(), _prices.rend(), price);
        if (it != _prices.rend()) {
            std::cout << price << ":" << *it << std::endl;
        }
        auto cnt = std::distance(it, _prices.rbegin());
        _prices.push_back(price);
        return cnt;
    }

private:
    std::vector<int> _prices{};
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

int main()
{
    return 0;
}

