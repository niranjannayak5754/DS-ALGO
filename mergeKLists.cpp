/**
 * Merge K Sorted List in ascending order
 *
 * There is an array of linked lists of size k. Need to merge them all and sort in ascending order and return merged list
 */
#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (!l1)
            return l2;
        if (!l2)
            return l1;

        if (l1->val < l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
    ListNode *mergeKLists(vector<ListNode *> &lists, int start, int end)
    {
        if (start > end)
            return nullptr;
        if (start == end)
            return lists[start];

        int mid = start + (end - start) / 2;

        ListNode *left = mergeKLists(lists, start, mid);
        ListNode *right = mergeKLists(lists, mid + 1, end);

        return mergeTwoLists(left, right);
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int n = lists.size();
        return mergeKLists(lists, 0, n - 1);
    }
};