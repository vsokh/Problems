#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countCost(vector<int>& cost, unordered_map<int,int> m, int i, int total)
    {
        if (i >= cost.size())
            return total;
        if (auto it = m.find(i);
                 it != m.end()) {
             if (it->second > total) {
                m[i] = total;
            }
        }
        else {
            m[i] = total;
        }
        return min(countCost(cost, m, i + 1, total+cost[i]),
                   countCost(cost, m, i + 2, total+cost[i]));
    }

    int minCostClimbingStairs(vector<int>& cost)
    {
        unordered_map<int, int> m;
        m[0] = cost[0]; m[1] = cost[1];
        return min(countCost(cost, m, 0, cost[0]),
                   countCost(cost, m, 1, cost[1]));
    }
};

int main()
{
	Solution s;
	vector<int> v = {1,100,1,1,1,100,1,1,100,1};
	cout << s.minCostClimbingStairs(v) << endl;
	return 0;
}
