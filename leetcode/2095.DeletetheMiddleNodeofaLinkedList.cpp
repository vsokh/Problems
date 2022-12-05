#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode sant{-1, head};

        ListNode* fast = &sant;
        ListNode* slow = &sant;

        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        if (sant->next == slow) {
            return nullptr;
        }

        if (slow->next != nullptr) {
            slow->next = slow->next->next;
        }

        return sant.next;
    }
};

int main() {
	return 0;
}
