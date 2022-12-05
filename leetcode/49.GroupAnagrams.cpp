#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;

        for (auto& str : strs) {
            auto key = str;
            sort(key.begin(), key.end());
            map[key].push_back(str);
        }

        vector<vector<string>> result;

        for (auto [_, sortedStrs]& : map) {
            vector<string> tmp;
            for (auto& str : sortedStrs) {
                tmp.push_back(str);
            }
            result.push_back(std::move(tmp));
        }

        return result;
    }
};

int main()
{
    return 0;
}
