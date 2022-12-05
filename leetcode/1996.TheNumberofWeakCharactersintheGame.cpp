#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties)
    {
        std::sort(properties.begin(), properties.end(), [](vector<int>& a, vector<int>& b) {
                return a[0] < b[0] && a[1] < b[1];
                });
        for (auto v : properties) {
            cout << "["<<v[0]<<","<<v[1]<<"]\n";
        }
    }
};

int main() {
    return 0;
}
