#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

class Solution
{
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int i = 0;
        int j = 0;
        int lastD = abs(arr[i]-x);
        for (;i < arr.size(); ++i) {
            int d = abs(arr[i]-x);
            if (lastD > d) {
                lastD = d;
                j = i;
            }
        }

        vector<int> result;
        int l = j;
        int r = j+1;
        while (k--) {
            if (l < 0 && r >= arr.size()) {
                break;
            }

            if (l < 0) {
                result.push_back(arr[r]);
                ++r;
                continue;
            }

            if (r >= arr.size()) {
                result.push_back(arr[l]);
                --l;
                continue;
            }

            if (abs(arr[l]-x) == abs(arr[r]-x)) {
                if (arr[l] < arr[r]) {
                    result.push_back(arr[l]);
                    --l;
                } else {
                    result.push_back(arr[r]);
                    ++r;
                }
            } else if (abs(arr[l]-x) < abs(arr[r]-x)) {
                result.push_back(arr[l]);
                --l;
            } else {
                result.push_back(arr[r]);
                ++r;
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};

int main()
{
	Solution s;
	vector<int> arr = {-70, 1, 4, 5, 10};
	/* vector<int> arr = {1, 2, 4, 6, 8}; */
	/* vector<int> arr = {1}; */
	/* vector<int> arr = {0,0,1,2,3,3,4,7,7,8}; */
	int k = 4, x = -68;
	auto v = s.findClosestElements(arr, k, x);

	for (int i : v)
	{ cout << i << " "; }
	cout << endl;

	return 0;
}
