#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isPalindrom(string& s, int i, int j){
        cout << i <<":"<< j <<"=" << string(s.begin()+i, s.begin()+j) << endl;
        while(i<=j){
            if(s[i]!=s[j-1])
                return false;
            ++i;--j;
        }
        return true;
    }
    void countSubstrings(string& s, vector<vector<int>>& v, int i, int j, int& cnt){
        int n=s.size();
        if(j>n){
            return;
        }
        if(!v[i][j]&&isPalindrom(s,i,j)){
            v[i][j]=1;
            ++cnt;
        }
        countSubstrings(s,v,i,j+1,cnt);
        countSubstrings(s,v,i+1,j+1,cnt);
    }
    int countSubstrings(string s) {
        vector<vector<int>> v(s.size()+1, vector<int>(s.size()+1));
        cout << s << endl;
        int cnt=0;
        countSubstrings(s,v,0,1,cnt);
        return cnt;
    }
};

int main() {
	Solution s;
    cout << s.countSubstrings("xkjkqlajprjwefilxgpdpebieswu") << endl;
	return 0;
}
