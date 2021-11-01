#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        if (!head)
            return nullptr;

        size_t sz = 0;
        for (auto* n = head; n != nullptr; n=n->next)
        {
            ++sz;
        }

        vector<ListNode*> v(sz); int i = 0;
        for (ListNode* n = head; n != nullptr; n=n->next)
        {
            v[i++] = new ListNode(n->val);
        }

        reverse(v.begin(), v.end());
        for (int i = 1; i < sz; ++i)
        {
            v[i-1]->next = v[i];
        }

        return v[0];
    }
};

int main()
{
    return 0;
}
