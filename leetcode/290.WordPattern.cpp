class Solution {
public:
    vector<string> split(string s)
    {
        vector<string> result;
        auto it = s.find(' ');
        for (; it != string::npos; it = s.find(' ')) {
            result.emplace_back(s.begin(), s.begin()+it);
            s.erase(0, it+1);
        }
        if (!s.empty()) {
            result.emplace_back(s.begin(), s.end());
        }
        return result;
    }

    bool wordPattern(string pattern, string s)
    {
        auto words = split(s);

        unordered_map<string, char> map;
        unordered_map<char, string> map2;

        if (pattern.size() != words.size()) {
            return false;
        }

        for (auto i = 0; i < pattern.size(); ++i) {
            if (auto it = map.find(words[i]); it != map.end()) {
                if (it->second != pattern[i]) {
                    return false;
                }
            } else {
                if (auto it2 = map2.find(pattern[i]); it2 != map2.end()) {
                    if (it2->second != words[i]) {
                        return false;
                    }
                } else {
                    map[words[i]] = pattern[i];
                    map2[pattern[i]] = words[i];
                }
            }
        }

        return true;
    }
};

