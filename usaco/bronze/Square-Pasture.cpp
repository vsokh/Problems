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

struct Rect {
	ll x1, y1, x2, y2;
};

ll area(Rect r)
{ return (r.x2-r.x1)*(r.y2-r.y1); }

ll intersect(Rect a, Rect b)
{
	ll x_overlap = max((ll)0, min(a.x2, b.x2)-max(a.x1, b.x1));
	ll y_overlap = max((ll)0, min(a.y2, b.y2)-max(a.y1, b.y1));
	return x_overlap*y_overlap;
}

void solve()
{
	Rect a, b;
	cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
	cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
	ll w = max(a.x2, b.x2)-min(a.x1, b.x1);
	ll h = max(a.y2, b.y2)-min(a.y1, b.y1);
	cout << (w > h ? w*w : h*h) << nl;
}

int main()
{
	setIO("square");

	solve();
	return 0;
}
