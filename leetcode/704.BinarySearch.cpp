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
	int search(vector<int>& nums, int start, int end, int target)
	{
		int mid = (start + end) / 2;
		if (nums[mid] == target)
			return mid;
		if (mid == start || mid == end)
			return -1;
		return nums[mid] < target
			? search(nums, mid, end, target)
			: search(nums, start, mid, target);
	}

    int search(vector<int>& nums, int target)
	{ return search(nums, 0, nums.size(), target); }
};

int main()
{
	Solution s;
	vi v1{-1,0,3,5,9,12};
	std::cout << s.search(v1, 9) << std::endl;

	vi v2{1,2,3,4};
	std::cout << s.search(v2, 5) << std::endl;

	vi v3{-1,0,3,5,9,12};
	std::cout << s.search(v3, 12) << std::endl;

	vi v4{1};
	std::cout << s.search(v4, 1) << std::endl;

	vi v5{1,2,3,4};
	std::cout << s.search(v5, 0) << std::endl;
	return 0;
}
