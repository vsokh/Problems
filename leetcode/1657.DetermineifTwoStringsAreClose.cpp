#include <iostream>
#include <iterator>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) {
            return false;
        }

        std::unordered_map<int, int> map1;
        for (auto ch : word1) {
            ++map1[ch];
        }

        std::unordered_map<int, int> map2;
        for (auto ch : word2) {
            if (auto it = map1.find(ch); it == map1.end()) {
                return false;
            }
            ++map2[ch];
        }

        std::unordered_map<int, int> map;
        for (auto [_, v] : map1) {
            ++map[v];
        }

        for (auto [_, v] : map2) {
            if (map[v] <= 0) {
                return false;
            }
            --map[v];
        }

        return true;

        // word1 = "cabbbak", word2 = "abbccck"
        // word1: c = 1, a = 2, b = 3, k = 1 => 1 = {c, k}, 2 = {a}, 3 = {b}
        // word2: c = 3, a = 1, b = 2, k = 1 => 1 = {a, k}, 2 = {b}, 3 = {c}
        // c -> a, a -> b, b -> c
        // word1' = abcccbk

    }
};

int main()
{
    Solution s;
    {
    auto res = s.closeStrings("cabbbak", "abbccck");
    std::cout << res << std::endl;
    }
    {
    auto res = s.closeStrings("cabbbak", "abbccck");
    std::cout << res << std::endl;
    }
    return 0;
}

