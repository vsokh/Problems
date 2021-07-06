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
class FrontMiddleBackQueue {
public:
	list<int> L;
    FrontMiddleBackQueue() {}
    void pushFront(int val) {
		L.push_front(val);
	}
    void pushMiddle(int val) {
		auto it = L.begin();
		for(size_t i=0;i<L.size()/2;++i){++it;}
		L.insert(it, val);
    }
    void pushBack(int val) {
		L.push_back(val);
    }
    int popFront() {
		if (L.empty()) return -1;
		int elem = L.front(); L.pop_front();
		return elem;
    }
    int popMiddle() {
		if (L.empty()) return -1;
		auto it = L.begin();
		for(size_t i=0;i<(L.size()-1)/2;++i){++it;}
		int elem = *it; L.erase(it);
		return elem;
    }
    int popBack() {
		if (L.empty()) return -1;
		int elem = L.back(); L.pop_back();
		return elem;
    }
};

int main()
{
	FrontMiddleBackQueue *q = new FrontMiddleBackQueue();
	q->pushFront(1);   // [1]
	q->pushBack(2);    // [1, 2]
	q->pushMiddle(3);  // [1, 3, 2]
	q->pushMiddle(4);  // [1, 4, 3, 2]
	for(auto i:q->L){cout << i;}
	cout << nl;
	q->popFront();     // return 1 -> [4, 3, 2]
	q->popMiddle();    // return 3 -> [4, 2]
	q->popMiddle();    // return 4 -> [2]
	q->popBack();      // return 2 -> []
	cout << q->popFront() << nl;     // return -1 -> [] (The queue is empty)
	/* obj->pushFront(4); obj->pushMiddle(5); obj->pushBack(6); */
	/* cout << obj->popFront() << obj->popMiddle() << obj->popBack() << nl; */
	setIO();
	return 0;
}
