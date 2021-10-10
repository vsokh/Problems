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
    bool check(string s1, string s2, string s3) {
		for (int i=0;i<s1.length();++i){
			for (int j=0;j<s3.length();++j){
				if(s1[i]==s3[j]){
					s1[i]=j; s3[j]=0;
				}
			}
		}
		for (int i=0;i<s2.length();++i){
			for (int j=0;j<s3.length();++j){
				if(s2[i]==s3[j]){
					s2[i]=j; s3[j]=0;
				}
			}
		}
		/* for (int i=0;i<s2.length();++i) */
		/* 	cout << s2[i]+'a'-97 << nl; */
		for (int i=1;i<s1.length();++i)
			if(s1[i]<s1[i-1])return false;
		for (int i=1;i<s2.length();++i)
			if(s2[i]<s2[i-1])return false;
		return true;
	}
    bool isInterleave(string s1, string s2, string s3) {
		bool ok=check(s1,s2,s3);
		if(!ok)ok=check(s2,s1,s3);
		return ok;
    }
};

int main()
{
	Solution s;
	cout << s.isInterleave("aabcc", "dbbca", "aadbbcbcac") << nl;
	/* cout << s.isInterleave("aabcc", "dbbca", "aadbbbaccc") << nl; */
	return 0;
}
