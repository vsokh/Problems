
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
	void countingSort(vector<int> &A) {
		vector<int> B(A.size());
		int k = *max_element(A.begin(), A.end());
		vector<int> C(k);
		for (int i=1;i<A.size();++i)
			C[A[i]]=C[A[i]]+1;
		for (int i=1;i<k;++i)
			C[i]=C[i]+C[i-1];
		for (int j=A.size(); 0<j;--j) {
			B[C[A[j]]] = A[j];
			C[A[j]] = C[A[j]]-1;
		}
		A = B;
	}
    int longestConsecutive(vector<int>& A) {
		/* for (int &t : A) t += 1e9; */
		countingSort(A);
		/* for (int &t : A) t = t>1e9?t-1e9:t; */
		for (int i = 0; i<A.size(); ++i)
			cout << (A[i]>1e9?A[i]-1e9:A[i]) << " ";
		cout << nl;
		int c, r; c = r = 1;
		for (int i = 1; i<A.size(); ++i){
			c = A[i-1] == A[i]-1 ? c+1 : 1;
			r = max(c,r);
		}
		return r;
    }
};

int main()
{
	Solution s;
	vector<int> v = {0,3,7,2,5,8,4,6,0,1};
	cout << s.longestConsecutive(v) << nl;
	return 0;
}
