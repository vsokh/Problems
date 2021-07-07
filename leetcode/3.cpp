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

class Solution
{
	public:
		int lengthOfLongestSubstring(string s)
		{
			int p1 = 0, p2 = 0, L = 0;
			set<int> A;
			while (p2 < s.length())
			{
				if (A.find(s[p2]) == A.end())
				{
					A.insert(s[p2]);
					L = max(L, (int)A.size());
				}
				else
				{
					while (p1 < s.length())
					{
						if (s[p1] == s[p2])
						{
							++p1; break;
						}
						A.erase(s[p1++]);
					}
				}
				++p2;
			}
			return L;
		}
};

int main()
{
	Solution s;
	{
		string str = "abcabcbb";
		cout << s.lengthOfLongestSubstring(str) << endl;
	}
	{
		string str = "bbbbb";
		cout << s.lengthOfLongestSubstring(str) << endl;
	}
	{
		string str = "pwwkew";
		cout << s.lengthOfLongestSubstring(str) << endl;
	}
	{
		string str = "";
		cout << s.lengthOfLongestSubstring(str) << endl;
	}
	{
		string str = "abcdeghijklnn";
		cout << s.lengthOfLongestSubstring(str) << endl;
	}
	return 0;
}
