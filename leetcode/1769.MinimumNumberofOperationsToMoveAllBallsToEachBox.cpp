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
    vector<int> minOperations(string boxes) {
		vector<int> ans(boxes.length());
		for(int i=0;i<ans.size();++i) {
			int moves=0;
			for(int j=0;j<ans.size();++j) {
				if (boxes[j] == '1') moves+=abs(i-j);
			}
			ans[i]=moves;
		}
		return ans;
    }
};

int main()
{
	setIO();
	Solution s;
	vector<int> v = s.minOperations("001011");
	for (int const &t:v) cout << t << " ";
	cout << endl;
	return 0;
}
