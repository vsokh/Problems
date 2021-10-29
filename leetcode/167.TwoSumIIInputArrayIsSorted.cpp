#include <iostream>

#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{

public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> um;
        for (int i = 0; i < numbers.size(); ++i)
        {
            if (um[numbers[i]] && target == numbers[um[numbers[i]]] + numbers[i])
            {
                return {um[numbers[i]], i+1};
            }

            um[numbers[i]]=i+1;
        }

        vector<int> result;
        for (auto& i : numbers)
        {
            if (um[target-i])
            {
                result = {um[i], um[target-i]};
                break;
            }
        }

        return result;
    }
};

int main()
{
    {

        vector<int> v = {2, 7, 11, 15}; int target = 9;
        Solution s;
        v = s.twoSum(v, target);
        for (auto& i: v)
            cout << i << " ";
        cout << endl;
    }
    {
        vector<int> v = {2,3,4}; int target = 6;
        Solution s;
        v = s.twoSum(v, target);
        for (auto& i: v)
            cout << i << " ";
        cout << endl;
    }
    {
        vector<int> v = {-1,0}; int target = -1;
        Solution s;
        v = s.twoSum(v, target);
        for (auto& i: v)
            cout << i << " ";
        cout << endl;
    }
    {
        vector<int> v = {0,0,1}; int target = 0;
        Solution s;
        v = s.twoSum(v, target);
        for (auto& i: v)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
