#include <vector>
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
    ListNode* oddEvenList(ListNode* head) {
        /* if (!head || !head->next) { */
        /*     return head; */
        /* } */
        ListNode* odd = head;
        ListNode* even = head->next;
        while (even->next != nullptr) {
            odd->next = even->next;
            even->next = even->next->next;

            even = even->next;
            odd = odd->next;
        }
        return head;
    }
};

int main()
{
    A a;
    return 0;
}
