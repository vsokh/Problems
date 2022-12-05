#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
/* #include <queue> */

using namespace std;

template<typename Q>
void print_queue(std::string_view name, Q q) {
    // NB: q is passed by value because there is no way to traverse
    // priority_queue's content without erasing the queue.
    for (std::cout << name << ": \t"; !q.empty(); q.pop())
        std::cout << q.top() << ' ';
    std::cout << '\n';
}


class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> map;

        for (auto& word : words) {
            ++map[word];
        }

        auto compare = [](auto a, auto b){ return a.second > b.second; };

        std::priority_queue<string, std::vector<string>, decltype(compare)> q(map.begin(), map.end(), compare);


        for(int i = 0;i<k;++i) {
        }
        return {};
    }
};

int main()
{
    Solution s;
    return 0;
}

