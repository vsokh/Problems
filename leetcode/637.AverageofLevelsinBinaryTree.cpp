#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution
{
public:
    struct LevelInfo {
        int sum{0};
        int amount{0};
    };

    using TreeLevels = std::vector<LevelInfo>;

    void exploreTreeLevels(TreeNode* node, int level, TreeLevels& levelsInfo)
    {
        if (!node)
            return;

        if (level >= levelsInfo.size()) {
            levelsInfo.emplace_back(node->val, 1);
        } else {
            auto& levelInfo = levelsInfo[level];
            levelInfo.sum += node->val;
            ++levelInfo.amount;
        }

        exploreTreeLevels(node->left, level+1, levelsInfo);
        exploreTreeLevels(node->right, level+1, levelsInfo);
    }

    vector<double> averageOfLevels(TreeNode* root) {
        TreeLevels levelsInfo;
        exploreTreeLevels(root, 0, levelsInfo);

        vector<double> result;
        for_each(levelsInfo.begin(), levelsInfo.end(), [&result](auto levelInfo)
        {
            result.push_back(levelInfo.sum / levelInfo.amount);
        });

        return result;
    }
};

int main()
{
    return 0;
}
