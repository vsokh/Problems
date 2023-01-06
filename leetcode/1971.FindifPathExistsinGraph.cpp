#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adjTab(n);

        for (auto edge : edges) {
            auto u = edge[0];
            auto v = edge[1];
            adjTab[u].push_back(v);
            adjTab[v].push_back(u);
        }

        vector<int> visited(n);
        queue<int> q; q.push(source);
        while (!q.empty()) {
             auto v = q.front(); q.pop();
             if (v == destination) {
                 return true;
             }
             if (visited[v]) {
                 continue;
             }
             visited[v] = 1;
             for (auto u : adjTab[v]) {
                 q.push(u);
             }
        }
        return false;
    }
};

int main()
{
    return 0;
}
