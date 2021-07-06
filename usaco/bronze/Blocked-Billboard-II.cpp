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
	ll x1,y1,x2,y2;
};

bool covered(ll x, ll y, ll x1, ll y1, ll x2, ll y2)
{ return x >= x1 && x <= x2 && y >= y1 && y <= y2; }

void solve()
{
	Rect a, b;
	cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
	cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;

	ll cc = 0;
	if (covered(a.x1, a.y1, b.x1, b.y1, b.x2, b.y2)) cc++;
	if (covered(a.x1, a.y2, b.x1, b.y1, b.x2, b.y2)) cc++;
	if (covered(a.x2, a.y1, b.x1, b.y1, b.x2, b.y2)) cc++;
	if (covered(a.x2, a.y2, b.x1, b.y1, b.x2, b.y2)) cc++;

	if (cc < 2) {
		cout << (a.x2-a.x1)*(a.y2-a.y1) << nl;
	}
	else if (cc == 4) {
		cout << 0 << nl;
	}
	else {
		ll xL = max(a.x1, b.x1); ll xR = min(a.x2, b.x2);
		ll yL = max(a.y1, b.y1); ll yR = min(a.y2, b.y2);
		cout << (a.x2-a.x1)*(a.y2-a.y1) - (xR-xL)*(yR-yL) << nl;
	}
}

int main()
{
	setIO("billboard");

	/* ll t; */
	/* cin >> t; */
	/* while (t--) */
	solve();
	return 0;
}
