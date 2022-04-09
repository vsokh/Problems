
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<int, int> map;
        for (auto ch : s) {
            ++map[ch];
        }

        for (auto ch : t) {
            if (map[ch]-- < 1) {
                return false;
            }
        }
        return true;
    }
};

int main() {
	Solution ss;
	{
        string s, t; s = "anagram"; t = "nagaram";
        cout << ss.isAnagram(s, t) << endl;
	}
	{
        string s, t; s = "rat"; t = "car";
        cout << ss.isAnagram(s, t) << endl;
	}
	return 0;
}
