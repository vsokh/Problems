#include <vector>
#include <queue>
#include <iostream>

using namespace std;

template<typename T>
void printQ(T q)
{
    while (!q.empty()) {
        auto e = q.top(); q.pop();
        std::cout << e[0] << " " << e[1] << " " << e[2] << std::endl;
    }
}

template<typename T>
void printQ(T q, int)
{
    std::cout << "Q: ";
    while (!q.empty()) {
        auto e = q.top(); q.pop();
        std::cout << e << " ";
    }
    std::cout << endl;
}

class Solution {
public:

    vector<int> getOrder(vector<vector<int>>& tasks) {
        for (int i = 0; i < tasks.size(); ++i) {
            tasks[i].push_back(i);
        }

        int t = 1;
        auto comparator = [&t](const vector<int>& a, const vector<int>& b)
        {
            if (a[0] <= t && b[0] <= t) {
                return a[1] > b[1];
            }
            return a[0] == b[0] ? a[1] > b[1] : a[0] > b[0];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(comparator)> pq(tasks.begin(), tasks.end(), comparator);

        vector<int> result;
        while (!pq.empty())
        {
            auto task = pq.top();
            t += task[1];
            result.push_back(task[2]);
            pq.pop();
        }

        return result;
    }
};


int main()
{
    vector<int> v{1,3,6,2,0};
    auto cmp = [](auto a, auto b){
        std::cout << a << " " << b << std::endl;
        return a > b;
    };

    std::priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
    for (auto n : v) {
        printQ(pq, 0);
        pq.push(n);
    }
    return 0;
}

