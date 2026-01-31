#include <bits/stdc++.h>
using namespace std;

// approach 1
//  struct ListNode
//  {
//      int val;
//      ListNode *next;
//      ListNode(int x) : val(x), next(NULL) {}
//  };

// class Solution
// {
// private:
//     unordered_set<ListNode *> st;

// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
//     {
//         if (headA == NULL || headB == NULL)
//         {
//             return NULL;
//         }
//         while (headA != NULL)
//         {
//             st.insert(headA);
//             headA = headA->next;
//         }

//         while (headB != NULL)
//         {
//             if (st.find(headB) != st.end())
//             {
//                 return headB;
//             }
//             st.insert(headB);
//             headB = headB->next;
//         }

//         return NULL;
//     }
// };

// int main()
// {
//     ListNode *headA = new ListNode(4);
//     headA->next = new ListNode(1);
//     headA->next->next = new ListNode(8);
//     headA->next->next->next = new ListNode(4);
//     headA->next->next->next->next = new ListNode(5);

//     ListNode *headB = new ListNode(5);
//     headB->next = new ListNode(6);
//     headB->next->next = new ListNode(1);
//     headB->next->next->next = headA->next->next;
//     headB->next->next->next->next = new ListNode(4);
//     headB->next->next->next->next->next = new ListNode(5);

//     Solution s;
//     ListNode *res = s.getIntersectionNode(headA, headB);
//     cout << res->val << endl;

//     return 0;
// }

// approach 2

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{

public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == NULL || headB == NULL)
        {
            return NULL;
        }

        ListNode *temp1 = headA;
        ListNode *temp2 = headB;
        int len1 = 0, len2 = 0;
        while (headA != NULL || headB != NULL)
        {
            if (headA != NULL)
            {
                len1++;
                headA = headA->next;
            }
            if (headB != NULL)
            {
                len2++;
                headB = headB->next;
            }
        }
        int diff = len1 - len2;

        headA = temp1;
        headB = temp2;
        if (diff > 0)
        {

            while (diff-- != 0)
            {
                headA = headA->next;
            }
        }
        else
        {
            while (diff++ != 0)
            {
                headB = headB->next;
            }
        }

        while (headA != NULL)
        {
            if (headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }
};

int main()
{
    ListNode *headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = new ListNode(8);
    headA->next->next->next = new ListNode(4);
    headA->next->next->next->next = new ListNode(5);

    ListNode *headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = headA->next->next;
    headB->next->next->next->next = new ListNode(4);
    headB->next->next->next->next->next = new ListNode(5);

    Solution s;
    ListNode *res = s.getIntersectionNode(headA, headB);
    cout << res->val << endl;

    return 0;
}
