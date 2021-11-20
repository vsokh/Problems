
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> map;
        for (char& ch : s)
            ++map[ch];
        for (char& ch : t)
            --map[ch];
        for (auto& [ch, i] : map)
            if (i != 0)
                return false;
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
