#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode* deleteDuplicates(ListNode* head) {
        auto node = head;
        while (node) {
            auto tmp = node->next;
            while (tmp && node->val == tmp->val) {
                tmp = tmp->next;
            }
            node->next = tmp;
            node = node->next;
        }
        return head;
    }
};

int main()
{
    return 0;
}
