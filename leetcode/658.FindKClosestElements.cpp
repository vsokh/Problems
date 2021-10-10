#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
#define nl "\n"

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define pf push_front

#define vi vector<int>
#define li list<int>
#define si set<int>
#define pi pair<int>

#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
#define nl "\n"

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define pf push_front

#define vi vector<int>
#define li list<int>
#define si set<int>
#define pi pair<int>

/* class Solution { */
/* 	public: */
/* 		vi findClosestElements(vi& arr, int k, int x) { */
/* 			vi B; li L; */
/* 			auto LB = lower_bound(all(arr), x); */
/* 			if (LB == arr.end()) */
/* 			{ */
/* 				auto it = arr.rbegin(); */
/* 				for (int i = 0; i<k; ++i) */
/* 				{ L.pf(*it++); } */
/* 			} */
/* 			else */
/* 			{ */
/* 				int p1 = LB-arr.begin(); */
/* 				int p2 = LB-arr.begin(); */
/* 				L.pb(*LB); p1--; p2++; */
/* 				for (int i = 0; i<k-1; ++i) */
/* 				{ */
/* 					if (p2 >= arr.size()) { L.pf(arr[p1--]); continue; } */
/* 					if (p1  < 0)          { L.pb(arr[p2++]); continue; } */

/* 					if (abs(arr[p1]-x)  < abs(arr[p2]-x) || */
/* 					   (abs(arr[p1]-x) == abs(arr[p2]-x) && arr[p1] < arr[p2])) */
/* 						L.pf(arr[p1--]); */
/* 					else */
/* 						L.pb(arr[p2++]); */
/* 				} */
/* 			} */
/* 			for (int i : L) */
/* 			{ B.push_back(i); } */
/* 			return B; */
/* 		} */
/* }; */

class Solution {
	public:
		vector<int> findClosestElements(vector<int>& arr, int k, int x) {
			vector<int> B; list<int> L;
			auto LB = lower_bound(arr.begin(), arr.end(), x);
			if (LB == arr.end())
			{
				auto it = arr.rbegin();
				for (int i = 0; i<k; ++i)
				{ L.push_front(*it++); }
			}
			else
			{
				int p1 = LB-arr.begin()-1;
				int p2 = p1+1;
				for (int i = 0; i<k; ++i)
				{
					if (p2 >= arr.size()) { L.push_front(arr[p1--]); continue; }
					if (p1  < 0)          { L.push_back(arr[p2++]);  continue; }

					if (abs(arr[p1]-x)  < abs(arr[p2]-x) ||
					   (abs(arr[p1]-x) == abs(arr[p2]-x) && arr[p1] < arr[p2]))
						L.push_front(arr[p1--]);
					else
						L.push_back(arr[p2++]);
				}
			}
			for (int i : L)
			{ B.push_back(i); }
			return B;
		}
};

int main()
{
	Solution s;
	vi arr = {-70, 1, 4, 5, 10};
	/* vi arr = {1, 2, 3, 4, 5}; */
	/* vi arr = {1}; */
	/* vi arr = {0,0,1,2,3,3,4,7,7,8}; */
	int k = 4, x = 15;
	vi v = s.findClosestElements(arr, k, x);

	for (int i : v)
	{ cout << i << " "; }
	cout << endl;

	return 0;
}
