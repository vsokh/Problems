
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
	vector<string> split(string s)
	{
		vector<string> r;
		size_t pos = s.find(" ");
		string tmp;
		if (pos != std::string::npos)
		{
			tmp = s.substr(0, pos);
			r.push_back(tmp);
			s.erase(0, pos+1);
		}
		while ((pos = s.find(" ")) != std::string::npos)
		{
			tmp = s.substr(0, pos);
			r.push_back(tmp);
			s.erase(0, pos+1);
		}
		tmp = s.substr(0, s.length());
		r.push_back(tmp);
		return r;
	}

	string reverse(string s)
	{
		size_t i = 0, j = s.size()-1;
		while (i < j)
		{
			std::swap(s[i], s[j]);
			++i; --j;
		}
		return s;
	}

    string reverseWords(string s)
	{
        auto words = split(s); // split
		cout << words.size() << endl;
		string ss;
		for (int i = 0; i < words.size(); ++i)
		{
			cout << words[i] << endl;
			ss += reverse(words[i]) + (i + 1 == words.size() ? "" : " ");
		}
		return ss;
    }
};

int main()
{

	Solution s;
	string ss = "Let's take LeetCode contest";
	auto sss = s.reverseWords(ss);

	return 0;
}
