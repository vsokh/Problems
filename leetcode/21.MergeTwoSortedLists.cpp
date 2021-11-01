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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if (!l1 && !l2) return nullptr;
        if (!l1) return l2;
        if (!l2) return l1;

        ListNode* h = nullptr;
        ListNode* n = nullptr;

        while (l1!=nullptr && l2!=nullptr)
        {
            int val = 0;
            if (l1->val > l2->val)
            {
                val = l2->val;
                l2 = l2->next;
            }
            else
            {
                val = l1->val;
                l1 = l1->next;
            }

            if (h==nullptr)
            {
                h = new ListNode{};
                h->val = val;
                n = h;
            }
            else
            {
                n->next = new ListNode{};
                n->next->val = val;
                n = n->next;
            }
        }

        while (l1!=nullptr)
        {
            if (h==nullptr)
            {
                h = new ListNode{};
                h->val = l1->val;
                n = h;
            }
            else
            {
                n->next = new ListNode{};
                n->next->val = l1->val;
                n = n->next;
            }
            l1=l1->next;
        }

        while (l2!=nullptr)
        {
            if (h==nullptr)
            {
                h = new ListNode{};
                h->val = l2->val;
                n = h;
            }
            else
            {
                n->next = new ListNode{};
                n->next->val = l2->val;
                n = n->next;
            }
            l2=l2->next;
        }
        return h;
    }
};

int main()
{
    return 0;
}
