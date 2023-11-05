/*
    Intersection of two linked lists: [Easy]

    Get the Intersection Node of two linked list.
    Provided that the linked list are not circular
    Return NULL if no intersection node is found

    Example 1:
    Input: listA = [4,1,8,4,5], listB = [5,6,1,8,4,5]
    Output : intersectVal = 8

    Example 2:
    Input : ListA = [1,9,1,2,4], listB = [3,2,4]
    Output : intersectVal = 2
*/
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int getLengthOfLinkedList(ListNode *node)
{
    int l = 0;
    while (node != NULL)
    {
        l++;
        node = node->next;
    }
    return l;
}

ListNode *traverseInLinkedList(ListNode *node, int k)
{
    while (k != 0)
    {
        node = node->next;
        k--;
    }
    return node;
}
ListNode *getIntersection(ListNode *headA, ListNode *headB)
{
    ListNode *list1 = headA, *list2 = headB;
    int l1 = getLengthOfLinkedList(list1);
    int l2 = getLengthOfLinkedList(list2);
    ListNode *a = headA, *b = headB;
    if (l1 > l2)
    {
        a = traverseInLinkedList(a, l1 - l2);
    }
    else if (l2 > l1)
    {
        b = traverseInLinkedList(b, l2 - l1);
    }
    while (a != b)
    {
        a = a->next;
        b = b->next;
    }
    return a;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *a = headA, *b = headB;
    // loop with end after second iteration if no intersection is found as a and b both will be null
    while (a != b)
    {
        // poiting to the head of another linked list after 1st iteration of each list
        a = a == NULL ? headB : a->next;
        b = b == NULL ? headA : b->next;
    }
    return a;
}

int main()
{
    // listA = [4,1,8,4,5], listB = [5,6,1,8,4,5]
    ListNode *headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = new ListNode(8);
    headA->next->next->next = new ListNode(4);
    headA->next->next->next->next = new ListNode(5);

    ListNode *headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = new ListNode(8);
    headB->next->next->next->next = new ListNode(4);
    headB->next->next->next->next->next = new ListNode(5);

    ListNode *res = getIntersectionNode(headA, headB);
    cout << res << endl;
    ListNode *res1 = getIntersection(headA, headB);
    return 0;
}