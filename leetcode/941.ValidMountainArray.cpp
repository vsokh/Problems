#include <vector>
#include <iostream>

using namespace std;

class Solution
{

public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3) {
            return false;
        }

        auto it = max_element(arr.begin(), arr.end());
        if (it == arr.begin() || it+1 == arr.end()) {
            return false;
        }

        for (auto c = arr.begin()+1, p = arr.begin(); c <= it; p = c, ++c) {
            if (*p >= *c) {
                return false;
            }
        }

        for (auto n = it+1, c = it; n < arr.end(); c = n, ++n) {
            if (*n >= *c) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<int> v{1, 4, 4};
    cout << s.validMountainArray(v) << endl;
    return 0;
}
