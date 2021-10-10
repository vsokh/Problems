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

class Solution {
public:
	auto toAdj(int n, vector<vi>& edges)
	{
		vector<vi> result(n);
		for (auto e : edges)
		{
			result[e[0]].push_back(e[1]);
			result[e[1]].push_back(e[0]);
		}
		return result;
	}

	void strongconnect(int v,
			vector<vi> const& adj,
			vi& visited,
			vi& stack,
			vi& inStack,
			int& count)
	{
	}

    int countComponents(int n, vector<vector<int>>& edges)
	{
		auto adj = toAdj(n, edges);
		vi visited(n), index(n), lowlink(n), stack(n), inStack(n);
		int count = 0, idx = 0;
		for (int u = 0; u < n; ++u)
		{
			if (!visisted[u])
				strongconnect(u, adj, visited, stack, inStack, count);
		}
		return count;
    }
};

int main()
{
	int n = 5;
	vector<vi> v{{0,1},{1,2},{3,4}};
	/* vector<vi> v{{0,1},{1,2},{2,3},{3,4}}; */
	Solution s; cout << s.countComponents(n, v) << endl;
	return 0;
}
