#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

class Solution
{
public:
    void minStoneSum(vector<int>& piles, int i, int k, int maxSum, int& minSum) {
        if (i >= k) {
            minSum = min(minSum, maxSum);
            return ;
        }

        int origPile = piles[i];
        piles[i] = std::ceil(float(piles[i]) / 2.0);

        minStoneSum(piles, i, k - 1, maxSum - origPile - piles[i], minSum);
        minStoneSum(piles, i + 1, k, maxSum - origPile - piles[i], minSum);
    }

    int minStoneSum(vector<int>& piles, int k) {
        sort(piles.begin(), piles.end(), std::greater<int>());

        int minSum = INT_MAX;
        int maxSum = std::accumulate(piles.begin(), piles.end(), 0);
        minStoneSum(piles, 0, k, maxSum, minSum);
        return minSum;
    }
};

int main()
{
    float a = 2;
    float b = 4;
    float f = b/a;
    std::cout << f << " " << std::ceil(f) << std::endl;
    return 0;
}
