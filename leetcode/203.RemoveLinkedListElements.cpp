#include <iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode sant{-1, head};
        ListNode* node = &sant;
        while (node && node->next) {
            while (node->next && node->next->val == val) {
                node->next = node->next->next;
            }
            node = node->next;
        }
        return sant.next;
    }
};

int main()
{
    return 0;
}
