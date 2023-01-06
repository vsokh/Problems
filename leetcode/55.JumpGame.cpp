#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    template<typename T>
    void printQueue(T q)
    {
        while (!q.empty()) {
            auto e = q.front(); q.pop();
            std::cout << e << " ";
        }
        std::cout << std::endl;
    }

    template<typename T>
    void printVisited(const T& vec)
    {
        for (int i = 0; i < vec.size(); ++i) {
            std::cout << vec[i] << " ";
        }
        std::cout << std::endl;
    }

    bool canJump(vector<int>& nums) {
        int goalIdx = nums.size()-1;

        vector<int> visited(nums.size());
        queue<int> q; q.push(0);

        while (!q.empty()) {
            auto currIdx = q.front(); q.pop();

            std::cout << currIdx << "; q: "; printQueue(q); printVisited(visited);

            if (currIdx >= goalIdx) { return true; }
            if (visited[currIdx])   { continue; }

            visited[currIdx] = 1;
            auto len = nums[currIdx];
            while (len--) {
                auto newIdx = currIdx + len;

                if (newIdx >= goalIdx) { return true; }
                if (visited[newIdx])   { continue; }

                q.push(newIdx);
            }
        }
        return false;
    }
};


int main()
{
    return 0;
}
