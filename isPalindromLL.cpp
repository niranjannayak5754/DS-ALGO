#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nextNode = nullptr;

        // reversing the first half of linked list
        while(curr != slow){
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        if(fast) slow = slow->next;
        while(slow && prev){
            if(slow->val != prev->val)
                return false;
            slow = slow->next;
            prev = prev->next;
        }

        return true;
    }
};