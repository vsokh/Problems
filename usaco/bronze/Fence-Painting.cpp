#include <bits/stdc++.h>
/* #define e9 1e9 */

/* #define setp(x) fixed<<setprecision(x) */

/* #define ulmx LLONG_MAX */
/* #define lmx LLONG_MAX */
/* #define lmn LLONG_MIN */

/* template<typename T> */
/* struct number_iterator : std::iterator<random_access_iterator_tag, T> { */
/* 	T v; */
/* 	number_iterator(T _v) : v(_v) {} */
/* 	operator T&(){return v;} */
/* 	T operator *() const {return v;} */
/* }; */

/* template<typename T> */
/* struct number_range { */
/* 	T b,e; */
/* 	number_range(T b, T e):b(b),e(e){} */
/* 	number_iterator<T> begin(){return b;} */
/* 	number_iterator<T> end(){return e;} */
/* }; */

/* template<typename T> number_range<T> range(T e) {return number_range<T>(0, e);} */
/* template<typename T> number_range<T> range(T b, T e) {return number_range<T>(b, e);} */

/* template<typename... Args> */
/* auto Func(Args... args) */
/* { */
/*     return (args + ...); */
/* } */

/* void err(istream_iterator<string> it) {} */
/* template<typename T, typename... Args> */
/* void err(istream_iterator<string> it, T a, Args... args) { */
/* 	cerr << *it << " = " << a << endl; */
/* 	err(++it, args...); */
/* } */

/* #define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); } */

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

void solve()
{
	ll a, b, c, d; cin >> a >> b >> c >> d;

	int l1 = b - a;
	int l2 = d - c;
	int i = 0;
	cout << l1 + l2 - i<< nl;
}

int main()
{
	setIO("paint");

	ll t;
	/* cin >> t; */
	/* while (t--) */
	solve();
	return 0;
}
