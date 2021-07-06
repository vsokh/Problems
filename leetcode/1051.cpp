
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
	using KeyGen = function<int(vector<int> const& A, int i)>;

	void printV(vector<int> const& v) {
		for (auto i : v)
			cout << i <<" ";
		cout << endl;
	}

    vector<int> countingSort(vector<int> const& A, int k, KeyGen key) {
		vector<vector<int>> L(k+1);
		for (int i = 0; i < A.size(); ++i)
			L[key(A, i)].push_back(A[i]);

		vector<int> result;
		for (auto vec : L)
			for (auto i : vec)
				result.push_back(i);
		return result;
    }

	int mylog(int a, int b) {
		return log(a) / log(b);
	}

	KeyGen keyGen(int m, int n) {
		return [m,n](vector<int> const& A, int i) {
			return (A[i]%m)/n;
		};
	}

	vector<int> radixSort(vector<int> const& A) {
		int r = 10;
		int k = *max_element(A.begin(), A.end());
		int d = mylog(k, r)+1;
		int m = r, n = 1;

		vector<int> B = A;
		for (int i = 0; i < d; ++i) {
			B = countingSort(B, r, keyGen(m, n));
			printV(B);
			m *= r; n *= r;
		}
		return B;
	}

    int heightChecker(vector<int>& heights) {
		vector<int> expected = radixSort(heights);

		int result = 0;
		for (int i = 0; i < expected.size(); ++i)
			result += expected[i] != heights[i];
		return result;
    }
};

int main() {
	Solution s;
	vector<int> v{1,1,4,2,1,3};
	cout << s.heightChecker(v) << endl;
	return 0;
}
