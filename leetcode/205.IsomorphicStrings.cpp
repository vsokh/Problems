
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        std::unordered_map<char, char> map;
        for(auto i=0;i<s.size();++i){
            if (auto it = map.find(s[i]); it == map.end()) {
                map[s[i]]=t[i];
            } else {
                if (it->second != t[i])
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    return 0;
}

