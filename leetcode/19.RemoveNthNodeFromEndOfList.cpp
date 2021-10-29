#include <iostream>

using namespace std;

struct ListNode
{
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{

public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        size_t nodes = 0;
        for (auto n = head; n != nullptr; n=n->next)
        { ++nodes; }

        size_t idx = nodes-n;
        ListNode *target = head;
        ListNode *prev = nullptr;
        for (size_t i = 0; i < idx; ++i)
        {
            prev = target;
            target = target->next;
        }

        if (prev == nullptr)
            return target->next;

        prev->next = target->next;
        return head;
    }
};

int main()
{
	return 0;
}
