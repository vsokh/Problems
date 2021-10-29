
#include <bits/stdc++.h>

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

class Solution
{
public:
    ListNode* middleNode(ListNode* head)
    {
        std::size_t nodes = 0;
        for (auto node = head; node != nullptr; node = node->next)
            ++nodes;

        std::size_t midNum = nodes/2;
        ListNode *midNode = head;
        for (std::size_t i = 0; i < midNum; ++i)
            midNode = midNode->next;
        return midNode;
    }
};

int main()
{
	return 0;
}
