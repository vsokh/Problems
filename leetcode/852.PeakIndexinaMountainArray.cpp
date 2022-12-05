#include <vector>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        /* int target = *max_element(arr.begin(), arr.end()); */
        int l = 0;
        int r = arr.size()-1;
        int m = l + (r - l) / 2;
        int peak = INT_MIN;
        while (l <= r) {
            if (arr[m] > peak) {
                peak = arr[m];
            }

            if (arr[m-1] < peak && peak > arr[m+1]) {
                break;
            }

            if (arr[m-1] > peak) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return m;
    }
};

int main() {
    return 0;
}
