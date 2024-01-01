/*
    *********** SWAP NODES IN PAIRS [ Medium ] ****************************8

    swap the nodes of linked in pairs

    Eg : 1 - 2 - 3 - 4 - 5
    Output : 2 - 1 - 4 - 3 - 5


*/

#include <iostream>
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
    ListNode *swapPairs(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *curr = head;
        ListNode *dummy = new ListNode();
        ListNode *prev = dummy;

        ListNode *nextNode, *nextNextNode;
        while (curr && curr->next)
        {
            nextNode = curr->next;
            nextNextNode = nextNode->next;

            prev->next = nextNode;
            nextNode->next = curr;
            curr->next = nextNextNode;

            prev = curr;
            curr = curr->next;
        }

        return dummy->next;
    }
};