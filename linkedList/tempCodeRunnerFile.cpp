class Solution
{
private:
    unordered_set<ListNode *> st;

public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (!headA || !headB)
        {
            return NULL;
        }
        while (headA != NULL && headB != NULL)
        {
            if (st.find(headA) != st.end())
            {
                return headA;
            }
            if (st.find(headB) != st.end())
            {
                return headB;
            }
            if (st.find(headA) == st.end())
            {
                st.insert(headA);
            }
            if (st.find(headB) == st.end())
            {
                st.insert(headB);
            }

            headA = headA->next;
            headB = headB->next;
        }
        while (headA != NULL)
        {
            if (st.find(headA) != st.end())
            {
                return headA;
            }
            st.insert(headA);
            headA = headA->next;
        }
        while (headB != NULL)
        {
            if (st.find(headB) != st.end())
            {
                return headB;
            }
            st.insert(headB);
            headB = headB->next;
        }
    }
};