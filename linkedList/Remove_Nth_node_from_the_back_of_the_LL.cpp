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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head->next == nullptr)
        {
            return nullptr;
        }
        ListNode *temp = head;
        int len = 0;
        while (temp != nullptr)
        {
            len++;
            temp = temp->next;
        }

        if (len == n)
        {
            ListNode *ans = head->next;
            ListNode *deleteNode = head;
            delete deleteNode;

            return ans;
        }

        int count = len - n;
        temp = head;
        while (count-- > 1)
        {
            temp = temp->next;
        }

        ListNode *deleteNode = temp->next;
        temp->next = temp->next->next;
        delete deleteNode;

        return head;
    }
};

void printLinkedList(ListNode *node)
{

    while (node != nullptr)
    {
        cout << node->val << "->";
        node = node->next;
    }
    cout << endl;
}

int main()
{
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    // list1->next->next = new ListNode(3);
    // list1->next->next->next = new ListNode(4);
    // list1->next->next->next->next = new ListNode(5);

    printLinkedList(list1);

    int n = 2;

    Solution s;
    ListNode *ans = s.removeNthFromEnd(list1, n);

    printLinkedList(ans);
    return 0;
}