#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{

public:
    string kthDistinct(vector<string>& arr, int k)
    {
        unordered_map<string, int> um;
        for (auto &s : arr)
            ++um[s];
        for (auto &s : arr)
        {
            if (um[s] == 1 && --k==0)
                return s;
        }
        return "";
    }
};

int main()
{
    vector<string> v = {"a","b","a"}; int k = 1;
    Solution s;
    cout << s.kthDistinct(v, k) << endl;
    return 0;
}

