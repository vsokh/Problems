
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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = 0;
        for (auto nd = head; nd != nullptr; nd=nd->next)
        {
            ++sz;
        }

        int k = sz-n;

        auto nd = head;
        while (nd->next != nullptr && --k)
        {
            nd = nd->next;
        }
        if (sz-n == 0)
        {
            head = head->next;
        }
        else
        {
            nd->next = nd->next ? nd->next->next : nullptr;
        }

        return head;
    }
};

int main()
{
	return 0;
}
