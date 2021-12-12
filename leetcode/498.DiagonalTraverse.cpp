#include <vector>
#include <iostream>

class Solution
{

public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat)
    {
        /*
        0 1 2 3
      0 a b c d
      1 e f g h
      2 i j k l
      3 m n o p
        */

        /*
        a(0,0) b(0,1) e(1,0) i(2,0) f(1,1) c(0,2) d(0,3) g(1,2) j(2,1) m(3,0) n(3,1) k(2,2) h(1,3) l(2,3) o(3,2) p(3,3)

        if n,n -> transition to a next column

        r = 3
        0,0 -> r-1 -> 0,0 -> r -> 1 -> 3,3
        i: 0,0,1,2(r-1),1,0,0,1,2,3(r),3,2,1,2,3,3

        c = 3
        0 -> 1, 0,0 -> c -> 0 -> c, c -> 2 -> c
        j: 0,1,0,0,1,2,3,2,1,0,1,2,3,3,2,3
        0 ->


        0,0;
        0,1;
        1,0;
        2,0;
        1,1;
        0,2;
        0,3;
        1,2;
        2,1;
        3,0;
        3,1;
        2,2;
        1,3;
        2,3;
        3,2;
        3,3;
        */
    }
};

int main()
{
    return 0;
}
