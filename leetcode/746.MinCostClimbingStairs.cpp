#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost, vector<int>& tab, int i)
    {
        if (i >= cost.size()) {
            return 0;
        }

        if (tab[i]) {
            return tab[i];
        }

        tab[i] = min(cost[i] + minCostClimbingStairs(cost, tab, i + 1),
                     cost[i] + minCostClimbingStairs(cost, tab, i + 2));

        return tab[i];
    }

    int minCostClimbingStairs(vector<int>& cost)
    {
        vector<int> tab(cost.size());
        return min(minCostClimbingStairs(cost, tab, 0), minCostClimbingStairs(cost, tab, 1));
    }
};

int main()
{
	Solution s;
	/* vector<int> v = {1,100,1,1,1,100,1,1,100,1}; */
	vector<int> v = {10, 15, 20};
	cout << s.minCostClimbingStairs(v) << endl;
	return 0;
}
