#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    void dfs(vector<vector<int>>& rooms, int key, vector<int>& visited) {
        visited[key] = 1;
        for (auto newKey : rooms[key]) {
            if (!visited[newKey] && newKey != key) {
                dfs(rooms, newKey, visited);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> visited(rooms.size());
        dfs(rooms, 0, visited);
        for (auto room : visited) {
            if (!room) {
                return false;
            }
        }
        return true;
    }
};
