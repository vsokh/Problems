
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

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
	public:
		Node* cloneGraph(Node* node) {
			Node *G = new Node(node.val, node.neighbors);
			queue<Node*> q; q.push(G);
			vector<Node*> adj;
			vector<int> visited(101);
			while (!q.empty()) {
				auto n = q.front(); q.pop();
				for (auto shallowNeighbor : n.neighbors) {
					auto deepNeighbor = new Node(shallowNeighbor.val, shallowNeighbor.neighbors);
					adj.push_back(deepNeighbor);
					if (!visited[deepNeighbor.val])
						q.push(deepNeighbor);
				}
				visited[n.val]=1;
				n.neighbors = adj; adj.clear();
			}
			return G;
		}
};

int main() {
	return 0;
}
