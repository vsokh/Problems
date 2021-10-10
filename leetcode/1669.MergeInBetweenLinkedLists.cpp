
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
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
		ListNode *l2tail = nullptr;
		for(ListNode *n=list2;n!=nullptr;n=n->next){
			l2tail = n;
		}
		int i=-1;
		for(ListNode *n=list1;n!=nullptr;n=n->next){
			if (++i == b)
				l2tail->next = n->next;
		}
		i=0;
		for(ListNode *n=list1;n!=nullptr;n=n->next){
			if (++i == a)
				n->next = list2;
		}
		return list1;
    }
};

int main()
{
	setIO();
	return 0;
}
