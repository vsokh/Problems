
#include <bits/stdc++.h>

using namespace std;

template<typename T>
struct number_iterator : std::iterator<random_access_iterator_tag, T> {
	T v;
	number_iterator(T _v) : v(_v) {}
	operator T&(){return v;}
	T operator *() const {return v;}
};

template<typename T>
struct number_range {
	T b,e;
	number_range(T b, T e):b(b),e(e){}
	number_iterator<T> begin(){return b;}
	number_iterator<T> end(){return e;}
};

template<typename T> number_range<T> range(T e) {return number_range<T>(0, e);}
template<typename T> number_range<T> range(T b, T e) {return number_range<T>(b, e);}

	template<typename... Args>
auto Func(Args... args)
{
	return (args + ...);
}

void err(istream_iterator<string> it) {}

template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

#define e9 1e9
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
#define pi pair<int, int>

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
    vector<int> sortedSquares(vector<int>& nums) {
		for (auto& i : nums)
		{
			i *=i;
		}

		int smallest = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			smallest = nums[smallest] > nums[i] ? i : smallest;
		}

		vector<int> B; B.push_back(nums[smallest]);
		int l = smallest-1, r = smallest+1;
		while (l >= 0 && r < nums.size())
		{
			if (nums[l] <= nums[r])
			{
				B.push_back(nums[l]);
				--l;
			}
			else
			{
				B.push_back(nums[r]);
				++r;
			}
		}
		while (l >= 0)
		{
			B.push_back(nums[l]);
			--l;
		}
		while (r < nums.size())
		{
			B.push_back(nums[r]);
			++r;
		}
        return B;
    }
};

int main()
{
	Solution s;
	{
		vector<int> in = {-4, -1, 0, 3, 10};
		const auto& ot = s.sortedSquares(in);
		for (auto& i : ot)
		{
			cout << i << " ";
		}
		cout << "\n";
	}

	{
		vector<int> in = {1, 2, 3, 4, 5};
		const auto& ot = s.sortedSquares(in);
		for (auto& i : ot)
		{
			cout << i << " ";
		}
		cout << "\n";
	}

	{
		vector<int> in = {-4, -3, -2, -1, 0};
		const auto& ot = s.sortedSquares(in);
		for (auto& i : ot)
		{
			cout << i << " ";
		}
		cout << "\n";
	}
	{
		vector<int> in = {0};
		const auto& ot = s.sortedSquares(in);
		for (auto& i : ot)
		{
			cout << i << " ";
		}
		cout << "\n";
	}

	return 0;
}