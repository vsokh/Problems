
#include <bits/stdc++.h>

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        size_t n = 0;
        for (auto* node = head; node != nullptr; node = node->next)
        {
            ++n;
        }

        size_t m = n/2;
        auto ret = head;
        while (m--)
        {
            ret = ret->next;
        }
        return ret;
    }
};

int main()
{
	return 0;
}
