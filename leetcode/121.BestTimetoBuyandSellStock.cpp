#include <iostream>
#include <vector>

class Solution
{

public:
    int maxProfit(vector<int>& prices)
    {
		/* {7,2,5,6,1,3} */
		/*
		 * buy at 1
		 * sell at 4
		 * res = 6-1 = 5
		 */
		// sell and buy at 0 => profit = 0
		// sell at 0, buy at 1 => profit -6
		// sell at 0, buy at 2 => profit -2
		// sell at 1, buy at 1 => profit 0
		// sell at 1, buy at 2 => profit 4
		// sell at 1, buy at 2 => profit 4
		//
		// *
		//          *
		//    *
		//              *
		//       *
		//
		//  *
		// // // // // //
		// find the biggest ai - aj > 0

    }

};

int main()
{
	return 0;
}
