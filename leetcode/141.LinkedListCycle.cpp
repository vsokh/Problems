#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{

public:
    bool hasCycle(ListNode *head)
    {
        unordered_set<ListNode*> set;
        for (auto p = head; p != NULL; p = p->next)
        {
            if (set.find(p) != set.end())
                return true;

            set.insert(p);
        }
        return false;
    }
};

int main()
{
    Solution s;
    {
        auto head = new ListNode(3);
        auto n1 = new ListNode(2);
        head->next = n1;
        auto n2 = new ListNode(0);
        n1->next = n2;
        auto n3 = new ListNode(-4);
        n2->next = n3;
        n3->next = n1;
        cout << s.hasCycle(head) << endl;
    }
	return 0;
}
