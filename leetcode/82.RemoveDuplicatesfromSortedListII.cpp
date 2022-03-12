#include <iostream>
#include <unordered_set>

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode sant{-1, head};
        ListNode* pred = &sant;
        while (head)
        {
            if (head->next && head->val == head->next->val)
            {
                while (head->next && head->val == head->next->val)
                {
                    head = head->next;
                }

                pred->next = head->next;
            }
            else
            {
                pred = pred->next;
            }
            head = head->next;
        }
        return sant.next;
    }
};

int main()
{
    return 0;
}
