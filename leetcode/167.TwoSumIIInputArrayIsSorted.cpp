#include <iostream>

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int binSearch(vector<int>& numbers, int target, int idx)
    {
        int l = 0;
        int r = numbers.size();
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (numbers[mid] == target && mid != idx)
                return mid;
            if (numbers[mid] < target)
                l = mid + 1;
            else
                r = mid;
        }
        return -1;
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        for (int i = 0; i < numbers.size(); ++i)
        {
            int j = binSearch(numbers, target-numbers[i], i);
            if (j != -1) {
                if (i > j) swap(i, j);
                result = {i+1, j+1};
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
