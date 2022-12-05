#include <vector>

using namespace std;

class Solution {
    public:
        int intersection(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
            if (ax2 < bx1 || bx2 < ax1 || ay1 > by2 || by1 > ay2) {
                return 0;
            }

            int A = ax1 < bx1 ? ax2 - bx1 : bx2 - ax1;
            int B = ay1 < by1 ? ay2 - by1 : by2 - ay1;

            return A*B;
        }

        int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
            int A = (ax2 - ax1) * (ay2 - ay1);
            int B = (bx2 - bx1) * (by2 - by1);
            return A + B - intersection(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);
        }
};

int main()
{
    return 0;
}
