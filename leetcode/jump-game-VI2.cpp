#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
#define nl "\n"

#define ull unsigned long long
#define ll long long

#define f first
#define s second
#define mp make_pair
#define pb push_back

#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

#define vl vector<ll>
#define sl set<ll>
#define pl pair<ll, ll>

void setIO(string name = "")
{
	cin.tie(0)->sync_with_stdio(0);
	if (name.size()) {
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

class Solution {
public:
	template<class T>
	void printQ(T pq) {
		while (!pq->empty()) {
			auto p = pq->top(); pq->pop();
			cout << "(" << p.first << ", " << p.second << ")"<< nl;
		}
	}

    int maxResult(vector<int>& nums, int k) {
		return 0;
    }
};

int main()
{
	Solution s;
	{
		vector<int> v {1,-1,-2,4,-7,3}; int k = 2;
		cout << s.maxResult(v, k) << nl;
	}
	{
		vector<int> v {10,-5,-2,4,0,3}; int k = 3;
		cout << s.maxResult(v, k) << nl;
	}
	{
		vector<int> v {1,-5,-20,4,-1,3,-6,-3}; int k = 2;
		cout << s.maxResult(v, k) << nl;
	}
	return 0;
}
