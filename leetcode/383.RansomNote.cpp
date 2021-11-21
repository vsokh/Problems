#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> map;
        for (char& ch : magazine)
            ++map[ch];
        for (char& ch : ransomNote)
            if (map[ch]-- < 1)
                return false;
        return true;
    }
};

int main() {
	Solution s;
	{
        string s1, s2;
        s1 = "a"; s2 = "b";
        cout << s.canConstruct(s1, s2) << endl;
	}
	{
        string s1, s2;
        s1 = "aa"; s2 = "ab";
        cout << s.canConstruct(s1, s2) << endl;
	}
	{
        string s1, s2;
        s1 = "aa"; s2 = "aab";
        cout << s.canConstruct(s1, s2) << endl;
	}
	return 0;
}
