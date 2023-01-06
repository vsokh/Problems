#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        auto& t = temperatures;
        vector<int> answer(n);
        for (int i = n-1; i >= 0; --i) {
            m[t[i]] = i;
        }
        return answer;
    }
};

int main()
{
    return 0;
}
