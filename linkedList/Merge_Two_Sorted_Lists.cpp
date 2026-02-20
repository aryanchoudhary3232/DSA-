#include <bits/stdc++.h>
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {

        if (list1 == nullptr)
        {
            return list2;
        }
        if (list2 == nullptr)
        {
            return list1;
        }

        ListNode *temp1 = list1;
        ListNode *temp2 = list2;

        ListNode dummyHead(-1);
        ListNode *temp = &dummyHead;

        while (temp1 != nullptr && temp2 != nullptr)
        {
            if (temp1->val <= temp2->val)
            {
                temp->next = temp1;
                temp = temp->next;
                temp1 = temp1->next;
            }
            else
            {

                temp->next = temp2;
                temp = temp->next;
                temp2 = temp2->next;
            }
        }

        if (temp1 != nullptr)
        {
            temp->next = temp1;
        }

        if (temp2 != nullptr)
        {
            temp->next = temp2;
        }

        return dummyHead.next;
    }
};

void printLinkedList(ListNode *node)
{

    while (node != nullptr)
    {
        cout << node->val << "->";
        node = node->next;
    }
}

int main()
{
    ListNode *list1 = new ListNode(3);
    list1->next = new ListNode(5);
    // list1->next->next = new ListNode(4);

    ListNode *list2 = new ListNode(1);
    list2->next = new ListNode(2);
    list2->next->next = new ListNode(4);

    Solution s;
    ListNode *ans = s.mergeTwoLists(list1, list2);
    printLinkedList(ans);
    return 0;
}